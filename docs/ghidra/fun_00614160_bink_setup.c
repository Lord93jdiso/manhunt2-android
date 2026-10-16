
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00614160(undefined4 param_1)

{
  HWND hWnd;
  int iVar1;
  undefined4 uVar2;
  float10 fVar3;
  float fStack_8;
  undefined1 auStack_4 [4];
  
  DAT_007064d4 = 1;
  DAT_0079e60c = 0;
  FUN_0056b5a0();
  FUN_0060d7d0();
  FUN_0060d520(4,0);
  FUN_0060d4f0();
  FUN_00613e00();
  _BinkSetSoundSystem_8(_BinkOpenDirectSound_4_exref,0);
  hWnd = (HWND)FUN_00408620();
  FUN_00613db0(auStack_4,&fStack_8);
  iVar1 = _BinkOpen_8(param_1,0x84000);
  while (DAT_0079e708 = iVar1, iVar1 == 0) {
    FUN_0054a770(1);
    iVar1 = _BinkOpen_8(param_1,0x84000);
  }
  fVar3 = (float10)FUN_00613b20();
  fStack_8 = (float)(fVar3 * (float10)DAT_007605e8);
  uVar2 = FUN_00618eb0();
  _BinkSetVolume_12(iVar1,**(undefined4 **)(iVar1 + 0x250),uVar2);
  _DAT_007064d8 = *(undefined4 *)(DAT_0079e708 + 0xc);
  uVar2 = thunk_FUN_00404010();
  uVar2 = thunk_FUN_0041e650(uVar2);
  DAT_0079e600 = FUN_00614460(hWnd,uVar2);
  if (DAT_0079e600 != 0) {
    FUN_00613b30();
    iVar1 = FUN_00614060();
    if (iVar1 != 0) {
      if (DAT_0079e708 == 0) {
        return 0;
      }
      SetTimer(hWnd,0,1000,(TIMERPROC)0x0);
      timeBeginPeriod(1);
      FUN_006140c0();
      return 1;
    }
    FUN_00614510(DAT_0079e600);
  }
  _BinkClose_4(DAT_0079e708);
  DAT_0079e708 = 0;
  return 0;
}

