
void __fastcall FUN_005b6f80(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 auStack_40 [64];
  
  if ((*(byte *)(param_1 + 0x18) & 1) != 0) {
    iVar1 = FUN_005c0ba0();
    if (((byte)*(undefined4 *)(iVar1 + 0x70) & 0xe) == 0xe) {
      FUN_0053ac60();
      iVar1 = **(int **)(param_1 + 0x14);
      thunk_FUN_0041d879((*(int **)(param_1 + 0x14))[5],0);
      uStack_b4 = 0;
      uStack_b8 = 0;
      uStack_bc = 0;
      uStack_c0 = 0;
      uStack_a4 = 0;
      uStack_a8 = 0;
      uStack_ac = 0;
      uStack_b0 = 0;
      uStack_94 = 0;
      uStack_98 = 0;
      uStack_9c = 0;
      uStack_a0 = 0;
      uStack_90 = 0;
      uStack_8c = 0;
      uStack_88 = 0;
      uStack_84 = 0x3f800000;
      FUN_0057e9f0(*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x14));
      FUN_0057e390();
      iVar4 = 1;
      if (1 < iVar1) {
        iVar3 = 0x40;
        do {
          uVar2 = FUN_005c9f00(iVar4);
          FUN_004adee0(uVar2);
          FUN_0057e730();
          uStack_74 = 0;
          uStack_78 = 0;
          uStack_7c = 0;
          uStack_80 = 0;
          uStack_64 = 0;
          uStack_68 = 0;
          uStack_6c = 0;
          uStack_70 = 0;
          uStack_54 = 0;
          uStack_58 = 0;
          uStack_5c = 0;
          uStack_60 = 0;
          uStack_50 = 0;
          uStack_4c = 0;
          uStack_48 = 0;
          uStack_44 = 0x3f800000;
          FUN_0057e4d0(&uStack_c0,*(int *)(*(int *)(param_1 + 0x14) + 0x14) + iVar3);
          FUN_0057e4d0(auStack_40,&uStack_80);
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 0x40;
        } while (iVar4 < iVar1);
      }
      uVar7 = 0;
      puVar6 = &DAT_0077b680;
      puVar5 = &DAT_0077b680;
      uVar2 = FUN_0056abd0(iVar1,&DAT_0077b680,&DAT_0077b680,0);
      FUN_00607780(uVar2,iVar1,puVar5,puVar6,uVar7);
      return;
    }
    iVar1 = *(int *)(param_1 + 8);
    if ((iVar1 != 0) || (iVar1 = **(int **)(param_1 + 0x10), iVar1 != 0)) {
      if (*(char *)(*(int *)(iVar1 + 0xc) + 0x38) != '\0') {
        FUN_005c0880();
      }
      FUN_004adee0(iVar1 + 0x80);
      uVar8 = 0;
      puVar6 = &DAT_0077b680;
      puVar5 = &DAT_0077b680;
      uVar7 = 1;
      uVar2 = FUN_0056abd0(1,&DAT_0077b680,&DAT_0077b680,0);
      FUN_00607780(uVar2,uVar7,puVar5,puVar6,uVar8);
    }
  }
  return;
}

