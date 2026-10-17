
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0055a287(void)

{
  bool in_ZF;
  
  if (in_ZF) {
    _DAT_0075f0c4 = _DAT_0075f0c4 | 1;
    FUN_0055a240();
    _atexit((_func_4879 *)&LAB_00636840);
  }
  if (DAT_0075f0c0 == '\0') {
    DAT_0075f0c0 = '\x01';
    FUN_00559640();
  }
  return &DAT_0075f058;
}

