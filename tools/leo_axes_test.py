#!/usr/bin/env python3
"""leo_axes_test.py — перебор вариантов мир-умножения матриц PMLC-скелета.

Цель: найти конвенцию (порядок умножения, транспонирование), при которой
bind-поза Лео анатомична: голова сверху, стопы снизу, корень (пелвис) ~1.0.
"""
import struct, os

MDL_IN = 'pc/Manhunt_2_Win_Files_EN/Game Files/global/player_bod-leoc_pc.mdl'
b = bytearray(open(MDL_IN, 'rb').read())
assert b[0:4] == b'PMLC'

valid = []
o = 0x2F30
while o + 0xC0 <= 0x4977C:
    s = b[o+0x18:o+0x38].split(b'\x00')[0]
    ok = 3 <= len(s) <= 22 and all(45 <= c <= 57 or 65 <= c <= 90 or 95 <= c <= 122 for c in s)
    if ok:
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
nodes = []
for a in valid:
    n = b[a+0x18:a+0x38].split(b'\x00')[0].decode('ascii')
    par = struct.unpack_from('<I', b, a + 8)[0]
    pi = valid.index(par) if par in addrs else -1
    L = list(struct.unpack_from('<16f', b, a + 0x40))   # локаль в файле
    L2 = list(struct.unpack_from('<16f', b, a + 0x80))  # вторая матрица
    nodes.append((n, pi, L, L2))

def mul(A, B):
    return [sum(A[r*4+k] * B[k*4+c] for k in range(4)) for r in range(4) for c in range(4)]

def T16(m):
    return [m[c*4+r] for r in range(4) for c in range(4)]

I16 = [1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1]

memo = {}
def wrec(j, cf, tf, sec, depth=0):
    if j < 0:
        return I16
    key = (j, cf, tf, sec)
    if key in memo:
        return memo[key]
    nn, pj, Lj, L2j = nodes[j]
    Lj = L2j if sec else Lj
    if tf:
        Lj = T16(Lj)
    P = wrec(pj, cf, tf, sec, depth + 1)
    W = mul(P, Lj) if cf == 'c×p' else mul(Lj, P)
    memo[key] = W
    return W

def pos_row(W):   return W[12:15]
def pos_col(W):   return [W[3], W[7], W[11]]

def score(posmap):
    def g(name): return posmap.get(name)
    head = g('Bip01_Head'); footL = g('Bip01_L_Foot'); footR = g('Bip01_R_Foot')
    root = g('Bip01'); pelvis = g('Bip01_Pelvis') or root
    if None in (head, footL, root):
        return -99, {}
    ys = [p[1] for p in posmap.values()]
    hmin, hmax = min(ys), max(ys)
    crit = {
        'root_y~1': abs(root[1] - 1.018) < 0.30,
        'head_top': head[1] > pelvis[1] > footL[1],
        'head_hi': 1.25 < head[1] < 2.3,
        'feet_low': -0.35 < footL[1] < 0.55 and -0.35 < footR[1] < 0.55,
        'span_ok': 1.2 < (hmax - hmin) < 2.6,
        'in_range': hmin > -2.0 and hmax < 4.0,
    }
    return sum(crit.values()), crit

best = []
for sec in (False, True):
    for cf in ('c×p', 'p×c'):
        for tf in (False, True):
            for dr in (0, 1):
                memo.clear()
                posmap = {}
                for i, (n, pi, L, L2) in enumerate(nodes):
                    W = wrec(i, cf, tf, sec)
                    posmap[n] = pos_row(W) if dr == 0 else pos_col(W)
                s, crit = score(posmap)
                tag = '%s sec=%d tf=%d row=%d' % (cf, sec, tf, dr)
                best.append((s, tag, crit, posmap))
                print('%2d %-18s %s' % (s, tag, crit))
best.sort(key=lambda x: -x[0])
print()
s, tag, crit, posmap = best[0]
print('=== ЛУЧШИЙ: %s  score=%d' % (tag, s))
for n in ('Bip01', 'Bip01_Pelvis', 'Bip01_Spine', 'Bip01_Head', 'Bip01_L_Hand',
          'Bip01_R_Hand', 'Bip01_L_Foot', 'Bip01_R_Foot', 'Bip01_L_Calf', 'Bip01_L_Thigh'):
    p = posmap.get(n)
    if p:
        print('  %-18s (%+7.3f %+7.3f %+7.3f)' % (n, p[0], p[1], p[2]))
