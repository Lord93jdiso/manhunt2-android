
void FUN_005b6e30(void)

{
  undefined4 *puVar1;
  int *piVar2;
  
  if (DAT_0077b660 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
    puVar1 = (undefined4 *)0x0;
    DAT_0077b668 = puVar1;
  }
  else {
    piVar2 = (int *)*DAT_0077b660;
    puVar1 = (undefined4 *)DAT_0077b660[2];
    DAT_0077b668 = puVar1;
  }
  while (piVar2 != (int *)0x0) {
    if (piVar2[0x6e] != 0x1001) {
      (**(code **)(*piVar2 + 0xac))();
      puVar1 = DAT_0077b668;
    }
    if (puVar1 == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)*puVar1;
      puVar1 = (undefined4 *)puVar1[2];
      DAT_0077b668 = puVar1;
    }
  }
  return;
}

