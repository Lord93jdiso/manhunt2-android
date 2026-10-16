
void FUN_0040a290(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*param_1 == 0) {
    piVar1 = (int *)thunk_FUN_0041e650();
    (**(code **)(*piVar1 + 0x3c))(piVar1,param_1[1]);
    return;
  }
  thunk_FUN_0042cd4c(0,0);
  iVar2 = thunk_FUN_007a7c40(param_1[1],param_1[3]);
  if (iVar2 == 0) {
    return;
  }
  FUN_004142f0(iVar2 + 0x4c,2);
  return;
}

