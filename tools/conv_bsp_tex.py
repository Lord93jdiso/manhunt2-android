import struct, gzip, math, io, os, re, sys

# Универсальный запуск:  conv_bsp_tex.py [bsp_in] [tex_in] [out_base]
#   bsp_in / tex_in — распакованные Z2HM (*.raw) файлы сцены;
#   out_base — база имён вывода: <out_base>.bin = меш,
#     "<out_base>" с заменой '_mesh' на '_texmap'/'_texall' — материалы/текстуры.
# Без аргументов — прежний дефолт (сцена 1, пути и имена файлов байт-в-байт те же).
BSP_IN = sys.argv[1] if len(sys.argv) > 1 else '/tmp/opencode/scene1_pc.bsp.raw'
TEX_IN = sys.argv[2] if len(sys.argv) > 2 else '/tmp/opencode/scene1_pc.tex.raw'
OUT = sys.argv[3] if len(sys.argv) > 3 else '/tmp/opencode/mh2mesh'
d = open(BSP_IN,'rb').read()
t = open(TEX_IN,'rb').read()

def U32(a, s=d): return struct.unpack('<I', s[a:a+4])[0]
def F32(a, s=d): return struct.unpack('<f', s[a:a+4])[0]

# ---------------- BSP mesh scan ----------------
res=[]
for o in range(0x88, len(d)-0x94, 4):
    if o+0x94 > len(d): break
    if U32(o) != 0x45D454: continue
    smc=U32(o+0x0C); ic=U32(o+0x10); vc=U32(o+0x30)
    if not (0 < smc <= 200 and 3 <= ic <= 400000 and 3 <= vc <= 150000): continue
    if U32(o+0x70) != 0x252 or U32(o+0x48) == 0: continue
    base = o+0x94
    idxb = base + smc*0x2C
    if idxb + ic*2 + vc*40 > len(d): continue
    bad=0
    for k in range(min(50,ic)):
        if struct.unpack('<H', d[idxb+2*k:idxb+2*k+2])[0] >= vc: bad += 1
    if bad > 2: continue
    res.append((o,smc,ic,vc,base))
res.sort()

out_subs=[]; out_verts=[]; out_idx=[]; gbmin=[1e9]*3; gbmax=[-1e9]*3
for (o,smc,ic,vc,base) in res:
    idxb = base + smc*0x2C; vb = idxb + ic*2
    vbase = len(out_verts); ibase = len(out_idx)
    # 1) позиции всех вершин меша
    pos=[]
    for k in range(vc):
        a = vb + k*40
        x,y,z = F32(a), F32(a+4), F32(a+8)
        if not(-90<=x<=140 and -90<=y<=140 and -90<=z<=140):
            x,y,z = 0.0,0.0,0.0
        pos.append((x,y,z))
        for c,val in ((0,x),(1,y),(2,z)):
            if val < gbmin[c]: gbmin[c]=val
            if val > gbmax[c]: gbmax[c]=val
    # 2) вертексные нормали = среднее нормалей треугольников (по всем подмешам меша)
    acc = [ [0.0,0.0,0.0] for _ in range(vc) ]
    for rr in range(smc):
        a = base + rr*0x2C
        cnt = U32(a+24) & 0xFFFF; start = U32(a+28) & 0xFFFF
        for k in range(0, cnt - 2, 3):
            i0 = struct.unpack_from('<H', d, idxb+(start+k)*2)[0]
            i1 = struct.unpack_from('<H', d, idxb+(start+k+1)*2)[0]
            i2 = struct.unpack_from('<H', d, idxb+(start+k+2)*2)[0]
            if i0 >= vc or i1 >= vc or i2 >= vc: continue
            ax,ay,az = pos[i0]; bx,by,bz = pos[i1]; cx,cy,cz = pos[i2]
            e1x,e1y,e1z = bx-ax, by-ay, bz-az
            e2x,e2y,e2z = cx-ax, cy-ay, cz-az
            nx,ny,nz = e1y*e2z-e1z*e2y, e1z*e2x-e1x*e2z, e1x*e2y-e1y*e2x
            ln = math.sqrt(nx*nx+ny*ny+nz*nz)
            if ln <= 1e-12: continue
            nx,ny,nz = nx/ln, ny/ln, nz/ln
            for ii in (i0,i1,i2):
                acc[ii][0]+=nx; acc[ii][1]+=ny; acc[ii][2]+=nz
    verts=[]
    for k in range(vc):
        a = vb + k*40
        b,g,r,al = d[a+20],d[a+21],d[a+22],d[a+23]
        u,v = F32(a+24), F32(a+28)
        if not (math.isfinite(u) and math.isfinite(v)): u,v = 0.0,0.0
        n = acc[k]
        ln = math.sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])
        if ln > 1e-9: n = (n[0]/ln, n[1]/ln, n[2]/ln)
        else: n = (0.0, 1.0, 0.0)
        x,y,z = pos[k]
        verts.append(struct.pack('<6f4Bff', x,y,z, n[0],n[1],n[2], r,g,b,al, u, v))
    assert len(verts[0]) == 36
    vbase = len(out_verts)
    for vt in verts: out_verts.append(vt)
    # 3) подмеши (индексы глобальные)
    for rr in range(smc):
        a = base + rr*0x2C
        u32v = U32(a+24); cnt = u32v & 0xFFFF; mat = u32v >> 16
        start = U32(a+28) & 0xFFFF
        bx = [F32(a+4*k) for k in range(6)]
        for k in range(cnt):
            out_idx.append(vbase + struct.unpack('<H', d[idxb+(start+k)*2:idxb+(start+k)*2+2])[0])
        out_subs.append((vbase, vc, ibase+start, cnt, mat, bx))

