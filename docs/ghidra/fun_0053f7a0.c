
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053f7a0(void)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  DAT_0079d0e4 = 1;
  FUN_00608960(_DAT_0076dee0);
  uVar7 = 0;
  _DAT_0079d0ec = _DAT_0075b124;
  if (DAT_0076decc != 0) {
    puVar8 = &DAT_0076de90;
    do {
      uVar1 = *puVar8;
      fVar2 = (float)puVar8[-2] * 0.05 * 0.5;
      fVar3 = _DAT_0075b11c - fVar2;
      fVar4 = _DAT_0075b120 + fVar2;
      fVar5 = _DAT_0075b11c + fVar2;
      fVar2 = _DAT_0075b120 - fVar2;
      if ((DAT_00789490 != 0) && (cVar6 = FUN_00599290(), cVar6 != '\0')) {
        thunk_FUN_0042041b(fVar3,fVar4,fVar5 - fVar3,fVar2 - fVar4,uVar1,uVar1,uVar1,uVar1,
                           *(undefined4 *)(&DAT_0076de98 + puVar8[-4] * 4),0,0,0);
      }
      uVar7 = uVar7 + 1;
      puVar8 = puVar8 + 1;
    } while (uVar7 < DAT_0076decc);
  }
  _DAT_0079d0ec = 0;
  DAT_0079d0e4 = 0;
  FUN_00592740();
  FUN_004e1150();
  FUN_00608960(0);
  return;
}

