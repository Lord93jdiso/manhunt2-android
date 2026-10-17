
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00557950(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  
  *(undefined4 *)(param_1 + 0x98) = 0xff;
  if (*(int *)(param_1 + 0x68) != 1) {
    if (*(int *)(param_1 + 0x68) == 3) {
      uVar6 = thunk_FUN_00434c1d();
      *(undefined4 *)(param_1 + 0x6c) = uVar6;
    }
    *(undefined1 *)(param_1 + 0xac) = 0;
    return;
  }
  uVar6 = 0xc;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0xff;
  thunk_FUN_0055a287(0xc);
  iVar5 = FUN_00559ef0(uVar6);
  fVar4 = _DAT_006a5fcc;
  fVar1 = _DAT_006a5fcc * (*(float *)(param_1 + 0x1c) / *(float *)(param_1 + 0x18));
  fVar2 = _DAT_006a5fc8 + *(float *)(iVar5 + 0x10);
  fVar3 = ((*(float *)(param_1 + 0xa4) + *(float *)(param_1 + 0x10)) - fVar2) /
          (*(float *)(param_1 + 0x10) - fVar2);
  if (fVar3 < 0.0 != (fVar3 == 0.0)) {
    *(undefined4 *)(param_1 + 0x6c) = 2;
    *(undefined4 *)(param_1 + 0x68) = 2;
    *(undefined1 *)(param_1 + 0xac) = 0;
    *(float *)(param_1 + 0xa4) = fVar2 - *(float *)(param_1 + 0x10);
    *(float *)(param_1 + 0x9c) = fVar4;
    *(float *)(param_1 + 0xa0) = fVar1;
    return;
  }
  *(float *)(param_1 + 0xa4) =
       *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0x10) * _DAT_006a5fc4;
  *(float *)(param_1 + 0x9c) =
       *(float *)(param_1 + 0x18) + (fVar4 - *(float *)(param_1 + 0x18)) * (1.0 - fVar3);
  *(float *)(param_1 + 0xa0) =
       (fVar1 - *(float *)(param_1 + 0x1c)) * (1.0 - fVar3) + *(float *)(param_1 + 0x1c);
  return;
}

