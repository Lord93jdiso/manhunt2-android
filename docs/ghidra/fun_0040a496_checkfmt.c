
bool FUN_0040a496(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 in_stack_000000c4;
  undefined4 in_stack_000000c8;
  
  piVar4 = (int *)thunk_FUN_0041e650();
  if (piVar4 != (int *)0x0) {
    puVar5 = (undefined4 *)thunk_FUN_007a6a10();
    puVar6 = (undefined4 *)thunk_FUN_007a6f00(&stack0x00000060);
    uVar3 = in_stack_000000c8;
    uVar2 = in_stack_000000c4;
    uVar1 = *puVar5;
    puVar8 = (undefined4 *)register0x00000010;
    for (iVar7 = 0x18; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    iVar7 = (**(code **)(*piVar4 + 0x28))(piVar4,puVar5[1],uVar1,param_3,0,uVar2,uVar3);
    return -1 < iVar7;
  }
  return false;
}

