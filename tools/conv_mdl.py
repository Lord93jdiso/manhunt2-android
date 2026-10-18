#!/usr/bin/env python3
"""conv_mdl.py — конвертер меша Лео player_bod-leoc_pc.mdl → MHP2-контейнер.

Структура .mdl (подтверждена Ghidra-отчётом + эмпирикой):
    [idx-pool u16-квады (a,a+1,a+2),(a+2,a+3,a))][...][vert-run 0x3C × n]
Глобальная нумерация вершин сквозная (голова 0..138 — face-атлас,
тело 139.. — body-атлас).
Контейнер MHP2:
    'MHP2' u32 ver=1 u32 nsub u32 nvert u32 nidx u32 ntex
    per sub: u32 vStart u32 vEnd u32 iStart u32 nidx u32 texIdx
    verts: 36 Б (pos12, nrm12=(0,1,0), col RGBA4, uv8)  — общий с уровнем лейаут
    idx   : u32 stream
    texs  : per tex: u32 w u32 h + RGBA raw
"""
import struct, gzip, os, sys, re
from PIL import Image

MDL = 'pc/Manhunt_2_Win_Files_EN/Game Files/global/player_bod-leoc_pc.mdl'
OUT = '/tmp/opencode/leo/mh2leo_mesh.bin'
TEX1 = '/tmp/opencode/leo/leo_tex1.png'   # Leo_bodA  — тело
TEX2 = '/tmp/opencode/leo/leo_tex2.png'   # Leo_newhed — лицо
HEAD_VN = 139                              # вершины < HEAD_VN → face-текстура

b = open(MDL, 'rb').read()
N = len(b)
def f32(o): return struct.unpack_from('<f', b, o)[0]
def u16(o): return struct.unpack_from('<H', b, o)[0]

# --- 1) вертекс-раны ---
def vrow(o):
    uv = (f32(o), f32(o + 4))
    pos = (f32(o + 8), f32(o + 12), f32(o + 16))
    w0 = f32(o + 0x20)
    if not all(-0.3 <= v <= 1.3 for v in uv): return False
    if not all(-3.0 <= v <= 3.0 for v in pos): return False
    if max(abs(v) for v in pos) < 0.05: return False
    if not (-0.01 <= w0 <= 1.001): return False
    w2, w3 = f32(o + 0x18), f32(o + 0x1C)
    if not (abs(w2) <= 1.001 and abs(w3) <= 1.001): return False
    if max(b[o + 0x24:o + 0x28]) >= 44: return False
    return True

vruns = []
i = 0x20
covered = 0
while i + 0x3C <= N:
    if i < covered:
        i += 0x3C
        continue
    if vrow(i):
        j, n = i, 0
        while j + 0x3C <= N and vrow(j):
            j += 0x3C; n += 1
        if n >= 8:
            vruns.append((i, n)); covered = j; i = j
        else:
            i += 1
    else:
        i += 1
print('вертекс-раны:', [(hex(s), n) for s, n in vruns])

# порядок ранов по смещению; глобальные индексы сквозные
vlist = []          # (uv, pos, rgb)
for s, n in vruns:
    for k in range(n):
        o = s + k * 0x3C
        uv = struct.unpack_from('<2f', b, o)
        pos = struct.unpack_from('<3f', b, o + 8)
        rgb = b[o + 0x30:o + 0x33]
        vlist.append((uv, pos, rgb))
NV = len(vlist)
print('всего вершин:', NV)

# --- 2) индексные пулы: квад-шаблон (a,a+1,a+2),(a+2,a+3,a) ---
def quad_hit(o, a):
    return (u16(o) == a and u16(o + 2) == a + 1 and u16(o + 4) == a + 2 and
            u16(o + 6) == a + 2 and u16(o + 8) == a + 3 and u16(o + 10) == a)

pools = []
i = 0x20
while i < N - 24:
    a = u16(i)
    if a + 3 < NV and quad_hit(i, a):
        j, q = i, 0
        while j + 12 < N and quad_hit(j, a + q * 4):
            j += 12; q += 1
        if q >= 2:
            pools.append((i, q * 6, a, a + q * 4 - 2))
            i = j
    i += 2
