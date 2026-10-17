
undefined4 __thiscall FUN_005b6a40(int param_1,uint param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((char)param_3 == '\0') && ((*(uint *)(*(int *)(param_1 + 0x1c0) + 0x304) & 0x1000000) == 0))
  {
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x1c0) + 700) + 0x150);
    if ((0x30 < iVar1) && (iVar1 < 0x38)) {
      iVar1 = FUN_00475860();
      if (iVar1 == 0) goto LAB_005b6a9d;
    }
    *(uint *)(param_1 + 0x224) = param_2 & 0xff;
    uVar2 = (**(code **)(**(int **)(param_1 + 0x278) + 0x54))(param_2);
    return uVar2;
  }
LAB_005b6a9d:
  if (param_4 != '\0') {
    return 0;
  }
  uVar2 = FUN_005276a0(param_2,param_3,0);
  return uVar2;
}

