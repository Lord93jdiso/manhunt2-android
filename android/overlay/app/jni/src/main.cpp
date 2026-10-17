// Manhunt 2 → Android: bring-up №3 — первая текстура игры (TCDT → DDS → DXT1).
//
// Что проверяем: в APK зашит .tex-блок игры (gzip), приложение читает,
// находит DDS-блоки, DXT распаковывает сам librw (Image::setPixelsDXT),
// текстура уходит в GLES через Texture::create(Raster::createFromImage).
// Рисуем Im2D-квад с этой текстурой. Тап — не выход (только в лог).
//
// Если разбор/декодирование сорвался — остаёмся в цветовом демо bring-up №2.
//
// Телефон/эмуляция: SDL3 surface → librw gl3 (GLES3) → showRaster.
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <rw.h>
#include <zlib.h>
#include <vector>
#include <string>

using namespace rw;

#define TEX_ASSET "mh2tex.bin"

// Чтение ассета с развёрткой: AGP разжимает .gz-ассеты и переименовывает
// (.bin.gz -> .bin), поэтому пробуем оба имени и sniff по магии
// (1f 8b = gzip, "TCDT" = уже готовый контейнер).
static std::vector<uint8> loadTexAsset(const char *name)
{
	const char *names[2];
	names[0] = name;
	names[1] = strcmp(name, "mh2tex.bin") == 0 ? "mh2tex.bin.gz" : "mh2tex.bin";

	uint8 buf[65536];
	for (int ni = 0; ni < 2; ni++) {
		SDL_IOStream *io = SDL_IOFromFile(names[ni], "rb");
		if (!io) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s: не читается (%s)", names[ni], SDL_GetError());
			continue;
		}
		size_t sz = SDL_GetIOSize(io);
		uint8 *raw = new uint8[sz];
		bool ok = SDL_ReadIO(io, raw, sz) == sz;
		SDL_CloseIO(io);
		if (!ok) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s: прочитано меньше %zu", names[ni], sz);
			delete[] raw;
			continue;
		}
		SDL_Log("%s: прочитано %zu байт, магия %02x%02x%02x%02x",
		        names[ni], sz, raw[0], raw[1], sz > 2 ? raw[2] : 0, sz > 3 ? raw[3] : 0);

		// gzip?
		if (sz >= 2 && raw[0] == 0x1f && raw[1] == 0x8b) {
			z_stream z = {};
			if (inflateInit2(&z, 47) != Z_OK) {	// 47 = gzip на входе
				delete[] raw;
				continue;
			}
			std::vector<uint8> out;
			out.reserve(sz * 2);
			z.next_in = raw;
			z.avail_in = (uInt)sz;
			int ret = Z_OK;
			while (ret == Z_OK || ret == Z_BUF_ERROR) {
				z.next_out = buf;
				z.avail_out = (uInt)sizeof(buf);
				ret = inflate(&z, Z_NO_FLUSH);
				size_t got = sizeof(buf) - z.avail_out;
				if (got) out.insert(out.end(), buf, buf + got);
				if (ret == Z_STREAM_END || z.avail_in == 0) break;
			}
			inflateEnd(&z);
			if (ret != Z_STREAM_END) {
				SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "inflate: ret=%d (%s)", ret, z.msg ? z.msg : "н/д");
				delete[] raw;
				continue;
			}
			SDL_Log("inflate: %zu -> %zu байт", sz, out.size());
			delete[] raw;
			return out;
		}
		// уже готовый TCDT?
		if (sz >= 4 && memcmp(raw, "TCDT", 4) == 0) {
			std::vector<uint8> out(raw, raw + sz);
			delete[] raw;
			return out;
		}
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s: неизвестная магия", names[ni]);
		delete[] raw;
	}
	return std::vector<uint8>();
}

static uint32 rd32(const uint8 *b)
{
	return (uint32)b[0] | ((uint32)b[1] << 8) | ((uint32)b[2] << 16) | ((uint32)b[3] << 24);
}

