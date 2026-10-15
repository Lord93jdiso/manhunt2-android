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

## Следующие шаги
1. [сейчас] Завершить распаковку PC-архива; распаковать `NoCD.7z`; классифицировать форматы по сигнатурам.
2. Ghidra: headless-импорт Manhunt2.exe с анализом → открыть проект в GUI с GhidraMCPPlugin.
3. librw: собрать demo под Linux x86; написать загрузчики форматов Manhunt 2 (по мере реверса).
4. Android-скелет: SDL3 (окно/ввод/аудио) + GLES3 + ≥30 FPS цель; тач-управление.
5. Декомпиляция ядра логики (ghidra-mcp + субагенты): вход → рендер-цикл → менеджер уровней.

## Полезные ссылки
- librw: https://github.com/aap/librw
- Manhunt: Replayed (reVC): https://github.com/syneack/mh-replayed
- Manhunt toolkit: https://github.com/Sor3nt/manhunt-toolkit
- Fire-Head/MHP (патчи Manhunt): https://github.com/Fire-Head/MHP
- PS2Recomp: https://github.com/ran-j/PS2Recomp · DolRecomp: https://github.com/ExpansionPak/DolRecomp
- LibertyRecompAndroid: https://github.com/vaduur/LibertyRecompAndroid
