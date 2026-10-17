
void FUN_00544460(void)

{
  int iVar1;
  float10 fVar2;
  undefined **_Format;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  char local_14 [8];
  char local_c [8];
  uint local_4;
  
  local_4 = DAT_006dc2e0 ^ (uint)&local_28;
  if (DAT_0075b10c != 0) {
    iVar1 = thunk_FUN_004103a7();
    if ((iVar1 == 2) && (DAT_0075b724 != 0)) {
      fVar2 = (float10)FUN_0053fa00();
      local_1c = (float)fVar2;
      fVar2 = (float10)FUN_0053fa40();
      local_20 = (float)fVar2;
      fVar2 = (float10)FUN_005440e0(&DAT_00663d04,0x3fc00000,1,0);
      local_18 = (float)fVar2;
      _sprintf(local_c,"%d",DAT_0075b72c);
      if (DAT_0075b730 < 10) {
        _Format = &PTR_s_UNPROD_4_ANIM_0064251c_0x14_00663d00;
      }
      else {
        _Format = (undefined **)&DAT_0065af1c;
      }
      _sprintf(local_14,(char *)_Format,DAT_0075b730);
      fVar2 = (float10)FUN_005440e0(local_14,0x3fc00000,1,0);
      local_28 = (float)((float10)0.9559999704360962 - fVar2);
      FUN_0053f490(0,0,0,0xff);
      local_20 = local_20 + 0.06;
      local_24 = local_1c + local_28;
      thunk_FUN_0042942b(local_14,local_24,local_20,0x3fc00000,0x3fc00000,0,1);
      FUN_0053f490(0x96,0x96,0x96,0xff);
      thunk_FUN_0042942b(local_14,local_28,0x3d75c28f,0x3fc00000,0x3fc00000,0,1);
      local_28 = 0.956 - local_18 * 1.13;
      FUN_0053f490(0,0,0,0xff);
      local_24 = local_1c + local_28;
      thunk_FUN_0042942b(&DAT_00663ce0,local_24,local_20,0x3fc00000,0x3fc00000,0,1);
      FUN_0053f490(0x96,0x96,0x96,0xff);
      thunk_FUN_0042942b(&DAT_00663ce0,local_28,0x3d75c28f,0x3fc00000,0x3fc00000,0,1);
      local_24 = local_28 - local_18 * 0.13;
      fVar2 = (float10)FUN_005440e0(local_c,0x3fc00000,1,0);
      local_28 = (float)((float10)local_24 - fVar2);
      FUN_0053f490(0,0,0,0xff);
      local_24 = local_1c + local_28;
      thunk_FUN_0042942b(local_c,local_24,local_20,0x3fc00000,0x3fc00000,0,1);
      FUN_0053f490(0x96,0x96,0x96,0xff);
      thunk_FUN_0042942b(local_c,local_28,0x3d75c28f,0x3fc00000,0x3fc00000,0,1);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_28);
  return;
}

