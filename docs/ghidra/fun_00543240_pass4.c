
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00543240(void)

{
  float fVar1;
  float local_8;
  float local_4;
  
  local_8 = _DAT_0076be90;
  local_4 = _DAT_0076be94;
  FUN_0053e0d0(&local_8);
  if (local_8 <= 0.99) {
    if (local_8 < 0.0) {
      local_8 = 0.0;
    }
  }
  else {
    local_8 = 0.99;
  }
  fVar1 = 0.99;
  if ((0.99 < local_4) || (fVar1 = 0.0, local_4 < 0.0)) {
    local_4 = fVar1;
  }
  thunk_FUN_0042041b(local_8,local_4,_DAT_0075a944 * 0.05,0x3d4ccccd,200,0xd2,0xaf,200,DAT_0075bf0c,
                     0,0,0);
  return;
}

