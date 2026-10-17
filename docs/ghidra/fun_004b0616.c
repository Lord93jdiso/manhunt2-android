
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b0616(void)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined2 *puVar7;
  int *piVar8;
  undefined2 uVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int in_stack_00000208;
  
  uVar2 = DAT_006dc2e0;
  if (DAT_0079e708 != 0) goto LAB_004b08a5;
  pcVar3 = DAT_0075969c;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)(&stack0x00000100 + -(int)DAT_0075969c)] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((in_stack_00000208 == 0) || (in_stack_00000208 == 1)) {
    iVar6 = 0;
    do {
      cVar1 = s_level_00_00694a30[iVar6];
      (&stack0x00000000)[iVar6] = cVar1;
      iVar6 = iVar6 + 1;
    } while (cVar1 != '\0');
    puVar7 = (undefined2 *)&stack0xffffffff;
    if (in_stack_00000208 == 0) {
      do {
        pcVar3 = (char *)((int)puVar7 + 1);
        puVar7 = (undefined2 *)((int)puVar7 + 1);
      } while (*pcVar3 != '\0');
      uVar9 = 0x695f;
    }
    else {
      do {
        pcVar3 = (char *)((int)puVar7 + 1);
        puVar7 = (undefined2 *)((int)puVar7 + 1);
      } while (*pcVar3 != '\0');
      uVar9 = 0x6f5f;
    }
    *puVar7 = uVar9;
    *(undefined1 *)(puVar7 + 1) = 0;
    pcVar3 = (char *)register0x00000010;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    puVar12 = (undefined4 *)&stack0x000000ff;
    do {
      pcVar4 = (char *)((int)puVar12 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    } while (*pcVar4 != '\0');
    puVar11 = (undefined4 *)register0x00000010;
    for (uVar10 = (uint)((int)pcVar3 - (int)&stack0x00000000) >> 2; uVar10 != 0; uVar10 = uVar10 - 1
        ) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
    for (uVar10 = (int)pcVar3 - (int)&stack0x00000000 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    puVar12 = (undefined4 *)&stack0x000000ff;
    do {
      pcVar3 = (char *)((int)puVar12 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    } while (*pcVar3 != '\0');
LAB_004b081a:
    *puVar12 = 0x6b69622e;
    *(undefined1 *)(puVar12 + 1) = 0;
  }
  else if (in_stack_00000208 == 3) {
    pcVar3 = &stack0x000000ff;
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (pcVar4[1] != '\0');
    builtin_strncpy(pcVar4 + 1,"stinger_wide.bik",0x11);
  }
  else if (in_stack_00000208 == 2) {
    puVar7 = (undefined2 *)&stack0xffffffff;
    do {
      puVar5 = puVar7;
      puVar7 = (undefined2 *)((int)puVar5 + 1);
    } while (*(char *)((int)puVar5 + 1) != '\0');
    *(undefined2 *)((int)puVar5 + 1) = 0x695f;
    *(undefined1 *)((int)puVar5 + 3) = 0;
    pcVar3 = (char *)register0x00000010;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    puVar12 = (undefined4 *)&stack0x000000ff;
    do {
      pcVar4 = (char *)((int)puVar12 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    } while (*pcVar4 != '\0');
    puVar11 = (undefined4 *)register0x00000010;
    for (uVar10 = (uint)((int)pcVar3 - (int)&stack0x00000000) >> 2; uVar10 != 0; uVar10 = uVar10 - 1
        ) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
    for (uVar10 = (int)pcVar3 - (int)&stack0x00000000 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    puVar12 = (undefined4 *)&stack0x000000ff;
    do {
      pcVar3 = (char *)((int)puVar12 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    } while (*pcVar3 != '\0');
    goto LAB_004b081a;
  }
  _DAT_00694a2c = in_stack_00000208;
  FUN_0053aba0(&stack0x00000100);
  piVar8 = (int *)FUN_0053bcc0(&stack0x00000100,1);
  if (piVar8 != (int *)0x0) {
    (**(code **)(*piVar8 + 0x18))();
    FUN_00606ee0(1);
    FUN_0056b1a0(&stack0x00000000,0);
    FUN_00614160(&stack0x00000100);
    DAT_006ec990 = 0xc;
    __security_check_cookie(uVar2);
    return;
  }
LAB_004b08a5:
  __security_check_cookie(uVar2);
  return;
}

