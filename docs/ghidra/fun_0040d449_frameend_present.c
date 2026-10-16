
void FUN_0040d449(void)

{
  char cVar1;
  int in_EAX;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int *unaff_EBP;
  code *unaff_EDI;
  bool in_ZF;
  undefined4 uVar5;
  
  if (!in_ZF) {
    (*unaff_EDI)(&DAT_006ddba0);
  }
  cVar1 = *(char *)(in_EAX + 0x309);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 == '\0') {
    thunk_FUN_0043189b();
    pcVar2 = (code *)thunk_FUN_00463e50();
    if (pcVar2 != (code *)0x0) {
      thunk_FUN_0043189b();
      thunk_FUN_007a65a0();
      (*pcVar2)();
      unaff_EBP = (int *)FUN_00404010();
      if (unaff_EBP == (int *)0x0) {
        return;
      }
    }
    iVar3 = (**(code **)(*unaff_EBP + 0x44))(unaff_EBP,0,0,0,0);
    if ((iVar3 < 0) && ((iVar3 == -0x7789f798 || (iVar3 == -0x7789f7d9)))) {
      uVar5 = 1;
      thunk_FUN_0043189b(1);
      thunk_FUN_004027b7(uVar5);
    }
  }
  iVar3 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    (*unaff_EDI)(&DAT_006ddba0);
  }
  iVar3 = *(int *)(iVar3 + 0x2b0);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar3 = iVar3 + 1;
  iVar4 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  *(int *)(iVar4 + 0x2b0) = iVar3;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar4 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar4 = *(int *)(iVar4 + 0x34c);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (iVar4 != 0) {
    thunk_FUN_0043189b();
    iVar4 = thunk_FUN_00410700();
    if (iVar4 < iVar3) {
      FUN_0040ae00(0);
    }
  }
  return;
}

