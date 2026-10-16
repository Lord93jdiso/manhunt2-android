#!/usr/bin/env python3
"""Патчи librw для сборки под Android (вызывается из CI).

CMake-скрипт librw (src/CMakeLists.txt) ожидает десктопный OpenGL:
цепочка `OpenGL::OpenGL → OpenGL::EGL → OpenGL::GL`, иначе FATAL_ERROR.
На Android нужен GLESv3 + EGL (есть в NDK). Патч:
  1) если CMake выдал OpenGL::GLES — линкуем его (проверяем раньше остальных);
  2) если вообще ничего не нашлось — линкуем сырые GLESv3/EGL (резолвятся NDK-тулчейном).

Идемпотентен: повторный запуск ничего не меняет.
Usage: ci_patch_librw_android.py <путь-к-клону-librw>
"""
from __future__ import annotations

import pathlib
import sys

GLES_BRANCH = (
    "if(TARGET OpenGL::GLES)\n"
    "        target_link_libraries(librw\n"
    "            PRIVATE\n"
    "                OpenGL::GLES\n"
    "        )\n"
    "    elseif(TARGET OpenGL::OpenGL)"
)

FATAL = 'message(FATAL_ERROR "find_package(OpenGL) failed.")'
FATAL_REPLACEMENT = (
    "target_link_libraries(librw\n"
    "            PRIVATE\n"
    "                GLESv3\n"
    "                EGL\n"
    "        )"
)


def main() -> int:
    root = pathlib.Path(sys.argv[1] if len(sys.argv) > 1 else ".")
    cmakelists = root / "src" / "CMakeLists.txt"
    if not cmakelists.is_file():
        print(f"ошибка: не найден {cmakelists}", file=sys.stderr)
        return 2

    text = cmakelists.read_text()
    original = text

    if "OpenGL::GLES" not in text:
        if "if(TARGET OpenGL::OpenGL)" not in text:
            print("ошибка: не найден ожидаемый фрагмент OpenGL-цепочки", file=sys.stderr)
            return 3
        text = text.replace("if(TARGET OpenGL::OpenGL)", GLES_BRANCH, 1)

    if FATAL in text:
        text = text.replace(FATAL, FATAL_REPLACEMENT, 1)

    if text != original:
        cmakelists.write_text(text)
        print(f"пропатчен: {cmakelists}")
    else:
        print("патч не требуется (уже применён)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
