
undefined4 FUN_0040e529(void)

{
  HACCEL hAccTable;
  int iVar1;
  HWND unaff_EBX;
  code *unaff_EBP;
  int iVar2;
  int unaff_retaddr;
  undefined4 uStack00000014;
  HACCEL in_stack_0000001c;
  undefined4 uVar3;
  HWND pHStack_4;
  
  pHStack_4 = (HWND)0x0;
  uStack00000014 = 0;
  (*unaff_EBP)(&stack0x00000010,0,0,0);
  hAccTable = in_stack_0000001c;
  do {
    if (unaff_retaddr == 0x12) {
      if (hAccTable != (HACCEL)0x0) {
        DestroyAcceleratorTable(hAccTable);
      }
      uVar3 = 0;
      thunk_FUN_0043189b(0);
      FUN_004025f0(uVar3);
      return 0;
    }
    iVar2 = 0;
    while (iVar1 = (*unaff_EBP)(&pHStack_4,0,0,0,1), iVar1 != 0) {
      if (((hAccTable == (HACCEL)0x0) || (unaff_EBX == (HWND)0x0)) ||
         (iVar1 = TranslateAcceleratorW(unaff_EBX,hAccTable,(LPMSG)&pHStack_4), iVar1 == 0)) {
        TranslateMessage((MSG *)&pHStack_4);
        DispatchMessageW((MSG *)&pHStack_4);
      }
      iVar2 = iVar2 + 1;
      if ((0x1f < iVar2) || (unaff_retaddr == 0x12)) break;
    }
    FUN_0040d8d0();
  } while( true );
}