# ---------------- BSP material table ----------------
# Положение таблицы материалов — из DLRW-заголовка (у сцены 1 это те же
# 0x361F4C/132, что были захардкожены):
MTAB = U32(0x50); MCNT = U32(0x54)
if not (0 < MCNT and MTAB + MCNT*12 <= len(d)) or not (0 < MTAB < len(d)):
    raise SystemExit('BAD B header material table (%s): mtab=%#x cnt=%d' % (BSP_IN, MTAB, MCNT))
mats=[]
for i in range(MCNT):
    a = MTAB + i*12
    nameOff = U32(a); col = U32(a+4); flags = U32(a+8)
    e = d[nameOff:]
    name = e[:e.index(b'\x00')].decode('latin1')
    rgb = (d[a+5], d[a+6], d[a+7])  # [?, R, G, B] by bytes
    mats.append((name, rgb, flags))

# ---------------- TCDT records ----------------
def T32(a): return struct.unpack('<I', t[a:a+4])[0]
texs=[]; ai = 0x40; visited=set()
while ai and ai not in visited and ai < len(t):
    visited.add(ai)
    m = re.match(rb'[ -~]{1,64}', t[ai+8:ai+72])
    name = m.group(0).decode('latin1') if m else ""
    w = T32(ai+0x48); h = T32(ai+0x4C); fmt = T32(ai+0x50)
    dat = T32(ai+0x60); size = T32(ai+0x68)
    if 8<=w<=2048 and 8<=h<=2048 and 0<dat<len(t) and name:
        texs.append(dict(name=name,w=w,h=h,fmt=fmt,dat=dat,size=size))
    ai = T32(ai)
print("texs:", len(texs))

def _pack565(r8,g8,b8):
    return ((r8>>3)<<11) | ((g8>>2)<<5) | (b8>>3)

