
void __thiscall FUN_00559ce0(int param_1,int param_2)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  
  if (DAT_0078949c == 0) {
    if ((param_2 == 1) && (*(char *)(param_1 + 0x69) != '\0')) {
      piVar2 = (int *)(param_1 + 0x34);
      iVar3 = 0xd;
      do {
        if (*piVar2 != 0) {
          (**(code **)(*(int *)*piVar2 + 4))();
        }
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    if (DAT_00789490 == 0) {
      pcVar1 = (char *)FUN_00594d60();
      bVar4 = *pcVar1 == '\0';
    }
    else {
      iVar3 = FUN_005981b0();
      bVar4 = iVar3 == 0;
    }
    if (!bVar4) {
      (**(code **)(**(int **)(param_1 + 100) + 4))();
    }
  }
  return;
}

