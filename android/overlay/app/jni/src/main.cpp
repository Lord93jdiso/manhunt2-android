// Manhunt 2 → Android: bring-up №6 — ПОЛНЫЙ УРОВЕНЬ С ТЕКСТУРАМИ.
//
// bpp 5 Kumpulan: bring-up №5 рендерил все 71 меш BSP из мегамеша (цвета вершин).
// Теперь добавлены:
//   mh2texmap.bin  — TEXM: 132 материалы → {texIdx i16, цвет RGB u8×3}
//   mh2texall.bin  — TEXA: 149 текстур {w,h,size RGB565} + пиксели (DXT1/3/5 декодированы
//                    и перевёрнуты по Y конвертером tools/conv_bsp_mesh + tex)
// Шейдер: цвет = vertexDiffuse × materialColor × texture(uv) × boost.
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <rw.h>
#include <zlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <GLES3/gl3.h>

using namespace rw;

#define MESH_ASSET    "mh2mesh.bin"	/* MMH: мегамеш    */
#define TEXMAP_ASSET  "mh2texmap.bin"	/* TEXM: материалы */
#define TEXALL_ASSET  "mh2texall.bin"	/* TEXA: текстуры  */

static uint32 rd32(const uint8 *b)
{
	return (uint32)b[0] | ((uint32)b[1] << 8) | ((uint32)b[2] << 16) | ((uint32)b[3] << 24);
}

static float rdf32(const uint8 *b)
{
	uint32 u = rd32(b);
	float f;
	memcpy(&f, &u, 4);
	return f;
}

// --- чтение ассета APK (gzip / уже развёрнутое AGP) ---

static std::vector<uint8> loadAssetBin(const char *name)
{
	char alt[64];
	snprintf(alt, sizeof(alt), "%s.gz", name);
	const char *names[2] = { name, alt };
	uint8 buf[65536];
	for (int ni = 0; ni < 2; ni++) {
		SDL_IOStream *io = SDL_IOFromFile(names[ni], "rb");
		if (!io)
			continue;
		size_t sz = SDL_GetIOSize(io);
		uint8 *raw = new uint8[sz];
		bool ok = SDL_ReadIO(io, raw, sz) == sz;
		SDL_CloseIO(io);
		if (!ok) { delete[] raw; continue; }
		SDL_Log("%s: %zu байт, магия %02x%02x%02x%02x", names[ni], sz,
		        raw[0], raw[1], raw[2], raw[3]);
		if (sz >= 2 && raw[0] == 0x1f && raw[1] == 0x8b) {	// gzip
			z_stream z = {};
			if (inflateInit2(&z, 47) == Z_OK) {
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
				if (ret == Z_STREAM_END) {
					SDL_Log("inflate: %zu -> %zu байт", sz, out.size());
					delete[] raw;
					return out;
				}
			}
			delete[] raw;
			continue;
		}
		std::vector<uint8> out(raw, raw + sz);
		delete[] raw;
		return out;
	}
	return std::vector<uint8>();
}

// --- мегамеш ---

struct SubMesh
{
	uint32 firstVert, numVerts, firstIdx, numIdx;
	int32 mat;
	float bbox[6];
};

static std::vector<SubMesh> g_subs;
static std::vector<uint8> g_verts;	// 24Б: pos f32×3 | rgba u8×4 | uv f32×2
static std::vector<uint32> g_idx;
static float g_bmin[3], g_bmax[3];