// --- DDS-блоки внутри TCDT-контейнера ---

struct Dds
{
	int off, w, h, mips, dxt;	// dxt: 1/3/5
	size_t size;
};

static void scanDDS(const uint8 *d, size_t len, std::vector<Dds> &out)
{
	for (size_t i = 0; i + 128 <= len; i++) {
		if (memcmp(d + i, "DDS ", 4) != 0)
			continue;
		const uint8 *h = d + i + 4;
		uint32 hdrSize = rd32(h);
		if (hdrSize < 120 || hdrSize > 512)
			continue;
		int height = (int)rd32(h + 8);
		int width = (int)rd32(h + 12);
		int mips = (int)rd32(h + 24);
		const uint8 *fcc = h + 80;
		int dxt = 0;
		if (memcmp(fcc, "DXT1", 4) == 0) dxt = 1;
		else if (memcmp(fcc, "DXT3", 4) == 0) dxt = 3;
		else if (memcmp(fcc, "DXT5", 4) == 0) dxt = 5;
		if (dxt == 0 || width == 0 || height == 0)
			continue;
		int bs = dxt == 1 ? 8 : 16;
		int cw = (width + 3) / 4, ch = (height + 3) / 4;
		size_t size = 0;
		for (int m = 0; m < mips && cw > 0 && ch > 0; m++) {
			size += (size_t)cw * ch * bs;
			if (cw > 1) cw >>= 1;
			if (ch > 1) ch >>= 1;
		}
		Dds e;
		e.off = (int)i; e.w = width; e.h = height; e.mips = mips; e.dxt = dxt; e.size = size;
		out.push_back(e);
		i += 128 + size - 1;
	}
}

// --- Im2D-квад ---
// Раскладка Im2DVertex из librw/gl3 (rwgl3.h) повторена локально:
// gl3immed читаетвершины по offset'ам (POS 0, COLOR 16, UV 20), поэтому
// структура должна быть байт-в-байт такой же.
struct Im2DVert
{
	float x, y, z, w;
	uint8 r, g, b, a;
	float u, v;
};

static Im2DVert quad[4];
static uint16 quadIdx[6] = { 0, 1, 2, 0, 2, 3 };

