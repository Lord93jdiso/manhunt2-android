#!/usr/bin/env python3
"""Z2HM-контейнеры Manhunt 2 PC: распаковка zlib-полезной нагрузки.

Формат (определён разведкой 2026-10-15):
    offset 0: b"Z2HM"
    offset 4: u32 (LE) — декларированный размер распакованных данных
    offset 8: zlib-поток (обычно 78 DA)

Внутри (по магии первых 4 байт распакованного):
    PMLC — модели (clump-контейнер)
    TCDT — текстуры (dictionary)
    DLRW — мир/RenderWare World ("WRLD")
    ANCT — анимации
    MHLS — скрипты уровня
    (прочее — текстовые ресурсы, напр. ".glg")

Usage:
    z2hm_unpack.py <файл|каталог> [-o OUT]
"""
from __future__ import annotations

import argparse
import struct
import sys
import zlib
from pathlib import Path

MAGIC = b"Z2HM"
INNER_HINTS = {
    b"PMLC": "модели (clump-контейнер)",
    b"TCDT": "текстуры (dictionary)",
    b"DLRW": "мир (RW WRLD)",
    b"ANCT": "анимации",
    b"MHLS": "скрипты уровня",
    b"MHSC": "скриптовый контейнер",
}


def unpack_file(src: Path, dst: Path) -> str:
    data = src.read_bytes()
    if data[:4] != MAGIC:
        return "skip (не Z2HM)"
    declared = struct.unpack_from("<I", data, 4)[0]
    try:
        raw = zlib.decompress(data[8:])
    except zlib.error as e:
        return f"ОШИБКА zlib: {e}"
    note = f"{len(raw)} байт"
    if declared != len(raw):
        note += f" (шапка говорит {declared})"
    kind = INNER_HINTS.get(raw[:4], repr(raw[:4]))
    dst.parent.mkdir(parents=True, exist_ok=True)
    dst.write_bytes(raw)
    return f"ok: {note}, внутри: {kind}"


def main(argv=None):
    ap = argparse.ArgumentParser(description="Распаковка Z2HM-контейнеров Manhunt 2")
    ap.add_argument("target", help="файл или каталог")
    ap.add_argument("-o", "--out", default=None, help="каталог для результатов")
    args = ap.parse_args(argv)

    t = Path(args.target)
    done = failed = skipped = 0

    if t.is_dir():
        out_root = Path(args.out) if args.out else t / "_unpacked"
        for p in sorted(t.rglob("*")):
            if not p.is_file() or "_unpacked" in p.parts:
                continue
            rel = p.relative_to(t)
            res = unpack_file(p, out_root / rel)
            if res.startswith("skip"):
                skipped += 1
                continue
            print(f"{str(rel):60s} {res}")
            if res.startswith("ok"):
                done += 1
            else:
                failed += 1
        print(f"\nготово: {done}, ошибок: {failed}, пропущено: {skipped}")
        print(f"каталог результата: {out_root}")
    else:
        o = Path(args.out) if args.out else None
        if o is None:
            dst = t.parent / (t.name + ".unpacked")
        elif o.is_dir() or not o.suffix:
            dst = o / t.name
        else:
            dst = o
        print(f"{t.name}: {unpack_file(t, dst)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