static bool parseMegamesh(const std::vector<uint8> &data)
{
	if (data.size() < 40 || memcmp(data.data(), "MMH1", 4) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "megamesh: неверная магия");
		return false;
	}
	const uint8 *h = data.data();
	uint32 nsub = rd32(h + 4);
	uint32 nvert = rd32(h + 8);
	uint32 nidx = rd32(h + 12);
	for (int i = 0; i < 3; i++) {
		g_bmin[i] = rdf32(h + 16 + 4 * i);
		g_bmax[i] = rdf32(h + 28 + 4 * i);
	}
	SDL_Log("megamesh: subs=%u verts=%u idx=%u bbox=(%.1f,%.1f,%.1f)..(%.1f,%.1f,%.1f)",
	        nsub, nvert, nidx, g_bmin[0], g_bmin[1], g_bmin[2], g_bmax[0], g_bmax[1], g_bmax[2]);
	const uint8 *p = h + 40;
	size_t need = (size_t)nsub * 44 + (size_t)nvert * 24 + (size_t)nidx * 4;
	if (data.size() - 40 < need) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "megamesh: коротко %zu < %zu", data.size() - 40, need);
		return false;
	}
	g_subs.resize(nsub);
	for (uint32 i = 0; i < nsub; i++) {
		SubMesh &s = g_subs[i];
		s.firstVert = rd32(p);
		s.numVerts = rd32(p + 4);
		s.firstIdx = rd32(p + 8);
		s.numIdx = rd32(p + 12);
		memcpy(&s.mat, p + 16, 4);
		for (int k = 0; k < 6; k++)
			s.bbox[k] = rdf32(p + 20 + 4 * k);
		p += 44;
	}
	g_verts.assign(p, p + (size_t)nvert * 24);
	p += (size_t)nvert * 24;
	g_idx.resize(nidx);
	memcpy(g_idx.data(), p, (size_t)nidx * 4);
 SDL_Log("megamesh: разобран");
	return nsub > 0 && nvert > 0 && nidx > 0;
}

// --- материалы и текстуры ---

struct TexEntry { uint16 w, h; uint32 off; };

static std::vector<TexEntry> g_tex;
static std::vector<uint8> g_texData;
static std::vector<int16> g_matTex;
static std::vector<float> g_matCol;	// 3 на материал
static int g_nmat;

static bool parseTexmap(const std::vector<uint8> &data)
{
	if (data.size() < 8 || memcmp(data.data(), "TEXM", 4) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "texmap: неверная магия");
		return false;
	}
	int n = (int)rd32(data.data() + 4);
	size_t need = 8 + (size_t)n * 5;
	if (data.size() < need) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "texmap: коротко");
		return false;
	}
	g_nmat = n;
	g_matTex.resize(n);
	g_matCol.resize(n * 3);
	const uint8 *p = data.data() + 8;
	for (int i = 0; i < n; i++) {
		g_matTex[i] = (int16)(uint32)(p[0] | (p[1] << 8));
		g_matCol[i * 3 + 0] = p[2] / 255.0f;
		g_matCol[i * 3 + 1] = p[3] / 255.0f;
		g_matCol[i * 3 + 2] = p[4] / 255.0f;
		p += 5;
	}
	SDL_Log("texmap: %d материалов", n);
	return n > 0;
}

static bool parseTexall(const std::vector<uint8> &data)
{
	if (data.size() < 8 || memcmp(data.data(), "TEXA", 4) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "texall: неверная магия");
		return false;
	}
	int n = (int)rd32(data.data() + 4);
	const uint8 *p = data.data() + 8;
	size_t hdrend = 8 + (size_t)n * 8;
	if (data.size() < hdrend) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "texall: коротко");
		return false;
	}
	g_tex.resize(n);
	size_t databytes = 0;
	for (int i = 0; i < n; i++) {
		g_tex[i].w = (uint16)(p[0] | (p[1] << 8));
		g_tex[i].h = (uint16)(p[2] | (p[3] << 8));
		uint32 sz = rd32(p + 4);
		g_tex[i].off = (uint32)databytes;
		databytes += sz;
		p += 8;
	}
	g_texData.assign(data.begin() + hdrend, data.end());
	SDL_Log("texall: %d текстур, данных %.1fMB", n, databytes / 1e6);
	return n > 0 && databytes <= g_texData.size();
}

// --- GL ---

