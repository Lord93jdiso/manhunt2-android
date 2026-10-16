
uint FUN_006151d0(int *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = (int *)thunk_FUN_0041e650();
  uVar2 = (**(code **)(*piVar1 + 0x28))(piVar1,param_1[1],*param_1,param_2,0x80000,3,param_3);
  if (-1 < (int)uVar2) {
    uVar2 = (**(code **)(*piVar1 + 0x28))(piVar1,param_1[1],*param_1,param_2,2,1,0x4b);
    if (((-1 < (int)uVar2) &&
        (((param_2 == 0x15 || (param_2 == 0x16)) &&
         (uVar2 = 0xfffe0200, 0xfffe01ff < (uint)param_1[0x31])))) &&
       (0xfffe01ff < (uint)param_1[0x33])) {
      return CONCAT31(0xfffe02,*param_1 == 1);
    }
  }
  return uVar2 & 0xffffff00;
}

