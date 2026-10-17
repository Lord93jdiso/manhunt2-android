
void __fastcall FUN_00484420(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  float10 fVar6;
  char cStack_25;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(*(int *)(param_1 + 4) + 0xfa4) == 0) {
    DAT_006eae1c = 0;
  }
  *(undefined4 *)(param_1 + 0xa8) = 1;
  iVar2 = *(int *)(param_1 + 0x34);
  if (iVar2 == 1) {
    if (((byte)*(undefined4 *)(*(int *)(param_1 + 0x38) + 0x74) & 8) != 8) {
LAB_00484466:
      if (*(int *)(param_1 + 0x34) == 0) {
        FUN_0049d140(*(undefined4 *)(param_1 + 0x38));
      }
      else if (*(int *)(param_1 + 0x34) == 5) {
        FUN_0049d0d0(*(undefined4 *)(param_1 + 0x38));
      }
    }
  }
  else if (((iVar2 == 0) || (iVar2 == 4)) || (iVar2 == 5)) goto LAB_00484466;
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 4) + 0xf54) + 0x1c) & 1) == 0) {
    FUN_0050c730();
    return;
  }
  FUN_00474390();
  FUN_004839f0();
  iVar2 = FUN_004742d0();
  if (iVar2 == -0x1b0) {
    iVar2 = 0;
  }
  else {
    iVar2 = iVar2 + 0x1b4;
  }
  if (*(int *)(param_1 + 4) == -0xf90) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 4) + 0xf94;
  }
  uStack_14 = 0;
  uStack_18 = 0;
  uStack_1c = 0;
  uStack_20 = 0;
  FUN_0060d830(&uStack_20,iVar3,iVar2);
  fVar6 = (float10)FUN_0060da40(&uStack_20);
  *(float *)(param_1 + 0xac) = (float)fVar6;
  iVar2 = FUN_004742d0();
  if (iVar2 == -0x1b0) {
    iVar2 = 0;
  }
  else {
    iVar2 = iVar2 + 0x1b4;
  }
  if (param_1 == -0x20) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + 0x24;
  }
  uStack_4 = 0;
  uStack_8 = 0;
  uStack_c = 0;
  uStack_10 = 0;
  FUN_0060d830(&uStack_10,iVar3,iVar2);
  fVar6 = (float10)FUN_0060da40(&uStack_10);
  *(float *)(param_1 + 0xb0) = (float)fVar6;
  FUN_00482a00();
  iVar2 = FUN_00474320();
  if (20.0 <= ABS(*(float *)(iVar2 + 0x11c))) {
    iVar3 = FUN_00474300();
    iVar4 = FUN_00496050();
    if (((iVar4 == 0) && (*(int *)(iVar3 + 0x1ec) != 0)) &&
       ((iVar3 = thunk_FUN_007cd180(), iVar3 != 0 &&
        ((*(int *)(*(int *)(param_1 + 4) + 0xfa4) == 0 && (40.0 < ABS(*(float *)(iVar2 + 0x11c))))))
       )) {
      iVar2 = FUN_00474300();
      *(undefined4 *)(iVar2 + 0x1ec) = 0;
    }
  }
  else {
    iVar2 = FUN_00474300();
    *(undefined4 *)(iVar2 + 0x1ec) = 1;
  }
  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xf60) + 700) + 0x150);
  if (((iVar2 == 0xe) || (iVar2 == 0x2d)) || (iVar2 == 0x2e)) {
    if (*(int **)(param_1 + 8) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 8) + 8))();
    }
    *(undefined4 *)(param_1 + 8) = 0;
    piVar5 = (int *)FUN_004742d0();
    (**(code **)(*piVar5 + 0x10))(0);
    DAT_006eade4 = 0;
    DAT_006eade8 = 0;
    DAT_006eadec = 0;
    DAT_006eadf0 = 0;
    DAT_006eadf4 = 0;
    return;
  }
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0:
    FUN_00482ca0();
    break;
  case 1:
    FUN_00482f00();
    break;
  case 2:
    FUN_00482da0();
    break;
  case 3:
    FUN_00481820();
    break;
  case 4:
    FUN_004819d0();
    break;
  case 5:
    FUN_00484070();
    break;
  case 6:
    FUN_00483060();
    break;
  case 7:
    FUN_004833d0();
    break;
  case 8:
    FUN_004834f0();
    break;
  case 9:
    FUN_00484390();
    break;
  case 10:
    FUN_00483530();
    break;
  case 0xb:
    FUN_00482ae0();
    break;
  case 0xc:
    FUN_004832a0();
    break;
  case 0xd:
    FUN_00483580();
  }
  if (DAT_006892f8 == 0) {
    FUN_00482fc0();
  }
  else {
    FUN_00480c30();
  }
  if ((*(int *)(param_1 + 4) == 0) || (*(int *)(*(int *)(param_1 + 4) + 0xf60) == 0))
  goto LAB_00484806;
  FUN_00474300();
  iVar2 = FUN_00618eb0();
  bVar1 = DAT_0068933c < iVar2;
  iVar2 = thunk_FUN_00410bb5();
  if (iVar2 == 0) {
    iVar2 = thunk_FUN_007cd200();
    cStack_25 = '\0';
    if (iVar2 != 0) goto LAB_0048479f;
  }
  else {
LAB_0048479f:
    cStack_25 = '\x01';
  }
  if ((bVar1) && (cStack_25 != '\0')) {
    if (*(char *)(param_1 + 0xfc) == '\0') {
      *(uint *)(param_1 + 0xf8) = DAT_007895b8 + DAT_006ece6c;
    }
    if ((*(uint *)(param_1 + 0xf8) != 0) && (DAT_006ece6c < *(uint *)(param_1 + 0xf8))) {
      iVar2 = FUN_00474300();
      *(undefined4 *)(iVar2 + 0x13c) = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  *(char *)(param_1 + 0xfc) = cStack_25;
LAB_00484806:
  *(uint *)(param_1 + 0x98) = (uint)(*(int *)(*(int *)(param_1 + 4) + 0xfa4) == 0);
  iVar2 = FUN_00474300();
  if ((*(int *)(iVar2 + 0x94) != 0) && (iVar2 != -4)) {
    iVar2 = FUN_00474300();
    if (*(int *)(iVar2 + 0x94) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 + 4;
    }
    *(undefined4 *)(param_1 + 0xf0) = 3;
    *(int *)(param_1 + 0xf4) = iVar2;
    FUN_0049cf30(iVar2);
    return;
  }
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 6;
  return;
}

