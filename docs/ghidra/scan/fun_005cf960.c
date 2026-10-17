
undefined1 __thiscall FUN_005cf960(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  
  FUN_005cd360();
  iVar1 = *(int *)(param_1 + 0x40);
  while( true ) {
    if (iVar1 == 0) {
      return 1;
    }
    cVar2 = (*param_2)(iVar1,param_3);
    if (cVar2 == '\0') break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return 0;
}

