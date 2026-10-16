# Заметки по строкам Manhunt2.exe (зацепки для декомпиляции)

Источник: `strings -a -n 6` (ASCII, 8458 строк) + UTF-16-проход по PC-exe.
Дата разведки: 2026-10-16. Инструмент: `tools/` + Ghidra (проект `mh2`).

## Следы исходной кодовой базы (главное для Ghidra)

- **Сборочный путь студии:** `W:\Manhunt2_PC\Code\src\ai\graph.cpp` — значит дерево исходников
  `Code\src\...`; по относительному пути из хедера — подсистемы `ai`, `general\mem`
  (`..\code\src\general\mem\tGEN_SmallUsageMemory.h`).
- **Wide-строки:** `W:\Manhunt2_PC\mh2_vs2005\DXUT\Core\DXUT.cpp`, `DXUTmisc.cpp` —
  окно/девайс/сообщения гоняются через Microsoft **DXUT** (VS2005-дерево `mh2_vs2005`).
  Для порта DXUT не тащим: это клей поверх D3D9, мы заменяем его на SDL3 + GLES3/Vulkan.
- **Assert-макрос** (наш основной инструмент сопоставления при декомпиляции):
  `Assertion failed: %s, file %s, line %d` (+ CRT-тексты про assert).
  На каждом assert-сайте рядом должны лежать `__FILE__`-строки и номера строк —
  можно восстанавливать исходные имена файлов.
- **Лог-строка:** `EntityAnim.cpp: %s has a buggered matrix` — файл `EntityAnim.cpp`
  (анимация сущностей).

## Пространства имён / RTTI

- `neo::` — фронтенд/движок: `.?AVDefaultSettingsPage@neo@@`, `.?AVSaveGamesPage@neo@@`,
  `LAYERED_DEFAULT_SETTINGS_PAGE`, `SAVEGAMES_PAGE`, `HEARTBEAT_SETTINGS`…
- Полный снимок RTTI: **`docs/rtti_classes.txt`** (все `.?AV`/`.?AU`-имена из exe).

## Уровни (имена папок данных из строк exe)

A01_Escape_Asylum, A02_The_Old_House, A03_Neighbourhood, A04_SM_Nightclub, A09_Burn,
A12_Plaza, A14_SugarFactory, A15_Cemetery, A18_Manor, … (полный список — в строках exe).

## Рантайм/данные

- **FMOD EX** (импорты `System@FMOD`…), звук: `%s.fsb`, `/LEVELEND.fsb`, `.fev` (события).
- **Initscripts:** `global/initscripts/SETTINGS.txt`, `initscripts/frontend/settings.txt`,
  `GLOBAL/INITSCR/SETTINGS.TXT`.
- Расширения, всплывающие в строках: `.mdl .tex` (Z2HM-контейнер), `.col`, `.cam`, `.grf`,
  `.bik`, `.fsb`, `.fev`, `.bsp`, `.bin`, `.tag`, `.lst`.
- **`.glg` — пак ресурсов уровня**: в каждой папке уровня лежат `resource1.glg`, `resource2.glg`,
  `resource3.glg` (~32 файла на все уровни).
- **Шейдеры**: `shaders/*.fxo` — 13 скомпилированных D3D9 Effect
  (`PostProcess`, `PostProcess2`, `depthshadow`, `lit_*`, `unlit_*`, `shadowrender`).
  Для порта: дизассемблировать/пересобрать в GLSL (GLES3) → позже в SPIR-V (Vulkan).

## Рендер (что заменяем)

- `d3dx9_35.dll`: `D3DXMatrixInverse/Multiply/Transpose/OrthoLH`, `D3DXCreateEffectEx/Pool`,
  `D3DPERF_*` (NVPerfHUD-метки событий).
- DXUT-фреймворк держит device/window/message-loop (заменяем на SDL3-каркас порта).

## TODO (по мере анализа)

- [ ] Найти assert-сайты в Ghidra → выписать `__FILE__`-константы (карта модулей кода).
- [ ] Сопоставить RTTI-классы (`docs/rtti_classes.txt`) с vtables/конструкторами.
- [ ] Разобрать `.glg` (32 упоминания) — похоже на шейдерный/GL-формат.
