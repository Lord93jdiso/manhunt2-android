
void __fastcall FUN_005bad70(int param_1)

{
  ushort uVar1;
  float fVar2;
  undefined4 uVar3;
  byte *pbVar4;
  float *pfVar5;
  ushort uVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  float *pfVar12;
  float10 fVar13;
  float local_52c;
  uint local_528;
  undefined4 local_524;
  undefined4 local_520;
  undefined4 local_51c;
  undefined4 local_518;
  int local_514;
  undefined1 auStack_510 [12];
  float fStack_504;
  int aiStack_500 [20];
  undefined1 auStack_4b0 [12];
  float local_4a4;
  int local_4a0 [296];
  
  if ((*(int *)(param_1 + 0x2f8) == 0) && (DAT_00789490 != 0)) {
    *(int *)(param_1 + 0x2f4) = DAT_00789490;
    *(byte *)(param_1 + 0x302) = *(byte *)(param_1 + 0x302) | 1;
    *(undefined1 *)(param_1 + 0x301) = 0;
    *(int *)(param_1 + 0x2f8) = param_1 + 0x11fc4;
    *(byte *)(param_1 + 0x302) = *(byte *)(param_1 + 0x302) | 2;
    *(byte *)(param_1 + 0x302) = *(byte *)(param_1 + 0x302) & 0xfe;
    *(int *)(param_1 + 0x11fa4) = param_1 + 0x24;
    *(short *)(param_1 + 0x12328) = *(short *)(param_1 + 0x12328) + 1;
    *(short *)(param_1 + 0x1232a) = *(short *)(param_1 + 0x1232a) + 1;
  }
  uVar1 = *(ushort *)(param_1 + 0x1232a);
  uVar6 = *(ushort *)(param_1 + 0x12328);
  if (uVar1 < uVar6) {
    if (uVar1 < 8) {
      uVar7 = (uint)uVar1;
      iVar11 = uVar7 * 0x6c + 0x11fc4 + param_1;
      piVar9 = (int *)(param_1 + 0x11fa4 + uVar7 * 4);
      pbVar4 = (byte *)(uVar7 * 0x2e0 + 0x302 + param_1);
      while( true ) {
        uVar10 = (uint)*(ushort *)(param_1 + 0x12328);
        if (8 < uVar10) {
          uVar10 = 8;
        }
        if (uVar10 <= uVar7) break;
        *pbVar4 = *pbVar4 | 1;
        *(int *)(pbVar4 + -10) = iVar11;
        pbVar4[-1] = 0;
        *piVar9 = (int)(pbVar4 + -0x2de);
        *(short *)(param_1 + 0x1232a) = *(short *)(param_1 + 0x1232a) + 1;
        uVar7 = uVar7 + 1;
        piVar9 = piVar9 + 1;
        iVar11 = iVar11 + 0x6c;
        pbVar4 = pbVar4 + 0x2e0;
      }
      uVar6 = *(ushort *)(param_1 + 0x12328);
      if (uVar6 <= *(ushort *)(param_1 + 0x1232a)) {
        return;
      }
    }
    if (((DAT_00789488 != 0) && (*(int *)(DAT_00789488 + 0x100) != 0)) &&
       (*(int *)(DAT_00789488 + 0x100) != -0x40)) {
      local_514 = *(int *)(DAT_00789488 + 0x100) + 0x70;
      local_528 = 1;
      if (1 < uVar6) {
        pfVar5 = &local_4a4;
        piVar9 = (int *)(param_1 + 0x5d4);
        do {
          if (((~(*(byte *)((int)piVar9 + 0xe) >> 2) & 1) == 0) ||
             (iVar11 = *piVar9, *(int *)(iVar11 + 0xb8) == 0)) {
            *pfVar5 = 9999999.0;
          }
          else {
            local_518 = 0;
            local_51c = 0;
            local_520 = 0;
            local_524 = 0;
            FUN_0060d830(&local_524,local_514,**(int **)(iVar11 + 0xb8) + 0x70);
            fVar13 = (float10)FUN_0060da30(&local_524);
            local_52c = (float)fVar13;
            *pfVar5 = local_52c;
            if ((*(byte *)(iVar11 + 0x74) & 0x11) == 0) {
              *pfVar5 = local_52c + 999999.0;
            }
          }
          uVar1 = *(ushort *)(param_1 + 0x12328);
          local_528 = local_528 + 1;
          pfVar5[1] = (float)(piVar9 + -0xb4);
          piVar9 = piVar9 + 0xb8;
          pfVar5 = pfVar5 + 3;
        } while (local_528 < uVar1);
      }
      local_52c = (float)((uint)local_52c & 0xffffff00);
      FUN_005baaf0(&local_4a4,auStack_4b0 + (uint)*(ushort *)(param_1 + 0x12328) * 0xc,
                   ((int)(auStack_4b0 + (uint)*(ushort *)(param_1 + 0x12328) * 0xc) -
                   (int)&local_4a4) / 0xc,local_52c);
      uVar7 = 1;
      if (1 < *(ushort *)(param_1 + 0x1232a)) {
        pfVar5 = (float *)(param_1 + 0x11fa8);
        pfVar12 = &fStack_504;
        do {
          if (((~(*(byte *)((int)*pfVar5 + 0x2de) >> 2) & 1) == 0) ||
             (iVar11 = *(int *)((int)*pfVar5 + 0x2d0), *(int *)(iVar11 + 0xb8) == 0)) {
            *pfVar12 = 9999999.0;
          }
          else {
            local_518 = 0;
            local_51c = 0;
            local_520 = 0;
            local_524 = 0;
            FUN_0060d830(&local_524,local_514,**(int **)(iVar11 + 0xb8) + 0x70);
            fVar13 = (float10)FUN_0060da30(&local_524);
            local_52c = (float)fVar13;
            *pfVar12 = local_52c;
            if ((*(byte *)(iVar11 + 0x74) & 0x11) == 0) {
              *pfVar12 = local_52c + 999999.0;
            }
          }
          fVar2 = *pfVar5;
          uVar1 = *(ushort *)(param_1 + 0x1232a);
          *(short *)(pfVar12 + 2) = (short)uVar7;
          pfVar12[1] = fVar2;
          uVar7 = uVar7 + 1;
          pfVar5 = pfVar5 + 1;
          pfVar12 = pfVar12 + 3;
        } while (uVar7 < uVar1);
      }
      local_52c = (float)((uint)local_52c & 0xffffff00);
      FUN_005bac30(&fStack_504,auStack_510 + (uint)*(ushort *)(param_1 + 0x1232a) * 0xc,
                   ((int)(auStack_510 + (uint)*(ushort *)(param_1 + 0x1232a) * 0xc) -
                   (int)&fStack_504) / 0xc,local_52c);
      uVar7 = 1;
      piVar8 = local_4a0;
      piVar9 = aiStack_500;
      while( true ) {
        uVar10 = (uint)*(ushort *)(param_1 + 0x12328);
        if (8 < uVar10) {
          uVar10 = 8;
        }
        if (uVar10 <= uVar7) break;
        iVar11 = *piVar8;
        if ((((~(*(byte *)(iVar11 + 0x2de) >> 2) & 1) != 0) &&
            ((*(byte *)(*(int *)(iVar11 + 0x2d0) + 0x74) & 0x11) != 0)) &&
           (*(int *)(iVar11 + 0x2d4) == 0)) {
          iVar11 = *piVar9;
          uVar3 = *(undefined4 *)(iVar11 + 0x2d4);
          *(undefined4 *)(iVar11 + 0x2d4) = 0;
          *(undefined4 *)(iVar11 + 0x2d8) = 0;
          iVar11 = *piVar8;
          *(byte *)(iVar11 + 0x2de) = *(byte *)(iVar11 + 0x2de) | 1;
          *(undefined4 *)(iVar11 + 0x2d4) = uVar3;
          *(undefined1 *)(iVar11 + 0x2dd) = 0;
          *(int *)(param_1 + 0x11fa4 + (uint)*(ushort *)(piVar9 + 1) * 4) = *piVar8;
          piVar9 = piVar9 + 3;
        }
        uVar7 = uVar7 + 1;
        piVar8 = piVar8 + 3;
      }
    }
  }
  return;
}

