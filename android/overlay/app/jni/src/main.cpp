// Manhunt 2 → Android: bring-up №4 — настоящая геометрия уровня (A01) с текстурой сцены.
//
// Что нового по сравнению с v3 (лицо Лео):
//  1. В APK зашиты два новых ассета (уже развёрнутые Z2HM+zlib → gz):
//     mh2scene.bin.gz   — scene1_pc.bsp  (DLRW/WORLD: геометрия уровня A01)
//     mh2scenetex.bin.gz— scene1_pc.tex  (TCDT: текстуры сцены, DDS/DXT)
//  2. BSP-эвристика: сбор 48-байтовых квад-блоков f32 (4 вершины/квад).
//  3. Рендер im3d (НАСТОЯЩИЙ 3D): перспектива, камера летает по уровню.
//  4. Текстура сцены из TCDT через тот же путь, что v3.
//
// Форматы-доказательства: docs/ghidra/map.md Приложение Б.
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <rw.h>
#include <zlib.h>
#include <vector>
#include <string>
#include <math.h>

using namespace rw;

#define TEX_ASSET     "mh2tex.bin"		/* лицо Лео, фитбэк */
#define SCENE_ASSET   "mh2scene.bin"	/* DLRW/BSP         */
#define SCENE_TEX     "mh2scenetex.bin"	/* TCDT сцены       */

static uint32 rd32(const uint8 *b)
{
	return (uint32)b[0] | ((uint32)b[1] << 8) | ((uint32)b[2] << 16) | ((uint32)b[3] << 24);
}

// --- чтение ассета APK: gzip/TCDT по магии, оба имени (.bin/.bin.gz) ---

