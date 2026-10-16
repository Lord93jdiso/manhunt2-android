# Manhunt 2 → ARM64/Android — рабочий каталог проекта

**Обновлено:** 2026-10-15
**Статус:** Этап 0 — рекогносцировка и инструменты

## Цель
Нативный порт Manhunt 2 на ARM64 (Android). Референс методологии: LibertyRecomp /
LibertyRecompAndroid (GTA IV с Xbox 360, статическая рекомпиляция PowerPC → C → ARM).

## Принятые решения
- **База порта: PC-версия** (`Manhunt_2_Win_Files_EN.7z`) — маршрут ИИ-декомпиляции
  (re3 / reLCS / reVC-стиль) + рендер через **librw** (реализация RenderWare с GLES/Android).
- PS2 ISO (SLES_548.19, EU, "Uncut") — оставлена как донор/сравнение; PS2-путь
  (PS2Recomp) признан research-уровня (VU0/VU1).
- Wii-путь (DolRecomp) и PSP-путь (reLCS) — запасные варианты.
- **Рендер: цель — Vulkan** (2026-10-16). D3D9-бэкенд не переносим.
  План: 1) bring-up на GLES3 через librw (быстрый путь до первой картинки);
  2) затем Vulkan: либо собственный бэкенд `rw_vulkan` для librw, либо GLES через ANGLE-over-Vulkan.
  Финальный выбор — на этапе рендера (когда librw уже собирается под arm64).
- **Сборки — только в облаке (GitHub Actions)**. Локальный ПК слабый: локально НЕ компилируем.
  Единственное локальное исключение — фоновая аналитика Ghidra (nice 10).

## Структура каталога
```
manhunt2-port/
├── iso/                 # PS2 ISO (Manhunt 2 [Uncut] (Europe), SLES_548.19)
├── pc/                  # PC-версия (распаковывается из 7z, bg)
├── rwsrc/               # RenderWare Graphics 3.7.0.2 (PC/D3D-ветка) — референс движка
├── ghidra-mcp/          # Ghidra MCP (bridge + расширение GhidraMCP 7.0.0)
├── librw/               # кроссплатформенный RenderWare (aap/librw)
├── mh-replayed/         # фанатский проект Manhunt на базе re3/reVC (syneack)
└── ghidra.sh            # запуск Ghidra GUI с JDK21 (JAVA_HOME=~/.local/jdk21)
```

## Инструменты (готово)
- **ghidra-mcp**: мост `~/.local/bin/bridge-mcp-ghidra` (uv tool, v7.0.0);
  расширение `GhidraMCP-7.0.0.zip` установлено в
  `~/.config/ghidra/ghidra_12.1.2_DEV/Extensions/` (собрано из исходников под Ghidra 12.1.2 DEV).
  Запись в `~/.config/opencode/opencode.jsonc` → `mcp.ghidra-mcp` (не забудь перезапуск opencode).
- **JDK 21**: `~/.local/jdk21` (Temurin, для Ghidra и сборок).
- Запуск Ghidra: `~/manhunt2-port/ghidra.sh` (+ в GUI включить `GhidraMCPPlugin`).
- Для проверки моста: в Ghidra открыть программу и `curl http://127.0.0.1:8089/check_connection`.
- **Headless-сервер GhidraMCP**: сборка `cd ghidra-mcp && JAVA_HOME=~/.local/jdk21 GHIDRA_INSTALL_DIR=/opt/ghidra ~/.local/maven/bin/mvn -P headless package -DskipTests`;
  запуск: `./run-ghidra-mcp-headless.sh [--project <path>]` → http://127.0.0.1:8089 (авто-анализ/декомпиляция без GUI).

## Ключевые факты об игре (PC)
- `Manhunt2.exe` (x86, 2007), `paul.dll` = SecuROM → **для анализа использовать exe из `NoCD.7z`**.
- Движок: RenderWare 3.7 (`rwsrc` — почти ровно та же версия), шейдеры D3D9 (`shaders/*.fxo`).
- Аудио: FMOD (`*.fev`, `*.fsb`, `*.wav`), видео: Bink (`*.bik`).
- Уровни: `levels/A01..A18/<Name>/` — `allanims_pc.ifp`, `collisions_pc.col`, плюс форматы
  `.mdl .tex .bsp .glg .gxt .mls .lsd .inst .grf .snd .bin` (классифицировать по magic-байтам!).
- Диалоги: `audio/PC/Speech/<CHAR>/<n>.wav`.

## Облачные сборки (GitHub Actions)
- Репозиторий кода: **https://github.com/Lord93jdiso/manhunt2-android** (private; игровые данные туда не попадают).
- Workflow `build-librw-android`: собирает **librw + SDL3 под Android arm64-v8a** в облаке (локально не компилируем).
  Шаги: SDL3 из исходников под NDK → патч librw (`tools/ci_patch_librw_android.py`: GLESv3/EGL вместо десктопного GL) →
  CMake+NDK (`LIBRW_PLATFORM=GL3`, `LIBRW_GL3_GFXLIB=SDL3`) → артефакты `dist/` (`librw.a`, `libSDL3.so`).
