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
4. [решено] `FUN_00404010` — геттер устройства (`App+4`); vtable +0xc `TestCooperativeLevel`, +0x20 `GetDisplayMode` — это `IDirect3DDevice9`.
5. [решено 2026-10-17] Полный путь от кадра до Draw* - см. Приложение A. Коротко: мастер-рендер кадра FUN_005c5c20 (case 4 из FUN_004b03c0) -> видовой шаг FUN_005c3390 -> FUN_005cf9b0(3) (состояние + регистрация) -> обход списка FUN_005cf960 -> callback 0x005cc320 -> FUN_005cfac0 -> FUN_00607610 (девайс: SetFVF/SetVertexDeclaration/SetIndices/SetStreamSource/DrawIndexedPrimitive). Второй draw-путь: FUN_005b6f80 (сборка) -> FUN_00607780.
6. [решено 2026-10-17] Все сайты прямых вызовов Draw* принадлежат функции-носителю (таблица A.1). Поправка к старой заметке: draw-B (FUN_00607780) имеет SetFVF (сайт 0x0060778d) - прежняя запись "без SetFVF" ошибочна. Хит в FUN_005b6a40 - ложный (поле +0x54 чужого объекта).
7. [в работе] Связка проходов мастера FUN_005c5c20 с эффектами FUN_006081d0 (техники Render*/RenderSkinned*) не подтверждена; зоны 0x608xxx-0x614xxx - UP/2D-пути (A.4).
8. [открыто] Сеттеры колбэков App+0x360 (тик), App+0x38c (конец кадра), App+0x3a4 (рендер).

## Приложение A: цепочка рендера и draw-носители (2026-10-17)

Тела - в docs/ghidra/scan/fun_*.c; сайты - pe_hits2.json + owners.json; вызывающие - callers_draw.json.

### A.1 Сайты прямых вызовов девайса (байтовый скан, окно 48 байт)

| Слот IDirect3DDevice9 | Адрес сайта | Функция-носитель |
|---|---|---|
| DrawPrimitive | - | (нет сайтов) |
| DrawIndexedPrimitive (0x148) | 0x00607736 | FUN_00607610 |
| DrawIndexedPrimitive (0x148) | 0x006078d9 | FUN_00607780 |
| DrawPrimitiveUP (0x14c) | 0x006088a0 | FUN_00608730 |
| DrawPrimitiveUP (0x14c) | 0x00608bce | FUN_00608ad0 |
| DrawPrimitiveUP (0x14c) | 0x0061474b | FUN_00614630 |
| DrawIndexedPrimitiveUP (0x150) | 0x00484621 | FUN_00484420 |
| DrawIndexedPrimitiveUP (0x150) | 0x005b6a64 | FUN_005b6a40 |
| SetVertexDeclaration (0x15c) | 0x00607639 | FUN_00607610 |
| SetVertexDeclaration (0x15c) | 0x006077b6 | FUN_00607780 |
| SetFVF (0x164) | 0x0060761f | FUN_00607610 |
| SetFVF (0x164) | 0x0060778d | FUN_00607780 |
| SetFVF (0x164) | 0x0060887f | FUN_00608730 |
| SetFVF (0x164) | 0x00608bad | FUN_00608ad0 |
| SetFVF (0x164) | 0x0061473b | FUN_00614630 |
| SetStreamSource (0x190) | 0x0060766e | FUN_00607610 |
| SetStreamSource (0x190) | 0x006077eb | FUN_00607780 |
| SetIndices (0x1a0) | 0x00607650 | FUN_00607610 |
| SetIndices (0x1a0) | 0x006077cd | FUN_00607780 |

Примечания: сайт 0x0061474b (FUN_00614630) - indirect CALL. Пул косвенных форм CreateVertexBuffer (CALL [reg+0x68], ~23 шт.) - отдельный слой, без проверки владельцев не использовать.

