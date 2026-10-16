
void FUN_004076b0(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_EBX;
  int *unaff_EDI;
  undefined4 *puVar5;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  cVar2 = FUN_00403fd0();
  if (cVar2 == '\0') {
    iVar3 = thunk_FUN_0043189b();
    if (DAT_00685000 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    piVar1 = *(int **)(iVar3 + 0x174);
    if (DAT_00685000 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    puVar5 = &local_30;
    iVar3 = (**(code **)(*piVar1 + 0x24))(piVar1,0);
    iVar4 = thunk_FUN_0043189b();
    if ((DAT_00685000 != '\0') &&
       (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0), DAT_00685000 != '\0')) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ddba0);
    }
    *(undefined4 *)(iVar4 + 0x184) = 0;
    *(undefined4 *)(iVar4 + 0x188) = 0;
    *(undefined4 *)(iVar4 + 0x18c) = 0;
    *(undefined4 *)(iVar4 + 400) = 0;
    *(undefined4 *)(iVar4 + 0x194) = 0;
    if (-1 < iVar3) {
      (**(code **)(*unaff_EDI + 0x30))(unaff_EDI,&stack0xffffffc4);
      *(undefined4 **)(iVar4 + 0x184) = puVar5;
      *(int **)(iVar4 + 0x188) = unaff_EDI;
      *(undefined4 *)(iVar4 + 0x18c) = unaff_EBX;
      *(undefined4 *)(iVar4 + 400) = local_30;
      *(undefined4 *)(iVar4 + 0x194) = uStack_2c;
      (*pcRam9b7e4c0c)(&DAT_00638b60);
    }
    return;
  }
  thunk_FUN_0043189b();
  thunk_FUN_004076d0();
  return;
}

