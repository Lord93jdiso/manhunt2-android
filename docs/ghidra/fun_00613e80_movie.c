
undefined4 FUN_00613e80(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_20;
  float local_1c;
  undefined1 local_14 [20];
  
  if (DAT_0079e708 == (int *)0x0) {
    return 0;
  }
  fVar3 = (float)DAT_0079bf40;
  fVar1 = (float)DAT_0079bf3c / fVar3;
  if (1.7777778 <= fVar1) {
    fVar1 = 1.7777778;
  }
  fVar1 = fVar1 / 1.7777778;
  local_1c = (float)*DAT_0079e708;
  if (*DAT_0079e708 < 0) {
    local_1c = local_1c + 4.2949673e+09;
  }
  local_1c = (float)DAT_0079bf3c / local_1c;
  fVar2 = (float)DAT_0079e708[1];
  if (DAT_0079e708[1] < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  local_20 = fVar3 / fVar2;
  if (fVar1 <= 1.0) {
    local_20 = fVar1 * local_20;
  }
  else {
    local_1c = fVar1 * local_1c;
  }
  FUN_006150b0(DAT_0079e604,0,(fVar3 - local_20 * fVar2) * 0.5,local_1c,local_20,0x3f800000);
  FUN_00613e00();
  FUN_0060cea0();
  FUN_004e1150();
  FUN_0060ee60(local_14,1);
  FUN_0060ceb0();
  FUN_00613e00();
  return 1;
}

