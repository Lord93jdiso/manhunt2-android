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

# --- TCDT-записи (та же схема, что в conv_bsp_tex.py) ---
TEXFILE = 'pc/Manhunt_2_Win_Files_EN/Game Files/global/player_bod-leoc_pc.tex'
t = open(TEXFILE, 'rb').read()
def T32(a): return struct.unpack('<I', t[a:a+4])[0]
def _pack565(r8, g8, b8):
    return ((r8 >> 3) << 11) | ((g8 >> 2) << 5) | (b8 >> 3)

def decode_block(c0, c1, bits):
    r0 = (c0 >> 11) & 0x1F; g0 = (c0 >> 5) & 0x3F; b0 = c0 & 0x1F
    r1 = (c1 >> 11) & 0x1F; g1 = (c1 >> 5) & 0x3F; b1 = c1 & 0x1F
    R0 = (r0 * 527 + 31) >> 6; G0 = (g0 * 259 + 33) >> 6; B0 = (b0 * 527 + 31) >> 6
    R1 = (r1 * 527 + 31) >> 6; G1 = (g1 * 259 + 33) >> 6; B1 = (b1 * 527 + 31) >> 6
    if c0 > c1:
        return (_pack565(R0, G0, B0), _pack565(R1, G1, B1),
                _pack565((2*R0 + R1)//3, (2*G0 + G1)//3, (2*B0 + B1)//3),
                _pack565((R0 + 2*R1)//3, (G0 + 2*G1)//3, (B0 + 2*B1)//3))
    return (_pack565(R0, G0, B0), _pack565(R1, G1, B1), 0, 0)

def dxt_decode(w, h, blob, fmt, flip=True):
    out = bytearray(w * h * 2)
    cw = (w + 3)//4; ch = (h + 3)//4
    bo = 8 if fmt != 4 else 0
    bs = 16 if fmt != 4 else 8
    need = cw * ch * bs
    if len(blob) < need:
        blob = blob + b'\x00' * (need - len(blob))
    for by in range(ch):
        for bx in range(cw):
            base = (by * cw + bx) * bs
            c0, c1 = struct.unpack_from('<HH', blob, base + bo)
            bits = struct.unpack_from('<I', blob, base + bo + 4)[0]
            pal = decode_block(c0, c1, bits)
            for py in range(4):
                pyw = by * 4 + py
                if pyw >= h: continue
                roww = (h - 1 - pyw) if flip else pyw
                for px in range(4):
                    pxw = bx * 4 + px
                    if pxw >= w: continue
                    code = (bits >> (2 * (py * 4 + px))) & 3
                    c = pal[code]
                    struct.pack_into('<H', out, ((roww * w) + pxw) * 2, c)
    return bytes(out)

record_names = {}
ai = 0x40
tc = 0
while ai and ai < len(t) and tc < 8:
    tc += 1
    w = T32(ai + 0x48); h = T32(ai + 0x4C); fmt = T32(ai + 0x50)
    dat = T32(ai + 0x60); size = T32(ai + 0x68)
    m = re.match(rb'[ -~]{1,64}', t[ai + 8:ai + 72])
    name = m.group(0).decode('latin1') if m else 'texNAME?'
    print('TCDT %-14s %dx%d fmt=%d dat=0x%X size=0x%X' % (name, w, h, fmt, dat, size))
    if 8 <= w <= 2048 and 8 <= h <= 2048 and 0 < dat < len(t):
        rgb565 = dxt_decode(w, h, t[dat:dat + size], fmt, flip=False)
        img = bytearray(w * h * 4)
        for k in range(w * h):
            c = struct.unpack_from('<H', rgb565, k * 2)[0]
            img[k*4] = ((c >> 11) & 31) << 3; img[k*4 + 1] = ((c >> 5) & 63) << 2
            img[k*4 + 2] = (c & 31) << 3; img[k*4 + 3] = 255
        if 'bod' in name.lower():
            record_names[0] = (w, h, bytes(img))
        else:
            record_names[1] = (w, h, bytes(img))
    ai = T32(ai)
for i in (0, 1):
    w, h, raw = record_names[i]
    texs.append((w, h))
    texdata += struct.pack('<II', w, h) + raw

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
