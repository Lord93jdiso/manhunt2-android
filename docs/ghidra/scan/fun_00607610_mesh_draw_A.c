
void __fastcall FUN_00607610(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *puVar4;
  undefined4 uStack_3c;
  undefined4 *puStack_38;
  int *piStack_34;
  undefined4 uStack_30;
  int *piStack_2c;
  undefined4 uStack_28;
  int *piStack_24;
  undefined4 uStack_20;
  
  uStack_20 = 0x60761d;
  piStack_24 = (int *)thunk_FUN_00404010();
  uStack_20 = 0;
  uStack_28 = 0x60762a;
  (**(code **)(*piStack_24 + 0x164))();
  uStack_28 = 0x60762f;
  piStack_2c = (int *)thunk_FUN_00404010();
  uStack_28 = *(undefined4 *)(param_1 + 0x90);
  uStack_30 = 0x607641;
  (**(code **)(*piStack_2c + 0x15c))();
  uStack_30 = 0x607646;
  piStack_34 = (int *)thunk_FUN_00404010();
  uStack_30 = *(undefined4 *)(param_1 + 0x88);
  puStack_38 = (undefined4 *)0x607658;
  (**(code **)(*piStack_34 + 0x1a0))();
  puStack_38 = (undefined4 *)0x60765d;
  piVar1 = (int *)thunk_FUN_00404010();
  iVar3 = *piVar1;
  puStack_38 = (undefined4 *)0x607668;
  puStack_38 = (undefined4 *)FUN_00607220();
  uStack_3c = 0;
  (**(code **)(iVar3 + 400))(piVar1,0,*(undefined4 *)(param_1 + 0x8c));
  puStack_38 = (undefined4 *)0x0;
  if (*(int *)(param_1 + 0xc) != 0) {
    puVar4 = (ushort *)(param_1 + 0xac);
    do {
      if (*puVar4 != 0) {
        uVar2 = FUN_005c2e30(puVar4[1]);
        iVar3 = FUN_006075a0(puVar4 + -0xc,uVar2);
        if ((DAT_00789498 == 0) || (iVar3 == DAT_00789498)) {
          piVar1 = (int *)FUN_005c2900(&uStack_3c,
                                       ((byte)*(undefined4 *)(param_1 + 0x70) & 0xe) == 0xe,0);
          (**(code **)(*piVar1 + 0x2c))(0);
          puStack_38 = (undefined4 *)thunk_FUN_00404010();
          piStack_34 = (int *)*puStack_38;
          (*(code *)piStack_34[0x52])
                    (puStack_38,4,0,0,*(undefined4 *)(param_1 + 0x30),puVar4[2],*puVar4 / 3);
          (**(code **)(*piVar1 + 0x30))();
          FUN_005c2640(&uStack_3c);
        }
      }
      puStack_38 = (undefined4 *)((int)puStack_38 + 1);
      puVar4 = puVar4 + 0x16;
    } while (puStack_38 < *(undefined4 **)(param_1 + 0xc));
  }
  return;
}

