
void __fastcall FUN_00563590(undefined1 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + 0x28);
  for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  iVar2 = FUN_00580ed0(0x38);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00554f30();
  }
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  FUN_00554f70(0,0x3f800000);
  FUN_0054fe80(0x3f4ccccd,0x3f800000);
  FUN_00554f90(8);
  FUN_005df1f0(0x14);
  FUN_00554fc0(1);
  FUN_00554fd0(1);
  iVar2 = FUN_00580ed0(0x38);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00554f30();
  }
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  FUN_00554f70(0,0x3f800000);
  FUN_0054fe80(0x3f733333,0x3f800000);
  FUN_00554f90(8);
  FUN_005df1f0(0x18);
  FUN_00554fc0(1);
  FUN_00554fd0(1);
  iVar2 = FUN_00580ed0(0x38);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00554f30();
  }
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  FUN_00554f70(0,0x3f800000);
  FUN_0054fe80(0,0x3f800000);
  FUN_00554f90(8);
  FUN_005df1f0(0x1e);
  FUN_00554fc0(0);
  FUN_00554fd0(1);
  FUN_00554fe0(2,2);
  iVar2 = FUN_00580ed0(0x38);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00554f30();
  }
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  FUN_00554f70(0,0x3f800000);
  FUN_0054fe80(0x3f733333,0x3f800000);
  FUN_00554f90(8);
  FUN_005df1f0(0x18);
  FUN_00554fc0(1);
  FUN_00554fd0(0);
  iVar2 = FUN_00580ed0(0x30);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0054fe50();
  }
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  FUN_005180f0(*(undefined4 *)(param_1 + 0x1c));
  FUN_0054fe80(0,0x3f800000);
  FUN_0054fea0(0x3d4ccccd);
  FUN_0054fec0(0x3f800000);
  FUN_0054feb0(0x40000000);
  FUN_0054fed0(0x42480000);
  FUN_00561c00();
  FUN_005476b0(0xffffffff);
  *param_1 = 1;
  FUN_00562f60();
  FUN_0056f380();
  DAT_0076be68 = 0;
  DAT_0076be64 = 0;
  DAT_0076be6c = 0;
  if (DAT_0076b308 == 0) {
    thunk_FUN_0042e7e8(1);
  }
  FUN_005626e0();
  FUN_005625b0(1);
  return;
}

