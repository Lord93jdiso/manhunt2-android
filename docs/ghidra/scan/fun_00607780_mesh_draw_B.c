
void __fastcall FUN_00607780(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  ushort *puVar5;
  undefined4 uStack_6c;
  int *piStack_68;
  undefined4 uStack_64;
  int *piStack_60;
  undefined4 uStack_5c;
  uint uStack_24;
  undefined4 auStack_20 [8];
  
  piVar1 = (int *)thunk_FUN_00404010();
  (**(code **)(*piVar1 + 0x164))();
  if (*(int *)(param_1 + 0x90) != 0) {
    uStack_5c = 0x6077ac;
    piStack_60 = (int *)thunk_FUN_00404010();
    uStack_5c = *(undefined4 *)(param_1 + 0x90);
    uStack_64 = 0x6077be;
    (**(code **)(*piStack_60 + 0x15c))();
    uStack_64 = 0x6077c3;
    piStack_68 = (int *)thunk_FUN_00404010();
    uStack_64 = *(undefined4 *)(param_1 + 0x88);
    uStack_6c = 0x6077d5;
    (**(code **)(*piStack_68 + 0x1a0))();
    uStack_6c = 0x6077da;
    piVar1 = (int *)thunk_FUN_00404010();
    iVar3 = *piVar1;
    uStack_6c = 0x6077e5;
    uStack_6c = FUN_00607220();
    (**(code **)(iVar3 + 400))(piVar1,0,*(undefined4 *)(param_1 + 0x8c),0);
    if (((byte)*(undefined4 *)(param_1 + 0x70) & 0xe) == 0xe) {
      FUN_0060d7d0();
      FUN_00426330();
      FUN_00607af0(auStack_20[0],uStack_24);
    }
    else {
      thunk_FUN_0041d879(auStack_20[0],0);
    }
    uStack_24 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      puVar5 = (ushort *)(param_1 + 0xac);
      do {
        uVar2 = FUN_005c2e30(puVar5[1]);
        iVar3 = FUN_006075a0(puVar5 + -0xc,uVar2);
        if ((DAT_00789498 == 0) || (iVar3 == DAT_00789498)) {
          piVar1 = (int *)FUN_005c2900(auStack_20,
                                       ((byte)*(undefined4 *)(param_1 + 0x70) & 0xe) == 0xe,
                                       *(undefined4 *)(param_1 + 0x70));
          (**(code **)(*piVar1 + 0x2c))(0);
          piVar4 = (int *)thunk_FUN_00404010();
          (**(code **)(*piVar4 + 0x148))
                    (piVar4,4,0,0,*(undefined4 *)(param_1 + 0x30),puVar5[2],*puVar5 / 3);
          (**(code **)(*piVar1 + 0x30))();
          FUN_005c2640(auStack_20);
        }
        uStack_24 = uStack_24 + 1;
        puVar5 = puVar5 + 0x16;
      } while (uStack_24 < *(uint *)(param_1 + 0xc));
    }
    piStack_60 = (int *)0x0;
    uStack_64 = 0;
    piStack_68 = (int *)0x0;
    uStack_6c = 0;
    uStack_5c = 0;
    FUN_0057e390();
    thunk_FUN_0041d879(&uStack_6c,0);
  }
  return;
}

