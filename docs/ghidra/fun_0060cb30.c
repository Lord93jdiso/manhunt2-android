
void FUN_0060cb30(undefined4 param_1)

{
  int *piVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if (DAT_0079d672 == '\0') {
    FUN_0060bf50(param_1,&DAT_0079d678);
    D3DXMatrixInverse(&DAT_0079e438,0,&DAT_0079d678);
    D3DXMatrixTranspose(&DAT_0079e478,&DAT_0079e438);
    D3DXMatrixMultiply(&DAT_0079e4f8,&DAT_0079d678,&DAT_0079e3f8);
    puVar3 = &DAT_0079e438;
    puVar2 = &DAT_0079d678;
    FUN_0060d7d0(&DAT_0079d678,&DAT_0079e438);
    FUN_00426330();
    FUN_00607b60(puVar2,puVar3);
    piVar1 = (int *)FUN_00404010();
    (**(code **)(*piVar1 + 0xb0))(piVar1,2,&DAT_0079d678);
  }
  return;
}

