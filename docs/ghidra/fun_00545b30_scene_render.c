
void FUN_00545b30(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_34 = 0;
  local_38 = 0;
  local_3c = 0;
  local_40 = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0x3f800000;
  FUN_0057e390();
  thunk_FUN_0041d879(&local_40,0);
  if (param_2 == 0) {
    iVar2 = thunk_FUN_004103a7();
    if (iVar2 == 1) goto LAB_00545bb1;
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  FUN_0053dec0(uVar3);
LAB_00545bb1:
  FUN_005678b0(param_1);
  if (DAT_0075b62c == 0) {
    if (param_2 == 0) {
      FUN_005b80d0(1);
    }
    thunk_FUN_0060bfc0(1,0);
    FUN_00545270(param_1,param_2);
    if (param_2 == 0) {
      FUN_005b7720();
      cVar1 = FUN_0053f360();
      if (cVar1 != '\0') {
        FUN_00589710(DAT_0075b6f0);
      }
    }
  }
  return;
}

