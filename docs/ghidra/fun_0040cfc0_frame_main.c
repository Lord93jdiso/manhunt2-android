
void FUN_0040cfc0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  code *pcVar8;
  float10 fVar9;
  float fStack_184;
  double dStack_180;
  int iStack_16c;
  undefined8 uStack_168;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 local_100 [24];
  undefined1 auStack_a0 [156];
  
  iVar2 = thunk_FUN_0043189b();
  pcVar8 = EnterCriticalSection_exref;
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x314);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if ((cVar1 != '\0') || (cVar1 = thunk_FUN_004af140(), cVar1 != '\0')) {
    Sleep(0x32);
  }
  piVar3 = (int *)FUN_00404010();
  iVar2 = thunk_FUN_0043189b();
  if (piVar3 == (int *)0x0) {
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    cVar1 = *(char *)(iVar2 + 0x314);
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    if (cVar1 == '\0') {
      return;
    }
    puVar4 = (undefined4 *)thunk_FUN_007a6f00(&local_160);
    puVar7 = local_100;
    for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar7 = puVar7 + 1;
    }
    FUN_0040af80(local_100,0);
    return;
  }
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x314);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 != '\0') {
    thunk_FUN_0043189b();
    cVar1 = thunk_FUN_007a5ea0();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*piVar3 + 0xc))(piVar3);
      if (iVar2 < 0) {
        if (iVar2 == -0x7789f798) {
          return;
        }
        cVar1 = thunk_FUN_004c1540();
        if (cVar1 != '\0') {
          piVar3 = (int *)thunk_FUN_0041e650();
          thunk_FUN_0043189b();
          iVar2 = thunk_FUN_004a1020();
          (**(code **)(*piVar3 + 0x20))();
          pcVar8 = EnterCriticalSection_exref;
          if (*(int *)(iVar2 + 0xc) != iStack_16c) {
            local_160 = 1;
            uStack_15c = 1;
            uStack_154 = 1;
            uStack_150 = 1;
            uStack_14c = 1;
            uStack_148 = 2;
            uStack_144 = 2;
            uStack_140 = 2;
            uStack_13c = 2;
            uStack_138 = 2;
            uStack_134 = 2;
            uStack_130 = 2;
            uStack_12c = 2;
            uStack_128 = 2;
            uStack_124 = 2;
            uStack_120 = 2;
            puVar4 = (undefined4 *)thunk_FUN_007a6f00(auStack_a0);
            puVar7 = local_100;
            for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar7 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar7 = puVar7 + 1;
            }
            iVar2 = thunk_FUN_007a8de0();
            if (iVar2 < 0) {
              thunk_FUN_00403011(0x80040902);
              FUN_0040ae00(0);
            }
            iVar2 = FUN_0040af80(local_100,0,0,0,0);
            if (-1 < iVar2) {
              return;
            }
            iVar2 = FUN_0040bbd0();
            if (-1 < iVar2) {
              return;
            }
            FUN_0040ae00(0);
            return;
          }
        }
        iVar2 = FUN_00409130();
        if (iVar2 < 0) {
          if (iVar2 == -0x7789f798) {
            return;
          }
          if ((iVar2 == -0x7ffbf6f8) || (iVar2 == -0x7ffbf6fd)) {
            thunk_FUN_00403011(iVar2);
            FUN_0040ae00(0);
            return;
          }
          thunk_FUN_0043189b();
          uVar5 = thunk_FUN_004a1020();
          iVar2 = FUN_0040af80(uVar5,0,0,1,0);
          if (iVar2 < 0) {
            FUN_0040ae00(0);
            return;
          }
        }
      }
      uVar5 = 0;
      thunk_FUN_0043189b(0);
      thunk_FUN_004027b7(uVar5);
    }
  }
  do {
    uVar6 = thunk_FUN_007a67d0(&DAT_006ddbc8);
  } while (uVar6 < 0x8256);
  QueryPerformanceCounter((LARGE_INTEGER *)&DAT_006ddbc8);
  thunk_FUN_00416d1c();
  FUN_00414700();
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    (*pcVar8)(&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x2ee);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 != '\0') {
    thunk_FUN_0043189b();
    fVar9 = (float10)FUN_00402270();
    fStack_184 = (float)fVar9;
    fVar9 = (float10)FUN_00404250();
    dStack_180 = (double)(fVar9 + (float10)fStack_184);
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    (*pcVar8)(&DAT_006ddba0);
  }
  *(double *)(iVar2 + 0x288) = dStack_180;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    (*pcVar8)(&DAT_006ddba0);
  }
  *(undefined8 *)(iVar2 + 0x290) = uStack_168;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    (*pcVar8)(&DAT_006ddba0);
  }
  *(float *)(iVar2 + 0x298) = fStack_184;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  FUN_00407c10();
  FUN_00407560();
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    (*pcVar8)(&DAT_006ddba0);
  }
  pcVar8 = *(code **)(iVar2 + 0x360);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (pcVar8 != (code *)0x0) {
    thunk_FUN_0043189b();
    uVar5 = thunk_FUN_007a6480();
    (*pcVar8)(dStack_180,fStack_184,uVar5);
    iVar2 = FUN_00404010();
    if (iVar2 == 0) {
      return;
    }
  }
  thunk_FUN_0043189b();
  thunk_FUN_0040d449();
  return;
}

