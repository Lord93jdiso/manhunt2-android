
int FUN_0040af80(int *param_1,int param_2,int param_3,char param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  undefined4 uVar6;
  LONG LVar7;
  HWND pHVar8;
  int iVar9;
  HMENU pHVar10;
  uint uVar11;
  WINDOWPLACEMENT *pWVar12;
  HWND pHVar13;
  BOOL BVar14;
  DWORD DVar15;
  undefined4 *puVar16;
  int *piVar17;
  undefined4 *puVar18;
  LONG Y;
  int iVar19;
  UINT UVar20;
  tagRECT *ptVar21;
  undefined4 uVar22;
  EXECUTION_STATE esFlags;
  tagRECT tStack_150;
  char cStack_13e;
  char cStack_13d;
  uint uStack_13c;
  int local_138;
  undefined4 auStack_134 [5];
  int iStack_120;
  int iStack_11c;
  int iStack_118;
  int iStack_114;
  WINDOWPLACEMENT WStack_10c;
  tagRECT tStack_e0;
  undefined4 auStack_d0 [4];
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  tagRECT tStack_70;
  undefined1 auStack_60 [96];
  
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar2 = *(int *)(iVar2 + 8);
  local_138 = iVar2;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if (*param_1 == 0) {
    iVar3 = FUN_00404cd0();
  }
  else {
    iVar3 = FUN_00404c10();
  }
  if (iVar3 < 0) {
    return -0x7ffbf6ff;
  }
  piVar4 = (int *)FUN_00580ed0(0x60);
  if (piVar4 == (int *)0x0) {
    return -0x7ff8fff2;
  }
  piVar17 = piVar4;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar17 = *param_1;
    param_1 = param_1 + 1;
    piVar17 = piVar17 + 1;
  }
  thunk_FUN_0043189b();
  pcVar5 = (code *)thunk_FUN_007a6250();
  if (((pcVar5 != (code *)0x0) && (param_2 == 0)) && (param_3 == 0)) {
    thunk_FUN_0043189b();
    uVar6 = thunk_FUN_004692f0();
    cVar1 = (*pcVar5)(piVar4,uVar6);
    if (cVar1 == '\0') {
      if (iVar2 == 0) {
        thunk_FUN_00403011(0x80040902);
      }
                    /* WARNING: Subroutine does not return */
      FUN_00580ef0(piVar4);
    }
    thunk_FUN_0043189b();
    iVar3 = thunk_FUN_0044bd30();
    if (iVar3 == 0) {
      thunk_FUN_0043189b();
      iVar3 = thunk_FUN_007a5530();
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00580ef0(piVar4);
      }
    }
  }
  piVar17 = piVar4;
  thunk_FUN_0043189b(piVar4);
  FUN_00401350(piVar17);
  FUN_004073a0(1,1);
  cVar1 = FUN_00403fd0();
  if (cVar1 != '\0') {
    uVar6 = 1;
    thunk_FUN_0043189b(1);
    FUN_00401bd0(uVar6);
  }
  if (((param_2 == 0) && (param_3 == 0)) && (iVar2 == 0)) {
    FUN_00404d60(piVar4);
  }
  cStack_13d = '\0';
  iVar3 = thunk_FUN_00434a40(piVar4);
  if ((iVar3 == 0) && (iVar3 = thunk_FUN_0041f380(piVar4), iVar3 == 0)) {
    cStack_13d = '\x01';
  }
  cVar1 = FUN_00403fd0();
  if (cVar1 == '\0') {
    cVar1 = thunk_FUN_0043c1cc(piVar4);
    if (cVar1 == '\0') {
      if ((iVar2 != 0) && (cVar1 = thunk_FUN_0043c1cc(iVar2), cVar1 != '\0')) {
        uVar6 = thunk_FUN_00434a40(iVar2);
        thunk_FUN_0043189b(uVar6);
        FUN_00401890(uVar6);
        uVar6 = thunk_FUN_0041f380(iVar2);
        thunk_FUN_0043189b(uVar6);
        FUN_004018d0(uVar6);
      }
    }
    else if ((iVar2 != 0) && (cVar1 = thunk_FUN_0043c1cc(iVar2), cVar1 == '\0')) {
      uVar6 = thunk_FUN_00434a40(iVar2);
      thunk_FUN_0043189b(uVar6);
      FUN_00401810(uVar6);
      uVar6 = thunk_FUN_0041f380(iVar2);
      thunk_FUN_0043189b(uVar6);
      FUN_00401850(uVar6);
    }
  }
  else {
    cVar1 = thunk_FUN_0043c1cc(piVar4);
    if (cVar1 == '\0') {
      if ((iVar2 == 0) || (cVar1 = thunk_FUN_0043c1cc(iVar2), cVar1 != '\0')) {
        thunk_FUN_0043189b();
        pWVar12 = (WINDOWPLACEMENT *)thunk_FUN_00425660();
        FUN_00616ac0(pWVar12,0,0x2c);
        pWVar12->length = 0x2c;
        pHVar8 = (HWND)thunk_FUN_007a6bf0();
        GetWindowPlacement(pHVar8,pWVar12);
        iVar3 = -0x14;
        pHVar8 = (HWND)thunk_FUN_007a6bf0();
        uVar11 = GetWindowLongW(pHVar8,iVar3);
        uStack_13c = CONCAT31(uStack_13c._1_3_,(char)(uVar11 >> 3)) & 0xffffff01;
        uVar11 = uStack_13c;
        thunk_FUN_0043189b(uStack_13c);
        FUN_004019d0(uVar11);
        iVar3 = -0x10;
        pHVar8 = (HWND)thunk_FUN_007a6bf0();
        uVar11 = GetWindowLongW(pHVar8,iVar3);
        uVar11 = uVar11 & 0xdeffffff;
        thunk_FUN_0043189b(uVar11);
        FUN_00401950(uVar11);
        if (iVar2 != 0) {
          uVar6 = thunk_FUN_00434a40(iVar2);
          thunk_FUN_0043189b(uVar6);
          FUN_00401890(uVar6);
          uVar6 = thunk_FUN_0041f380(iVar2);
          thunk_FUN_0043189b(uVar6);
          FUN_004018d0(uVar6);
        }
      }
      iVar3 = 0;
      pHVar8 = (HWND)thunk_FUN_007a6b80();
      ShowWindow(pHVar8,iVar3);
      LVar7 = -0x7ff80000;
      iVar3 = -0x10;
      pHVar8 = (HWND)thunk_FUN_007a6b80();
      SetWindowLongW(pHVar8,iVar3,LVar7);
      iVar3 = thunk_FUN_007a6b80();
      iVar9 = thunk_FUN_007a6bf0();
      if (iVar3 == iVar9) {
        pHVar8 = (HWND)thunk_FUN_007a6b80();
        pHVar10 = GetMenu(pHVar8);
        thunk_FUN_0043189b(pHVar10);
        FUN_00401790(pHVar10);
        pHVar10 = (HMENU)0x0;
        pHVar8 = (HWND)thunk_FUN_007a6b80();
        SetMenu(pHVar8,pHVar10);
      }
      FUN_00616ac0(&WStack_10c,0,0x2c);
      pWVar12 = &WStack_10c;
      WStack_10c.length = 0x2c;
      pHVar8 = (HWND)thunk_FUN_007a6b80();
      GetWindowPlacement(pHVar8,pWVar12);
      if ((WStack_10c.flags & 2) != 0) {
        WStack_10c.flags = WStack_10c.flags & 0xfffffffd;
        pWVar12 = &WStack_10c;
        WStack_10c.showCmd = 9;
        pHVar8 = (HWND)thunk_FUN_007a6b80();
        SetWindowPlacement(pHVar8,pWVar12);
      }
    }
    else {
      if ((iVar2 != 0) && (cVar1 = thunk_FUN_0043c1cc(iVar2), cVar1 == '\0')) {
        uVar6 = thunk_FUN_00434a40(iVar2);
        thunk_FUN_0043189b(uVar6);
        FUN_00401810(uVar6);
        uVar6 = thunk_FUN_0041f380(iVar2);
        thunk_FUN_0043189b(uVar6);
        FUN_00401850(uVar6);
        thunk_FUN_0043189b();
        LVar7 = thunk_FUN_007a56c0();
        iVar3 = -0x10;
        pHVar8 = (HWND)thunk_FUN_007a6bf0();
        SetWindowLongW(pHVar8,iVar3,LVar7);
      }
      iVar3 = thunk_FUN_007a6b80();
      iVar9 = thunk_FUN_007a6bf0();
      if (iVar3 != iVar9) {
        iVar3 = 0;
        pHVar8 = (HWND)thunk_FUN_007a6b80();
        ShowWindow(pHVar8,iVar3);
      }
      iVar3 = thunk_FUN_007a6b80();
      iVar9 = thunk_FUN_007a6bf0();
      if (iVar3 == iVar9) {
        thunk_FUN_0043189b();
        iVar3 = thunk_FUN_007a5660();
        if (iVar3 != 0) {
          thunk_FUN_0043189b();
          pHVar10 = (HMENU)thunk_FUN_007a5660();
          pHVar8 = (HWND)thunk_FUN_007a6bf0();
          SetMenu(pHVar8,pHVar10);
        }
      }
    }
  }
  if ((param_4 == '\0') && (cVar1 = thunk_FUN_007a6db0(iVar2,piVar4,param_2,param_3), cVar1 != '\0')
     ) {
    iVar3 = 5;
    pHVar8 = (HWND)thunk_FUN_007a6b80();
    ShowWindow(pHVar8,iVar3);
    cVar1 = FUN_004034b0(iVar2);
    if (cVar1 == '\0') {
      iVar3 = FUN_00409a90();
    }
    else {
      iVar3 = FUN_00409130();
    }
    if (iVar3 < 0) {
      if (iVar3 != -0x7789f798) {
        if ((iVar3 != -0x7ffbf6f8) && (iVar3 != -0x7ffbf6fd)) {
          thunk_FUN_0043189b(iVar2);
          FUN_00401350(iVar2);
          iVar2 = FUN_0040af80(piVar4,param_2,param_3,1,param_5);
          if (-1 < iVar2) {
            FUN_004073a0(0,0);
            return 0;
          }
          FUN_0040ae00();
          return -0x7ffbf6fb;
        }
        if (iVar2 == 0) {
          thunk_FUN_00403011(iVar3);
          FUN_0040ae00(0);
          return iVar3;
        }
                    /* WARNING: Subroutine does not return */
        FUN_00580ef0(iVar2);
      }
      uVar6 = 1;
      thunk_FUN_0043189b(1);
      thunk_FUN_004027b7(uVar6);
    }
  }
  else {
    if (iVar2 != 0) {
      FUN_0040add0(0);
    }
    cVar1 = FUN_004034b0(piVar4);
    if (cVar1 == '\0') {
      iVar3 = FUN_00409480(param_3);
    }
    else {
      iVar3 = FUN_00408dc0(param_2);
    }
    if (iVar3 < 0) {
      if (iVar2 == 0) {
        FUN_0040add0(1);
        thunk_FUN_00403011(iVar3);
        FUN_004073a0(0,0);
        uVar6 = 0;
        thunk_FUN_0043189b(0);
        FUN_00401bd0(uVar6);
        iVar2 = FUN_0042ffb1();
        return iVar2;
      }
                    /* WARNING: Subroutine does not return */
      FUN_00580ef0(iVar2);
    }
  }
  cVar1 = thunk_FUN_0043c1cc(piVar4);
  if (cVar1 == '\0') {
    thunk_FUN_0043189b();
    uVar6 = thunk_FUN_007a58f0();
  }
  else {
    thunk_FUN_0043189b();
    uVar6 = thunk_FUN_004bff30();
  }
  thunk_FUN_0042ea68(uVar6);
  uVar6 = FUN_0040a290(piVar4);
  thunk_FUN_0043189b(uVar6);
  FUN_00401710(uVar6);
  FUN_00407960();
  if (((iVar2 != 0) && (cVar1 = thunk_FUN_0043c1cc(iVar2), cVar1 == '\0')) &&
     (cVar1 = thunk_FUN_0043c1cc(piVar4), cVar1 != '\0')) {
    thunk_FUN_0043189b();
    pWVar12 = (WINDOWPLACEMENT *)thunk_FUN_00425660();
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    SetWindowPlacement(pHVar8,pWVar12);
    thunk_FUN_0043189b();
    cVar1 = thunk_FUN_007a5720();
    UVar20 = 0xb;
    iVar19 = 0;
    iVar9 = 0;
    iVar3 = 0;
    iVar2 = 0;
    pHVar8 = (HWND)((cVar1 != '\0') - 2);
    pHVar13 = (HWND)thunk_FUN_007a6bf0();
    SetWindowPos(pHVar13,pHVar8,iVar2,iVar3,iVar9,iVar19,UVar20);
  }
  cStack_13e = '\0';
  cVar1 = thunk_FUN_0043c1cc(piVar4);
  if ((cVar1 == '\0') || (cStack_13d != '\0')) goto LAB_0040bb4a;
  pHVar8 = (HWND)thunk_FUN_007a6bf0();
  BVar14 = IsIconic(pHVar8);
  if (BVar14 == 0) {
    ptVar21 = &tStack_150;
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    GetClientRect(pHVar8,ptVar21);
    iVar2 = tStack_150.right - tStack_150.left;
    iVar3 = tStack_150.bottom - tStack_150.top;
  }
  else {
    FUN_00616ac0(&WStack_10c,0,0x2c);
    pWVar12 = &WStack_10c;
    WStack_10c.length = 0x2c;
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    GetWindowPlacement(pHVar8,pWVar12);
    if (((WStack_10c.flags & 2) == 0) || (WStack_10c.showCmd != 2)) {
      tStack_150.left = 0;
      tStack_150.top = 0;
      tStack_150.right = 0;
      tStack_150.bottom = 0;
      thunk_FUN_0043189b();
      iVar2 = thunk_FUN_007a5660();
      uVar11 = (uint)(iVar2 != 0);
      thunk_FUN_0043189b();
      DVar15 = thunk_FUN_007a56c0();
      AdjustWindowRect(&tStack_150,DVar15,uVar11);
      iVar2 = ((WStack_10c.rcNormalPosition.right - WStack_10c.rcNormalPosition.left) -
              tStack_150.right) + tStack_150.left;
      iVar3 = ((WStack_10c.rcNormalPosition.bottom - WStack_10c.rcNormalPosition.top) -
              tStack_150.bottom) + tStack_150.top;
    }
    else {
      iVar2 = 9;
      pHVar8 = (HWND)thunk_FUN_007a6bf0();
      ShowWindow(pHVar8,iVar2);
      ptVar21 = &tStack_150;
      pHVar8 = (HWND)thunk_FUN_007a6bf0();
      GetClientRect(pHVar8,ptVar21);
      iVar2 = tStack_150.right - tStack_150.left;
      iVar3 = tStack_150.bottom - tStack_150.top;
      iVar9 = 6;
      pHVar8 = (HWND)thunk_FUN_007a6bf0();
      ShowWindow(pHVar8,iVar9);
    }
  }
  iVar9 = thunk_FUN_00434a40(piVar4);
  if ((iVar2 != iVar9) || (iVar2 = thunk_FUN_0041f380(piVar4), iVar3 != iVar2)) {
    cStack_13e = '\x01';
  }
  if ((char)param_5 == '\0') {
LAB_0040b819:
    if (cStack_13e == '\0') goto LAB_0040bb4a;
  }
  else {
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    BVar14 = IsIconic(pHVar8);
    if (BVar14 != 0) goto LAB_0040b819;
    auStack_134[0] = 0x28;
    iVar2 = FUN_0040a290(piVar4);
    thunk_FUN_00436416(iVar2,auStack_134);
    uVar22 = 1;
    uVar6 = FUN_00408620(1);
    iVar3 = FUN_004142a0(uVar6,uVar22);
    ptVar21 = &tStack_150;
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    GetWindowRect(pHVar8,ptVar21);
    if ((((iStack_120 <= tStack_150.left) && (tStack_150.right <= iStack_118)) &&
        (iStack_11c <= tStack_150.top)) && (tStack_150.bottom <= iStack_114)) goto LAB_0040b819;
    if (iVar3 == iVar2) {
      pHVar8 = (HWND)thunk_FUN_007a6bf0();
      BVar14 = IsZoomed(pHVar8);
      if (BVar14 != 0) goto LAB_0040b819;
    }
  }
  pHVar8 = (HWND)thunk_FUN_007a6bf0();
  BVar14 = IsIconic(pHVar8);
  if (BVar14 != 0) {
    iVar2 = 9;
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    ShowWindow(pHVar8,iVar2);
  }
  pHVar8 = (HWND)thunk_FUN_007a6bf0();
  BVar14 = IsZoomed(pHVar8);
  if (BVar14 != 0) {
    iVar2 = 9;
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    ShowWindow(pHVar8,iVar2);
  }
  if ((char)param_5 == '\0') {
    tStack_150.left = 0;
    tStack_150.top = 0;
    tStack_150.right = 0;
    tStack_150.bottom = 0;
    tStack_150.right = thunk_FUN_00434a40(piVar4);
    tStack_150.bottom = thunk_FUN_0041f380(piVar4);
    thunk_FUN_0043189b();
    iVar2 = thunk_FUN_007a5660();
    uVar11 = (uint)(iVar2 != 0);
    iVar2 = -0x10;
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    DVar15 = GetWindowLongW(pHVar8,iVar2);
    AdjustWindowRect(&tStack_150,DVar15,uVar11);
    iVar3 = tStack_150.bottom - tStack_150.top;
    iVar2 = tStack_150.right - tStack_150.left;
    UVar20 = 6;
    iVar19 = 0;
    iVar9 = 0;
    pHVar13 = (HWND)0x0;
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    SetWindowPos(pHVar8,pHVar13,iVar9,iVar19,iVar2,iVar3,UVar20);
  }
  else {
    auStack_134[0] = 0x28;
    uVar6 = FUN_0040a290();
    thunk_FUN_00436416(uVar6,auStack_134);
    pWVar12 = &WStack_10c;
    uVar22 = 1;
    WStack_10c.length = 0x28;
    uVar6 = FUN_00408620(1,pWVar12);
    uVar6 = FUN_004142a0(uVar6,uVar22);
    thunk_FUN_00436416(uVar6,pWVar12);
    iVar9 = iStack_118 - iStack_120;
    iVar3 = iStack_114 - iStack_11c;
    iVar2 = thunk_FUN_00434a40(piVar4);
    uStack_13c = thunk_FUN_0041f380(piVar4);
    ptVar21 = &tStack_70;
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    GetWindowRect(pHVar8,ptVar21);
    tStack_150.left = 0;
    tStack_150.top = 0;
    tStack_150.bottom = uStack_13c;
    tStack_150.right = iVar2;
    thunk_FUN_0043189b();
    iVar2 = thunk_FUN_007a5660();
    uVar11 = (uint)(iVar2 != 0);
    iVar2 = -0x10;
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    DVar15 = GetWindowLongW(pHVar8,iVar2);
    AdjustWindowRect(&tStack_150,DVar15,uVar11);
    iVar2 = tStack_150.right - tStack_150.left;
    if (iVar9 < tStack_150.right - tStack_150.left) {
      iVar2 = iVar9;
    }
    iVar19 = tStack_150.bottom - tStack_150.top;
    if (iVar3 < tStack_150.bottom - tStack_150.top) {
      iVar19 = iVar3;
    }
    if (((tStack_150.left < iStack_120) || (tStack_150.top < iStack_11c)) ||
       ((iStack_118 < tStack_150.right || (iStack_114 < tStack_150.bottom)))) {
      iVar9 = (iVar9 - iVar2) / 2;
      tStack_150.left = iVar9 + iStack_120;
      iVar3 = (iVar3 - iVar19) / 2;
      tStack_150.top = iStack_11c + iVar3;
      tStack_150.right = iVar9 + iVar2 + iStack_120;
      tStack_150.bottom = iVar3 + iVar19 + iStack_11c;
    }
    UVar20 = 4;
    pHVar13 = (HWND)0x0;
    LVar7 = tStack_150.left;
    Y = tStack_150.top;
    pHVar8 = (HWND)thunk_FUN_007a6bf0();
    SetWindowPos(pHVar8,pHVar13,LVar7,Y,iVar2,iVar19,UVar20);
  }
  ptVar21 = &tStack_e0;
  pHVar8 = (HWND)thunk_FUN_007a6bf0();
  GetClientRect(pHVar8,ptVar21);
  iVar2 = thunk_FUN_00434a40(piVar4);
  if ((tStack_e0.right - tStack_e0.left != iVar2) ||
     (iVar2 = thunk_FUN_0041f380(piVar4), tStack_e0.bottom - tStack_e0.top != iVar2)) {
    puVar16 = (undefined4 *)thunk_FUN_007a6f00(auStack_60);
    puVar18 = auStack_d0;
    for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar18 = *puVar16;
      puVar16 = puVar16 + 1;
      puVar18 = puVar18 + 1;
    }
    cVar1 = FUN_004034b0(auStack_d0);
    if (cVar1 == '\0') {
      uStack_c0 = 0;
    }
    else {
      uStack_bc = 0;
    }
    cVar1 = FUN_004034b0(auStack_d0);
    if (cVar1 == '\0') {
      uStack_bc = 0;
    }
    else {
      uStack_b8 = 0;
    }
    iVar2 = FUN_0040af80(auStack_d0,0,0,0,param_5);
    if (iVar2 < 0) {
      if (local_138 == 0) {
        FUN_0040add0(1);
        FUN_004073a0(0,0);
        uVar6 = 0;
        thunk_FUN_0043189b(0);
        FUN_00401bd0(uVar6);
        return iVar2;
      }
                    /* WARNING: Subroutine does not return */
      FUN_00580ef0(local_138);
    }
  }
LAB_0040bb4a:
  pHVar8 = (HWND)FUN_00408620();
  BVar14 = IsWindowVisible(pHVar8);
  if (BVar14 == 0) {
    iVar2 = 5;
    pHVar8 = (HWND)FUN_00408620();
    ShowWindow(pHVar8,iVar2);
  }
  cVar1 = thunk_FUN_004c1540();
  if (cVar1 == '\0') {
    esFlags = 0x80000002;
  }
  else {
    esFlags = 0x80000000;
  }
  SetThreadExecutionState(esFlags);
  if (local_138 == 0) {
    uVar6 = 0;
    thunk_FUN_0043189b(0);
    FUN_00401bd0(uVar6);
    FUN_004073a0(0,0);
    uVar6 = 1;
    thunk_FUN_0043189b(1);
    FUN_00402470(uVar6);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00580ef0(local_138);
}

