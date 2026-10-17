
void __fastcall FUN_005b7440(int param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 extraout_ST1;
  float fStack_1c;
  int local_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pfVar5 = *(float **)(param_1 + 0xe2c);
  local_18 = DAT_00789488;
  if (DAT_00789488 == 0) {
    local_18 = DAT_0075b6f0;
  }
  if (pfVar5 != (float *)0x0) {
    bVar3 = false;
    if ((DAT_00789490 != 0) && (*(float *)(DAT_00789490 + 0x7c) <= 0.0)) {
      bVar3 = true;
    }
    FUN_0060b610(0);
    FUN_00609ae0(DAT_0075bf38);
    fVar7 = (float10)0.10000000149011612;
    fVar9 = (float10)1;
    fVar8 = (float10)0;
    do {
      if (*(short *)(pfVar5 + 4) < 300) {
        fStack_10 = (float)((float10)pfVar5[5] * fVar7);
        fStack_14 = (float)((float10)pfVar5[5] * fVar7);
        fVar2 = pfVar5[6];
        fStack_1c = (float)((int)*(short *)(pfVar5 + 4) - *(int *)(param_1 + 0xeb4)) /
                    (float)(300 - *(int *)(param_1 + 0xeb4));
        fVar1 = (float)((fVar9 - (float10)ABS(*(float *)(*(int *)(local_18 + 0x100) + 100))) *
                       (float10)*(float *)(param_1 + 0xe84));
        if (bVar3) {
          pfVar5[1] = pfVar5[1] - *(float *)(param_1 + 0xe98) * fVar1;
          fStack_1c = (float)fVar8;
        }
        else if (fVar8 <= (float10)fStack_1c) {
          pfVar5[1] = pfVar5[1] - *(float *)(param_1 + 0xe98) * fVar1;
        }
        else {
          fStack_1c = (float)fVar8;
        }
        fStack_c = (float)(int)ROUND((float10)*(byte *)((int)pfVar5 + 0x1b) *
                                     (fVar9 - (float10)((float)(int)*(short *)(pfVar5 + 4) / 300.0))
                                    );
        uVar4 = (uint)fStack_c & 0xff;
        if (((int)uVar4 <= *(int *)(param_1 + 0xe9c)) ||
           ((float10)*(float *)(param_1 + 0xea8) + fVar9 <= (float10)pfVar5[1])) goto LAB_005b768e;
        fStack_4 = (float)fVar8;
        fStack_8 = (float)fVar8;
        FUN_0053f5f0(&fStack_4,&fStack_8,&fStack_10,&fStack_14,0,0);
        fStack_c = *pfVar5 - fStack_10 * 0.5;
        FUN_0060acd0(fStack_c,pfVar5[1] - fStack_14 * 0.5,fStack_10,
                     fStack_14 +
                     (pfVar5[5] + 1.0) * *(float *)(param_1 + 0xeb0) * fStack_14 * fStack_1c,
                     (uint)fVar2 & 0xff,(uint)fVar2 >> 8 & 0xff,(uint)fVar2 >> 0x10 & 0xff,uVar4);
        fVar9 = (float10)1;
        *(short *)(pfVar5 + 4) = *(short *)(pfVar5 + 4) + 1;
        fVar7 = (float10)0.10000000149011612;
        pfVar6 = (float *)pfVar5[7];
        fVar8 = (float10)0;
      }
      else {
LAB_005b768e:
        pfVar6 = (float *)pfVar5[7];
        fVar8 = (float10)FUN_005b7300(pfVar5);
        fVar9 = extraout_ST1;
      }
      pfVar5 = pfVar6;
    } while (pfVar6 != (float *)0x0);
    thunk_FUN_00608730(0,0);
    FUN_0060b610(1);
  }
  return;
}

