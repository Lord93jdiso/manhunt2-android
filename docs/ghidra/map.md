# Карта функций Manhunt2.exe (проект Ghidra `mh2`)

> Обновляется по мере реверса. Адреса — виртуальные (image base 0x00400000).
> Декомпиляции — в `docs/ghidra/*.c`, bulk-выгрузки — `imports.json`, `classes.json`,
> `strings_src_paths.json`, `entry_points.json`.

## Точка входа и запуск
| Адрес | Функция | Заметки |
|---|---|---|
| 0x0061c2a1 | `entry` | PE entry (xref×2) |
| 0x0061c0c2 | `___tmainCRTStartup` | VS2005 CRT → вызывает WinMain |
| 0x006155c0 | **WinMain** | mutex `"Manhunt2"` (single instance + локализованное «уже запущен»); парсинг `-safe` и второго флага; проверка `global/pictures/legal_fr.tex`; 11× `FUN_004047xx(FUN_00615xxx,0)` — регистрация обработчиков; затем цепочка инициализаций (см. ниже); последним — геттер `FUN_0044c1a0` (поле App+0x2f8) |

### Цепочка инициализаций из WinMain (порядок)
`FUN_0040dc80(fullscreen?,…,w,h,…)` → `FUN_006154f0` → `FUN_0056f560` → `FUN_0040e3a0(0)` → `FUN_0056f9a0` → `FUN_0056c0c0` → `*(App+0x20)=1` → `FUN_00594420` → `FUN_005943d0` → `FUN_004df4a0` → `FUN_004ce710` → `thunk_FUN_0044c1a0`.

## Объект приложения (синглтон)
- `GetApp()`: `thunk_FUN_0043189b` → `FUN_00403f05` — возвращает `DAT_006ddbb8` (объект App);
  при первом вызове — `thunk_FUN_007a6900()` + `_atexit(&LAB_006356f0)` (дestructor при выходе).
- `DAT_00685000` — флаг «Southpark» (использовать критическую секцию), секция @ `0x006ddba0`.
- Наблюдённые поля App: `+0x2f8` состояние/код, `+0x305`, `+0x306`, `+0x324`, `+0x32c`, `+0x340`,
  `+0x341`, `+0x342` — флаги; `+0x31c` режим; `+0x338`/`+0x33c` — размеры окна; `+8` — «другое окно»/prev.

## Окно / девайс
| Адрес | Функция | Заметки |
|---|---|---|
| 0x0040dc80 | `FUN_0040dc80(fullscreen?,w,h,flags,?)` | сборка структуры настроек (0x60 байт) → `FUN_0040af80`; возвращает `<0` при ошибке |
| 0x0040af80 | `FUN_0040af80(settings*,…,?)` | **оконный менеджер**: аллокация 0x60, вызов callback через `.secu`-указатель `0x7a6250`, `CreateWindowExW`, `AdjustWindowRect`, `SetWindowPos`, `ShowWindow`, пересоздание окна при смене режима; при успехе → `FUN_00409a90`/`FUN_00409130` |
| 0x0040e3a0 | `FUN_0040e3a0` | «старт игры»: `FUN_0040dc80(1,0,0,0x3c,0)` → `FUN_00408620` → `FUN_0042b096` |
| 0x00408620 | геттер hwnd? | зовётся по всему оконному коду (`FUN_00408620()` → HWND) |
| 0x00409a90 | `FUN_00409a90` (322 б) | после создания окна; `GetClientRect`, `FUN_00435f90` |
| 0x00409130 | `FUN_00409130` (753 б) | после создания окна; `FUN_00616f0c`, `FUN_0048d1d0` |

## Главный цикл (найден 2026-10-16)
- `FUN_0042b096` — «Run»: настраивает указатель на `PeekMessageW` (через IAT 0x638258) + таблицу акселераторов (HACCEL) → вызывает `FUN_0040e529`. Зовётся из `FUN_0040e3a0`.
- `FUN_0040e529` — **message loop**: `PeekMessageW(&msg,0,0,0,PM_REMOVE)` (до 32 сообщений/проход) → `TranslateMessage`/`DispatchMessageW`; при `WM_QUIT (0x12)` — `DestroyAcceleratorTable` + выход. **Каждый проход → `FUN_0040d8d0()` — ядро кадра (update+render).**
- `FUN_0040d8d0` — **ядро кадра** [декомпиляция в работе].

