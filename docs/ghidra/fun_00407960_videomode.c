
void FUN_00407960(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined **ppuVar6;
  wchar_t *pwVar7;
  undefined2 auStack_25c [100];
  undefined1 auStack_194 [200];
  undefined1 auStack_cc [200];
  uint local_4;
  
  local_4 = DAT_006dc2e0 ^ (uint)auStack_25c;
  iVar3 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  cVar2 = *(char *)(iVar3 + 0x2eb);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (cVar2 != '\0') goto LAB_00407bf6;
  iVar3 = thunk_FUN_0043189b();
  if (DAT_00685000 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  iVar3 = *(int *)(iVar3 + 8);
  if (DAT_00685000 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
  }
  if (iVar3 == 0) goto LAB_00407bf6;
  cVar2 = FUN_004034b0(iVar3);
  if (cVar2 == '\0') {
    iVar4 = thunk_FUN_0042cd4c(0,0);
    if (iVar4 != 0) {
      iVar4 = thunk_FUN_0044ad80(*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 8),
                                 *(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 0x20),
                                 *(undefined4 *)(iVar3 + 0x40));
      if (iVar4 != 0) {
        uVar5 = FUN_00413a10(*(undefined4 *)(iVar4 + 8),0);
        thunk_FUN_004cc900(auStack_25c,100,uVar5);
        thunk_FUN_004ae450(auStack_194,100,L" (MS%u, Q%u)",*(undefined4 *)(iVar3 + 0x2c),
                           *(undefined4 *)(iVar3 + 0x30));
        thunk_FUN_0043189b();
        uVar5 = thunk_FUN_007a66c0();
        ppuVar6 = &PTR_s__00660060_0xf_00638c1c;
        if (*(int *)(iVar3 + 0x50) != 0) {
          ppuVar6 = &PTR_DAT_00638c14;
        }
        thunk_FUN_004ae450(uVar5,0x100,L"D3D10 %%sVsync %s (%dx%d), %s%s",ppuVar6,
                           *(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14),auStack_25c,
                           auStack_194);
      }
    }
    goto LAB_00407bf6;
  }
  iVar4 = thunk_FUN_004ae6e0(0);
  if (iVar4 == 0) goto LAB_00407bf6;
  iVar4 = thunk_FUN_0046add0(*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 8),
                             *(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 0x1c),
                             *(undefined4 *)(iVar3 + 0x34));
  if (iVar4 == 0) goto LAB_00407bf6;
  iVar1 = *(int *)(iVar4 + 8);
  if (iVar1 == *(int *)(iVar4 + 0xc)) {
    uVar5 = FUN_00413620(iVar1,0);
    thunk_FUN_004cc900(auStack_194,100,uVar5);
  }
  else {
    uVar5 = FUN_00413620(iVar1,0);
    uVar5 = FUN_00413620(*(undefined4 *)(iVar4 + 0xc),0,uVar5);
    thunk_FUN_004ae450(auStack_194,100,L"backbuf %s, adapter %s",uVar5);
  }
  if (*(int *)(iVar3 + 0x38) == 0) {
    auStack_25c[0] = 0;
  }
  else {
    uVar5 = FUN_00413620(*(undefined4 *)(iVar3 + 0x3c),0);
    thunk_FUN_004ae450(auStack_25c,100,L" (%s)",uVar5);
  }
  iVar4 = *(int *)(iVar3 + 0x24);
  if (iVar4 == 0) {
    pwVar7 = L"";
LAB_00407af2:
    thunk_FUN_004cc900(auStack_cc,100,pwVar7);
  }
  else {
    if (iVar4 == 1) {
      pwVar7 = L" (Nonmaskable Multisample)";
      goto LAB_00407af2;
    }
    thunk_FUN_004ae450(auStack_cc,100,L" (%dx Multisample)",iVar4);
  }
  thunk_FUN_0043189b();
  uVar5 = thunk_FUN_007a66c0();
  ppuVar6 = &PTR_s__00660060_0xf_00638c1c;
  if (*(int *)(iVar3 + 0x48) != -0x80000000) {
    ppuVar6 = &PTR_DAT_00638c14;
  }
  thunk_FUN_004ae450(uVar5,0x100,L"D3D9 %%sVsync %s (%dx%d), %s%s%s",ppuVar6,
                     *(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(iVar3 + 0x18),auStack_194,
                     auStack_25c,auStack_cc);
LAB_00407bf6:
  __security_check_cookie(local_4 ^ (uint)auStack_25c);
  return;
}

