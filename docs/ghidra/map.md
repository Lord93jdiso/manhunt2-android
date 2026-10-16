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
- `FUN_0040d8d0` — диспетчер кадра: `FUN_00403fd0()` (состояние WinObj) → `FUN_0040cfc0()` (игра) либо `FUN_0040d5c0()` (фронтенд).

### Кадр игры `FUN_0040cfc0` (порядок)
1. Если `App+0x314` или `FUN_004af140()` — `Sleep(50)`.
2. Текущее устройство: `FUN_00404010()` (`App+4` = `IDirect3DDevice9*`); NULL и флаг `App+0x314` → пересоздание окна (96 байт настроек из `007a6f00` → `FUN_0040af80`).
3. `device->vtbl[+0xc]()` = `TestCooperativeLevel`; `0x88760868` (`D3DERR_DEVICELOST`) → восстановление окна/девайса (`FUN_00409130`, `FUN_0041e650`, `FUN_0040af80(...,1,0)`).
4. **Лимитер ≈30 FPS**: spin до `0x8256` (33366 µs) от QPC (`DAT_006ddbc8`).
5. Тайминги: `FUN_00416d1c` (начало), `FUN_00414700` (конец) → `App+0x288` (double t), `App+0x290` (u64), `App+0x298` (float dt).
6. Апдейты подсистем: `FUN_00407c10()`, `FUN_00407560()`.
7. **Главный тик**: колбэк `App+0x360(t, dt, hwnd)`.
8. Завершение кадра: `FUN_0040d449()` — колбэк `App+0x38c` (геттер `FUN_00463e50`) → **`Present`** (`device->vtbl[+0x44](dev,0,0,0,0)`); ошибки `0x88760868`/`0x88760827` (`DEVICELOST`/`DEVICENOTRESET`) → `FUN_004027b7(1)` (флаг `App+0x314`).

### Кадр фронтенда `FUN_0040d5c0`
- Проверка окна (`007a6a80`), текущий экран `thunk_FUN_00435f90`; `Sleep(50)` при неактивности.
- Тайминги те же; время двигают `FUN_00401c10/FUN_00401c50/FUN_00401c90`; апдейты: `FUN_00406030`, `FUN_00407c10`, `FUN_00407560`.
- Тик `App+0x360(t,dt,hwnd)`, затем **рендер-колбэк** `App+0x3a4` (геттер `FUN_00464030`, thunk 0x403170) → `(*pcVar)(hwnd, t, dt, …)`.
- `screen->vtbl[+0x20]()` → коды: `0x87a0001`, `-0x7785fff9` (→ `FUN_00409a90`), `-0x7785fffb` (→ `FUN_0040c160`).
- Хвост: `thunk_FUN_004c9650()` (кадросчётчик), `FUN_00401dd0`, `FUN_00406480`, `FUN_004068d0`, контроль `FUN_00410700()`.

## D3D9 — граница рендера (найдено 2026-10-16)
- Строка `Direct3DCreate9` @ 0x0063b1d0 (ASCII); xref → **`FUN_00413ef0`** — динамическая инициализация D3D9
  (LoadLibrary + GetProcAddress). **[основной кандидат на замену при порте: GLES3/Vulkan]**.
