
uint FUN_004b1470(void)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  
  (**(code **)(**(int **)(DAT_0079e700 + 0xc) + 0xc))();
  switch(DAT_006ec990) {
  case 0:
    iVar4 = (**(code **)(**(int **)(DAT_0079e700 + 0xc) + 4))();
    DAT_0075b754 = iVar4 + 60000;
    DAT_006ec990 = 1;
    FUN_004b1470();
    if (DAT_0069452c != '\0') {
      FUN_004b12b0(&LAB_004b13d0);
      DAT_0069452c = '\0';
    }
    break;
  case 1:
    FUN_004b1870();
    break;
  case 2:
    if ((DAT_0075b71c == 0) && (cVar2 = FUN_004b1250(thunk_FUN_007d2a00), cVar2 != '\0')) {
      return 1;
    }
    cVar2 = thunk_FUN_007d2a00();
    if (cVar2 == '\0') {
      return 0;
    }
    break;
  case 4:
    iVar4 = FUN_005c4d90();
    if (iVar4 == 0) {
      DAT_006ec990 = 5;
LAB_004b14e3:
      FUN_004c5960();
      FUN_004aa840();
      FUN_00606270();
      return 1;
    }
    break;
  case 5:
    if (DAT_006d3830 == 4) {
      FUN_005c60b0();
      if (DAT_00759524 != 0) {
        FUN_005ca550(DAT_00759524,0);
        DAT_00759524 = 0;
      }
      uVar6 = 0;
      DAT_006ec990 = 4;
      FUN_00562df0(0);
      FUN_00562680(uVar6);
      return 1;
    }
    FUN_004b1070();
    FUN_004c5cd0(0);
    if (DAT_00789463 == '\0') {
      DAT_0075b71c = 0;
      if (DAT_006d3830 != 1) {
        FUN_004b1100();
        DAT_006ec990 = 0;
        FUN_00541dc0();
        return 1;
      }
      DAT_006ec990 = 7;
      return 1;
    }
    FUN_004b1100();
    DAT_006ec990 = 8;
    return 1;
  case 6:
    FUN_004b1070();
    FUN_004b1100();
    FUN_004b1110();
    DAT_006ec990 = 4;
    return 1;
  case 7:
    (**(code **)(**(int **)(DAT_0079e700 + 0xc) + 0x14))();
    (**(code **)(**(int **)(DAT_0079e700 + 0xc) + 0x10))();
    FUN_0056b3f0();
    cVar2 = FUN_004b1290(FUN_004b1770);
    if (cVar2 == '\0') {
      FUN_004b1770();
    }
    break;
  case 8:
    DAT_006ec990 = FUN_004b09f0();
    if (DAT_006ecbac != 0) {
      DAT_006ec990 = 9;
      DAT_006ecbac = 0;
      goto LAB_004b14e3;
    }
    break;
  case 9:
    (**(code **)(**(int **)(DAT_0079e700 + 0xc) + 0x14))();
    (**(code **)(**(int **)(DAT_0079e700 + 0xc) + 0x10))();
    DAT_006ec990 = 0;
    FUN_00541dc0();
    FUN_004b1470();
    break;
  case 0xc:
    if (DAT_0079e708 != 0) {
      if (DAT_0078949c != 0) {
        return 1;
      }
      cVar2 = FUN_006140c0();
      if (cVar2 != '\0') {
        return 1;
      }
      FUN_00606ee0(1);
    }
    FUN_004b0090();
    uVar6 = 1;
    FUN_00562df0(1);
    FUN_005625b0(uVar6);
    pcVar1 = DAT_006ecbb8;
    bVar5 = DAT_006ecbb8 != (code *)0x0;
    uVar3 = 1;
    DAT_006ecbb8 = (code *)0x0;
    if (bVar5) {
      uVar3 = (*pcVar1)();
    }
    return uVar3 & 0xff;
  }
  uVar3 = thunk_FUN_004b14dd();
  return uVar3;
}

