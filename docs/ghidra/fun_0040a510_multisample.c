
bool FUN_0040a510(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_c0 [24];
  undefined1 local_60 [96];
  
  piVar2 = (int *)thunk_FUN_0041e650();
  if (piVar2 != (int *)0x0) {
    puVar3 = (undefined4 *)thunk_FUN_007a6a10();
    puVar4 = (undefined4 *)thunk_FUN_007a6f00(local_60);
    uVar1 = *puVar3;
    puVar6 = local_c0;
    for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    iVar5 = (**(code **)(*piVar2 + 0x2c))(piVar2,puVar3[1],uVar1,local_c0[3],0,param_1,0);
    return -1 < iVar5;
  }
  return false;
}