### A.2 Мастер-рендер кадра FUN_005c5c20 (case 4; файл fun_005c5c20_state4.c)

Порядок: FUN_005b8d00(); FUN_005b9380(); счётчик DAT_00697ed4++; ранний выход FUN_005c3700() при DAT_006d3834==1 и DAT_0077e640; далее FUN_005c3a70(), FUN_005c34c0(param_1), FUN_004ea600(), FUN_005bb160() (= FUN_005bad70 - сортировка draw-списков, 6032 симв. + FUN_005b9880 - таймер перезагрузки).
Лестница подсистем по битам _DAT_006d384c: 0x1->FUN_005e3c10, 0x2->FUN_005cf270, 0x8->FUN_005c32c0 (после FUN_0060bfc0(0xc,1)), 0x20->FUN_004e1150 (заглушка), 0x80->FUN_005e1810, 0x100->FUN_005e4c80, 0x400->FUN_005c36d0, 0x800->FUN_005efcd0, 0x1000->FUN_005c3430, 0x2000->FUN_005f1f50, 0x4000->FUN_005fd190, 0x8000->FUN_005e7660, 0x10000->FUN_005f7060, 0x20000->FUN_005434e0, 0x40000->FUN_0050c360, 0x80000->FUN_005b7440, 0x100000->FUN_005fb6f0.
Три вида: FUN_005c3800(1/2/3) -> thunk_FUN_00435616 + FUN_005c55b0 + FUN_005c3390(param_1) + FUN_005c3e80.
Хвост: при DAT_006ec990 != 4 -> FUN_00605ef0(1); FUN_00545b30(param_1,1) - выход на рендер мира (FUN_00545270); FUN_005c3470; FUN_005c3a10; FUN_00522bd0(&DAT_007894c0); FUN_005e8b80. Else-ветка: FUN_005af790(); FUN_005c34b0(DAT_0075b6f0); FUN_00605ef0(0).

### A.3 Цепочка draw-A (файлы: fun_005c3390.c, fun_005cf9b0.c, fun_005cf960.c, fun_005cfac0_meshdrawA_host.c, fun_00607610_mesh_draw_A.c)

FUN_005c3390 (видовой шаг): при DAT_00789484 - FUN_00585a00(1) (если DAT_0078947c==0), FUN_005cc2e0, FUN_005cc2c0, состояния FUN_0060bfc0(10,5)/(0xb,6)/(0x20,DAT_0078954c), затем FUN_005cf9b0(3), затем FUN_0060bfc0(0x20,0) и повтор FUN_005cc2e0/FUN_005cc2c0.
FUN_005cf9b0(3): FUN_0060bde0() -> holder;(holder+0x30/0x34/0x38 - три float) -> FUN_005cd060(...,2,0xff) -> FUN_005c2280; FUN_0060bfc0(0x1f,1); локальный буфер 64 байта = 0, последний = 1.0f (0x3f800000); FUN_0057e390(); thunk_FUN_0041d879(&buf,0); регистрация: FUN_005cf960(callback=&LAB_005cc320, ctx=3); объект-владелец списка передаётся через ECX (this-call), в декомпиле не виден - уточнить.
FUN_005cf960 (обход): FUN_005cd360(); голова списка = *(this+0x40); для каждого узла: callback(узел, ctx); callback вернул 0 -> стоп (return 0); следующий = *(узел+4); пустой список -> 1.
0x005cc320 (thunk): MOV EAX,[ESP+8]; MOV ECX,[ESP+4]; PUSH EAX; CALL FUN_005cfac0; MOV AL,1; RET.
FUN_005cfac0 (25 байт): if (*(int*)(p1+0x48) != 0) FUN_00607610(p2+0x30, 0);
FUN_00607610 -> девайс: SetFVF(0x164)@0x0060761f, SetVertexDeclaration(0x15c)@0x00607639, SetIndices(0x1a0)@0x00607650, SetStreamSource(0x190)@0x0060766e, DrawIndexedPrimitive(0x148)@0x00607736; карта вершинных форматов - FUN_00607220.

