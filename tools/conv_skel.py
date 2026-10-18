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

Выход: SKL1-файл:
    'SKL1' + u32 nodes число
    на ноду: u8 nameLen, name, i16 parentIdx (-1 = root), 16 × f32 (матр.)
Плюс мир-позиции для контрольного дампa.
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

if os.environ.get('SKEL_DUMPWORLD') == '1':
    I = [[1.0 if i == j else 0.0 for j in range(4)] for i in range(4)]
    def world(i, depth=0):
        if i < 0 or depth > 40:
            return I
        m = struct.unpack_from('<16f', b, valid[i] + 0x40)
        L = [list(m[k*4:k*4+4]) for k in range(4)]
        Wp = world(nodes[i][1], depth + 1)
        return [[sum(Wp[r][k] * L[k][c] for k in range(4)) for c in range(4)] for r in range(4)]
    for i, (n, pi, _) in enumerate(nodes):
        W = world(i)
        print('%2d %-22s parent=%-3d pos=(%+8.3f %+8.3f %+8.3f)' %
              (i, n, pi, W[3][0], W[3][1], W[3][2]))

buf = bytearray(b'SKL1')
buf += struct.pack('<I', len(nodes))
for n, pi, m in nodes:
    nb = n.encode('ascii')[:22]
    buf += struct.pack('<B', len(nb)) + nb + struct.pack('<h', pi)
    buf += struct.pack('<16f', *m)
os.makedirs(os.path.dirname(OUT), exist_ok=True)
open(OUT, 'wb').write(bytes(buf))
gz = OUT + '.gz'
open(gz, 'wb').write(gzip.compress(bytes(buf)))
print('записано %s (%d Б) и %s (%d Б)' % (OUT, len(buf), gz, os.path.getsize(gz)))
