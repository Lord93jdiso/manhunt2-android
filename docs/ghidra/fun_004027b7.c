
void __thiscall FUN_004027b7(int param_1,undefined1 param_2)

{
  bool in_ZF;
  
  if (!in_ZF) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  *(undefined1 *)(param_1 + 0x314) = param_2;
  if (DAT_00685000 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x004027e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    return;
  }
  return;
}

