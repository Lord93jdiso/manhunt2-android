
undefined4 FUN_00404cd0(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar2 = *piVar1;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (iVar2 == 0) {
    iVar2 = FUN_004140f0(0x20);
    if (iVar2 == 0) {
      return 0x80040901;
    }
    piVar1 = (int *)thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    *piVar1 = iVar2;
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
  }
  return 0;
}

