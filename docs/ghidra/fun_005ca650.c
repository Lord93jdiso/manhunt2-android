
undefined4 FUN_005ca650(void)

{
  int *piVar1;
  int *piVar2;
  undefined1 local_4 [4];
  
  piVar1 = (int *)FUN_0045ec60();
  (**(code **)(*piVar1 + 0x48))(piVar1,0,local_4);
  piVar2 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar2 + 0x94))(piVar2,0,piVar1);
  (**(code **)(*piVar2 + 8))(piVar2);
  return 1;
}

