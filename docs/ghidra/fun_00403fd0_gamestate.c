
void FUN_00403fd0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  uVar1 = *(undefined4 *)(iVar2 + 8);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  FUN_004034b0(uVar1);
  return;
}

