
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c5c20(undefined4 param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  float10 fVar3;
  
  FUN_005b8d00();
  FUN_005b9380();
  if (DAT_00789490 != 0) {
    cVar2 = FUN_005a93b0(1);
    if ((DAT_0078949c == 0) && (DAT_0076e5b3 == '\0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((param_2 == '\0') &&
       ((((!bVar1 || (cVar2 != '\0')) && (_DAT_00758850 == 0.0)) &&
        ((DAT_007894a4 == 0 && ((*(uint *)(DAT_00789490 + 0x111c) & 0x400) == 0)))))) {
      cVar2 = thunk_FUN_00428520();
      if (cVar2 == '\0') {
        thunk_FUN_0042b786();
      }
      else {
        FUN_005b1170();
      }
    }
  }
  DAT_00697ed4 = DAT_00697ed4 + 1;
  if (999999999 < DAT_00697ed4) {
    DAT_00697ed4 = 0;
  }
  if ((DAT_006d3834 != 1) && (DAT_0077e640 != '\0')) {
    FUN_005c3700();
    return;
  }
  if (DAT_0076f860 == '\0') {
    bVar1 = false;
    if ((param_2 == '\0') && (DAT_0076f4fe = 1, DAT_0076f4fd != '\0')) {
      bVar1 = true;
      thunk_FUN_0042b786();
      DAT_0076f4fd = '\0';
      DAT_0076f4fe = 0;
    }
    FUN_005c3a70();
    FUN_005c34c0(param_1);
    if (((DAT_0078949c == 0) && (DAT_0076e5b3 == '\0')) && (DAT_00789530 != 0)) {
      fVar3 = (float10)FUN_004892f0();
      FUN_00572b80(DAT_00789488,(float)fVar3);
    }
    FUN_004ea600();
    FUN_005b8d00();
    FUN_005bb160();
    FUN_005c3300(param_1);
    if ((_DAT_006d384c & 1) != 0) {
      FUN_005e3c10();
    }
    if ((_DAT_006d384c & 2) != 0) {
      FUN_005cf270();
    }
    FUN_005c5130();
    if (DAT_0078947c != 0) {
      FUN_005cd3e0();
    }
    cVar2 = FUN_005c3800(1);
    if (cVar2 != '\0') {
      thunk_FUN_00435616(param_1);
      FUN_005c55b0();
      FUN_005c3390(param_1);
      FUN_005c3e80();
    }
    cVar2 = FUN_005c3800(2);
    if (cVar2 != '\0') {
      thunk_FUN_00435616(param_1);
      FUN_005c55b0();
      FUN_005c3390(param_1);
      FUN_005c3e80();
    }
    FUN_005c3800(0);
    if ((_DAT_006d384c & 8) != 0) {
      FUN_0060bfc0(0xc,1);
      FUN_005c32c0(param_1);
    }
    if ((_DAT_006d384c & 0x100) != 0) {
      FUN_005e4c80();
    }
    if ((_DAT_006d384c & 0x20) != 0) {
      FUN_004e1150();
    }
    FUN_005b7720();
    if ((_DAT_006d384c & 0x400) != 0) {
      FUN_005c36d0(param_1);
    }
    FUN_005b80d0(0);
    cVar2 = FUN_005c3800(3);
    if (cVar2 != '\0') {
      thunk_FUN_00435616(param_1);
      FUN_005c55b0();
      FUN_005c3390(param_1);
      FUN_005c3e80();
    }
    FUN_005c3800(0);
    FUN_005c5bd0();
    if ((_DAT_006d384c & 0x80) != 0) {
      FUN_005e1810();
    }
    FUN_005c3460(param_1);
    FUN_0060bfc0(10,5);
    FUN_0060bfc0(0xb,6);
    FUN_0060bfc0(8,1);
    FUN_0060bfc0(6,1);
    FUN_0060bfc0(0xc,1);
    FUN_0060bfc0(0xe,1);
    FUN_00587ac0();
    FUN_005879d0();
    if ((DAT_00789514 != 0) && ((_DAT_006d384c & 0x800) != 0)) {
      FUN_005efcd0();
    }
    if ((DAT_00789530 != 0) && ((_DAT_006d384c & 0x1000) != 0)) {
      FUN_005c3430(param_1);
    }
    if ((DAT_00789518 != 0) && ((_DAT_006d384c & 0x2000) != 0)) {
      FUN_005f1f50();
    }
    if ((_DAT_006d384c & 0x4000) != 0) {
      FUN_005fd190();
    }
    if ((DAT_00789528 != 0) && ((_DAT_006d384c & 0x8000) != 0)) {
      FUN_005e7660();
    }
    if ((DAT_0078951c != 0) && ((_DAT_006d384c & 0x10000) != 0)) {
      FUN_005f7060();
    }
    if ((_DAT_006d384c & 0x20000) != 0) {
      FUN_005434e0();
    }
    if ((_DAT_006d384c & 0x40000) != 0) {
      FUN_0050c360();
    }
    FUN_0053f700();
    FUN_0060cea0();
    if ((_DAT_006d384c & 0x80000) != 0) {
      FUN_005b7440();
    }
    FUN_0060ceb0();
    FUN_0060cea0();
    thunk_FUN_005ea2a0(param_1);
    FUN_0060ceb0();
    FUN_005b80d0(0);
    FUN_005fb660();
    if ((_DAT_006d384c & 0x100000) != 0) {
      FUN_005fb6f0();
    }
    FUN_005b7720();
    if (DAT_006ec990 == 4) {
      FUN_00605ef0(1);
    }
    FUN_0060cea0();
    FUN_00545b30(param_1,1);
    FUN_005c3470(param_1);
    FUN_005c3a10();
    FUN_0060ceb0();
    if (param_2 == '\0') {
      FUN_005c34b0(param_1);
    }
    FUN_00522bd0(&DAT_007894c0);
    FUN_005e8b80();
    if ((param_2 == '\0') && (bVar1)) {
      thunk_FUN_0042b786();
    }
    DAT_0076f67c = 0;
    if (DAT_007894b6 != '\0') {
      FUN_0056a3a0();
      return;
    }
  }
  else {
    FUN_005af790();
    FUN_005c34b0(DAT_0075b6f0);
    FUN_00605ef0(0);
  }
  return;
}

