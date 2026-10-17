
void __fastcall FUN_00563860(char *param_1)

{
  char cVar1;
  int iVar2;
  
  if ((((DAT_0075b0f4 != 1) && (iVar2 = FUN_004e08d0(), iVar2 == 0)) &&
      (FUN_00549100(), DAT_0075cd2c == 0)) && (DAT_0075c948 == 0)) {
    if (param_1[0xf4] != '\0') {
      if (*param_1 == '\0') {
        FUN_00563590();
      }
      iVar2 = thunk_FUN_004103a7();
      if (iVar2 == 2) {
        if (DAT_0078949c == 0) {
          return;
        }
      }
      else {
        FUN_00547670(0);
      }
      FUN_00562150();
      if ((*(int *)(param_1 + 8) != 0) &&
         ((**(code **)(**(int **)(param_1 + 8) + 4))(), *(int *)(param_1 + 8) != 0)) {
        (**(code **)(**(int **)(param_1 + 8) + 8))();
      }
    }
    if (*param_1 != '\0') {
      FUN_00609600(2,1);
      if (((*(int *)(param_1 + 0x10) != 0) && (*(int *)(param_1 + 0x14) != 0)) &&
         (*(int *)(param_1 + 0x18) != 0)) {
        if ((param_1[0xf4] != '\0') &&
           ((**(code **)**(undefined4 **)(param_1 + 0x10))(), param_1[0xf4] != '\0')) {
          (**(code **)**(undefined4 **)(param_1 + 0x14))();
        }
        cVar1 = FUN_0053ec40();
        if (cVar1 != '\0') {
          (**(code **)**(undefined4 **)(param_1 + 0x18))();
        }
      }
      if (*(int *)(param_1 + 0x20) != 0) {
        FUN_0054fee0();
      }
      if (((*(int *)(param_1 + 0x1c) != 0) && (cVar1 = FUN_0053ec40(), cVar1 != '\0')) &&
         (*(int *)(param_1 + 0x1c) != 0)) {
        (**(code **)**(undefined4 **)(param_1 + 0x1c))();
      }
      FUN_006095b0();
      return;
    }
  }
  return;
}

