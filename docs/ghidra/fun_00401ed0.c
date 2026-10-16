
undefined1 __fastcall thunk_FUN_007a58f0(int param_1)

{
  undefined1 uVar1;
  
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  uVar1 = *(undefined1 *)(param_1 + 0x2b8);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  return uVar1;
}

