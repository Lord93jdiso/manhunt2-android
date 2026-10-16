
int FUN_00409130(void)

{
  char cVar1;
  code *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 unaff_EBP;
  
  piVar4 = (int *)FUN_00404010();
  if (piVar4 == (int *)0x0) {
    FUN_00616f0c(&PTR_s_USE_EXECUTE_NEWSPAPER_3_ANIM_0064006c_4_00639018,
                 L"W:\\Manhunt2_PC\\mh2_vs2005\\DXUT\\Core\\DXUT.cpp",0xbda);
  }
  iVar5 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar5 + 0x304);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 == '\x01') {
    iVar5 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    *(undefined1 *)(iVar5 + 0x305) = 1;
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    iVar5 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    pcVar2 = *(code **)(iVar5 + 900);
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    if (pcVar2 != (code *)0x0) {
      iVar5 = thunk_FUN_0043189b();
      if (DAT_00685000 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
      }
      uVar6 = *(undefined4 *)(iVar5 + 0x3d0);
      if (DAT_00685000 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
      }
      (*pcVar2)(uVar6);
    }
    iVar5 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    *(undefined1 *)(iVar5 + 0x304) = 0;
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    iVar5 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    *(undefined1 *)(iVar5 + 0x305) = 0;
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
  }
  iVar5 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar5 = *(int *)(iVar5 + 8);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar5 = (**(code **)(*piVar4 + 0x40))(piVar4,iVar5 + 0x14);
  if (iVar5 < 0) {
    return (-(uint)(iVar5 != -0x7789f798) & 0xf78e009e) + 0x88760868;
  }
  FUN_004076b0();
  FUN_00407870();
  iVar5 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  *(undefined1 *)(iVar5 + 0x305) = 1;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  uVar6 = thunk_FUN_0048d1d0();
  iVar5 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  pcVar2 = *(code **)(iVar5 + 0x380);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar5 = 0;
  if (pcVar2 != (code *)0x0) {
    iVar5 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    uVar3 = *(undefined4 *)(iVar5 + 0x3cc);
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    iVar5 = (*pcVar2)(unaff_EBP,uVar6,uVar3);
  }
  iVar7 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  *(undefined1 *)(iVar7 + 0x305) = 0;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (iVar5 < 0) {
    uVar6 = 1;
    thunk_FUN_0043189b(1);
    FUN_004025b0(uVar6);
    thunk_FUN_0043189b();
    iVar5 = thunk_FUN_0040940d();
    return iVar5;
  }
  uVar6 = 1;
  thunk_FUN_0043189b(1);
  FUN_004026b0(uVar6);
  return 0;
}

