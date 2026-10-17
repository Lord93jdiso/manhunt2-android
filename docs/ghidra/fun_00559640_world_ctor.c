
void __fastcall FUN_00559640(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_1 = 0;
  iVar1 = FUN_00580ed0(0x58);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00556ba0(0,0,0,0,0xff,0xff,0xff);
  }
  param_1[3] = uVar2;
  iVar1 = FUN_00580ed0(0x54);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00556c00(0,0,0,0,0xa2,0x96,0x65);
  }
  param_1[4] = uVar2;
  iVar1 = FUN_00580ed0(0x54);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00565fe0(0,0,0,0,0xa2,0x96,0x65);
  }
  param_1[2] = uVar2;
  iVar1 = FUN_00580ed0(0xfc);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0055b6e0(0,0,0,0);
  }
  param_1[1] = uVar2;
  iVar1 = FUN_00580ed0(0x54);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00556cd0();
  }
  param_1[8] = uVar2;
  iVar1 = FUN_00580ed0(0x54);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00556e30();
  }
  param_1[9] = uVar2;
  iVar1 = FUN_00580ed0(0x58);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00556660(0,0,0,0,0x53,0x6e,0x2a);
  }
  param_1[5] = iVar1;
  *(undefined4 *)(iVar1 + 0xc) = 5;
  iVar1 = FUN_00580ed0(0x58);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00556660(0,0,0,0,0x53,0x6e,0x2a);
  }
  param_1[6] = iVar1;
  *(undefined4 *)(iVar1 + 0xc) = 6;
  iVar1 = FUN_00580ed0(0xf8);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0055aff0();
  }
  param_1[10] = uVar2;
  iVar1 = FUN_00580ed0(0x94);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005557d0();
  }
  param_1[0xb] = uVar2;
  iVar1 = FUN_00580ed0(0xdc);
  if (iVar1 != 0) {
    uVar2 = FUN_00557fd0(0,0,0,0,0xa2,0x96,0x65);
    param_1[0xc] = uVar2;
    return;
  }
  param_1[0xc] = 0;
  return;
}

