
int FUN_0040e3a0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_ESI;
  undefined4 uVar4;
  
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x305);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 != '\0') {
LAB_0040e5d9:
    iVar2 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    iVar2 = *(int *)(iVar2 + 0x2f8);
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    if (iVar2 != 0) {
      iVar2 = thunk_FUN_0043189b();
      if (DAT_00685000 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
      }
      iVar2 = *(int *)(iVar2 + 0x2f8);
      if (DAT_00685000 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
      }
      if (iVar2 != 10) {
        return -0x7fffbffb;
      }
    }
    iVar2 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    *(undefined4 *)(iVar2 + 0x2f8) = 1;
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    return -0x7fffbffb;
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x306);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 != '\0') goto LAB_0040e5d9;
  uVar4 = 1;
  thunk_FUN_0043189b(1);
  FUN_004025f0(uVar4);
  thunk_FUN_0043189b();
  cVar1 = thunk_FUN_007a5d00();
  if (cVar1 == '\0') {
    thunk_FUN_0043189b();
    cVar1 = thunk_FUN_007a5dd0();
    if (cVar1 != '\0') goto LAB_0040e44e;
    iVar2 = FUN_0040dc80(1,0,0,0x3c,0);
    if (iVar2 < 0) {
      thunk_FUN_0043189b();
      iVar3 = thunk_FUN_004af1d0();
      if (iVar3 != 0) {
        thunk_FUN_0043189b();
        iVar3 = thunk_FUN_004af1d0();
        if (iVar3 != 10) {
          return iVar2;
        }
      }
      uVar4 = 1;
      thunk_FUN_0043189b(1);
      thunk_FUN_00402337(uVar4);
      return iVar2;
    }
  }
  FUN_00408620();
  thunk_FUN_0043189b();
  cVar1 = thunk_FUN_007a5c40();
  if (cVar1 != '\0') {
    thunk_FUN_0043189b();
    cVar1 = thunk_FUN_007a5ca0();
    if (cVar1 != '\0') {
      thunk_FUN_0043189b();
      cVar1 = thunk_FUN_007a5d00();
      if (cVar1 != '\0') {
        iVar2 = FUN_0042b096(unaff_ESI);
        return iVar2;
      }
    }
  }
LAB_0040e44e:
  thunk_FUN_0043189b();
  iVar2 = thunk_FUN_004af1d0();
  if (iVar2 != 0) {
    thunk_FUN_0043189b();
    iVar2 = thunk_FUN_004af1d0();
    if (iVar2 != 10) {
      return -0x7fffbffb;
    }
  }
  uVar4 = 1;
  thunk_FUN_0043189b(1);
  thunk_FUN_00402337(uVar4);
  return -0x7fffbffb;
}

