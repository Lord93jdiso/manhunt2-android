
void FUN_004b03c0(void)

{
  int *piVar1;
  int *piVar2;
  undefined1 local_4 [4];
  
  if (((DAT_007604e4 < 1) && (DAT_007604f8 == '\0')) && (DAT_006ec990 != 0xc)) {
    FUN_00606c90();
    FUN_005ca650();
  }
  else {
    piVar2 = (int *)thunk_FUN_00404010();
    (**(code **)(*piVar2 + 0x48))(piVar2,0,0,0,local_4);
    piVar1 = (int *)thunk_FUN_00404010();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,piVar2);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar2 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar2 + 0xac))(piVar2,0,0,7,0,0x3f800000,0);
  switch(DAT_006ec990) {
  case 1:
  case 8:
    FUN_00546130();
    return;
  case 2:
    FUN_0056e320();
    return;
  case 4:
    FUN_005c5c20(DAT_00789488,0);
    break;
  case 0xc:
    FUN_00613e80();
    return;
  }
  return;
}

