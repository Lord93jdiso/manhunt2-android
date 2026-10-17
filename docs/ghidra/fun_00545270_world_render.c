
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00545270(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 auStack_174 [28];
  float fStack_158;
  float fStack_154;
  float fStack_150;
  float fStack_14c;
  char acStack_148 [260];
  uint local_44;
  
  local_44 = DAT_006dc2e0 ^ (uint)auStack_174;
  FUN_00541ee0();
  if (DAT_0075b0ec == 0) goto LAB_00545a7b;
  FUN_0060b610();
  if (DAT_0075b334 != 0) {
    FUN_0053f3b0(1,1,1,1);
    _sprintf(&DAT_00759840,"%d shadow cameras active",DAT_0075b338);
    thunk_FUN_0042942b(&DAT_00759840,0x3f1c28f6,0x3f23d70a,0x3f333333,0x3f333333,0,1);
    DAT_0075b338 = 0;
  }
  if ((DAT_0075b52c != 0) && (DAT_0075b2fc == 0)) {
    FUN_0053f3b0(1,1,1,1);
    fStack_158 = 0.0;
    do {
      fVar1 = fStack_158;
      iVar2 = FUN_0053d600();
      if (iVar2 != 0) {
        (&DAT_0075b548)[(int)fVar1] = 0;
      }
      _sprintf(&DAT_00759840,"(%d : %.3f ms)",fVar1,(double)(float)(&DAT_0075b548)[(int)fVar1]);
      fStack_158 = (float)(int)fStack_158 * 0.03 + 0.04;
      thunk_FUN_0042942b(&DAT_00759840,0x3ca3d70a,fStack_158,0x3f333333,0x3f333333,0,1);
      fStack_158 = (float)((int)fVar1 + 1);
    } while ((int)fStack_158 < 3);
  }
  if (DAT_0075b2f4 == 1) {
    thunk_FUN_0042041b(0,0x3f000000,0x3f800000,0x3a83126f,0,100,0,0xff,0,0,0,0);
  }
  if (DAT_0075b2f4 == 2) {
    thunk_FUN_0042041b(0x3f000000,0,0x3a83126f,0x3f800000,0,100,0,0xff,0,0,0,0);
  }
  iVar2 = FUN_0053dee0();
  if (iVar2 == 0) {
    if (DAT_0075b348 != 0) {
      fStack_154 = 0.0;
      fStack_14c = 0.0;
      fStack_150 = 1.5;
      fStack_158 = 1.5;
      FUN_0053f5f0(&fStack_154,&fStack_14c,&fStack_158,&fStack_150,0,0);
      fVar1 = fStack_158;
      fStack_154 = (1.0 - fStack_158) * 0.5;
      fStack_158 = (1.0 - fStack_150) * 0.5;
      uVar4 = DAT_0075bf18;
      if (DAT_0075b558 == 0) {
        uVar4 = DAT_0075bf14;
      }
      thunk_FUN_0042041b(fStack_154,fStack_158,fVar1,fStack_150,0xff,0xff,0xff,0xff,uVar4,0,0,0);
      if (fStack_154 != 0.0) {
        FUN_00609ae0();
        FUN_0060acd0(0,0,fStack_154,0x3f800000,0,0,0,0xff);
        fStack_158 = 1.0 - fStack_154;
        FUN_0060acd0(fStack_158,0,fStack_154,0x3f800000,0,0,0,0xff);
        thunk_FUN_00608730(0,0);
      }
    }
  }
  else {
    DAT_0075b348 = 0;
  }
  thunk_FUN_0055a287();
  FUN_00559ce0();
  FUN_004e1150();
  iVar2 = thunk_FUN_0055a287();
  if (((*(char *)(iVar2 + 0x69) != '\0') && (DAT_0075b110 != 0)) && (DAT_0075b6f8 != 0)) {
    FUN_006094c0();
    FUN_00609480(2,2);
    if (DAT_0075b114 == 0) {
      FUN_0053f7a0();
    }
    FUN_006094f0();
  }
  if (param_2 != 0) {
    FUN_0054c430();
  }
  FUN_00544460();
  FUN_00544780();
  FUN_00562df0();
  FUN_00563860();
  if (DAT_006ec990 == 1) {
    pcVar3 = (char *)FUN_00594d60();
    if (*pcVar3 == '\0') {
      FUN_00543240();
    }
  }
  if (DAT_0075b128 != 0) {
    FUN_005449e0(0x3df5c28f,0x3ca3d70a,0x3f400000,0x3e19999a,0x3f4ccccd,0x3f333333,1,0x3cf5c28f);
  }
  if (DAT_0075b384 == 0) {
    FUN_00545070();
  }
  if (DAT_0075b300 != 0) {
    FUN_0053f3b0(1,1,1,1);
    iVar2 = FUN_00580e30();
    _sprintf(acStack_148,"Mem. used = %d",*(undefined4 *)(iVar2 + 0x1268));
    thunk_FUN_0042942b(acStack_148,0x3e99999a,0x3f6e147b,0x3f800000,0x3f19999a,0,1);
    iVar2 = FUN_00580e30();
    _sprintf(acStack_148,"Mem2. used = %d",*(undefined4 *)(iVar2 + 0x1268));
    thunk_FUN_0042942b(acStack_148,0x3f19999a,0x3f6e147b,0x3f800000,0x3f19999a,0,1);
  }
  FUN_0054bcf0();
  if (DAT_0075b108 != 0) {
    FUN_0060af80(0,0x3f000000,0x3f800000,0x3f000000,0,0x80,0,0xff,1);
    FUN_0060af80(0x3f000000,0,0x3f000000,0x3f800000,0,0x80,0,0xff,1);
    FUN_0060af80(0,0,0x3f800000,0,0,0x80,0,0xff,1);
    FUN_0060af80(0x3f800000,0,0x3f800000,0x3f800000,0,0x80,0,0xff,1);
    FUN_0060af80(0,0x3f800000,0x3f800000,0x3f800000,0,0x80,0,0xff,1);
    FUN_0060af80(0,0,0,0x3f800000,0,0x80,0,0xff,1);
    fStack_158 = (float)thunk_FUN_0042ec26();
    fStack_150 = (float)(int)fStack_158;
    iVar2 = FUN_005b7840();
    fStack_158 = 17.0 / fStack_150;
    fStack_150 = 1.0 - fStack_158;
    fStack_154 = 17.0 / (float)iVar2;
    fStack_14c = 1.0 - fStack_154;
    FUN_0060af80(fStack_158,fStack_154,fStack_158,fStack_14c,0,0x80,0,0xff,1);
    FUN_0060af80(fStack_150,fStack_154,fStack_150,fStack_14c,0,0x80,0,0xff,1);
    FUN_0060af80(fStack_158,fStack_154,fStack_150,fStack_154,0,0x80,0,0xff,1);
    FUN_0060af80(fStack_158,fStack_14c,fStack_150,fStack_14c,0,0x80,0,0xff,1);
  }
  if (DAT_0075b150 == 0) {
LAB_005459d5:
    DAT_0075b150 = 0;
  }
  else {
    iVar2 = thunk_FUN_004103a7();
    if (iVar2 == 2) goto LAB_005459d5;
    thunk_FUN_0042041b(0,0,0x3f800000,0x3f800000,0,0,0,0xff,0,0,0,0);
  }
  if (DAT_0075b138 != 0) {
    DAT_0075b138 = 0;
    _DAT_0075b13c = 0xff;
    (*DAT_0075b140)();
  }
  if (DAT_0075b144 != 0) {
    DAT_0075b144 = 0;
    _DAT_0075b148 = 0;
    (*DAT_0075b14c)();
    thunk_FUN_0042041b(0,0,0x3f800000,0x3f800000,0,0,0,0xff,0,0,0,0);
  }
  FUN_0053e3c0();
  iVar2 = FUN_004e08d0();
  if (((iVar2 != 0) && (DAT_0076e5b3 = 0, DAT_0075b100 == 0)) && (DAT_007064cc == 0)) {
    DAT_0075b0f4 = DAT_0075b0f4 ^ 1;
  }
  FUN_0060b610();
  uVar4 = FUN_004b1840();
  FUN_00541850(uVar4);
LAB_00545a7b:
  __security_check_cookie(local_44 ^ (uint)auStack_174);
  return;
}

