
void FUN_0053d6a0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 local_4 [4];
  
  if ((DAT_007604e4 < 1) && (DAT_007604f8 == '\0')) {
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
  uVar7 = 0;
  uVar6 = 7;
  fVar5 = 0.0;
  fVar4 = 0.0;
  (**(code **)(*piVar2 + 0xac))(piVar2,0,0,7,0,0x3f800000,0);
  piVar2 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar2 + 0xa4))(piVar2);
  iVar3 = FUN_005b80d0(1);
  if (iVar3 != 0) {
    thunk_FUN_0042041b(0.5 - fVar4 * 0.5,0.5 - fVar5 * 0.5,fVar4,fVar5,0xff,0xff,0xff,uVar6,uVar7,0,
                       0,0);
    FUN_005b7720();
  }
  FUN_00607030();
  return;
}

