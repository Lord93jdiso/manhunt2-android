
undefined4 __fastcall FUN_005b8dc0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar1 + 0xbc))(piVar1,param_1);
  piVar1 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar1 + 0x9c))(piVar1,0);
  piVar1 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar1 + 0x94))(piVar1,0,*(undefined4 *)(param_1 + 0x18));
  piVar1 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar1 + 0x9c))(piVar1,*(undefined4 *)(param_1 + 0x1c));
  (**(code **)(**(int **)(param_1 + 0x18) + 8))(*(int **)(param_1 + 0x18));
  (**(code **)(**(int **)(param_1 + 0x1c) + 8))(*(int **)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  return 1;
}

