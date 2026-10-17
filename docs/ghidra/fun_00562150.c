
void __fastcall FUN_00562150(int param_1)

{
  float fVar1;
  char cVar2;
  float10 fVar3;
  
  if (*(int *)(param_1 + 8) != 0) {
    cVar2 = FUN_00564200();
    if (cVar2 == '\0') {
      fVar1 = (float)DAT_006ece6c;
      if (DAT_006ece6c < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      fVar1 = *(float *)(param_1 + 0x5c0) - fVar1 / 1000.0;
      *(float *)(param_1 + 0x5c0) = fVar1;
      if (fVar1 < 0.0) {
        fVar3 = (float10)FUN_00401040();
        if ((float)(fVar3 * ((float10)100.0 - (float10)0) + (float10)0) <
            *(float *)(param_1 + 0x5c4)) {
          *(float *)(param_1 + 0x5c0) =
               *(float *)(param_1 + 0x5b8) + *(float *)(param_1 + 0x5b4) +
               *(float *)(param_1 + 0x5bc);
          FUN_00605e20(*(undefined4 *)(param_1 + 0x5a8),*(undefined4 *)(param_1 + 0x5b0),
                       *(undefined4 *)(param_1 + 0x5b4),*(undefined4 *)(param_1 + 0x5b8),
                       *(undefined4 *)(param_1 + 0x5bc));
        }
      }
    }
  }
  return;
}