## D3D9 — граница рендера (найдено 2026-10-16)
- Строка `Direct3DCreate9` @ 0x0063b1d0 (ASCII); xref → **`FUN_00413ef0`** — динамическая инициализация D3D9
  (LoadLibrary + GetProcAddress). **[основной кандидат на замену при порте: GLES3/Vulkan]**.
- В импортах D3D9-функций нет вообще → весь интерфейс с D3D9 идёт через указатели, полученные рантайм.

## SecuROM (`.secu`, RWX, 0x007a5000–0x007d8fff)
- `thunk_FUN_007a****` — обёртки защиты. Замечены: `0x7a6b80`, `0x7a6bf0` (→ HWND главного окна),
  `0x7a6250` (callback создания окна), `0x7a70d0` (вызов из WinMain), `0x7a5fe0`, `0x7a8de0`, `0x7a6900`,
  `0x7a56c0`, `0x7a5660`, `0x7a58f0`, `0x7a5d00`, `0x7a5dd0`, `0x7a5c40`, `0x7a5ca0`, `0x7a5d70`, `0x7a6140`, `0x7a6190`, `0x7a6040`…
- Т.е. многие «системные» вызовы проходят через `.secu`-трамплины — при адаптации под ARM их надо идентифицировать (вероятно, тонкие обёртки `jmp [imp]`).

## Импорты (228, `docs/ghidra/imports.json`)
- USER32: CreateWindowExW, PeekMessageW, DispatchMessageW, ShowWindow, AdjustWindowRect, SetWindowPos, SetThreadExecutionState, GetWindowPlacement…
- D3DX9 (`d3dx9_35.dll`): `D3DXCreateEffectEx`, `D3DXCreateEffectPool`, `D3DXMatrix{OrthoLH,Transpose,Multiply,Inverse}`
  → эффекты `.fxo`! **В импортах нет `Direct3DCreate9`** — d3d9, судя по всему, грузится динамически (проверяется).
- DINPUT8: `DirectInput8Create`; WINMM; `binkw32.dll` (`_BinkOpenDirectSound@4`); `fmodex`/`fmod_event`;
  `mscoree.dll` (CLR — вероятно, только для чего-то мелкого/DXUT).

## Сегменты
`Headers` 0x400000; `.text` 0x401000–0x637fff (2.3 МБ); `.rdata` 0x638000–0x684fff; `.data` 0x685000–0x7a1023;
`.rsrc` 0x7a2000; `.secu` 0x7a5000–0x7d8fff (RWX, SecuROM); `tdb` 0xffdff000.

## Строки-маркеры
- `W:\Manhunt2_PC\Code\src\ai\graph.cpp`, `W:\Manhunt2_PC\mh2_vs2005\DXUT\Core\DXUT*.cpp` (assert'ы практически вычищены в релизе).
- Эффекты постобработки: `RENDER_VSYNC_EFFECT`, `RENDER_GHOST_IMAGE`, `RENDER_COLOR_NOISE`, `RENDER_COLOR_SHIFT`, `RENDER_BORDER`, `RENDER_PIXELS`; `ShadowRender`, `RenderSkinned%s`.
- Анимации: `*_SURRENDER_INTO_ANIM` и т.п. (это, похоже, список названий анимаций внутри exe).

## Открытые вопросы
1. [решено] Главный цикл: `FUN_0042b096` → `FUN_0040e529` → `FUN_0040d8d0` → (`FUN_0040cfc0` / `FUN_0040d5c0`).
2. [решено] D3D9 грузится динамически; инициализация — `FUN_00413ef0` (см. раздел D3D9).
3. Что такое `FUN_004047xx`-регистрации из WinMain (система подсистем)?
4. «Экран-объекты»: `FUN_00404010` (кадр) / `thunk_FUN_00435f90` (фронтенд), vtables +0xc/+0x20 — что это за система?
5. Где рендер-проход мира (RW-подобный pipeline) и вызовы «девайса» из кадра?
6. Кто ставит колбэк `App+0x360` (вызывается каждый кадр)?