- В импортах D3D9-функций нет вообще → весь интерфейс с D3D9 идёт через указатели, полученные рантайм.
- Глобальные точки: `DAT_006ddbe0` = HMODULE `d3d9.dll`; `DAT_006ddbe4` = `Direct3DCreate9`; `DAT_006ddbe8…006ddc00` = `D3DPERF_*` (PIX-профайлер).
- `FUN_004140f0(0x20)` = `Direct3DCreate9(D3D_SDK_VERSION=32)` → **сырой `IDirect3D9*`** в **`App[0]`** (создаётся в `FUN_00404cd0` под критсекцией; обёртки нет — проверено дизасмом).
- ⚠ Ключевое: в vtable `IDirect3D9` перед `CreateDevice` стоит **`GetAdapterMonitor`** (объявлен в `d3d9helper.h`): **+0x3c = `GetAdapterMonitor(Adapter)`→HMONITOR**, **+0x40 = `CreateDevice`**.
- **Поверхность `IDirect3D9`, используемая игрой** (подтверждена дизасмом): +0x10 `GetAdapterCount`, +0x14 `GetAdapterIdentifier`, +0x18 `GetAdapterModeCount`, +0x1c `EnumAdapterModes` (`FUN_004122c0` — энумератор адаптеров/режимов, дедуп по DeviceName@+0x204); +0x20 `GetAdapterDisplayMode` (`FUN_0040e860`, `FUN_00410c60`, `FUN_00412900`); +0x28 `CheckDeviceFormat` (`FUN_006151d0` = колбэк `App+0x378`; вызов `(..., 2, 1, 0x4b)`); +0x2c `CheckDeviceMultiSampleType` (`FUN_0040a510`); +0x3c `GetAdapterMonitor` (`FUN_0040a290`: результат → `GetMonitorInfoW`, и в `App+0x238` через `FUN_00401710`); +0x40 `CreateDevice` (`FUN_00408dc0`).
- `FUN_0041e650` (68 б) — **геттер `IDirect3D9*`** (App[0], thunk 0x408690): зовёт `FUN_00404cd0` и возвращает указатель. 47+ потребителей.
- **Создание устройства — `FUN_00408dc0`** (167 строк): из `WinObj` (App+8): `+4` = адаптер, `+8` = `D3DDEVTYPE`, `+0x10` = hFocusWindow-поле; `CreateDevice` (vtable+0x40) → **`App+4` = `IDirect3DDevice9*`**; `GetDeviceCaps` → `D3DCAPS9` в `App+0x2c`; `D3DERR_DEVICELOST` → `FUN_004027b7(1)`; курсор — `FUN_00403690`, `FUN_00407870` (`SetCursorProperties`+0x28, `ShowCursor`+0x30).
- **Геттер устройства `FUN_00404010`** (`App+4`; ~23 потребителя — кадры, `FUN_00409130`, SecuROM `FUN_007a6db0`).
- `FUN_004027b7(x)` — сеттер флага **`App+0x314` «устройство потеряно»** (при флаге кадр делает `Sleep(50)` и пропускает рендер).
- **Present — `FUN_0040d449`** (конец кадра, thunk 0x41c946): колбэк `App+0x38c` (геттер `FUN_00463e50`) → `(*cb)()` → `device->vtbl[+0x44](dev,0,0,0,0)`; `0x88760868`/`0x88760827` (`DEVICELOST`/`DEVICENOTRESET`) → `FUN_004027b7(1)`.
- **Рендер-колбэк `App+0x3a4`** (геттер `FUN_00464030`, thunk 0x403170): `(*cb)(hwnd, t, dt, …)` — каждый кадр фронтенда.
- `FUN_00407960` — лог видеорежима (`D3D9 %sVsync %s (%dx%d), …`): имя адаптера — `FUN_00413a10` (850 б), имена `D3DFMT_*` — `FUN_00413629`. Конфиг окна — `WinObj = App+8` (+0x14/+0x18 W/H, +0x24 multisample, +0x48 presentation interval, +0x2eb «залогировано»).
- Колбэки: `FUN_00404740(x, y)` пишет `App+0x378 = x`, `App+0x3c4 = y`; `FUN_004047c0(x, y)` — `App+0x37c = x`, `App+0x3c8 = y` (простые сеттеры полей, не «регистрации»); значения из WinMain: `FUN_006151d0`, `LAB_00615260`.
- **D3D10-путь**: `FUN_00413fc0` грузит `d3d10.dll` + `dxgi.dll`; списки устройств — геттеры `FUN_0040e680` (объект+0x58) и `FUN_0040ea20` (объект+0x38); предикат выбора пути `FUN_00403fd0`→`FUN_004034b0(WinObj)`.
- **DXUT** вкомпилирован (assert `w:\manhunt2_pc\mh2_vs2005\dxut\core\DXUTmisc.h`): `0x40a2xx–0x40a5xx` — перечислитель устройств (`FUN_0040a2e0` — поиск настройки под HMONITOR через `GetAdapterMonitor`+`GetMonitorInfoW`; `FUN_0040a496` +0x28; `FUN_0040a510` +0x2c); `0x4142xx` — монитор-хелперы (`FUN_004142a0` = `MonitorFromWindow`, `FUN_004142f0` = `MonitorFromRect`).

## SecuROM (`.secu`, RWX, 0x007a5000–0x007d8fff)
- `thunk_FUN_007a****` — обёртки защиты. Замечены: `0x7a6b80`, `0x7a6bf0` (→ HWND главного окна),
  `0x7a6250` (callback создания окна), `0x7a70d0` (вызов из WinMain), `0x7a5fe0`, `0x7a8de0`, `0x7a6900`,
  `0x7a56c0`, `0x7a5660`, `0x7a58f0`, `0x7a5d00`, `0x7a5dd0`, `0x7a5c40`, `0x7a5ca0`, `0x7a5d70`, `0x7a6140`, `0x7a6190`, `0x7a6040`…
