#!/usr/bin/env python3
"""scan_mdl_geo.py — разведка геометрии player_bod-leoc_pc.mdl (по данным Ghidra-отчёта).

Вертекс-запись 0x3C (60 Б):
    +0x00 uv.x f32, +0x04 uv.y f32
    +0x08 pos f32 ×3            (head ~1.58 == скелет Bip01_Head 1.589)
    +0x18 w2 f32, +0x1C w3 f32, +0x20 w0 f32
    +0x24 blend indices u8 ×4   (< 44 — число костей)
    +0x28..0x2F unknown
    +0x30 RGB + 0xFF
    +0x34 f32 ×2 (uv2/norm?)
Индексы: u16-триплеты с 0xCF0 (квад → 2 треугольника).
"""
import struct, math, sys

MDL = 'pc/Manhunt_2_Win_Files_EN/Game Files/global/player_bod-leoc_pc.mdl'
b = open(MDL, 'rb').read()
N = len(b)
print('файл 0x%X (%d)' % (N, N))

# --- 1) пул индексов с 0xCF0 ---
IDX0 = 0xCF0
vals = []
off = IDX0
while off + 2 <= N:
    v = struct.unpack_from('<H', b, off)[0]
    if v >= 21000:        # граница: число вершин вряд ли > 21000
        break
    vals.append(v)
    off += 2
print('индексный пул 0x%X..0x%X: %d значений, max=%d, последние=%s' %
      (IDX0, off, len(vals), max(vals), vals[-6:]))
trip_ok = sum(1 for i in range(0, len(vals) - 2, 3))
print('   полных триплетов: %d' % trip_ok)
# распределение паттерна: первых 24 значения
print('   первые 24:', vals[:24])

# --- 2) карта 0x3C-записей: валидность по маске ---
def rec(o):
    uv = struct.unpack_from('<2f', b, o)
    pos = struct.unpack_from('<3f', b, o + 8)
    w2, w3, w0 = struct.unpack_from('<3f', b, o + 0x18)
    bidx = b[o + 0x24:o + 0x28]
    tail = struct.unpack_from('<2f', b, o + 0x34)
    return uv, pos, (w0, w2, w3), bidx, tail

def rec_ok(o):
    uv, pos, (w0, w2, w3), bidx, tail = rec(o)
    ok_uv = all(-0.2 <= v <= 1.2 for v in uv)
    ok_pos = all(-2.5 <= v <= 2.5 for v in pos)
    ok_w = -0.01 <= w0 <= 1.01
    ok_b = all(v < 44 for v in bidx)
    return ok_uv and ok_pos and ok_w and ok_b

zones = []
o = 0x8A10
while o + 0x3C <= 0x464E4:
    zones.append(1 if rec_ok(o) else 0)
    o += 0x3C
# ран-блоки
runs = []
start = None
for i, z in enumerate(zones):
    if z and start is None: start = i
    if not z and start is not None:
        runs.append((start, i)); start = None
if start is not None:
    runs.append((start, len(zones)))
runs = [(s, e, e - s) for s, e in runs if e - s >= 4]
print('валидные 0x3C-раны (≥4 записи) в [0x8A10, 0x464E4): %d' % len(runs))
tot = 0
for s, e, l in runs[:12]:
    a = 0x8A10 + s * 0x3C; c = 0x8A10 + e * 0x3C
    tot += l
    print('   0x%05X..0x%05X  n=%d' % (a, c, l))
print('сумма валидных записей:', tot)

# --- 3) статистика первой большой зоны ---
if runs:
    a = 0x8A10 + runs[0][0] * 0x3C
    cnt = runs[0][2]
    ymin = 9e9; ymax = -9e9; bmax = 0
    xs = []; ys = []; zs = []; us = []; vs = []
    for i in range(cnt):
        uv, pos, w, bid, tail = rec(a + i * 0x3C)
        xs.append(pos[0]); ys.append(pos[1]); zs.append(pos[2])
        us.append(uv[0]); vs.append(uv[1])
        bmax = max(bmax, *bid)
    print('\nран1 @0x%X n=%d:' % (a, cnt))
    print('   pos x[%.3f..%.3f] y[%.3f..%.3f] z[%.3f..%.3f]' % (min(xs), max(xs), min(ys), max(ys), min(zs), max(zs)))
    print('   uv  u[%.3f..%.3f] v[%.3f..%.3f]  blend max=%d' % (min(us), max(us), min(vs), max(vs), bmax))
