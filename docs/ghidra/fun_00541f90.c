
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00541f90(undefined4 param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int extraout_ECX;
  int iVar9;
  int iVar10;
  int unaff_EBP;
  undefined8 uVar11;
  code *unaff_retaddr;
  
  _DAT_0075b0e4 = param_1;
  piVar4 = (int *)FUN_0053bd00(param_1);
  pcVar5 = (char *)FUN_00580ed0(80000);
  iVar6 = (**(code **)(*piVar4 + 0xc))(pcVar5,80000);
  (**(code **)(*piVar4 + 4))();
  (**(code **)(*piVar4 + 0x18))();
  iVar10 = iVar6;
  _DAT_0075a524 = pcVar5;
  DAT_0075b0e0 = pcVar5;
  if ((*pcVar5 == -1) && (pcVar5[1] == -2)) {
    DAT_0075b720 = 1;
    FUN_00580e30(80000);
    unaff_EBP = FUN_00580c30();
    iVar10 = iVar6 + -6;
    iVar8 = 0;
    _DAT_00759c40 = unaff_EBP;
    if (0 < iVar10) {
      do {
        *(char *)(iVar8 + unaff_EBP) = pcVar5[iVar8 + 2];
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar10);
    }
    iVar9 = iVar10 >> 0x1f;
    uVar7 = iVar10 - iVar9;
    iVar10 = iVar10 / 2;
    iVar8 = 0;
    if (0 < iVar10) {
      do {
        uVar11 = FUN_0053ec80(CONCAT22((short)((uint)iVar9 >> 0x10),
                                       (ushort)*(byte *)(unaff_EBP + iVar8 * 2)),
                              CONCAT22((short)(uVar7 >> 0x10),
                                       (ushort)*(byte *)(unaff_EBP + 1 + iVar8 * 2)));
        iVar9 = (int)((ulonglong)uVar11 >> 0x20);
        uVar7 = (uint)uVar11 & 0xffff;
        if ((ushort)uVar11 < 0x80) {
          pcVar5[extraout_ECX] = (char)uVar7;
        }
        else {
          pcVar5[extraout_ECX] = '\x01';
        }
        iVar8 = extraout_ECX + 1;
      } while (iVar8 < iVar10);
    }
  }
  pcVar5[iVar10] = ' ';
  bVar3 = false;
  bVar2 = false;
  iVar10 = 0;
  if (0 < iVar6) {
    do {
      if (bVar2) {
        if (!bVar3) {
          if ((pcVar5[iVar10] == '\"') && (pcVar5[iVar10 + -1] != '\\')) {
            bVar2 = false;
          }
          goto LAB_005420c6;
        }
LAB_005420c2:
        pcVar5[iVar10] = ' ';
      }
      else {
        cVar1 = pcVar5[iVar10];
        if (cVar1 == '#') {
          bVar3 = true;
          goto LAB_005420c2;
        }
        if ((cVar1 == '\n') || (cVar1 == '\r')) {
          bVar3 = false;
        }
        else if (cVar1 == '\"') {
          if (bVar3) goto LAB_005420c2;
          bVar2 = true;
        }
        else if (bVar3) goto LAB_005420c2;
      }
LAB_005420c6:
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar6);
  }
  iVar10 = 0;
  if (0 < iVar6) {
    do {
      cVar1 = pcVar5[iVar10];
      if (((cVar1 == '\n') || (cVar1 == '\r')) || (cVar1 == '\t')) {
        pcVar5[iVar10] = ' ';
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar6);
  }
  if (*pcVar5 == ' ') {
    FUN_0053f310();
  }
  (*unaff_retaddr)();
  if (DAT_0075b720 != 0) {
    FUN_00580e30(unaff_EBP);
    FUN_00580d80(unaff_EBP);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00580ef0(pcVar5);
}