static void fillQuad(int w, int h)
{
	for (int i = 0; i < 4; i++) {
		quad[i].r = 255; quad[i].g = 255; quad[i].b = 255; quad[i].a = 255;
		quad[i].z = 0.0f;
		quad[i].w = 1.0f;
	}
	quad[0].x = 0; quad[0].y = 0; quad[0].u = 0; quad[0].v = 0;
	quad[1].x = w; quad[1].y = 0; quad[1].u = 1; quad[1].v = 0;
	quad[2].x = w; quad[2].y = h; quad[2].u = 1; quad[2].v = 1;
	quad[3].x = 0; quad[3].y = h; quad[3].u = 0; quad[3].v = 1;
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init: %s", SDL_GetError());
		return 1;
	}

	if (!Engine::init()) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "rw::Engine::init — не удалось");
		SDL_Quit();
		return 1;
	}

	SDL_Window *window = nullptr;
	EngineOpenParams params = {};
	params.window = &window;
	params.fullscreen = true;
	params.width = 1280;
	params.height = 720;
	params.windowtitle = "Manhunt 2 Port — TCDT bring-up";

	if (!Engine::open(&params)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "rw::Engine::open — не удалось");
		Engine::term();
		SDL_Quit();
		return 1;
	}
	if (!Engine::start()) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "rw::Engine::start — не удалось");
		Engine::close();
		Engine::term();
		SDL_Quit();
		return 1;
	}

	int w = params.width, h = params.height;
	if (window)
		SDL_GetWindowSizeInPixels(window, &w, &h);
	SDL_Log("окно librw: %dx%d", w, h);

	// --- камера (как в bring-up №2: своя, с буферами под окно) ---
	Camera *cam = Camera::create();
	cam->setFrame(Frame::create());
	cam->frameBuffer = Raster::create(w, h, 0, Raster::CAMERA);
	cam->zBuffer = Raster::create(w, h, 0, Raster::ZBUFFER);
	cam->setFarPlane(1000.0f);
	SDL_Log("камера готова %dx%d", w, h);

	// --- текстура игры ---
	Texture *tex = nil;
	{
		std::vector<uint8> data = loadTexAsset(TEX_ASSET);
		if (!data.empty()) {
			SDL_Log("TCDT: magic=%.4s ver=%d размер=%zu", data.data(), (int)rd32(data.data() + 4), data.size());
			std::vector<Dds> blobs;
			scanDDS(data.data(), data.size(), blobs);
			SDL_Log("DDS-блоков: %d", (int)blobs.size());
			size_t pick = 0;
			for (size_t i = 0; i < blobs.size(); i++)
				SDL_Log("  [%zu] @0x%x %dx%d mips=%d DXT%d size=%zu",
				        i, blobs[i].off, blobs[i].w, blobs[i].h, blobs[i].mips, blobs[i].dxt, blobs[i].size);
			if (!blobs.empty()) {
				const Dds &b = blobs[pick];
				Image *img = Image::create(b.w, b.h, 32);
				img->allocate();	// без этого pixels = nil → crash в decompressDXT1
				img->setPixelsDXT(b.dxt, data.data() + b.off + 128);
				Raster *ras = Raster::createFromImage(img);
				img->destroy();
				if (ras) {
					tex = Texture::create(ras);
					// CLAMP x CLAMP, LINEAR (VVVVUUUU FFFFFFFF)
					tex->filterAddressing = (3 << 8) | (3 << 12) | 2;
					SDL_Log("текстура готова: %dx%d DXT%d", b.w, b.h, b.dxt);
				} else {
					SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Raster::createFromImage — не удался");
				}
			}
		}
		if (!tex)
			SDL_Log("фолбэк: цветовое демо (текстуры нет)");
	}
	fillQuad(w, h);

	// --- цикл ---
	bool running = true;
	Uint64 t0 = SDL_GetTicks();
	while (running) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				running = false;
			} else if (e.type == SDL_EVENT_FINGER_DOWN || e.type == SDL_EVENT_KEY_DOWN) {
				SDL_Log("ввод получен — демо продолжает работать");
			}
		}

		if (tex) {
			RGBA col;
			col.red = 0; col.green = 0; col.blue = 0; col.alpha = 255;
			cam->beginUpdate();
			cam->clear(&col, Camera::CLEARIMAGE | Camera::CLEARZ);
			SetRenderState(ZTESTENABLE, 0);
			SetRenderState(ZWRITEENABLE, 0);
			SetRenderState(CULLMODE, CULLNONE);
			SetRenderStatePtr(TEXTURERASTER, tex->raster);
			im2d::RenderIndexedPrimitive(PRIMTYPETRILIST, quad, 4, quadIdx, 6);
			cam->endUpdate();
			cam->showRaster(0);
			SDL_Delay(16);
			continue;
		}

		// фолбэк: старое цветовое демо
		{
			float t = (float)(SDL_GetTicks() - t0) * 0.001f;
			RGBA col;
			col.red = (uint8)(128.0f + 127.0f * SDL_sinf(t));
			col.green = 40;
			col.blue = (uint8)(128.0f - 127.0f * SDL_sinf(t));
			col.alpha = 255;
			cam->beginUpdate();
			cam->clear(&col, Camera::CLEARIMAGE | Camera::CLEARZ);
			cam->endUpdate();
			cam->showRaster(0);
			SDL_Delay(16);
		}
	}

	if (tex) {
		tex->destroy();
	}
	cam->destroy();

	Engine::stop();
	Engine::close();
	Engine::term();
	SDL_Quit();
	SDL_Log("выход, всё чисто (TCDT bring-up)");
	return 0;
}
