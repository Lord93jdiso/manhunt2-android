
undefined4 FUN_005c9f50(byte *param_1)

{
  int *piVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  bool bVar7;
  
  iVar6 = DAT_00789790;
  do {
    if (iVar6 == 0) {
      return 0;
    }
    piVar1 = &DAT_007895fc + iVar6;
    iVar6 = iVar6 + -1;
    pbVar3 = (byte *)(*piVar1 + 8);
    pbVar5 = param_1;
    do {
      bVar2 = *pbVar3;
      bVar7 = bVar2 < *pbVar5;
      if (bVar2 != *pbVar5) {
LAB_005c9f90:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_005c9f95;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar7 = bVar2 < pbVar5[1];
      if (bVar2 != pbVar5[1]) goto LAB_005c9f90;
      pbVar3 = pbVar3 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_005c9f95:
    if (iVar4 == 0) {
      return *(undefined4 *)(&DAT_00789600 + iVar6 * 4);
    }
  } while( true );
}