static const char *VS = R"(#version 300 es
uniform mat4 u_mvp;
layout(location=0) in vec3 a_pos;
layout(location=1) in vec4 a_col;
layout(location=2) in vec2 a_uv;
out vec4 v_col;
out vec2 v_uv;
void main(){ gl_Position = u_mvp * vec4(a_pos, 1.0); v_col = a_col; v_uv = a_uv; })";

static const char *FS = R"(#version 300 es
precision mediump float;
in vec4 v_col;
in vec2 v_uv;
uniform sampler2D u_tex;
uniform vec3 u_matcol;
uniform float u_boost;
out vec4 fragColor;
void main(){
  vec3 tc = texture(u_tex, v_uv).rgb;
  vec3 c = tc * u_boost;
  fragColor = vec4(min(c, vec3(1.0)), 1.0); })";

static GLuint g_prog, g_vao, g_vbo, g_ibo;
static GLint g_locMvp = -1, g_locBoost = -1, g_locMatcol = -1, g_locTex = -1;
static std::vector<GLuint> g_texArr;
static GLuint g_whiteTex = 0;

static GLuint makeShader(GLenum type, const char *src)
{
	GLuint sh = glCreateShader(type);
	glShaderSource(sh, 1, &src, NULL);
	glCompileShader(sh);
	GLint ok = 0;
	glGetShaderiv(sh, GL_COMPILE_STATUS, &ok);
	if (!ok) {
		char log[1024];
		glGetShaderInfoLog(sh, sizeof(log), NULL, log);
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "шейдер: %s", log);
	}
	return sh;
}

static void setupTexParams(void)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

static void buildGL(const std::vector<uint8> &verts, const std::vector<uint32> &idx)
{
	GLuint vs = makeShader(GL_VERTEX_SHADER, VS);
	GLuint fs = makeShader(GL_FRAGMENT_SHADER, FS);
	g_prog = glCreateProgram();
	glAttachShader(g_prog, vs);
	glAttachShader(g_prog, fs);
	glLinkProgram(g_prog);
	GLint ok = 0;
	glGetProgramiv(g_prog, GL_LINK_STATUS, &ok);
	if (!ok) {
		char log[1024];
		glGetProgramInfoLog(g_prog, sizeof(log), NULL, log);
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "линковка: %s", log);
	}
	g_locMvp = glGetUniformLocation(g_prog, "u_mvp");
	g_locBoost = glGetUniformLocation(g_prog, "u_boost");
	g_locMatcol = glGetUniformLocation(g_prog, "u_matcol");
	g_locTex = glGetUniformLocation(g_prog, "u_tex");

	glGenVertexArrays(1, &g_vao);
	glGenBuffers(1, &g_vbo);
	glGenBuffers(1, &g_ibo);
	glBindVertexArray(g_vao);
	glBindBuffer(GL_ARRAY_BUFFER, g_vbo);
	glBufferData(GL_ARRAY_BUFFER, verts.size(), verts.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, idx.size() * 4, idx.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void *)(uintptr)0);
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, 24, (void *)(uintptr)12);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 24, (void *)(uintptr)16);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	// текстуры (RGB565, mip0, REPEAT)
	int n = (int)g_tex.size();
	g_texArr.resize(n);
	glGenTextures(n, g_texArr.data());
	for (int i = 0; i < n; i++) {
		glBindTexture(GL_TEXTURE_2D, g_texArr[i]);
		setupTexParams();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB565, g_tex[i].w, g_tex[i].h, 0,
		             GL_RGB565, GL_UNSIGNED_SHORT_5_6_5,
		             g_texData.data() + g_tex[i].off);
	}
	// белая заглушка
	glGenTextures(1, &g_whiteTex);
	glBindTexture(GL_TEXTURE_2D, g_whiteTex);
	setupTexParams();
	uint16 white = 0xFFFF;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB565, 2, 2, 0, GL_RGB565,
	             GL_UNSIGNED_SHORT_5_6_5, &white);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
	SDL_Log("GL: программа+VBO(%zu Б)+IBO(%zu Б)+текстуры(%d) готовы", verts.size(), idx.size() * 4, n);
}

