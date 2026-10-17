
void FUN_00545070(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  float10 fVar4;
  float local_10;
  int local_c;
  
  local_c = 0;
  do {
    if ((&DAT_0075b38c)[local_c] != 0) {
      fVar4 = (float10)FUN_005440e0((&DAT_0075b4c4)[local_c],0x3f333333,1,0);
      fVar1 = (float)fVar4;
      local_10 = 0.5 - fVar1 * 0.5;
      fVar2 = (float)local_c * 0.038 + 0.01;
      if (local_c < 1) {
        uVar3 = 0x80;
      }
      else {
        if (DAT_0075b388 == 0) {
          return;
        }
        if ((&DAT_0075b45c)[local_c] == 0) {
          uVar3 = 0;
          local_10 = 0.042;
        }
        else {
          uVar3 = 0;
          local_10 = 0.954;
        }
      }
      FUN_0053f490(0xff,0xff,0xff,0xff);
      fVar4 = (float10)FUN_0053ec60(1,0x3f333333,uVar3,0,0,0x70,0,0,0,0);
      if ((&DAT_0075b45c)[local_c] == 0) {
        thunk_FUN_0042041b(local_10 - 0.01,fVar2,fVar1 + 0.02,(float)fVar4);
        uVar3 = (&DAT_0075b4c4)[local_c];
      }
      else {
        thunk_FUN_0042041b((local_10 - 0.01) - fVar1,fVar2,fVar1 + 0.02,(float)fVar4);
        uVar3 = (&DAT_0075b4c4)[local_c];
        local_10 = local_10 - fVar1;
      }
      thunk_FUN_0042942b(uVar3,local_10,fVar2,0x3f333333,0x3f333333,0,1);
    }
    local_c = local_c + 1;
  } while (local_c < 0x1a);
  return;
}

