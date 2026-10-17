// Manhunt 2 → Android: bring-up №2 — librw (GL3 → GLES3) через SDL3.
//
// Проверяем сквозную цепочку: CI собирает librw.a (LIBRW_PLATFORM=GL3,
// LIBRW_GL3_GFXLIB=SDL3) → линкуется в libmain.so → на устройстве:
// окно и GLES-контекст создаёт сам librw (список профилей ES 3.1 → ES 2.0),
// камера librw чистит экран и кадр отдаётся через showRaster.
// Тап по экрану (или клавиша / закрытие) — выход.
//
// Это первый прогон рендер-слоя librw на телефоне; следующим шагом будет
// загрузка реальных ассетов (PMLC/TCDT) и вывод геометрии.
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <rw.h>

using namespace rw;

static void log_subsystems(void)
{
    int n = Engine::getNumSubSystems();
    for (int i = 0; i < n; i++) {
        SubSystemInfo info;
        if (Engine::getSubSystemInfo(&info, i))
            SDL_Log("подсистема [%d/%d]: %s", i + 1, n, info.name);
    }
    // как в скелете librw: выбрать последнюю (gl3)
    if (n > 0)
        Engine::setSubSystem(n - 1);
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

    // Окно и GLES-контекст создаёт librw (gl3device.cpp: профили ES 3.1 → ES 2.0).
    SDL_Window *window = nullptr;
    EngineOpenParams params = {};
    params.window = &window;
    params.fullscreen = true;
    params.width = 1280;
    params.height = 720;
    params.windowtitle = "Manhunt 2 Port — librw bring-up";

    if (!Engine::open(&params)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "rw::Engine::open — не удалось");
        Engine::term();
        SDL_Quit();
        return 1;
    }
    log_subsystems();

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

    VideoMode mode;
    if (Engine::getVideoModeInfo(&mode, Engine::getCurrentVideoMode()))
        SDL_Log("видеорежим librw: %dx%d@%d", mode.width, mode.height, mode.depth);

    // Камера с растрами под размер окна (аналог sk::CameraCreate из скелета librw).
    Camera *cam = Camera::create();
    cam->setFrame(Frame::create());
    cam->frameBuffer = Raster::create(w, h, 0, Raster::CAMERA);
    cam->zBuffer = Raster::create(w, h, 0, Raster::ZBUFFER);
    cam->setFarPlane(1000.0f);
    // текущую камеру выставляет сам beginUpdate() (defaultBeginUpdateCB → engine->currentCamera)

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

        float t = (float)(SDL_GetTicks() - t0) * 0.001f;
        RGBA col;
        col.red   = (uint8)(128.0f + 127.0f * SDL_sinf(t));
        col.green = 40;
        col.blue  = (uint8)(128.0f - 127.0f * SDL_sinf(t));
        col.alpha = 255;

        cam->beginUpdate();
        cam->clear(&col, Camera::CLEARIMAGE | Camera::CLEARZ);
        cam->endUpdate();
        cam->showRaster(0);
        SDL_Delay(16);
    }

    cam->frameBuffer->destroy();
    cam->zBuffer->destroy();
    Frame *f = cam->getFrame();
    cam->setFrame(nil);
    f->destroy();
    cam->destroy();

    Engine::stop();
    Engine::close();
    Engine::term();
    SDL_Quit();
    SDL_Log("выход, всё чисто (librw)");
    return 0;
}
