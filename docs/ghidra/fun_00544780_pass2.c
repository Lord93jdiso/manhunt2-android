
void FUN_00544780(void)

{
  int iVar1;
  undefined4 uVar2;
  float10 fVar3;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  char local_10 [12];
  uint local_4;
  
  local_4 = DAT_006dc2e0 ^ (uint)&local_24;
  if (DAT_0075b10c != 0) {
    iVar1 = thunk_FUN_004103a7();
    if ((iVar1 == 2) && (DAT_0075b734 != 0)) {
      fVar3 = (float10)FUN_0053ec60(1,0x3f4ccccd);
      local_1c = (float)fVar3;
      fVar3 = (float10)FUN_0053fa00();
      local_18 = (float)fVar3;
      fVar3 = (float10)FUN_0053fa40();
      local_14 = (float)fVar3;
      _sprintf(local_10,"%d",DAT_0075b738);
      uVar2 = FUN_0056b730("BOCOUNT",0);
      fVar3 = (float10)FUN_00543f30(uVar2,0x3f99999a,1,0);
      local_20 = (float)((float10)0.5 - fVar3 * (float10)0.5);
      FUN_0053f490(0,0,0,0xff);
      local_24 = local_20 + local_18;
      FUN_00544180(uVar2,local_24,local_14 + 0.06,0x3f99999a,0x3f4ccccd,0,1,0);
      FUN_0053f490(0x96,0x96,0x96,0xff);
      FUN_00544180(uVar2,local_20,0x3d75c28f,0x3f99999a,0x3f4ccccd,0,1,0);
      local_24 = local_1c + 0.06;
      fVar3 = (float10)FUN_005440e0(local_10,0x3fc00000,1,0);
      local_20 = (float)((float10)0.5 - fVar3 * (float10)0.5);
      FUN_0053f490(0,0,0,0xff);
      local_1c = local_20 + local_18;
      thunk_FUN_0042942b(local_10,local_1c,local_14 + local_24,0x3fc00000,0x3fc00000,0,1);
      FUN_0053f490(0x96,0x96,0x96,0xff);
      thunk_FUN_0042942b(local_10,local_20,local_24,0x3fc00000,0x3fc00000,0,1);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_24);
  return;
}