def decode_block(c0, c1, bits):
    r0=(c0>>11)&0x1F; g0=(c0>>5)&0x3F; b0=c0&0x1F
    r1=(c1>>11)&0x1F; g1=(c1>>5)&0x3F; b1=c1&0x1F
    def exp(v, m): return min(m, (v*m+ (m//2))//(m-1) if m>1 else 0) or v
    R0=(r0*527+31)>>6; G0=(g0*259+33)>>6; B0=(b0*527+31)>>6
    R1=(r1*527+31)>>6; G1=(g1*259+33)>>6; B1=(b1*527+31)>>6
    rows=[]
    if c0 > c1:
        rows=[(_pack565(R0,G0,B0), _pack565(R1,G1,B1),
               _pack565((2*R0+R1)//3,(2*G0+G1)//3,(2*B0+B1)//3),
               _pack565((R0+2*R1)//3,(G0+2*G1)//3,(B0+2*B1)//3))]
    else:
        K = 3
        rows=[(_pack565(R0,G0,B0), _pack565(R1,G1,B1), 0, 0)]
    return rows[0]

def dxt_decode(w, h, blob, fmt, flip=True):
    out = bytearray(w*h*2)
    cw=(w+3)//4; ch=(h+3)//4
    bo = 8 if fmt != 4 else 0
    bs = 16 if fmt != 4 else 8
    databytes = cw*ch*bs
    if len(blob) < databytes:
        blob = blob + b'\x00'*(databytes-len(blob))
    for by in range(ch):
        for bx in range(cw):
            idx = by*cw + bx
            base = idx*bs
            c0, c1 = struct.unpack_from('<HH', blob, base+bo)
            bits = struct.unpack_from('<I', blob, base+bo+4)[0]
            pal = decode_block(c0, c1, bits)
            for py in range(4):
                pyw = by*4+py
                if pyw >= h: continue
                roww = (h-1-pyw) if flip else pyw
                for px in range(4):
                    pxw = bx*4+px
                    if pxw >= w: continue
                    code = (bits >> (2*(py*4+px))) & 3
                    c = pal[code]
                    struct.pack_into('<H', out, ((roww*w)+pxw)*2, c)
    return bytes(out)

texdata = bytearray(); hdrs=[]; name2tx={}
for T in texs:
    blob = t[T['dat']:T['dat']+T['size']]
    w, h, fmt = T['w'], T['h'], T['fmt']
    try:
        rgb = dxt_decode(w, h, blob, fmt)
    except Exception as ex:
        print("decode fail", T['name'], ex); rgb = b'\x18\x3f'*(w*h)
    texdata += rgb
    name2tx[T['name']] = len(hdrs)
    hdrs.append((T['name'], w, h, len(rgb)))

matmap=[]; found=0
for (nm, rgb, fl) in mats:
    idx = name2tx.get(nm, -1)
    if idx>=0: found+=1
    matmap.append((idx, rgb))
print("материал→текстура: %d/%d" % (found, MCNT))

# ---------------- emit ----------------
b = io.BytesIO()
b.write(b'MMH2')
b.write(struct.pack('<I', len(out_subs))); b.write(struct.pack('<I', len(out_verts))); b.write(struct.pack('<I', len(out_idx)))
b.write(struct.pack('<3f', *gbmin)); b.write(struct.pack('<3f', *gbmax))
for (vbase,vc,ibase,cnt,mat,bx) in out_subs:
    b.write(struct.pack('<IIIIi', vbase, vc, ibase, cnt, mat)); b.write(struct.pack('<6f', *bx))
b.write(b"".join(out_verts))
for x in out_idx: b.write(struct.pack('<I', x))
TEXM_P = OUT.replace('mesh','texmap')
TEXA_P = OUT.replace('mesh','texall')
open(OUT+'.bin','wb').write(b.getvalue())

b = io.BytesIO(); b.write(b'TEXM'); b.write(struct.pack('<I', MCNT))
for (idx, (r,g,bl)) in matmap:
    b.write(struct.pack('<hBBB', idx, r, g, bl))
open(TEXM_P+'.bin','wb').write(b.getvalue())

b = io.BytesIO(); b.write(b'TEXA'); b.write(struct.pack('<I', len(hdrs)))
for (nm,w,h,sz) in hdrs:
    b.write(struct.pack('<HHI', w, h, sz))
b.write(bytes(texdata))
open(TEXA_P+'.bin','wb').write(b.getvalue())

OUTS = [OUT+'.bin', TEXM_P+'.bin', TEXA_P+'.bin']
for bp in OUTS:
    with gzip.open(bp+'.gz','wb') as f:
        f.write(open(bp,'rb').read())
print("DONE raw sizes: mesh=%d map=%d tex=%d" % tuple(os.path.getsize(p) for p in OUTS))
