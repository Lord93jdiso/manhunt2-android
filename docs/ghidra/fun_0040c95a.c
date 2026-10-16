
undefined4 FUN_0040c95a(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  
  cVar1 = thunk_FUN_007a6ce0();
  if (cVar1 != '\0') {
    cVar1 = thunk_FUN_004c1540();
    if (cVar1 == '\0') {
      cVar1 = FUN_00403fd0();
      if (cVar1 == '\0') {
        thunk_FUN_0043189b();
        cVar1 = thunk_FUN_007a5be0();
        if (cVar1 == '\0') {
          SetCursor((HCURSOR)0x0);
          return 1;
        }
      }
      else {
        piVar2 = (int *)FUN_00404010();
        if (piVar2 != (int *)0x0) {
          thunk_FUN_0043189b();
          cVar1 = thunk_FUN_007a5be0();
          if (cVar1 != '\0') {
            (**(code **)(*piVar2 + 0x30))(piVar2,1);
            uVar3 = FUN_0041687d();
            return uVar3;
          }
        }
      }
      return 1;
    }
  }
  thunk_FUN_0043189b();
  uVar3 = FUN_0041c926();
  return uVar3;
}

