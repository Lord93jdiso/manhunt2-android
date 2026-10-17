
int FUN_00608ad0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int local_4;
  
  uVar5 = (DAT_0079d0f8 - DAT_0079d0f4) / 0x18;
  if (uVar5 == 0) {
    return (DAT_0079d0f8 - DAT_0079d0f4) * 0x2aaaaaab;
  }
  FUN_0060d7d0();
  if (DAT_0079d100 == 0) {
    piVar1 = (int *)FUN_0060d520(0,0);
  }
  else {
    FUN_0060b790(2,&local_4);
    piVar1 = (int *)FUN_0060d520(5 - (uint)(local_4 != 0),0);
    (**(code **)(*piVar1 + 0x38))(DAT_0079d100);
  }
  (**(code **)(*piVar1 + 0x2c))(0);
  uVar4 = 1;
  switch(DAT_0079d10c) {
  case 0:
    uVar4 = 2;
    break;
  case 1:
  case 4:
    uVar4 = 4;
    break;
  case 2:
    uVar4 = 5;
    break;
  case 3:
    uVar4 = 6;
    break;
  default:
    goto switchD_00608b65_default;
  }
  switch(DAT_0079d10c) {
  case 1:
  case 4:
    uVar5 = (uint)((ulonglong)uVar5 * 0xaaaaaaab >> 0x20);
  case 0:
    uVar5 = uVar5 >> 1;
    break;
  case 2:
  case 3:
    uVar5 = uVar5 - 2;
    break;
  default:
switchD_00608b65_default:
    uVar5 = 0;
  }
  piVar2 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar2 + 0x164))(piVar2,0x142);
  piVar2 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar2 + 0x14c))(piVar2,uVar4,uVar5,DAT_0079d0f4,0x18);
  iVar3 = (**(code **)(*piVar1 + 0x30))();
  return iVar3;
}

