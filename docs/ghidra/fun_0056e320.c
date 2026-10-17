
void FUN_0056e320(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  FUN_0060b610(0);
  FUN_005b80d0(1);
  FUN_0060cea0();
  FUN_0054bcf0();
  cVar2 = FUN_00549d30();
  if ((cVar2 == '\0') && (DAT_006ccf50 != 1)) {
    FUN_00547c80();
  }
  else {
    FUN_00547c70();
  }
  FUN_0060ceb0();
  FUN_0054a770(0);
  FUN_005b7720();
  FUN_005b7700();
  iVar3 = FUN_004b1840();
  fVar1 = (float)iVar3;
  if (iVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  iVar3 = FUN_00618eb0(fVar1 / 1000.0);
  while ((DAT_0075cd2c == 0x1a || (DAT_0075cd2c == 0x1b))) {
    iVar4 = FUN_004b1840();
    fVar1 = (float)iVar4;
    if (iVar4 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    if (2.0 <= fVar1 / 1000.0 - (float)iVar3) break;
    FUN_004b1870();
  }
  FUN_0060b610(1);
  return;
}

