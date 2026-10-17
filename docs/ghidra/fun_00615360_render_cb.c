
void FUN_00615360(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 0xa4))(param_1);
  if (iVar2 < 0) {
    (**(code **)(*param_1 + 0xa8))(param_1);
  }
  else {
    FUN_004df5a0();
    (**(code **)(*param_1 + 0xa8))(param_1);
  }
  cVar1 = FUN_004b0340();
  if (cVar1 == '\0') {
    FUN_00606cc0();
  }
  thunk_FUN_007d26c0();
  return;
}

