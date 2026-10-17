
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005449e0(float param_1,float param_2,float param_3,float param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,float param_8)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float10 extraout_ST0;
  float10 fVar7;
  undefined8 uVar8;
  float fStack_24c;
  float fStack_248;
  float fStack_244;
  undefined2 uStack_240;
  undefined2 local_23e;
  float local_23c;
  int local_238;
  float local_234;
  float local_230;
  float local_22c;
  int local_228;
  double dStack_224;
  double dStack_21c;
  double dStack_214;
  double dStack_20c;
  short asStack_204 [256];
  uint local_4;
  
  iVar4 = DAT_0075a428;
  local_4 = DAT_006dc2e0 ^ (uint)&fStack_24c;
  local_23c = param_1 + 0.01;
  local_23e = 0;
  local_238 = 0;
  local_234 = (param_2 + param_8) - 0.02;
  iVar3 = 1000;
  local_228 = 1;
  local_230 = local_23c;
  local_22c = local_234;
  FUN_00609ae0(0);
  fStack_248 = param_4 + 0.007352941;
  FUN_0060acd0(param_1,param_2,param_3,fStack_248,0x20,100,0x20,0xb4);
  fStack_244 = param_2 - 0.01;
  FUN_0060acd0(param_1,fStack_244,param_3,0x3c23d70a,0x20,0x3c,0x20,0xb4);
  fStack_248 = param_2 + param_4;
  dStack_224 = (double)fStack_248;
  FUN_0060acd0(param_1,fStack_248,param_3,0x3d4ccccd,0x20,0x3c,0x20,0xb4);
  fStack_248 = param_4 + 0.06;
  fStack_24c = param_1 - 0.005;
  FUN_0060acd0(fStack_24c,fStack_244,0x3ba3d70a,fStack_248,0x20,0x3c,0x20,0xb4);
  fStack_24c = param_1 + param_3;
  dStack_21c = (double)fStack_24c;
  FUN_0060acd0(fStack_24c,fStack_244,0x3ba3d70a,fStack_248,0x20,0x3c,0x20,0xb4);
  thunk_FUN_00608730(0,0);
  FUN_0053f3b0(10,10,2,2);
  fVar6 = (float10)FUN_0053ec60(param_7,param_6);
  fStack_244 = (float)fVar6;
  uStack_240 = 0x20;
  fVar6 = (float10)FUN_00543f30(&uStack_240,param_5,param_7,1);
  fStack_248 = (float)fVar6;
  _DAT_0075a440 = fStack_244;
  dStack_214 = (double)(param_3 - 0.01);
  dStack_20c = (double)(local_22c + param_4);
  do {
    iVar5 = 0;
    sVar1 = *(short *)(DAT_00759c50 + iVar4 * 2);
    iVar2 = iVar4;
    do {
      iVar4 = iVar2;
      if (sVar1 == 0) {
        local_238 = 1;
        goto LAB_00544ca1;
      }
      asStack_204[iVar5] = sVar1;
      sVar1 = *(short *)(DAT_00759c50 + (iVar4 + 1) * 2);
      iVar5 = iVar5 + 1;
      iVar2 = iVar4 + 1;
    } while (sVar1 != 0x20);
    iVar4 = iVar4 + 2;
LAB_00544ca1:
    asStack_204[iVar5] = 0;
    fVar6 = (float10)FUN_00543f30(asStack_204,param_5,param_7,1);
    fStack_24c = (float)fVar6;
    if ((fStack_24c + local_23c) - param_1 <= (float)dStack_214) {
      fVar6 = (float10)fStack_244;
    }
    else {
      if ((float)dStack_214 < (local_230 + fStack_24c) - param_1) {
        FUN_0053f3b0(6,6,2,2);
        fStack_24c = (float)((float10)dStack_21c + (float10)0.009999999776482582);
        thunk_FUN_0042942b("### Window X size too small! ###",fStack_24c,
                           (float)((float10)dStack_224 + (float10)0.02800000086426735),0x3f0ccccd,
                           0x3fa66666,0,1);
      }
      local_23c = local_230;
      fVar6 = (float10)fStack_244;
      local_234 = (float)(fVar6 + (float10)local_234);
      if (iVar3 != 0) {
        iVar3 = iVar3 + 1;
      }
    }
    iVar2 = DAT_0075b0f4;
    if (((((iVar3 == 0x3e9) && (DAT_0075b0f4 == 0)) && (DAT_0075b60c != 0)) &&
        ((local_238 == 0 && (DAT_0075a438 == 0)))) && (DAT_0075a430 == 0)) {
      uVar8 = FUN_0053ec90(asStack_204);
      iVar2 = (int)((ulonglong)uVar8 >> 0x20);
      DAT_0075a42c = (iVar4 - (int)uVar8) + -1;
      DAT_0075a430 = 2;
      iVar3 = 0;
      DAT_0075a438 = 1;
      fVar6 = extraout_ST0;
    }
    if (((local_228 != 0) && (iVar2 == 0)) && ((DAT_0075b604 != 0 && (DAT_0075a430 == 0)))) {
      DAT_0075a430 = 1;
      local_228 = 0;
    }
    fVar7 = (float10)_DAT_0075a43c + (float10)local_234;
    if ((float10)dStack_20c < fVar6 + fVar7) {
      uStack_240 = 4;
      fStack_24c = (float)((float10)dStack_21c - (float10)0.029999999329447746);
      FUN_00544180(&uStack_240,fStack_24c,(float)((float10)dStack_224 + (float10)0.0),0x3f800000,
                   0x3f99999a,0,1,0);
      DAT_0075a438 = 0;
      goto LAB_00544f51;
    }
    if (local_238 != 0) {
      DAT_0075a438 = 1;
    }
    if ((float10)local_22c < fVar6 * (float10)0.5 + fVar7) {
      fStack_24c = (float)fVar7;
      FUN_00544180(asStack_204,local_23c,fStack_24c,param_5,param_6,0,param_7,0);
    }
    fVar6 = (float10)FUN_00543f30(asStack_204,param_5,param_7,1);
    local_23c = (float)(fVar6 + (float10)fStack_248 + (float10)local_23c);
    if (local_238 == 1) {
LAB_00544f51:
      if (0 < DAT_00759c54) {
        uStack_240 = 3;
        fStack_24c = (float)((float10)dStack_21c - (float10)0.05999999865889549);
        FUN_00544180(&uStack_240,fStack_24c,(float)((float10)dStack_224 + (float10)0.0),0x3f800000,
                     0x3f99999a,0,1,0);
      }
      __security_check_cookie(local_4 ^ (uint)&fStack_24c);
      return;
    }
  } while( true );
}

