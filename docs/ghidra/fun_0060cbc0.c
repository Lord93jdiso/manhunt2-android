
void FUN_0060cbc0(undefined4 param_1)

{
  int *piVar1;
  
  FUN_0060bf50(param_1,&DAT_0079e3f8);
  piVar1 = (int *)FUN_00404010();
  (**(code **)(*piVar1 + 0xb0))(piVar1,3,&DAT_0079e3f8);
  D3DXMatrixMultiply(&DAT_0079e4f8,&DAT_0079d678,&DAT_0079e3f8);
  return;
}

