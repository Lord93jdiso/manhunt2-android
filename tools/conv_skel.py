#!/usr/bin/env python3
"""conv_skel.py — извлечение скелета из player_bod-leoc_pc.mdl (PMLC, RAW).

Формат PMLC (подтверждён реверсом 2026-10-18):
    32Б дескриптор {tag=PMLC, ver=1, total, unk, reloc_off, reloc_count, 0, 0}
    релоки: reloc_count × u32 (смещения от начала секции), база = 0
    тело: ноды stride 0xC0:
       +0x08 ptr → родитель (нода) или корень 0xB40
       +0x0C ptr → общий корень (запись 'Player_Bod-LeoC')
       +0x10 ptr → первая связь/потомок (для иерархии не нужен)
       +0x18 имя inline (до 22 символов)
       +0x40 rw-матрица 4×4 (row-major, pos в 4-й строке) — локальная bind
       +0x80 rw-матрица 4×4 (вторая, назначение уточняется Ghidra-агентом)

Выход: SKL2-файл (мир-координаты выпечены):
    'SKL2' + u32 nodes
    на ноду: u8 nameLen, name, i16 parentIdx, f32 worldPos[3], f32 localMat[16]
Конвенция матриц (подтверждена leo_axes_test.py, инварианты длины сегментов и
симметрия выполнены точно на всех 40 сегментах):
    W_flat = parent_world_flat × local_flat^T ; pos = 4-й СТОЛБЕЦ результата
    (эквивалентно L×P в flat-пространстве с pos в 4-й строке).
    Bind-поза: таз 1.018, голова 1.589, руки ±0.645, стопы ±0.194/0.109.
"""
import struct, gzip, sys, os

MDL_IN = sys.argv[1] if len(sys.argv) > 1 else \
    'pc/Manhunt_2_Win_Files_EN/Game Files/global/player_bod-leoc_pc.mdl'
OUT = sys.argv[2] if len(sys.argv) > 2 else '/tmp/opencode/leo/mh2leo_skel.bin'

b = bytearray(open(MDL_IN, 'rb').read())
tag = b[0:4]
assert tag == b'PMLC', 'не PMLC: %r' % tag
total = struct.unpack_from('<I', b, 8)[0]
roff = struct.unpack_from('<I', b, 0x10)[0]
rcnt = struct.unpack_from('<I', b, 0x14)[0]
assert total == len(b), 'total=0x%X, файл 0x%X' % (total, len(b))
for o in struct.unpack_from('<%dI' % rcnt, b, roff):
    v = struct.unpack_from('<I', b, o)[0]
    struct.pack_into('<I', b, o, v & 0xFFFFFFFF)

# --- сбор нод (скелет): scan stride 0xC0 от 0x2F30 до 0x6210, имя валидно ---
valid = []
o = 0x2F30
while o + 0xC0 <= 0x4977C:
    s = b[o+0x18:o+0x38].split(b'\x00')[0]
    ok = 3 <= len(s) <= 22 and all(45 <= c <= 57 or 65 <= c <= 90 or 95 <= c <= 122 for c in s)
    if ok:
        # имя должно быть сплошным ASCII (без мусора) и старт с буквы
        try:
            n = s.decode('ascii')
            if n[:1].isalpha() or n.startswith('_'):
                pl = [struct.unpack_from('<I', b, o + k)[0] for k in (4, 8, 0xC, 0x10)]
                if all((0x20 <= x < 0x49700) or x == 0 for x in pl):
                    valid.append(o)
        except Exception:
            pass
    o += 0x10
addrs = set(valid)
print('нод-кандидатов: %d' % len(valid))

def mat_at(a, off=0x40):
    return list(struct.unpack_from('<16f', b, a + off))

nodes = []
for a in valid:
    n = b[a+0x18:a+0x38].split(b'\x00')[0].decode('ascii')
    par = struct.unpack_from('<I', b, a + 8)[0]
    pi = valid.index(par) if par in addrs else -1
    nodes.append((n, pi, mat_at(a)))
print('в списке: %d нод' % len(nodes))

# --- точный расчёт: W = P_w × T16(L); итоговая позиция = [W[3], W[7], W[11]] ---
def T16(m):
    return [m[c*4+r] for r in range(4) for c in range(4)]

def mul(A, B):
    return [sum(A[r*4+k] * B[k*4+c] for k in range(4)) for r in range(4) for c in range(4)]

I16 = [1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1]
_wmemo = {}
def world_mat(i, depth=0):
    if i < 0 or depth > 40:
        return I16
    if i in _wmemo:
        return _wmemo[i]
    n, pi, _ = nodes[i]
    L = T16(mat_at(valid[i]))
    P = world_mat(pi, depth + 1)
    W = mul(P, L)
    _wmemo[i] = W
    return W

buf = bytearray(b'SKL2')
buf += struct.pack('<I', len(nodes))
for i, (n, pi, m) in enumerate(nodes):
    W = world_mat(i)
    wp = [W[3], W[7], W[11]]            # 4-й столбец = позиция
    nb = n.encode('ascii')[:22]
    buf += struct.pack('<B', len(nb)) + nb + struct.pack('<h', pi)
    buf += struct.pack('<3f', *wp)
    buf += struct.pack('<16f', *m)
os.makedirs(os.path.dirname(OUT) or '.', exist_ok=True)
open(OUT, 'wb').write(bytes(buf))
gz = OUT + '.gz'
open(gz, 'wb').write(gzip.compress(bytes(buf)))
print('записано %s (%d Б) и %s (%d Б)' % (OUT, len(buf), gz, os.path.getsize(gz)))
# контрольный дамп ключевых нод
_kb = {}
_j = 0
_p = buf[8:]
for i in range(len(nodes)):
    nl = _p[_j]; _j += 1
    nm = _p[_j:_j+nl].decode(); _j += nl
    pi = struct.unpack_from('<h', _p, _j)[0]; _j += 2
    wp = struct.unpack_from('<3f', _p, _j); _j += 12 + 64
    _kb[nm] = wp
for k in ('Bip01', 'Bip01_Head', 'Bip01_L_Hand', 'Bip01_R_Hand', 'Bip01_L_Foot', 'Bip01_R_Foot'):
    print('  %-16s (%+7.3f %+7.3f %+7.3f)' % (k, *_kb[k]))