// --- матрицы ---

static void matMul(float *out, const float *a, const float *b)
{
	float t[16];
	for (int c = 0; c < 4; c++)
		for (int r = 0; r < 4; r++) {
			float s = 0;
			for (int k = 0; k < 4; k++)
				s += a[k * 4 + r] * b[c * 4 + k];
			t[c * 4 + r] = s;
		}
	memcpy(out, t, sizeof(t));
}

static void matPerspective(float *m, float fovYdeg, float aspect, float zn, float zf)
{
	float f = 1.0f / tanf(fovYdeg * 3.14159265f / 360.0f);
	memset(m, 0, 16 * sizeof(float));
	m[0] = f / aspect;
	m[5] = f;
	m[10] = (zf + zn) / (zn - zf);
	m[11] = -1.0f;
	m[14] = 2.0f * zf * zn / (zn - zf);
}

static void matLookAt(float *m, float ex, float ey, float ez,
                      float tx, float ty, float tz, float ux, float uy, float uz)
{
	float zx = ex - tx, zy = ey - ty, zz = ez - tz;
	float zl = sqrtf(zx*zx + zy*zy + zz*zz);
	zx /= zl; zy /= zl; zz /= zl;
	float xx = uy * zz - uz * zy;
	float xy = uz * zx - ux * zz;
	float xz = ux * zy - uy * zx;
	float xl = sqrtf(xx*xx + xy*xy + xz*xz);
	xx /= xl; xy /= xl; xz /= xl;
	float yx = zy * xz - zz * xy;
	float yy = zz * xx - zx * xz;
	float yz = zx * xy - zy * xx;
	m[0] = xx; m[1] = yx; m[2] = zx; m[3] = 0;
	m[4] = xy; m[5] = yy; m[6] = zy; m[7] = 0;
	m[8] = xz; m[9] = yz; m[10] = zz; m[11] = 0;
	m[12] = -(xx*ex + xy*ey + xz*ez);
	m[13] = -(yx*ex + yy*ey + yz*ez);
	m[14] = -(zx*ex + zy*ey + zz*ez);
	m[15] = 1.0f;
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
	params.windowtitle = "Manhunt 2 Port — уровень с текстурами";

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

	Camera *cam = Camera::create();
	cam->setFrame(Frame::create());
	cam->frameBuffer = Raster::create(w, h, 0, Raster::CAMERA);
	cam->zBuffer = Raster::create(w, h, 0, Raster::ZBUFFER);
	cam->setProjection(Camera::PERSPECTIVE);
	cam->setNearPlane(0.2f);
	cam->setFarPlane(800.0f);
	cam->setFOV(70.0f, (float)w / (float)h);

	bool haveLevel = false;
	{
		std::vector<uint8> txm = loadAssetBin(TEXMAP_ASSET);
		std::vector<uint8> txa = loadAssetBin(TEXALL_ASSET);
		bool t_ok = false;
		if (!txm.empty() && !txa.empty())
			t_ok = parseTexmap(txm) && parseTexall(txa);
		std::vector<uint8> mm = loadAssetBin(MESH_ASSET);
		if (!mm.empty() && parseMegamesh(mm)) {
			buildGL(g_verts, g_idx);
			haveLevel = true;
			if (!t_ok)
				SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "текстуры не загрузились — цветной режим");
		} else if (!t_ok) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "мегамеш/текстуры не загружены");
		}
	}

	float cx = (g_bmin[0] + g_bmax[0]) * 0.5f;
	float cy = (g_bmin[1] + g_bmax[1]) * 0.5f;
	float cz = (g_bmin[2] + g_bmax[2]) * 0.5f;
	float spanX = g_bmax[0] - g_bmin[0];
	float spanY = g_bmax[1] - g_bmin[1];
	float spanZ = g_bmax[2] - g_bmin[2];
	float orbit = (spanX > spanZ ? spanX : spanZ) * 0.65f + 10.0f;

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

		float t = (float)(SDL_GetTicks() - t0) * 0.001f;

		RGBA col;
		col.red = 10; col.green = 10; col.blue = 14; col.alpha = 255;
		cam->beginUpdate();
		cam->clear(&col, Camera::CLEARIMAGE | Camera::CLEARZ);

		if (haveLevel) {
			// две фазы: god-view → street-level
			float phase = fmodf(t / 22.0f, 2.0f);
			float yaw, ex, eyr, ez, tx = cx, ty = cy, tz = cz;
			if (phase < 1.0f) {
				yaw = t * 0.12f;
				eyr = cy + spanY * 0.9f;
				ex = cx + orbit * cosf(yaw);
				ez = cz + orbit * sinf(yaw);
			} else {
				yaw = t * 0.15f;
				float rr = (spanX > spanZ ? spanX : spanZ) * 0.18f + 6.0f;
				eyr = g_bmin[1] + 6.0f;
				ex = cx + rr * cosf(yaw);
				ez = cz + rr * sinf(yaw);
				tx = ex - sinf(yaw);
				tz = ez + cosf(yaw);
				ty = eyr + 0.5f;
			}
			static int nlog;
			if (++nlog % 60 == 1)
				SDL_Log("кам%s: pos=(%.1f,%.1f,%.1f) цел=(%.1f,%.1f,%.1f)",
				        phase < 1.0f ? "(god)" : "(street)", ex, eyr, ez, tx, ty, tz);

			float proj[16], view[16], mvp[16];
			matPerspective(proj, 70.0f, (float)w / (float)h, 0.2f, 800.0f);
			matLookAt(view, ex, eyr, ez, tx, ty, tz, 0.0f, 1.0f, 0.0f);
			matMul(mvp, proj, view);

			glBindVertexArray(g_vao);
			glUseProgram(g_prog);
			glUniformMatrix4fv(g_locMvp, 1, GL_FALSE, mvp);
			glUniform1f(g_locBoost, 1.25f);
			glUniform1i(g_locTex, 0);
			glUniform3f(g_locMatcol, 1.0f, 1.0f, 1.0f);
			glActiveTexture(GL_TEXTURE0);
			glDisable(GL_BLEND);
			glDisable(GL_CULL_FACE);
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LEQUAL);
			for (size_t i = 0; i < g_subs.size(); i++) {
				const SubMesh &s = g_subs[i];
				if (s.numIdx == 0)
					continue;
				int mi = (int)s.mat;
				GLuint tex = g_whiteTex;
				if (mi >= 0 && mi < g_nmat && g_matTex[mi] >= 0 &&
				    g_matTex[mi] < (int)g_texArr.size())
					tex = g_texArr[g_matTex[mi]];
				glBindTexture(GL_TEXTURE_2D, tex);
				glUniform3f(g_locMatcol,
				            g_matCol[mi * 3 + 0],
				            g_matCol[mi * 3 + 1],
				            g_matCol[mi * 3 + 2]);
				glDrawElements(GL_TRIANGLES, (GLsizei)s.numIdx, GL_UNSIGNED_INT,
				               (void *)(uintptr)(s.firstIdx * 4));
			}
		}
		cam->endUpdate();
		cam->showRaster(0);
		SDL_Delay(16);
	}

	if (haveLevel) {
		glBindVertexArray(0);
		glDeleteTextures((GLsizei)g_texArr.size(), g_texArr.data());
		glDeleteTextures(1, &g_whiteTex);
		glDeleteBuffers(1, &g_ibo);
		glDeleteBuffers(1, &g_vbo);
		glDeleteVertexArrays(1, &g_vao);
		glDeleteProgram(g_prog);
	}
	cam->destroy();

	Engine::stop();
	Engine::close();
	Engine::term();
	SDL_Quit();
	SDL_Log("выход, всё чисто (уровень с текстурами)");
	return 0;
}
