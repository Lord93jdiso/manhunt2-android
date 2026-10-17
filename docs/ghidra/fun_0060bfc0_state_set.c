
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0060bfc0(float *param_1,float *param_2)

{
  float *pfVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 extraout_ECX;
  uint uVar5;
  float *pfStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  pfStack_2c = param_1;
  cVar2 = FUN_0060bd80();
  if (cVar2 != '\0') {
switchD_0060bfe5_caseD_3:
    return 0;
  }
  switch(param_1) {
  case (float *)0x1:
    break;
  case (float *)0x2:
    if ((DAT_0079d660 != '\0') || (DAT_006da2a8 != param_2)) {
      DAT_006da2a8 = param_2;
      return 1;
    }
    break;
  default:
    goto switchD_0060bfe5_caseD_3;
  case (float *)0x6:
    if ((DAT_0079d660 != '\0') || ((bool)DAT_006da2a3 != (param_2 != (float *)0x0))) {
      DAT_006da2a3 = param_2 != (float *)0x0;
      pfStack_2c = (float *)0x60c533;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = (float *)(uint)(DAT_006da2a3 != '\0');
      (**(code **)(*piVar4 + 0xe4))(piVar4,7);
      return 1;
    }
    break;
  case (float *)0x7:
    if ((DAT_0079d660 != '\0') || (DAT_006da2a4 != param_2)) {
      DAT_006da2a4 = param_2;
      pfStack_2c = (float *)0x60c015;
      FUN_0060bc70();
      return 1;
    }
    break;
  case (float *)0x8:
    if ((DAT_0079d660 != '\0') || ((bool)DAT_006da2a2 != (param_2 != (float *)0x0))) {
      DAT_006da2a2 = param_2 != (float *)0x0;
      pfStack_2c = (float *)0x60c584;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = (float *)(uint)(DAT_006da2a2 != '\0');
      (**(code **)(*piVar4 + 0xe4))(piVar4,0xe);
      return 1;
    }
    break;
  case (float *)0xa:
    if ((DAT_0079d660 != '\0') || (DAT_006da28c != param_2)) {
      DAT_006da28c = param_2;
      pfStack_2c = (float *)0x60c03e;
      FUN_0060bb10();
      return 1;
    }
    break;
  case (float *)0xb:
    if ((DAT_0079d660 != '\0') || (DAT_006da290 != param_2)) {
      DAT_006da290 = param_2;
      pfStack_2c = (float *)0x60c067;
      FUN_0060bb10();
      return 1;
    }
    break;
  case (float *)0xc:
    if ((DAT_0079d660 != '\0') || ((bool)DAT_006da2a0 != (param_2 != (float *)0x0))) {
      DAT_006da2a0 = param_2 != (float *)0x0;
      pfStack_2c = (float *)0x60c324;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = (float *)(uint)(DAT_006da2a0 != '\0');
      (**(code **)(*piVar4 + 0xe4))(piVar4,0x1b);
      return 1;
    }
    break;
  case (float *)0xd:
    if ((DAT_0079d660 != '\0') || ((bool)DAT_006da2a1 != (param_2 != (float *)0x0))) {
      DAT_006da2a1 = param_2 != (float *)0x0;
      pfStack_2c = (float *)0x60c375;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = (float *)(-(uint)(DAT_006da2a1 != '\0') & 0xf);
      (**(code **)(*piVar4 + 0xe4))(piVar4,0xa8);
      return 1;
    }
    break;
  case (float *)0xe:
    if ((DAT_0079d660 != '\0') || ((bool)DAT_0079d662 != (param_2 != (float *)0x0))) {
      DAT_0079d662 = param_2 != (float *)0x0;
      pfStack_2c = (float *)0x60c616;
      FUN_0060bb70();
      return 1;
    }
    break;
  case (float *)0xf:
    if ((DAT_0079d660 != '\0') || (DAT_006da294 != param_2)) {
      DAT_006da294 = param_2;
      pfStack_2c = (float *)0x60c643;
      FUN_0060bb70();
      return 1;
    }
    break;
  case (float *)0x10:
    if ((DAT_0079d660 != '\0') || (DAT_006da298 != param_2)) {
      DAT_006da298 = param_2;
      pfStack_2c = (float *)0x60c670;
      FUN_0060bb70();
      return 1;
    }
    break;
  case (float *)0x11:
    if ((DAT_0079d660 != '\0') || (DAT_006da29c != param_2)) {
      DAT_006da29c = param_2;
      pfStack_2c = (float *)0x60c69d;
      FUN_0060bb70();
      return 1;
    }
    break;
  case (float *)0x12:
    if ((DAT_0079d660 != '\0') || (DAT_0079d668 != (char)param_2)) {
      DAT_0079d668 = (char)param_2;
      pfStack_2c = (float *)0x60c6ca;
      FUN_0060bb70();
      return 1;
    }
    break;
  case (float *)0x13:
    if ((DAT_0079d660 != '\0') || (DAT_0079d669 != (char)param_2)) {
      DAT_0079d669 = (char)param_2;
      pfStack_2c = (float *)0x60c6f7;
      FUN_0060bb70();
      return 1;
    }
    break;
  case (float *)0x15:
    if ((DAT_0079d660 != '\0') || ((bool)DAT_0079d661 != (param_2 != (float *)0x0))) {
      DAT_0079d661 = param_2 != (float *)0x0;
      pfStack_2c = DAT_006da274;
      uVar3 = FUN_0060bbe0(DAT_0079d664,_DAT_006da278,_DAT_006da27c,_DAT_006da284,_DAT_006da288);
      FUN_0060bc10(extraout_ECX,uVar3);
      return 1;
    }
    break;
  case (float *)0x16:
    pfStack_2c = (float *)*param_2;
    goto LAB_0060c16c;
  case (float *)0x17:
    if ((DAT_0079d660 != '\0') || (DAT_0079d664 != param_2)) {
      pfStack_2c = DAT_006da274;
      DAT_0079d664 = param_2;
      uVar3 = FUN_0060bbe0(param_2,_DAT_006da278,_DAT_006da27c,_DAT_006da284,_DAT_006da288);
      FUN_0060bc10(DAT_0079d661,uVar3);
      return 1;
    }
    break;
  case (float *)0x18:
    if ((DAT_0079d660 == '\0') && (*param_2 == _DAT_006da280)) {
      return 1;
    }
    _DAT_006da280 = *param_2;
    pfStack_2c = DAT_006da274;
    goto LAB_0060c16c;
  case (float *)0x1a:
    if ((DAT_0079d660 == '\0') && (*param_2 == _DAT_006da278)) {
      return 1;
    }
    _DAT_006da278 = *param_2;
    pfStack_2c = DAT_006da274;
    goto LAB_0060c16c;
  case (float *)0x1b:
    if ((DAT_0079d660 == '\0') && (*param_2 == _DAT_006da27c)) {
      return 1;
    }
    _DAT_006da27c = *param_2;
    pfStack_2c = DAT_006da274;
    goto LAB_0060c16c;
  case (float *)0x1c:
    if ((DAT_0079d660 == '\0') && (*param_2 == _DAT_006da284)) {
      return 1;
    }
    _DAT_006da284 = *param_2;
    pfStack_2c = DAT_006da274;
    goto LAB_0060c16c;
  case (float *)0x1d:
    if ((DAT_0079d660 == '\0') && (*param_2 == _DAT_006da288)) {
      return 1;
    }
    _DAT_006da288 = *param_2;
    pfStack_2c = DAT_006da274;
LAB_0060c16c:
    DAT_006da274 = pfStack_2c;
    uVar3 = FUN_0060bbe0(DAT_0079d664,_DAT_006da278,_DAT_006da27c,_DAT_006da284,_DAT_006da288);
    FUN_0060bc10(DAT_0079d661,uVar3);
    return 1;
  case (float *)0x1f:
    if ((DAT_0079d660 == '\0') && ((bool)DAT_0079d66b == (param_2 != (float *)0x0))) {
      return 1;
    }
    DAT_0079d66b = param_2 != (float *)0x0;
    pfStack_2c = (float *)0x60c40c;
    piVar4 = (int *)thunk_FUN_00404010();
    pfStack_2c = (float *)(uint)(DAT_0079d66b != '\0');
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x89);
    if (DAT_0079d66b != '\0') {
      return 1;
    }
    FUN_0060d7d0();
    FUN_00426330();
    uVar5 = 0;
    do {
      pfStack_2c = (float *)0x0;
      uStack_1c = 0;
      uStack_18 = 0;
      uStack_14 = 0;
      uStack_10 = 0x3f800000;
      FUN_00607c10(&uStack_1c);
      FUN_00607c90(&pfStack_2c,uVar5);
      FUN_00607c40(&pfStack_2c,uVar5);
      FUN_00607c80(&pfStack_2c,uVar5);
      uVar5 = uVar5 + 1;
    } while (uVar5 < 4);
    FUN_00607cd0();
    return 1;
  case (float *)0x20:
    DAT_0079d66c = (float)param_2 * -1.0;
    pfVar1 = (float *)(DAT_0079d66c * 1.5625e-05);
    pfStack_2c = (float *)0x60c4e6;
    piVar4 = (int *)thunk_FUN_00404010();
    pfStack_2c = pfVar1;
    (**(code **)(*piVar4 + 0xe4))(piVar4,0xc3);
    return 1;
  case (float *)0x21:
    if ((DAT_0079d660 != '\0') || (DAT_006da2ac != param_2)) {
      DAT_006da2ac = param_2;
      pfStack_2c = (float *)0x60c5ca;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = DAT_006da2ac;
      (**(code **)(*piVar4 + 0xe4))(piVar4,0x17);
      return 1;
    }
    break;
  case (float *)0x22:
    if ((DAT_0079d660 != '\0') || ((bool)DAT_0079d670 != (param_2 != (float *)0x0))) {
      DAT_0079d670 = param_2 != (float *)0x0;
      pfStack_2c = (float *)0x60c72f;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = (float *)(uint)(DAT_0079d670 != '\0');
      (**(code **)(*piVar4 + 0xe4))(piVar4,0x34);
      return 1;
    }
    break;
  case (float *)0x23:
    if ((DAT_0079d660 != '\0') || (DAT_006da2b4 != param_2)) {
      DAT_006da2b4 = param_2;
      pfStack_2c = (float *)0x60c775;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = DAT_006da2b4;
      (**(code **)(*piVar4 + 0xe4))(piVar4,0x35);
      return 1;
    }
    break;
  case (float *)0x24:
    if ((DAT_0079d660 != '\0') || (DAT_006da2b8 != param_2)) {
      DAT_006da2b8 = param_2;
      pfStack_2c = (float *)0x60c7b6;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = DAT_006da2b8;
      (**(code **)(*piVar4 + 0xe4))(piVar4,0x36);
      return 1;
    }
    break;
  case (float *)0x25:
    if ((DAT_0079d660 != '\0') || (DAT_006da2bc != param_2)) {
      DAT_006da2bc = param_2;
      pfStack_2c = (float *)0x60c7f7;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = DAT_006da2bc;
      (**(code **)(*piVar4 + 0xe4))(piVar4,0x37);
      return 1;
    }
    break;
  case (float *)0x26:
    if ((DAT_0079d660 != '\0') || (DAT_006da2c0 != param_2)) {
      DAT_006da2c0 = param_2;
      pfStack_2c = (float *)0x60c838;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = DAT_006da2c0;
      (**(code **)(*piVar4 + 0xe4))(piVar4,0x38);
      return 1;
    }
    break;
  case (float *)0x27:
    if ((DAT_0079d660 != '\0') || (DAT_0079d674 != param_2)) {
      DAT_0079d674 = param_2;
      pfStack_2c = (float *)0x60c879;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = DAT_0079d674;
      (**(code **)(*piVar4 + 0xe4))(piVar4,0x39);
      return 1;
    }
    break;
  case (float *)0x28:
    if ((DAT_0079d660 != '\0') || (DAT_006da2c4 != param_2)) {
      DAT_006da2c4 = param_2;
      pfStack_2c = (float *)0x60c8ba;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = DAT_006da2c4;
      (**(code **)(*piVar4 + 0xe4))(piVar4,0x3b);
      return 1;
    }
    break;
  case (float *)0x29:
    if ((DAT_0079d660 != '\0') || (DAT_006da2b0 != param_2)) {
      DAT_006da2b0 = param_2;
      pfStack_2c = (float *)0x60c3c0;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = DAT_006da2b0;
      (**(code **)(*piVar4 + 0xe4))(piVar4,0x16);
      return 1;
    }
    break;
  case (float *)0x2a:
    if ((DAT_0079d660 != '\0') || ((bool)DAT_0079d671 != (param_2 != (float *)0x0))) {
      DAT_0079d671 = param_2 != (float *)0x0;
      pfStack_2c = (float *)0x60c906;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = (float *)(uint)(DAT_0079d671 != '\0');
      (**(code **)(*piVar4 + 0xe4))(piVar4,0xa1);
      return 1;
    }
    break;
  case (float *)0x2b:
    if ((DAT_0079d660 != '\0') || (DAT_006da2c8 != param_2)) {
      DAT_006da2c8 = param_2;
      pfStack_2c = (float *)0x60c94f;
      piVar4 = (int *)thunk_FUN_00404010();
      pfStack_2c = DAT_006da2c8;
      (**(code **)(*piVar4 + 0xe4))(piVar4,0xab);
      return 1;
    }
  }
  return 1;
}

