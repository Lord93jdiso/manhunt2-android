// Manhunt 2 → Android: минимальный bring-up (SDL3 + GLES3).
// Шаг 1: окно, GLES3-контекст, очистка экрана — проверка сквозной цепочки
// «CI → APK → устройство». Тап по экрану (или любая клавиша) завершает приложение.
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <GLES3/gl3.h>

static void log_gl_info(void)
{
    SDL_Log("GL_VERSION : %s", (const char *)glGetString(GL_VERSION));
    SDL_Log("GL_RENDERER: %s", (const char *)glGetString(GL_RENDERER));
    SDL_Log("GL_VENDOR  : %s", (const char *)glGetString(GL_VENDOR));
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init failed: %s", SDL_GetError());
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    SDL_Window *win = SDL_CreateWindow("Manhunt 2 Port — bring-up", 1280, 720,
                                       SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
    if (!win) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateWindow failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_GLContext ctx = SDL_GL_CreateContext(win);
    if (!ctx) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_GL_CreateContext failed: %s", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    int v = SDL_GetVersion();
    SDL_Log("SDL %d.%d.%d | видео-драйвер: %s",
            v / 1000000, (v / 1000) % 1000, v % 1000, SDL_GetCurrentVideoDriver());
    log_gl_info();

    bool running = true;
    Uint64 t0 = SDL_GetTicks();
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT ||
                e.type == SDL_EVENT_KEY_DOWN ||
                e.type == SDL_EVENT_FINGER_DOWN) {
                running = false;
            }
        }

        int w = 0, h = 0;
        SDL_GetWindowSizeInPixels(win, &w, &h);
        glViewport(0, 0, w, h);

        float t = (float)(SDL_GetTicks() - t0) * 0.001f;
        glClearColor(0.5f + 0.5f * SDL_sinf(t), 0.35f, 0.5f - 0.5f * SDL_sinf(t), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(win);
        SDL_Delay(16);
    }

    SDL_GL_DestroyContext(ctx);
    SDL_DestroyWindow(win);
    SDL_Quit();
    SDL_Log("выход, всё чисто");
    return 0;
}
