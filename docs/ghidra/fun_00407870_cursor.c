
void FUN_00407870(void)

{
  char cVar1;
  int iVar2;
  HWND pHVar3;
  DWORD DVar4;
  int *piVar5;
  int nIndex;
  tagRECT *ptVar6;
  tagRECT local_10;
  
  ptVar6 = &local_10;
  cVar1 = FUN_00403fd0();
  if (cVar1 == '\0') {
    cVar1 = thunk_FUN_004c1540();
    if (cVar1 == '\0') {
      thunk_FUN_0043189b();
      cVar1 = thunk_FUN_007a5b90();
      if (cVar1 != '\0') {
        pHVar3 = (HWND)thunk_FUN_007a6b80();
        GetWindowRect(pHVar3,ptVar6);
        ClipCursor(&local_10);
        return;
      }
    }
  }
  else {
    iVar2 = FUN_00404010();
    cVar1 = thunk_FUN_004c1540();
    if ((cVar1 == '\0') && (iVar2 != 0)) {
      thunk_FUN_0043189b();
      cVar1 = thunk_FUN_007a5be0();
      if (cVar1 == '\0') {
        SetCursor((HCURSOR)0x0);
        piVar5 = (int *)FUN_00404010();
      }
      else {
        SetCursor((HCURSOR)0x0);
        nIndex = -0xc;
        pHVar3 = (HWND)thunk_FUN_007a6b80();
        DVar4 = GetClassLongW(pHVar3,nIndex);
        FUN_00403690(iVar2,DVar4,0);
        piVar5 = (int *)FUN_00404010();
      }
      (**(code **)(*piVar5 + 0x30))(piVar5,cVar1 != '\0');
    }
    cVar1 = thunk_FUN_004c1540();
    ptVar6 = &local_10;
    if (cVar1 == '\0') {
      thunk_FUN_0043189b();
      cVar1 = thunk_FUN_007a5b90();
      if (cVar1 != '\0') {
        pHVar3 = (HWND)thunk_FUN_007a6b80();
        GetWindowRect(pHVar3,ptVar6);
        ClipCursor(&local_10);
        return;
      }
    }
  }
  ClipCursor((RECT *)0x0);
  return;
}

