
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0054fee0(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined2 extraout_var;
  uint3 uVar3;
  float10 fVar4;
  uint local_8;
  
  if (*param_1 != 0) {
    if ((float)param_1[9] < 0.0) {
      if ((float)param_1[10] == 0.0) {
        fVar4 = (float10)FUN_00401040();
        local_8 = (uint)((float)(fVar4 * ((float10)100.0 - (float10)0) + (float10)0) <
                        (float)param_1[0xb]);
        param_1[10] = (int)(float)local_8;
        if ((float)local_8 == 0.0) {
          fVar1 = (float)param_1[8];
        }
        else {
          fVar1 = (float)param_1[7];
        }
        fVar4 = (float10)FUN_00401040();
        param_1[9] = (int)(float)(fVar4 * ((float10)fVar1 - (float10)0) + (float10)0);
        fVar1 = (float)param_1[4];
        fVar2 = (float)param_1[5];
        fVar4 = (float10)FUN_00401040();
        fVar1 = (float)(fVar4 * ((float10)fVar2 - (float10)fVar1) + (float10)fVar1);
        param_1[1] = (int)fVar1;
        FUN_0054fe80(fVar1,(float)param_1[6] + fVar1);
        fVar1 = (float)param_1[10];
        uVar3 = (uint3)(CONCAT22(extraout_var,
                                 (ushort)(0.0 < fVar1) << 8 | (ushort)NAN(fVar1) << 10 |
                                 (ushort)(fVar1 == 0.0) << 0xe) >> 8);
        if (fVar1 == 0.0) {
          FUN_00554fd0((uint)uVar3 << 8);
        }
        else {
          FUN_00554fd0(CONCAT31(uVar3,1));
        }
      }
      else {
        fVar1 = (float)param_1[8];
        fVar4 = (float10)FUN_00401040();
        param_1[9] = (int)(float)(fVar4 * ((float10)fVar1 - (float10)0) + (float10)0);
        param_1[10] = 0;
        FUN_00554fd0(0);
      }
    }
    fVar1 = _DAT_006ece68;
    if (_DAT_006ece68 <= 0.0) {
      fVar1 = 0.0001;
    }
    param_1[9] = (int)((float)param_1[9] - fVar1);
  }
  return;
}

