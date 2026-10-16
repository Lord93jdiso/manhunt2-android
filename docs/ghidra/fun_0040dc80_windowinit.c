
uint FUN_0040dc80(byte param_1,int param_2,int param_3,uint param_4,int param_5)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8 [5];
  int local_a4;
  int local_98;
  undefined4 local_90;
  uint local_88;
  undefined4 local_80;
  uint local_78;
  undefined4 local_74;
  int local_5c [23];
  
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x305);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 != '\0') {
    return 0x80004005;
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  *(undefined1 *)(iVar2 + 0x302) = 1;
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x2fe);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 == '\0') {
    thunk_FUN_0043189b();
    cVar1 = thunk_FUN_007a5d70();
    if (cVar1 != '\0') {
      return 0x80004005;
    }
    uVar3 = thunk_FUN_007a70d0(&PTR_DAT_006397b8,0,0,0,0x80000000,0x80000000);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  local_100 = 0;
  local_fc = 0;
  local_f4 = 0;
  local_f8 = 0;
  local_f0 = 1;
  local_ec = 0;
  local_e8 = 0;
  if ((param_1 == 0) && ((param_2 == 0 || (param_3 == 0)))) {
    local_e4 = 0;
  }
  else {
    local_e4 = 2;
  }
  local_e0 = 0;
  local_dc = 0;
  local_d0 = 0;
  local_cc = 2;
  local_c8 = 0;
  local_c4 = 2;
  local_c0 = 0;
  if (param_5 == 0) {
    local_d8 = 0;
    local_d4 = 0;
  }
  else {
    local_d8 = 2;
    local_d4 = 2;
  }
  FUN_00616ac0(&local_bc,0,0x60);
  local_88 = (uint)param_1;
  local_bc = 0;
  local_b8[4] = param_2;
  local_a4 = param_3;
  local_80 = 0x4b;
  local_78 = ~-(uint)(param_1 != 0) & param_4;
  if (param_5 != 0) {
    local_90 = 1;
    local_98 = param_5;
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar2 = *(int *)(iVar2 + 0x338);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (iVar2 != 0) {
    thunk_FUN_0043189b();
    local_b8[4] = thunk_FUN_007a6140();
    local_e4 = 1;
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar2 = *(int *)(iVar2 + 0x33c);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (iVar2 != 0) {
    thunk_FUN_0043189b();
    local_a4 = thunk_FUN_007a6190();
    local_e4 = 1;
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar2 = *(int *)(iVar2 + 800);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (iVar2 != -1) {
    thunk_FUN_0043189b();
    local_b8[0] = thunk_FUN_007a6040();
    local_f4 = 1;
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x32c);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 != '\0') {
    local_88 = 0;
    thunk_FUN_0043189b();
    iVar2 = thunk_FUN_007a6140();
    if (iVar2 == 0) {
      thunk_FUN_0043189b();
      iVar2 = thunk_FUN_007a6190();
      if (iVar2 == 0) {
        local_e4 = 0;
      }
    }
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x324);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 != '\0') {
    local_88 = 1;
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x340);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 != '\0') {
    local_b8[1] = 1;
    local_f4 = 1;
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x341);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 != '\0') {
    local_b8[1] = 2;
    local_f4 = 1;
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar1 = *(char *)(iVar2 + 0x342);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar1 == '\0') {
    thunk_FUN_0043189b();
    cVar1 = thunk_FUN_00453100();
    if (cVar1 != '\0') {
      local_b8[3] = 0x40;
      goto LAB_0040e0b7;
    }
    thunk_FUN_0043189b();
    cVar1 = thunk_FUN_007a61f0();
    if (cVar1 != '\0') {
      local_b8[3] = 0x20;
      goto LAB_0040e0b7;
    }
  }
  else {
    local_b8[3] = 0x50;
LAB_0040e0b7:
    local_e8 = 1;
  }
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar2 = *(int *)(iVar2 + 0x350);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (iVar2 == 0) {
    local_74 = 0x80000000;
  }
  else {
    thunk_FUN_0043189b();
    iVar2 = thunk_FUN_00464680();
    if (iVar2 != 1) goto LAB_0040e11f;
    local_74 = 0;
  }
  local_c0 = 1;
LAB_0040e11f:
  iVar2 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar2 = *(int *)(iVar2 + 0x31c);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (iVar2 != -1) {
    thunk_FUN_0043189b();
    iVar2 = thunk_FUN_007a5fe0();
    if (iVar2 == 9) {
      local_bc = 0;
      local_100 = 1;
    }
    else {
      thunk_FUN_0043189b();
      iVar2 = thunk_FUN_007a5fe0();
      if (iVar2 == 10) {
        local_bc = 1;
        local_100 = 1;
        FUN_00616ac0(local_5c,0,0x5c);
        thunk_FUN_007a93c0(local_b8,local_5c);
        piVar4 = local_5c;
        piVar5 = local_b8;
        for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar5 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar5 = piVar5 + 1;
        }
      }
    }
  }
  uVar3 = thunk_FUN_007a8de0(&local_bc,&local_bc,&local_100);
  if (-1 < (int)uVar3) {
    uVar3 = FUN_0040af80(&local_bc,0,0,0,1);
    return uVar3 & (-1 < (int)uVar3) - 1;
  }
  thunk_FUN_00403011(uVar3);
  return uVar3;
}