print('пулов:', len(pools))

# недостающие значения кандидата- gloves: разрывы баз
# --- 3) сборка индексов: на каждый пул тянем u16-поток до начала следующего пула ---
# (хвостовые «нерегулярные» листы между квадами попадают в поток)
# --- 3) сборка индексных потоков (сшитые зоны, фильтр: только валидные индексы) ---
HEAD_IDX = (0x0CF0, 0x0E8E)            # пул головы: базы 0..138
BODY_ZONES = [(0x63C4, 0x8A10), (0x8A10, 0x97C4)]   # квад-пулы + хвостовой tri-stream

idx_face = [u16(o) for o in range(HEAD_IDX[0], HEAD_IDX[1], 2)]
idx_body = []
for lo, hi in BODY_ZONES:
    for o in range(lo, hi, 2):
        v = u16(o)
        if 139 <= v < NV:              # global индексы тела
            idx_body.append(v)
print('idx face=%d body=%d' % (len(idx_face), len(idx_body)))
# чистка: face-значения тоже валидируем (< 139)
idx_face = [v for v in idx_face if 0 <= v < 139]
print('после валидации: face=%d body=%d' % (len(idx_face), len(idx_body)))

# --- 5) контейнер MHP2 ---
VERT_STRIDE = 36
verts_buf = bytearray(NV * VERT_STRIDE)
off = 0
for uv, pos, rgb in vlist:
    struct.pack_into('<3f', verts_buf, off, *pos)
    struct.pack_into('<3f', verts_buf, off + 12, 0, 1, 0)
    r, g, bl = rgb[0], rgb[1], rgb[2]
    verts_buf[off + 24] = min(255, int(r) * 8)   # затенение 0..31 → 0..255
    verts_buf[off + 25] = min(255, int(g) * 8)
    verts_buf[off + 26] = min(255, int(bl) * 8)
    verts_buf[off + 27] = 255
    struct.pack_into('<2f', verts_buf, off + 28, *uv)
    off += VERT_STRIDE

idx_stream = bytearray()
# sub face: свои индексы со смещением 0; sub body: свои
# порядок subs: 0) face(Leo_newhed,tex1) 1) body(Leo_bodA,tex0)
subs_meta = []
base_i = 0
for name, arr in (('Leo_newhed', idx_face), ('Leo_bodA', idx_body)):
    tex = 1 if name == 'Leo_newhed' else 0
    vlo = min(arr) if arr else 0
    vhi = max(arr) if arr else 0
    subs_meta.append((vlo, vhi + 1, base_i, len(arr), tex, name))
    idx_stream += struct.pack('<%dI' % len(arr), *arr)
    base_i += len(arr)

texdata = bytearray()
texs = []
for png in (TEX1, TEX2):
    im = Image.open(png).convert('RGBA')
    W, H = im.size
    raw = im.tobytes()
    texs.append((W, H))
    texdata += struct.pack('<II', W, H) + raw

buf = bytearray(b'MHP2')
buf += struct.pack('<5I', 1, len(subs_meta), NV, base_i, len(texs))
for vlo, vhi, is_, ni, tex, nm in subs_meta:
    nb = nm.encode('ascii')
    buf += struct.pack('<5IBB', vlo, vhi, is_, ni, tex, len(nb), 0) + nb
buf += verts_buf
buf += idx_stream
buf += texdata
open(OUT, 'wb').write(bytes(buf))
open(OUT + '.gz', 'wb').write(gzip.compress(bytes(buf)))
print('MHP2: %s (%.1f КБ) gz %.1f КБ; subs=%d verts=%d idx=%d tex=%s' %
      (OUT, len(buf) / 1024, os.path.getsize(OUT + '.gz') / 1024,
       len(subs_meta), NV, base_i, texs))
for vlo, vhi, is_, ni, tex, nm in subs_meta:
    print('   sub %-12s v[%d..%d) idx[%d..%d) n=%d tex=%d' %
          (nm, vlo, vhi, is_, is_ + ni, ni, tex))
