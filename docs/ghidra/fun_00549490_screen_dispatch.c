
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00549490(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  FUN_004b1840();
  _DAT_0075cd1c = FUN_00618eb0();
  uVar2 = DAT_0075cd2c;
  DAT_0075cac8 = 0xffffffff;
  DAT_0075cd24 = 0;
  switch(param_1) {
  case 9:
    if ((DAT_0076b304 == 5) || (DAT_0076b304 == 6)) {
      uVar10 = 0;
      uVar9 = 1;
      uVar7 = 1;
      uVar2 = FUN_0056b730(&DAT_00663f24,0);
      uVar5 = FUN_0056b730("RETRY",0);
      break;
    }
    if (DAT_0076b304 == 1) {
      uVar10 = 0;
      uVar5 = 2;
      iVar3 = DAT_0076b304;
      uVar7 = FUN_0056b730(&DAT_00663f78,0);
      uVar9 = FUN_0056b730("RETRY",0);
      pcVar8 = "NOMC_IN";
    }
    else {
      FUN_00562df0();
      thunk_FUN_00426b91();
      cVar1 = FUN_005fda80("ingame completed save");
      if (cVar1 == '\0') {
        FUN_00562df0();
        cVar1 = FUN_00561be0();
        uVar10 = 0;
        if (cVar1 == '\0') {
          uVar9 = 1;
          uVar2 = FUN_0056b730(&DAT_00663f78,0);
          uVar7 = FUN_0056b730(&DAT_00663f24,0);
          uVar5 = FUN_0056b730("RETRY",0);
          goto LAB_005495f7;
        }
        uVar9 = 2;
        uVar7 = 1;
        uVar2 = FUN_0056b730(&DAT_00663f24,0);
        uVar5 = FUN_0056b730("RETRY",0);
        break;
      }
      uVar10 = 0;
      uVar5 = 2;
      iVar3 = 1;
      uVar7 = FUN_0056b730(&DAT_00663f78,0);
      uVar9 = FUN_0056b730("RETRY",0);
      pcVar8 = "NOMC_SV";
    }
    goto LAB_00549851;
  case 10:
    uVar10 = 0;
    uVar9 = 1;
    uVar7 = 2;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    puVar6 = &DAT_00663f9c;
    goto LAB_00549c44;
  default:
    goto switchD_005494f3_caseD_b;
  case 0xc:
    FUN_00562df0();
    cVar1 = FUN_00561be0();
    uVar10 = 0;
    uVar9 = 2;
    if (cVar1 == '\0') {
      uVar2 = FUN_0056b730(&DAT_00663f78,0);
      uVar7 = FUN_0056b730(&DAT_00663f98,0);
      uVar5 = FUN_0056b730(&DAT_00663f9c,0);
      goto LAB_005495f7;
    }
    uVar7 = 2;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    uVar5 = FUN_0056b730(&DAT_00663f9c,0);
    break;
  case 0xd:
    uVar10 = 0;
    uVar9 = 1;
    uVar7 = 1;
    uVar2 = FUN_0056b730(&DAT_00663f24,0);
    uVar5 = FUN_0056b730("RETRY",0);
    break;
  case 0xf:
    FUN_00562df0();
    cVar1 = FUN_00561be0();
    uVar10 = 0;
    if ((cVar1 == '\0') && (DAT_0076b304 != 1)) {
      uVar9 = 1;
      uVar2 = FUN_0056b730(&DAT_00663f78,0);
      uVar7 = FUN_0056b730(&DAT_00663f24,0);
      uVar5 = FUN_0056b730("RETMENU",0);
      goto LAB_005495f7;
    }
    uVar5 = 2;
    iVar3 = 2;
    uVar7 = FUN_0056b730(&DAT_00663f24,0);
    uVar9 = FUN_0056b730("RETMENU",0);
    pcVar8 = "IN_SPA2";
LAB_00549851:
    uVar4 = FUN_0056b730(pcVar8,0);
    FUN_005491f0(uVar4,uVar9,uVar7,iVar3,uVar5,uVar10);
    FUN_005478a0();
    goto switchD_005494f3_caseD_b;
  case 0x10:
    FUN_00562df0();
    cVar1 = FUN_00561be0();
    uVar10 = 0;
    if (cVar1 == '\0') {
      uVar9 = 1;
      uVar2 = FUN_0056b730(&DAT_00663f78,0);
      uVar7 = FUN_0056b730(&DAT_00663f24,0);
      uVar5 = FUN_0056b730("RETMENU",0);
      goto LAB_005495f7;
    }
    uVar9 = 2;
    uVar7 = 2;
    uVar2 = FUN_0056b730(&DAT_00663f24,0);
    uVar5 = FUN_0056b730("RETMENU",0);
    break;
  case 0x11:
    uVar10 = 0;
    uVar9 = 1;
    uVar7 = 2;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    uVar5 = FUN_0056b730(&DAT_00663f9c,0);
    break;
  case 0x14:
    uVar10 = 0;
    uVar9 = 1;
    uVar7 = 1;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    uVar5 = FUN_0056b730(&DAT_00663f9c,0);
    break;
  case 0x15:
    uVar7 = FUN_0056b730("LD_NDIR",0);
    FUN_00548690(uVar7,0,0);
    goto switchD_005494f3_caseD_b;
  case 0x16:
    uVar7 = FUN_0056b730("CRPTLDF",0);
    FUN_00548690(uVar7,0,0);
switchD_005494f3_caseD_b:
    DAT_0075cd2c = param_1;
    if (param_1 == 0) {
      pcVar8 = "FE_genramps";
    }
    else {
      pcVar8 = "FE_colramps";
    }
    FUN_00606b80(0,pcVar8,1,0);
    FUN_00606270();
    FUN_0056fda0();
    return uVar2;
  case 0x1e:
    uVar10 = 0;
    uVar9 = 3;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    uVar7 = FUN_0056b730(&DAT_00663f78,0);
    uVar5 = FUN_0056b730(&DAT_00663f9c,0);
LAB_005495f7:
    uVar2 = FUN_0040334c(0,uVar5,uVar7,uVar2,uVar9,uVar10);
    return uVar2;
  case 0x20:
    FUN_00562df0();
    cVar1 = FUN_00561be0();
    uVar10 = 0;
    if (cVar1 == '\0') {
      uVar9 = 1;
      uVar2 = FUN_0056b730(&DAT_00663f78,0);
      uVar7 = FUN_0056b730(&DAT_00663f98,0);
      uVar5 = FUN_0056b730(&DAT_00663f9c,0);
      goto LAB_005495f7;
    }
    uVar9 = 2;
    uVar7 = 2;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    uVar5 = FUN_0056b730(&DAT_00663f9c,0);
    break;
  case 0x21:
    FUN_00562df0();
    cVar1 = FUN_00561be0();
    uVar10 = 0;
    if (cVar1 == '\0') {
      uVar9 = 1;
      uVar2 = FUN_0056b730(&DAT_00663f78,0);
      uVar7 = FUN_0056b730(&DAT_00663f98,0);
      uVar5 = FUN_0056b730(&DAT_00663f9c,0);
      goto LAB_005495f7;
    }
    uVar9 = 2;
    uVar7 = 2;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    uVar5 = FUN_0056b730(&DAT_00663f9c,0);
    break;
  case 0x22:
    uVar10 = 0;
    uVar9 = 1;
    uVar7 = 2;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    uVar5 = FUN_0056b730(&DAT_00663f9c,0);
    break;
  case 0x24:
    iVar3 = FUN_00562df0();
    if (*(char *)(iVar3 + 0xf4) != '\0') {
      FUN_00562df0();
      thunk_FUN_00426b91();
      cVar1 = FUN_005fda80("new game saveslots");
      if (cVar1 != '\0') {
        uVar10 = 0;
        uVar9 = 1;
        uVar2 = FUN_0056b730(&DAT_00663f78,0);
        uVar7 = FUN_0056b730(&DAT_00663f98,0);
        uVar5 = FUN_0056b730(&DAT_00663f9c,0);
        goto LAB_005495f7;
      }
    }
    uVar10 = 0;
    uVar9 = 1;
    uVar7 = 2;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    uVar5 = FUN_0056b730(&DAT_00663f9c,0);
    break;
  case 0x26:
    uVar10 = 0;
    uVar9 = 1;
    uVar7 = 2;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    uVar5 = FUN_0056b730(&DAT_00663f9c,0);
    break;
  case 0x27:
    uVar10 = 0;
    uVar9 = 1;
    uVar7 = 1;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    uVar5 = FUN_0056b730(&DAT_00663f9c,0);
    break;
  case 0x28:
    uVar10 = 0;
    uVar9 = 1;
    uVar7 = 2;
    uVar2 = FUN_0056b730(&DAT_00663f98,0);
    uVar5 = FUN_0056b730(&DAT_00663f9c,0);
    break;
  case 0x33:
    uVar10 = 1;
    uVar9 = 2;
    uVar7 = 1;
    uVar2 = FUN_0056b730(&DAT_00663f9c,0);
    uVar5 = FUN_0056b730(&DAT_00663f98,0);
    break;
  case 0x34:
  case 0x36:
    uVar10 = 1;
    uVar9 = 2;
    uVar7 = 1;
    uVar2 = FUN_0056b730(&DAT_00663f9c,0);
    puVar6 = &DAT_00663f98;
LAB_00549c44:
    uVar5 = FUN_0056b730(puVar6,0);
  }
  uVar2 = FUN_00421a9c(0,uVar5,uVar2,uVar7,uVar9,uVar10);
  return uVar2;
}

