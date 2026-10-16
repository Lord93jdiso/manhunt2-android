
undefined4 FUN_0041e650(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  FUN_00404cd0();
  puVar2 = (undefined4 *)thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  uVar1 = *puVar2;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  return uVar1;
}