static std::vector<uint8> loadAssetBin(const char *name)
{
	const char *names[2];
	names[0] = name;
	names[1] = strcmp(name, "mh2tex.bin") == 0
	    ? "mh2tex.bin.gz"
	    : strcmp(name, "mh2scene.bin") == 0 ? "mh2scene.bin.gz"
	    : strcmp(name, "mh2scenetex.bin") == 0 ? "mh2scenetex.bin.gz"
	    : "unknown.asset";

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
		SDL_Log("%s: %zu байт, магия %02x%02x%02x%02x",
		        names[ni], sz, raw[0], raw[1], sz > 2 ? raw[2] : 0, sz > 3 ? raw[3] : 0);

		if (sz >= 2 && raw[0] == 0x1f && raw[1] == 0x8b) {	// gzip
			z_stream z = {};
			if (inflateInit2(&z, 47) != Z_OK) {
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
		// уже развёрнутое (AGP сам раскрывает .gz и переименовывает) — годится как есть
		std::vector<uint8> out(raw, raw + sz);
		delete[] raw;
		return out;
	}
	return std::vector<uint8>();
}

// --- сканер DDS-блоков внутри TCDT ---

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

static Texture *texFromTCDT(const std::vector<uint8> &data, const char *label)
{
	if (data.size() < 0x40 || memcmp(data.data(), "TCDT", 4) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s: TCDT не опознан", label);
		return nil;
	}
	std::vector<Dds> blobs;
	scanDDS(data.data(), data.size(), blobs);
	SDL_Log("%s: DDS-блоков %d", label, (int)blobs.size());
	for (size_t i = 0; i < blobs.size() && i < 16; i++)
		SDL_Log("  [%zu] @0x%x %dx%d mips=%d DXT%d", i, blobs[i].off,
		        blobs[i].w, blobs[i].h, blobs[i].mips, blobs[i].dxt);

	// берём самый крупный блоб ≥128px (крупные текстуры стен/объектов)
	int pick = -1;
	int bestArea = 0;
	for (size_t i = 0; i < blobs.size(); i++) {
		if (blobs[i].w < 128 || blobs[i].h < 128)
			continue;
		int area = blobs[i].w * blobs[i].h;
		if (area > bestArea) { bestArea = area; pick = (int)i; }
	}
	if (pick < 0) {
		SDL_Log("%s: нет блобов ≥128px", label);
		return nil;
	}
	const Dds &b = blobs[pick];
	Texture *tex = nil;
	{
		Image *img = Image::create(b.w, b.h, 32);
		img->allocate();
		img->setPixelsDXT(b.dxt, data.data() + b.off + 128);
		Raster *ras = Raster::createFromImage(img);
		img->destroy();
		if (!ras)
			return nil;
		tex = Texture::create(ras);
		// REPEAT x REPEAT, LINEAR (мировые UV могут выходить за 0..1)
		tex->filterAddressing = (1 << 8) | (1 << 12) | 2;
		SDL_Log("%s: текстура [%d]: %dx%d DXT%d", label, pick, b.w, b.h, b.dxt);
	}
	return tex;
}

// --- BSP (DLRW): эвристический сбор квад-блоков f32 ---

#define MAXQUADS 1600
static float g_quad[MAXQUADS * 12];	// 4 вершины × xyz на квад
static int g_nquad;

static void scanBSPquads(const uint8 *d, size_t len)
{
	g_nquad = 0;
	for (size_t o = 0x88; o + 48 <= len && g_nquad < MAXQUADS; o += 48) {
		const float *f = (const float *)(d + o);
		bool ok = true;
		for (int k = 0; k < 12; k++) {
			float v = f[k];
			if (!(v == v) || fabs(v) > 5000.0f) { ok = false; break; }
		}
		if (ok)
			memcpy(g_quad + g_nquad++ * 12, f, 48);
	}
	SDL_Log("BSP: собрано квадов %d (по 48б от 0x88)", g_nquad);
}

// Раскладка Im3DVertex из rwgl3.h — локальная копия байт-в-байт
// (gl3immed: POS@0, NORMAL@12, COLOR@24, UV@28)
struct Im3DVert
{
	float x, y, z;
	float nx, ny, nz;
	uint8 r, g, b, a;
	float u, v;
};

static Im3DVert g_vert[MAXQUADS * 4];
static uint16 g_idx[MAXQUADS * 6];
static int g_nvert, g_nidx;

static void buildGeoFromQuads(void)
{
	g_nvert = 0; g_nidx = 0;
	const float S = 1.0f / 16.0f;
	for (int q = 0; q < g_nquad; q++) {
		float *p = g_quad + q * 12;
		// доминирующая ось — плоская UV-развёртка
		float ux = p[3] - p[0], uy = p[4] - p[1], uz = p[5] - p[2];
		float nrmx = 0, nrmy = 0, nrmz = 0;
		{
			float ax = p[3] - p[0], ay = p[4] - p[1], az = p[5] - p[2];
			float bx = p[9] - p[0], by = p[10] - p[4] ? p[10] - p[1] : p[10] - p[1], bz = p[11] - p[2];
			nrmx = ay * bz - az * by;
			nrmy = az * bx - ax * bz;
			nrmz = ax * by - ay * bx;
		}
		(void)ux; (void)uy; (void)uz;
		int upAxis = 0;
		if (fabs(nrmy) >= fabs(nrmx) && fabs(nrmy) >= fabs(nrmz)) upAxis = 1;
		else if (fabs(nrmx) >= fabs(nrmz)) upAxis = 0;
		else upAxis = 2;
		for (int v = 0; v < 4; v++) {
			Im3DVert &d = g_vert[g_nvert + v];
			float X = p[v * 3 + 0], Y = p[v * 3 + 1], Z = p[v * 3 + 2];
			d.x = X; d.y = Y; d.z = Z;
			d.nx = nrmx; d.ny = nrmy; d.nz = nrmz;
			float len = sqrtf(nrmx * nrmx + nrmy * nrmy + nrmz * nrmz);
			if (len > 1e-9f) { d.nx /= len; d.ny /= len; d.nz /= len; }
			d.r = 255; d.g = 255; d.b = 255; d.a = 255;
			if (upAxis == 1) { d.u = X * S; d.v = Z * S; }
			else if (upAxis == 0) { d.u = Z * S; d.v = Y * S; }
			else { d.u = X * S; d.v = Y * S; }
		}
		uint16 base = g_nvert;
		uint16 *ii = g_idx + g_nidx;
		ii[0] = base + 0; ii[1] = base + 1; ii[2] = base + 2;
		ii[3] = base + 0; ii[4] = base + 2; ii[5] = base + 3;
		g_nvert += 4; g_nidx += 6;
	}
	SDL_Log("геометрия: вершин %d, индексов %d", g_nvert, g_nidx);
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

	SDL_Window *window = nil;
	EngineOpenParams params = {};
	params.window = &window;
	params.fullscreen = true;
	params.width = 1280;
	params.height = 720;
	params.windowtitle = "Manhunt 2 Port — BSP bring-up";

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
	cam->setProjection(Camera::PERSPECTIVE);
	cam->setNearPlane(0.2f);
	cam->setFarPlane(600.0f);
	cam->setFOV(70.0f, (float)w / (float)h);

	// --- ассеты игры ---
	Texture *sceneTex = nil;
	bool haveBSP = false;
	{
		std::vector<uint8> tcdt = loadAssetBin(SCENE_TEX);
		if (!tcdt.empty())
			sceneTex = texFromTCDT(tcdt, "scene");
		std::vector<uint8> bsp = loadAssetBin(SCENE_ASSET);
		if (bsp.size() > 0x88 + 48 && memcmp(bsp.data(), "DLRW", 4) == 0) {
			scanBSPquads(bsp.data(), bsp.size());
			buildGeoFromQuads();
			haveBSP = g_nquad > 0;
		}
	}
	if (!haveBSP)
		SDL_Log("фолбэк: BSP нет — цветовое демо");

	// --- стартная камера: центр уровня, вид вбок ---
	V3d campos = makeV3d(-20.0f, 6.0f, 25.0f);
	V3d camdir = makeV3d(-0.7f, -0.15f, 0.7f);

	bool running = true;
	Uint64 t0 = SDL_GetTicks();
	while (running) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT)
				running = false;
			else if (e.type == SDL_EVENT_FINGER_DOWN || e.type == SDL_EVENT_KEY_DOWN)
				SDL_Log("ввод получен — демо продолжает работать");
		}

		if (haveBSP) {
			// медленное панорамирование камеры
			float t = (float)(SDL_GetTicks() - t0) * 0.001f;
			float yaw = 0.35f * sinf(t * 0.25f);
			camdir = makeV3d(-0.99f * cosf(yaw), -0.15f, 0.99f * sinf(yaw));

			Matrix m;
			m.setIdentity();
			m.pos = campos;
			m.lookAt(camdir, makeV3d(0.0f, 1.0f, 0.0f));
			cam->getFrame()->matrix = m;
			cam->getFrame()->matrix.update();

			RGBA col;
			col.red = 8; col.green = 8; col.blue = 10; col.alpha = 255;
			cam->beginUpdate();
			cam->clear(&col, Camera::CLEARIMAGE | Camera::CLEARZ);
			SetRenderState(CULLMODE, CULLNONE);
			SetRenderState(ZTESTENABLE, 1);
			SetRenderState(ZWRITEENABLE, 1);
			if (sceneTex)
				SetRenderStatePtr(TEXTURERASTER, sceneTex->raster);
			if (g_nvert) {
				static Matrix ident;
				ident.setIdentity();
				im3d::Transform(g_vert, g_nvert, &ident, im3d::VERTEXUV | im3d::ALLOPAQUE);
				im3d::RenderIndexedPrimitive(PRIMTYPETRILIST, g_idx, g_nidx);
				im3d::End();
			}
			cam->endUpdate();
			cam->showRaster(0);
			SDL_Delay(16);
			continue;
		}

		// фолбэк: цветовое демо bring-up №2
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

	if (sceneTex)
		sceneTex->destroy();
	cam->destroy();

	Engine::stop();
	Engine::close();
	Engine::term();
	SDL_Quit();
	SDL_Log("выход, всё чисто (BSP bring-up)");
	return 0;
}
