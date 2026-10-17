
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c430(void)

{
  int iVar1;
  bool bVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iStack_4;
  
  if (DAT_0075cf40 != 0) {
    FUN_0054c210();
    DAT_0075cf40 = 0;
  }
  iVar7 = *(int *)(DAT_00789490 + 0x1c0);
  iVar1 = *(int *)(DAT_00789490 + 0x1bc);
  DAT_0075cf84 = *(int *)(*(int *)(iVar1 + 0xc) + 4);
  DAT_0075cf88 = *(int *)(*(int *)(iVar1 + 0xc) + 8);
  DAT_0075cf8c = *(int *)(*(int *)(iVar1 + 0xc) + 0xc);
  DAT_0075cf90 = *(int *)(*(int *)(iVar1 + 0xc) + 0x10);
  if (((DAT_0075cf84 != 0) || (DAT_0075cf88 != 0)) || (DAT_0075cdec = 1, DAT_0075cf90 != 0)) {
    DAT_0075cdec = 0;
  }
  if (DAT_0075cf00 == 0) {
    if ((DAT_0075cf94 != 0) && (DAT_0075cf84 == 0)) {
      FUN_00599d50(0);
    }
    if ((DAT_0075cf98 != 0) && (DAT_0075cf88 == 0)) {
      FUN_00599d50(0);
    }
    if ((DAT_0075cf9c != 0) && (DAT_0075cf8c == 0)) {
      FUN_00599d50(0);
    }
    if ((DAT_0075cfa0 != 0) && (DAT_0075cf90 == 0)) {
      FUN_00599d50(0);
    }
    if (DAT_0075cf00 != 0) goto LAB_0054c5ec;
    bVar2 = false;
    if ((DAT_0075cf74 == 0) && (iVar7 != 0)) {
      bVar2 = true;
    }
    if ((DAT_0075cf38 == 3) && (DAT_0075cf8c == 0)) {
      bVar2 = true;
    }
    if (DAT_0075cf84 != DAT_0075cf94) {
      if (bVar2) {
        DAT_0075cf38 = 1;
      }
      DAT_0075cf80 = 1;
    }
    if (DAT_0075cf88 != DAT_0075cf98) {
      if (bVar2) {
        DAT_0075cf38 = 2;
      }
      DAT_0075cf80 = 1;
    }
    if (DAT_0075cf8c != DAT_0075cf9c) {
      if (bVar2) {
        DAT_0075cf38 = 3;
      }
      DAT_0075cf80 = 1;
    }
    if (DAT_0075cf90 != DAT_0075cfa0) {
      if (bVar2) {
        DAT_0075cf38 = 4;
      }
      goto LAB_0054c5f6;
    }
  }
  else {
LAB_0054c5ec:
    DAT_0075cf38 = DAT_0075cf04;
LAB_0054c5f6:
    DAT_0075cf80 = 1;
  }
  DAT_0075cf94 = DAT_0075cf84;
  DAT_0075cf98 = DAT_0075cf88;
  DAT_0075cfa0 = DAT_0075cf90;
  DAT_0075cf74 = iVar7;
  DAT_0075cf9c = DAT_0075cf8c;
  if ((DAT_0075cf00 == 0) || (DAT_0075cf04 != 0)) {
    if (DAT_0075cf8c != 0) goto LAB_0054c674;
  }
  else {
    DAT_0075cf38 = 3;
  }
  _DAT_0075cf58 = 0x10;
  _DAT_0075cf68 = FUN_00569130(0x10);
LAB_0054c674:
  if (DAT_0075cf80 != 0) {
    FUN_0054c210();
    FUN_0054c070();
    iVar8 = 0;
    do {
      iVar6 = DAT_0075cf84;
      if ((((iVar8 != 0) && (iVar6 = DAT_0075cf88, iVar8 != 1)) &&
          (iVar6 = DAT_0075cf8c, iVar8 != 2)) && (iVar6 = iStack_4, iVar8 == 3)) {
        iVar6 = DAT_0075cf90;
      }
      if (iVar6 != 0) {
        uVar4 = FUN_00526960(0);
        uVar4 = FUN_0054c150(uVar4);
        uVar5 = FUN_00526960();
        (&DAT_0075cf50)[iVar8] = uVar5;
        (&DAT_0075cf60)[iVar8] = uVar4;
      }
      iVar8 = iVar8 + 1;
      iStack_4 = iVar6;
    } while (iVar8 < 4);
    DAT_0075cf80 = 0;
  }
  iVar8 = DAT_0075cf38;
  iVar1 = *(int *)(*(int *)(iVar1 + 0xc) + DAT_0075cf38 * 4);
  iVar6 = FUN_0053dee0();
  if (iVar6 == 0) {
    if (iVar1 == 0) {
      FUN_00506be0(0,0);
    }
    else if (iVar7 != iVar8) {
      fVar3 = _DAT_006ece68;
      if (_DAT_006ece68 <= 0.0) {
        fVar3 = 0.0001;
      }
      _DAT_0075cfa4 = fVar3 + _DAT_0075cfa4;
      if (_DAT_0076eb48 + _DAT_0076eb44 < _DAT_0075cfa4) {
        _DAT_0075cfa4 = 0.0;
        FUN_00506be0(iVar8,0);
      }
    }
  }
  if (DAT_0075cf44 != 0) {
    DAT_0075cf44 = 0;
    iVar7 = 0;
    while ((&DAT_0075cf20)[iVar7] != iVar8) {
      iVar7 = iVar7 + 1;
      if (3 < iVar7) {
        _DAT_0075cf7c = 0;
        DAT_0075cf00 = 0;
        return;
      }
    }
    _DAT_0075cf34 = iVar7 + 1;
  }
  _DAT_0075cf7c = 0;
  DAT_0075cf00 = 0;
  return;
}

