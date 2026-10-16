
undefined4 FUN_004140f0(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_00413ef0();
  if ((cVar1 != '\0') && (DAT_006ddbe4 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00414102. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*DAT_006ddbe4)();
    return uVar2;
  }
  return 0;
}

