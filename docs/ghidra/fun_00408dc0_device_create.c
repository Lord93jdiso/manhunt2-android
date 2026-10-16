
int FUN_00408dc0(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  undefined4 local_4;
  
  local_4 = 0;
  iVar1 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar1 = *(int *)(iVar1 + 8);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)thunk_FUN_0041e650();
    param_1 = *(int **)(iVar1 + 0x10);
    iVar4 = *piVar2;
    uVar3 = thunk_FUN_007a6af0(param_1,iVar1 + 0x14,&local_4);
    iVar4 = (**(code **)(iVar4 + 0x40))
                      (piVar2,*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),uVar3);
    if (iVar4 == -0x7789f798) {
      uVar3 = 1;
      thunk_FUN_0043189b(1);
      thunk_FUN_004027b7(uVar3);
      return 0;
    }
    if (iVar4 < 0) {
      return -0x7ffbf6fb;
    }
  }
  else {
    (**(code **)(*param_1 + 4))(param_1);
  }
  iVar4 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  *(int **)(iVar4 + 4) = param_1;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (*(int *)(iVar1 + 8) == 2) {
    iVar4 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    iVar4 = *(int *)(iVar4 + 0x2f8);
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    if (iVar4 != 0) goto LAB_00408eda;
    uVar3 = 10;
  }
  else {
LAB_00408eda:
    if (*(int *)(iVar1 + 8) != 1) goto LAB_00408f20;
    iVar4 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    iVar4 = *(int *)(iVar4 + 0x2f8);
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    if (iVar4 != 10) goto LAB_00408f20;
    uVar3 = 0;
  }
  thunk_FUN_0043189b(uVar3);
  thunk_FUN_00402337(uVar3);
LAB_00408f20:
  FUN_004076b0();
  FUN_00407870();
  iVar4 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  piVar2 = (int *)FUN_00404010();
  (**(code **)(*piVar2 + 0x1c))(piVar2,iVar4 + 0x2c);
  thunk_FUN_004ae6e0(0);
  iVar4 = thunk_FUN_007a7a10(*(undefined4 *)(iVar1 + 4));
  FUN_00407de0(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x10),iVar4 + 4);
  uVar3 = thunk_FUN_0048d1d0();
  iVar1 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  *(undefined1 *)(iVar1 + 0x305) = 1;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar1 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  pcVar6 = *(code **)(iVar1 + 0x37c);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar1 = 0;
  if (pcVar6 != (code *)0x0) {
    iVar1 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    uVar5 = *(undefined4 *)(iVar1 + 0x3c8);
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    uVar5 = FUN_00404010(uVar3,uVar5);
    iVar1 = (*pcVar6)(uVar5);
  }
  iVar4 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  *(undefined1 *)(iVar4 + 0x305) = 0;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar4 = FUN_00404010();
  if (iVar4 != 0) {
    if (iVar1 < 0) {
      return (uint)(iVar1 != -0x7ffbf6fd) * 4 + -0x7ffbf6fd;
    }
    uVar5 = 1;
    thunk_FUN_0043189b(1);
    FUN_00402630(uVar5);
    uVar5 = 1;
    thunk_FUN_0043189b(1);
    FUN_004025b0(uVar5);
    thunk_FUN_0043189b();
    pcVar6 = (code *)thunk_FUN_007a62b0();
    iVar1 = 0;
    if (pcVar6 != (code *)0x0) {
      thunk_FUN_0043189b();
      uVar5 = thunk_FUN_007a64f0();
      uVar3 = FUN_00404010(uVar3,uVar5);
      iVar1 = (*pcVar6)(uVar3);
    }
    uVar3 = 0;
    thunk_FUN_0043189b(0);
    FUN_004025b0(uVar3);
    iVar4 = FUN_00404010();
    if (iVar4 != 0) {
      if (iVar1 < 0) {
        return (-(uint)(iVar1 != -0x7ffbf6fd) & 5) + 0x80040903;
      }
      uVar3 = 1;
      thunk_FUN_0043189b(1);
      FUN_004026b0(uVar3);
      return 0;
    }
  }
  return -0x7fffbffb;
}

