
void FUN_0040d5c0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  float10 fVar7;
  ulonglong uVar8;
  double dVar9;
  undefined8 uVar10;
  float local_54;
  double local_50;
  undefined8 local_48;
  
  iVar2 = thunk_FUN_007a6a80();
  if (iVar2 == 0) {
    return;
  }
  piVar3 = (int *)thunk_FUN_00435f90();
  if (piVar3 == (int *)0x0) {
    return;
  }
  cVar1 = thunk_FUN_004af140();
  if ((cVar1 == '\0') && (cVar1 = thunk_FUN_007a6ce0(), cVar1 != '\0')) {
    thunk_FUN_0043189b();
    cVar1 = thunk_FUN_007a5600();
    if (cVar1 != '\0') goto LAB_0040d60c;
  }
  else {
LAB_0040d60c:
    Sleep(0x32);
  }
  thunk_FUN_00416d1c();
  FUN_00414700();
  thunk_FUN_0043189b();
  cVar1 = thunk_FUN_00495510();
  if (cVar1 != '\0') {
    thunk_FUN_0043189b();
    fVar7 = (float10)FUN_00402270();
    local_54 = (float)fVar7;
    fVar7 = (float10)FUN_00404250();
    local_50 = (double)(fVar7 + (float10)local_54);
  }
  dVar9 = local_50;
  thunk_FUN_0043189b(local_50);
  FUN_00401c10(dVar9);
  thunk_FUN_0043189b(local_48);
  FUN_00401c50(local_48);
  thunk_FUN_0043189b();
  FUN_00401c90();
  FUN_00406030();
  FUN_00407c10();
  FUN_00407560();
  iVar4 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  pcVar6 = *(code **)(iVar4 + 0x360);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (pcVar6 != (code *)0x0) {
    thunk_FUN_0043189b();
    uVar5 = thunk_FUN_007a6480();
    (*pcVar6)(local_50,local_54,uVar5);
    iVar2 = thunk_FUN_007a6a80();
    if (iVar2 == 0) {
      return;
    }
  }
  thunk_FUN_0043189b();
  cVar1 = thunk_FUN_007a5ea0();
  if (cVar1 == '\0') {
    thunk_FUN_0043189b();
    pcVar6 = (code *)thunk_FUN_00464030();
    if (pcVar6 != (code *)0x0) {
      thunk_FUN_0043189b();
      cVar1 = thunk_FUN_007a5600();
      if (cVar1 == '\0') {
        thunk_FUN_0043189b();
        uVar5 = thunk_FUN_007a6660();
        (*pcVar6)(iVar2,local_50,local_54,uVar5);
        iVar2 = thunk_FUN_007a6a80();
        if (iVar2 == 0) {
          return;
        }
      }
    }
  }
  thunk_FUN_0043189b();
  cVar1 = thunk_FUN_007a5600();
  if (cVar1 == '\0') {
    thunk_FUN_0043189b();
    iVar2 = thunk_FUN_004a1020();
    uVar5 = *(undefined4 *)(iVar2 + 0x54);
  }
  else {
    uVar5 = 1;
  }
  thunk_FUN_0043189b();
  iVar2 = thunk_FUN_004a1020();
  uVar10 = CONCAT44(uVar5,*(undefined4 *)(iVar2 + 0x50));
  iVar2 = (**(code **)(*piVar3 + 0x20))();
  if (iVar2 == 0x87a0001) {
    uVar8 = CONCAT44(piVar3,1);
  }
  else {
    if (iVar2 == -0x7785fff9) {
      iVar2 = FUN_00409a90();
      if (iVar2 < 0) {
        if ((iVar2 == -0x7ffbf6f8) || (iVar2 == -0x7ffbf6fd)) {
          thunk_FUN_00403011(iVar2,piVar3,uVar10);
          FUN_0040ae00(0);
          return;
        }
        thunk_FUN_0043189b();
        uVar5 = thunk_FUN_004a1020();
        iVar2 = FUN_0040af80(uVar5,0,0,1,0);
        if (iVar2 < 0) {
          FUN_0040ae00(0);
          return;
        }
      }
      goto LAB_0040d877;
    }
    if (iVar2 == -0x7785fffb) {
      iVar2 = FUN_0040c160();
      if (iVar2 < 0) {
        thunk_FUN_00403011(0x8004090a,piVar3,uVar10);
        FUN_0040ae00(0);
        return;
      }
      goto LAB_0040d877;
    }
    if (iVar2 < 0) goto LAB_0040d877;
    thunk_FUN_0043189b();
    uVar8 = CONCAT44(piVar3,0x40d865);
    cVar1 = thunk_FUN_007a5600();
    if (cVar1 == '\0') goto LAB_0040d877;
    uVar8 = uVar8 & 0xffffffff00000000;
  }
  thunk_FUN_0043189b(uVar8);
  thunk_FUN_00401597();
LAB_0040d877:
  thunk_FUN_0043189b();
  iVar2 = thunk_FUN_004c9650();
  thunk_FUN_0043189b(iVar2 + 1);
  FUN_00401dd0();
  FUN_00406480();
  FUN_004068d0();
  thunk_FUN_0043189b();
  iVar4 = thunk_FUN_00410700();
  if (iVar4 != 0) {
    thunk_FUN_0043189b();
    iVar4 = thunk_FUN_00410700();
    if (iVar4 < iVar2 + 1) {
      FUN_0040ae00(0);
    }
  }
  return;
}

