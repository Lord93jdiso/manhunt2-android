
undefined4 __fastcall FUN_00464030(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  uVar1 = *(undefined4 *)(param_1 + 0x3a4);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  return uVar1;
}