- Т.е. многие «системные» вызовы проходят через `.secu`-трамплины — при адаптации под ARM их надо идентифицировать (вероятно, тонкие обёртки `jmp [imp]`).

## Импорты (228, `docs/ghidra/imports.json`)
- USER32: CreateWindowExW, PeekMessageW, DispatchMessageW, ShowWindow, AdjustWindowRect, SetWindowPos, SetThreadExecutionState, GetWindowPlacement…
- D3DX9 (`d3dx9_35.dll`): `D3DXCreateEffectEx`, `D3DXCreateEffectPool`, `D3DXMatrix{OrthoLH,Transpose,Multiply,Inverse}`
  → эффекты `.fxo`! **В импортах нет `Direct3DCreate9`** — d3d9 грузится динамически (подтверждено: `FUN_00413ef0`).
  Эффект-класс — `FUN_006081d0`: данные `.fxo` в полях +8/+0xc, `ID3DXEffect*` в +0x10; параметры — `GetParameterByName` (+0x24):
  `g_mWorld`, `g_mWorldInverseTranspose`, `g_mWorldViewProjection`, `g_mInverseView`, `g_mView`, `g_amBoneMtx`,
  `g_oDiffuseSampler/Tex`, `g_oSecondSampler/Tex`, `g_vLightAmbient`, `g_avLightPos{X,Y,Z}`, `g_avLightCol{R,G,B}`,
  `g_avLight4OneOverRange`, `g_avLight4SpecularIntensity`, `g_vFogAttributes`, `g_vFogColor`, `g_vDiffuseTransform`,
  `g_vAlphaTest`, `g_vTexCoordOffset`; техники `Render%s`/`RenderSkinned%s` (массив `PTR_DAT_006da234`) через `GetTechniqueByName` (+0x34).
- DINPUT8: `DirectInput8Create`; WINMM; `binkw32.dll` (`_BinkOpenDirectSound@4`); `fmodex`/`fmod_event`;
  `mscoree.dll` (CLR — вероятно, только для чего-то мелкого/DXUT).

## Сегменты
`Headers` 0x400000; `.text` 0x401000–0x637fff (2.3 МБ); `.rdata` 0x638000–0x684fff; `.data` 0x685000–0x7a1023;
`.rsrc` 0x7a2000; `.secu` 0x7a5000–0x7d8fff (RWX, SecuROM); `tdb` 0xffdff000.

## Строки-маркеры
- `W:\Manhunt2_PC\Code\src\ai\graph.cpp`, `W:\Manhunt2_PC\mh2_vs2005\DXUT\Core\DXUT*.cpp` (assert'ы практически вычищены в релизе).
- Эффекты постобработки: `RENDER_VSYNC_EFFECT`, `RENDER_GHOST_IMAGE`, `RENDER_COLOR_NOISE`, `RENDER_COLOR_SHIFT`, `RENDER_BORDER`, `RENDER_PIXELS`; `ShadowRender`, `RenderSkinned%s`.
- **Шейдеры — 13 `.fxo`** в `Game Files/shaders/`: `PostProcess(.2)`, `depthshadow`, `shadowrender`, `lit_{dualtexture,environmentmap,singletexture,singletexture_uvanim,texreconfig}`, `unlit_{32indtexture,notexture,singletexture,singletexture_texclamp}`.
- Анимации: `*_SURRENDER_INTO_ANIM` и т.п. (это, похоже, список названий анимаций внутри exe).

## Открытые вопросы
1. [решено] Главный цикл: `FUN_0042b096` → `FUN_0040e529` → `FUN_0040d8d0` → (`FUN_0040cfc0` / `FUN_0040d5c0`).
2. [решено] D3D9 грузится динамически; инициализация — `FUN_00413ef0` (см. раздел D3D9).
3. [решено] `FUN_004047xx` из WinMain — сеттеры полей App (`+0x378/+0x3c4`, `+0x37c/+0x3c8`); значения — `FUN_006151d0`, `LAB_00615260`.
4. [решено] `FUN_00404010` — геттер устройства (`App+4`); vtable +0xc `TestCooperativeLevel`, +0x20 `GetDisplayMode` — это `IDirect3DDevice9`. `thunk_FUN_00435f90` (фронтенд) — уточнить.
5. [в работе] Рендер-мир и поверхность девайса: эффекты `FUN_006081d0`, регион 0x60xxxx; потребители устройства `FUN_0060cb30/FUN_0060cbc0/FUN_0060be00` и др.
6. [открыто] Сеттеры колбэков `App+0x360` (тик), `App+0x38c` (конец кадра), `App+0x3a4` (рендер).