### A.4 Прочие draw-носители

- FUN_00607780 (draw-B): SetFVF@0x0060778d, SetVertexDeclaration@0x006077b6, SetIndices@0x006077cd, SetStreamSource@0x006077eb, DrawIndexedPrimitive@0x006078d9. Caller: FUN_005b6f80 (0x005b7114, 0x005b7172). FUN_005b6f80 - сборка: пул DAT_0077b680, скин-матрицы FUN_0057e4d0, сборка FUN_0056abd0 -> FUN_00607780. Вызовы FUN_005b6f80 - с адресов 0x005bb530 и 0x005bc987 (в Ghidra без функции-владельца; рядом PUSH 0xe; CALL FUN_0060d7d0).
- Адаптер draw-B: thunk 0x005bb520 (PUSH ESI; MOV ESI,[ESP+8]; SETNZ AL; MOV ECX,ESI; PUSH EAX; CALL FUN_005b6f80); FUN_005bbd5a (326 б, data-ref на 0x005bb520; вызывает FUN_0060bfc0(0x1f) и FUN_005bbc40(callback 0x5bb520)); FUN_005bbc40 - обход списка this+0x14: callback(узел, arg) до нуля; единственный caller FUN_005bbd5a - thunk_FUN_005bbd5a (0x0041fbd6).
- FUN_00608730: SetFVF@0x0060887f + DrawPrimitiveUP@0x006088a0; callers: FUN_00608990, FUN_0060af80, FUN_0060b1d0 (x2). FUN_0060af80 вызывается из FUN_00545270 12 раз.
- FUN_00608ad0: SetFVF@0x00608bad + DrawPrimitiveUP@0x00608bce; 8 callers: FUN_005ef78d, FUN_005f1d40, FUN_005f1f50, FUN_005f7060, FUN_00608c10, FUN_00608ce0, FUN_00608db0, FUN_00609020.
- FUN_00614630 (2D-квад): SetFVF@0x0061473b + DrawPrimitiveUP@0x0061474b; callers: FUN_00614c50 (x4), FUN_00614e80; FUN_00614c50 <- FUN_006150b0 (обёртка SetViewport).
- FUN_00484420 (UI): DrawIndexedPrimitiveUP@0x00484621.
- FUN_005b6a40: ложный хит; xref 0 (мёртв).

### A.5 Побочные находки (не draw)

- FUN_005cfb90 - AABB-обход дерева: узлы ushort* по param_1+0x44, локальный стек 32; при попадании бокса (FUN_005cc6e0) callback param_3(начало, начало+count*8, ctx). Обёртка около 0x0060ed70: PUSH 0x0060ec20; CALL FUN_005cfb90 (тело callback 0x60ec20 не декомпилировано - TODO).
- FUN_005c9b50 - глобальные настройки окружения: разбор строк RAINY/THUNDERSTORM/CLEAR/WINDY/THUNDERNORAIN и ARTFILTER/INSIDE/FOGPATCHES/GLOBAL_SETTINGS/FILTERS/CAMERA*; применение на DAT_006ecd10 через FUN_005c7690/FUN_005c78f0.
- FUN_005c9f50/FUN_005c9f70 - поиск в таблице по строке (DAT_007895fc/DAT_00789790, strcmp-цикл).
- FUN_00602ea0 - обход коллекции FUN_005b6e30 (единственный его caller) + матрицы FUN_0060d860 и др.; назначение не установлено.
- FUN_005b9880 - таймер: если *(obj+0x1232c) в диапазоне (0, DAT_006ece6c) -> обнулить и FUN_005b9730().
- FUN_0060bde0 - геттер объекта-держателя (используется FUN_005cf9b0: поля +0x30/+0x34/+0x38).
