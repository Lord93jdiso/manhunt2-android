
undefined1 * __fastcall FUN_00561b00(undefined1 *param_1)

{
  int iVar1;
  
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  param_1[0xf4] = 1;
  iVar1 = 0x31;
  do {
    FUN_00561a90();
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  FUN_005fda60();
  *(undefined4 *)(param_1 + 0x5b4) = 0;
  *(undefined4 *)(param_1 + 0x5b8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x5bc) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x5c4) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x5c8) = 0;
  return param_1;
}

