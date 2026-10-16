# Android-скелет порта (bring-up)

Цель этого каталога — собрать в облаке **debug-APK** с первой «картинкой»: окно SDL3 +
контекст **GLES3** + очистка экрана. Это проверка сквозной цепочки
`GitHub Actions → NDK → gradle → APK → устройство`, на которую дальше садится librw и порт.

## Как это работает

В репозитории лежит только **overlay** (`overlay/`): наши файлы, которые в CI накатываются
поверх официального шаблона `android-project` из клона SDL3 (`release-3.2.x`):

| Файл overlay | Что заменяет/добавляет |
|---|---|
| `app/build.gradle` | конфиг приложения: `minSdk 24`, `arm64-v8a`, cmake-путь `jni/CMakeLists.txt` |
| `app/jni/CMakeLists.txt` | верхний CMake приложения (вызывает `src/`) |
| `app/jni/src/CMakeLists.txt` | сборка `libmain.so`, линковка `SDL3::SDL3` + `GLESv3` |
| `app/jni/src/main.cpp` | минимальное приложение: SDL3 + GLES3, цветной цикл, выход по тапу |

Java-часть (`org.libsdl.app.SDLActivity` и т.д.), манифест, ресурсы и gradle-wrapper
берутся из шаблона SDL3 — мы их не дублируем.

Сборка: workflow **`build-android-apk`** (собирает SDL3 под Android → накладывает overlay →
`gradlew assembleDebug` → артефакт `mh2-port-debug-apk`).

## Запуск

```
gh workflow run build-android-apk
# или push, затрагивающий android/** (или сам файл workflow)
```

Скачать готовый APK:

```
gh run download -n mh2-port-debug-apk
```

Установка на устройство: `adb install -r app-debug.apk` (debug-подпись, сайдлоад).

## Дальше

1. Прикрутить к скелету `librw.a` и `libSDL3.so` из артефактов **`build-librw-android`**,
   вызвать `rw::Engine::init/open` из `main.cpp` (проверка GL3-драйвера librw на GLES3).
2. Первая сцена: загрузчик `.bsp`/`.mdl` (Z2HM → PMLC) и вывод примитива.
3. Тач-управление, аудио (SDL3), затем шейдерная замена `.fxo` → GLSL.
