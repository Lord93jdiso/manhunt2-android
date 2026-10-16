
void FUN_00405480(void)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_00404010();
  if (iVar3 != 0) {
    iVar3 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    *(undefined1 *)(iVar3 + 0x305) = 1;
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    iVar3 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    cVar1 = *(char *)(iVar3 + 0x304);
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    if (cVar1 == '\x01') {
      iVar3 = thunk_FUN_0043189b();
      if (DAT_00685000 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
      }
      pcVar2 = *(code **)(iVar3 + 900);
      if (DAT_00685000 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
      }
      if (pcVar2 != (code *)0x0) {
        thunk_FUN_0043189b();
        uVar4 = thunk_FUN_007a6550();
        (*pcVar2)(uVar4);
      }
      uVar4 = 0;
      thunk_FUN_0043189b(0);
      FUN_004026b0(uVar4);
    }
    iVar3 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    cVar1 = *(char *)(iVar3 + 0x303);
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    if (cVar1 == '\x01') {
      iVar3 = thunk_FUN_0043189b();
      if (DAT_00685000 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
      }
      pcVar2 = *(code **)(iVar3 + 0x388);
      if (DAT_00685000 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
      }
      if (pcVar2 != (code *)0x0) {
        thunk_FUN_0043189b();
        uVar4 = thunk_FUN_004a3660();
        (*pcVar2)(uVar4);
      }
      uVar4 = 0;
      thunk_FUN_0043189b(0);
      FUN_00402630(uVar4);
    }
    thunk_FUN_0043189b();
    thunk_FUN_004055e7();
    return;
  }
  return;
}

