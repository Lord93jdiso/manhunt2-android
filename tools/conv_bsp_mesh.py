import struct, gzip, math, sys
import os
d = open('/tmp/opencode/scene1_pc.bsp.raw','rb').read()
def U32(a): return struct.unpack('<I', d[a:a+4])[0]
def F32(a): return struct.unpack('<f', d[a:a+4])[0]

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
print("meshes:", len(res))

out_subs=[]; out_verts=[]; out_idx=[]; gbmin=[1e9]*3; gbmax=[-1e9]*3
for (o,smc,ic,vc,base) in res:
    idxb = base + smc*0x2C
    vb   = idxb + ic*2
    vbase = len(out_verts)
    ibase = len(out_idx)
    # vertices 40B: pos@0, junk@12,16, color@20 [B,G,R,A], uv@24, pad@32
    for k in range(vc):
        a = vb + k*40
        x,y,z = F32(a), F32(a+4), F32(a+8)
        b,g,r,al = d[a+20],d[a+21],d[a+22],d[a+23]
        u,v = F32(a+24), F32(a+28)
        assert -90<=x<=140 and -90<=y<=140 and -90<=z<=140, (hex(o),k,x,y,z)
        assert math.isfinite(u) and math.isfinite(v), (hex(o),k,u,v)
        out_verts.append(struct.pack('<fff4Bff', x,y,z, r,g,b,al, u,v))
        for c,val in ((0,x),(1,y),(2,z)):
            if val < gbmin[c]: gbmin[c]=val
            if val > gbmax[c]: gbmax[c]=val
    # submeshes
    last_end = 0
    for rr in range(smc):
        a = base + rr*0x2C
        u = U32(a+24); cnt = u & 0xFFFF; mat = u >> 16
        v = U32(a+28); start = v & 0xFFFF
        bx = [F32(a+4*k) for k in range(6)]
        gi = []
        for k2 in range(cnt):
            pos = idxb + (start+k2)*2
            idx = struct.unpack('<H', d[pos:pos+2])[0]
            assert idx < vc, (hex(o), rr, idx, vc)
            gi.append(src := vbase + idx)
        out_idx.extend(gi)
        out_subs.append((vbase, vc, ibase + start, cnt, mat, bx))
        last_end = start+cnt
    s=sum( (s&0xFFFF if False else U32(base+rr*0x2C+28)&0xFFFF) for rr in range(smc))
    print("mesh 0x%06x subs=%2d ic=%5d vc=%5d startsum=%d last=%d sum_cnt=%d" %
          (o, smc, ic, vc, s, last_end, sum(U32(base+rr*0x2C+24)&0xFFFF for rr in range(smc))))

# build binary
import io
b = io.BytesIO()
b.write(b'MMH1')
b.write(struct.pack('<I', len(out_subs)))
b.write(struct.pack('<I', len(out_verts)))
b.write(struct.pack('<I', len(out_idx)))
b.write(struct.pack('<3f', *gbmin))
b.write(struct.pack('<3f', *gbmax))
for (vbase,vc,ibase,cnt,mat,bx) in out_subs:
    b.write(struct.pack('<IIIIi16f', vbase, vc, ibase, cnt, mat, *bx) if False else struct.pack('<IIIIi', vbase, vc, ibase, cnt, mat))
    b.write(struct.pack('<6f', *bx))
for vt in out_verts: b.write(vt)
for x in out_idx: b.write(struct.pack('<I', x))
raw = b.getvalue()
open('/tmp/opencode/mh2mesh.bin','wb').write(raw)
with gzip.open('/tmp/opencode/mh2mesh.bin.gz','wb') as f: f.write(raw)
print("megamesh: subs=%d verts=%d idx=%d raw=%.2fMB gz-size=%d" %
      (len(out_subs), len(out_verts), len(out_idx), len(raw)/1e6,
       os.path.getsize('/tmp/opencode/mh2mesh.bin.gz') if True else 0))
