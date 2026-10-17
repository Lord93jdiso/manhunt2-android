
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00608730(undefined4 param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  
  FUN_0060cc00(1);
  uVar6 = (DAT_0079d0f8 - DAT_0079d0f4) / 0x18;
  if (uVar6 == 0) goto LAB_006088b4;
  iVar2 = FUN_0060d7d0();
  uVar5 = 0;
  if (DAT_0079d100 == 0) {
    if ((char)param_1 != '\0') {
LAB_006087f4:
      piVar3 = (int *)FUN_0060d520(7,0);
      goto LAB_00608801;
    }
    piVar3 = (int *)FUN_0060d520(0,0);
  }
  else {
    if ((char)param_1 != '\0') goto LAB_006087f4;
    piVar3 = (int *)FUN_0060d520(4,0);
    if (*(int *)(iVar2 + 0x44) == 0xd) {
      fVar1 = (float)*(int *)(DAT_0079d100 + 0x48);
      if (*(int *)(DAT_0079d100 + 0x48) < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      if (_DAT_007604c8 == fVar1) {
        fVar1 = (float)*(int *)(DAT_0079d100 + 0x4c);
        if (*(int *)(DAT_0079d100 + 0x4c) < 0) {
          fVar1 = fVar1 + 4.2949673e+09;
        }
        if (_DAT_007604cc == fVar1) {
          uVar5 = 1;
        }
      }
    }
LAB_00608801:
    (**(code **)(*piVar3 + 0x38))(DAT_0079d100);
    (**(code **)(*piVar3 + 0x3c))(param_1);
  }
  (**(code **)(*piVar3 + 0x2c))(uVar5);
  uVar5 = 1;
  switch(DAT_0079d10c) {
  case 0:
    uVar5 = 2;
    break;
  case 1:
  case 4:
    uVar5 = 4;
    break;
  case 2:
    uVar5 = 5;
    break;
  case 3:
    uVar5 = 6;
    break;
  default:
    goto switchD_00608837_default;
  }
  switch(DAT_0079d10c) {
  case 1:
  case 4:
    uVar6 = (uint)((ulonglong)uVar6 * 0xaaaaaaab >> 0x20);
  case 0:
    uVar6 = uVar6 >> 1;
    break;
  case 2:
  case 3:
    uVar6 = uVar6 - 2;
    break;
  default:
switchD_00608837_default:
    uVar6 = 0;
  }
  piVar4 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar4 + 0x164))(piVar4,0x142);
  piVar4 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar4 + 0x14c))(piVar4,uVar5,uVar6,DAT_0079d0f4,0x18);
  (**(code **)(*piVar3 + 0x30))();
LAB_006088b4:
  _DAT_0079d0e8 = 0;
  FUN_0060cc00(0);
  return;
}