- Запуск: `gh workflow run build-librw-android` или push, затрагивающий workflow/патч.

## Форматы данных (разведка 2026-10-15)
| Расширение | Сигнатура | Что это |
|---|---|---|
| `.mdl`, `.tex`, `.bsp`, `.ifp`, `.mls`, `.glg` | `Z2HM` + u32 size + `78 DA` (zlib) | сжатые R*-контейнеры: модели/текстуры/сцены/анимации/скрипты/ресурсы. Внутри — распаковать zlib (начиная с offset 8) |
| `.gxt` / `_us.gxt` | `TKEY` | GTA-линия GXT (тексты), инструменты сообщества существуют |
| `.scc` | `MHSC` → блоки `SCPT`/`NAME` | компилированные скрипты игры |
| `.col` | записи с именами | коллизии (`a16_*_StaticProp.ppp`); структуры с именами+float |
| `.inst` | u32-массивы | расстановка сущностей уровня |
| `.grf` | `GNIA` | «mapai» — навигационный граф |
| `.lsd` | текст-заголовок (`DIRECTOR_LEO`…) | lipsync-данные |
| `.lst` | plain text CRLF | списки реплик |
| `.dat` (font) | `<FONT>` | шрифтовые данные |
| `.fev` / `.fsb` / `.fxb` | `FEV1` / `FSB3` / `JPXF` | FMOD Ex: события / банки сэмплов / эффекты |
| `.snd` / `.wav` | `RIFF` | WAVE: музыка (ADPCM) / диалоги (PCM 24кГц) |
| `.bik` | `BIK` | Bink-видео (25 шт.) |
| `.fxo` | — | скомпилированные DX9-шейдеры (`shaders/`) |
| `.dir` | высокая энтропия | зашифрованные/сжатые каталоги (`Executions.dir`, `Scripted.dir`) |

Примечания: уровни `levels/A01..A18` содержат `modelspc.mdl+tex`, `scene*_pc.bsp(+tex)`, `picload_pc.tex`, `resource*.glg`, `allanims_pc.ifp`, `collisions_pc.col`, `entity_pc.inst`, `*_pc.grf`, `mat_pc.bin`, `strmanim_pc.bin`, `<Level>.mls`, `lipsync.lsd`, `speech.lst`.

## Следующие шаги
1. [сейчас] Завершить распаковку PC-архива; распаковать `NoCD.7z`; классифицировать форматы по сигнатурам.
2. Ghidra: headless-импорт Manhunt2.exe с анализом → открыть проект в GUI с GhidraMCPPlugin.
3. librw: собрать demo под Linux x86; написать загрузчики форматов Manhunt 2 (по мере реверса).
4. Android-скелет: SDL3 (окно/ввод/аудио) + GLES3 + ≥30 FPS цель; тач-управление.
5. Декомпиляция ядра логики (ghidra-mcp + субагенты): вход → рендер-цикл → менеджер уровней.

## Хроника
- **2026-10-16** — рестарт сессии отменил импорт в проект `mh2` (на середине); анализ перезапущен (фон, nice 10). Решения дня: рендер → **Vulkan**; сборки → **GitHub Actions (облако)**; заведён private-репозиторий (https://github.com/Lord93jdiso/manhunt2-android) и CI-workflow сборки librw+SDL3 под Android arm64.
- **2026-10-15** — разведка и инструменты: PC-база выбрана; поднят GhidraMCP headless-сервер (:8089, UDS-сокет) + расширение под Ghidra 12.1.2 DEV; создан постоянный проект `ghidra-projects/mh2`; запущен импорт `Manhunt2.exe` с полным автоанализом.
  Находки: контейнеры данных `Z2HM`+zlib (внутри PMLC/TCDT/DLRW/ANCT/MHLS); 328 RTTI-имён C++ классов (`cAI_*`, `aAI_*`, `CGraphPath`, …); COFF-символов нет; импорты: d3dx9_35, fmodex/fmod_event, binkw32, DINPUT8.

## Полезные ссылки
- librw: https://github.com/aap/librw
- Manhunt: Replayed (reVC): https://github.com/syneack/mh-replayed
- Manhunt toolkit: https://github.com/Sor3nt/manhunt-toolkit
- Fire-Head/MHP (патчи Manhunt): https://github.com/Fire-Head/MHP
- PS2Recomp: https://github.com/ran-j/PS2Recomp · DolRecomp: https://github.com/ExpansionPak/DolRecomp
- LibertyRecompAndroid: https://github.com/vaduur/LibertyRecompAndroid
