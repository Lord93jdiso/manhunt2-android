
undefined1 __thiscall FUN_005cfb90(int param_1,int param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  ushort *puVar7;
  int local_80 [32];
  
  puVar7 = *(ushort **)(param_1 + 0x44);
  if (puVar7 == (ushort *)0x0) {
    return 1;
  }
  piVar5 = local_80;
LAB_005cfbc0:
  do {
    if (*(int *)(puVar7 + 6) < 0) {
      cVar4 = FUN_005cc6e0(param_2,puVar7);
      if ((cVar4 != '\0') &&
         (iVar1 = *(int *)(param_1 + 0x40) + (uint)puVar7[0xe] * 8,
         cVar4 = (*param_3)(iVar1,iVar1 + (uint)puVar7[0xf] * 8,param_4), cVar4 == '\0')) {
        return 0;
      }
    }
    else {
      fVar2 = *(float *)(*(int *)(puVar7 + 6) * 4 + param_2);
      fVar3 = *(float *)(*(int *)(puVar7 + 6) * 4 + 0x10 + param_2);
      if ((fVar2 <= *(float *)(puVar7 + 2)) || (fVar3 <= *(float *)(puVar7 + 2))) {
        if ((*(float *)(puVar7 + 4) < fVar2 != (*(float *)(puVar7 + 4) == fVar2)) ||
           (piVar6 = piVar5, *(float *)(puVar7 + 4) < fVar3 != (*(float *)(puVar7 + 4) == fVar3))) {
          piVar6 = piVar5 + 1;
          *piVar5 = (uint)puVar7[1] * 0x10 + *(int *)(param_1 + 0x44);
        }
        puVar7 = (ushort *)((uint)*puVar7 * 0x10 + *(int *)(param_1 + 0x44));
        piVar5 = piVar6;
        goto LAB_005cfbc0;
      }
      if ((*(float *)(puVar7 + 4) < fVar2 != (*(float *)(puVar7 + 4) == fVar2)) ||
         (*(float *)(puVar7 + 4) < fVar3 != (*(float *)(puVar7 + 4) == fVar3))) {
        puVar7 = (ushort *)((uint)puVar7[1] * 0x10 + *(int *)(param_1 + 0x44));
        goto LAB_005cfbc0;
      }
    }
    if (piVar5 == local_80) {
      return 1;
    }
    puVar7 = (ushort *)piVar5[-1];
    piVar5 = piVar5 + -1;
  } while( true );
}

