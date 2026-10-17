
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_00602ea0(int param_1)

{
  int iVar1;
  bool bVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  float local_170;
  float local_16c;
  float local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 local_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined1 local_fc [84];
  undefined1 local_a8 [44];
  int iStack_7c;
  undefined1 local_54 [84];
  
  FUN_004deb10();
  FUN_004deb10();
  FUN_004deb10();
  uVar7 = 0;
  local_170 = 0.0;
  FUN_005b6e30();
  iVar5 = FUN_00603490();
  if (iVar5 == 3) {
    local_168 = *(float *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x58);
    FUN_00600280(local_54,local_168,&local_168);
    FUN_006004e0(local_a8,local_168,&local_168);
    uVar7 = FUN_00602050(&local_170,local_168,&local_16c);
    uStack_158 = 0;
    uStack_15c = 0;
    uStack_160 = 0;
    uStack_164 = 0;
    uStack_148 = 0;
    uStack_14c = 0;
    uStack_150 = 0;
    uStack_154 = 0;
    puVar6 = (undefined4 *)FUN_005fe480(&local_134);
    uStack_164 = *puVar6;
    uStack_160 = puVar6[1];
    uStack_15c = puVar6[2];
    uStack_158 = puVar6[3];
    uStack_128 = 0;
    uStack_12c = 0;
    uStack_130 = 0;
    local_134 = 0;
    FUN_0060d860(&local_134,param_1 + 0x14,0x42c80000);
    uStack_138 = 0;
    uStack_13c = 0;
    uStack_140 = 0;
    uStack_144 = 0;
    FUN_0060d800(&uStack_144,&uStack_164,&local_134);
    uStack_154 = uStack_144;
    uStack_150 = uStack_140;
    uStack_14c = uStack_13c;
    uStack_148 = uStack_138;
    FUN_005f0070(&uStack_164,&uStack_154);
    fVar3 = local_170;
    bVar2 = (int)local_170 <= *(int *)(*(int *)(param_1 + 4) + 0x34);
    if ((((*(int *)(*(int *)(param_1 + 8) + 0xc) == 0) || (iVar5 = FUN_00526960(), iVar5 != 0x83))
        || (uVar7 == 0)) && (bVar2)) {
      if (iStack_7c == 0) {
        local_170 = 0.0;
        if (0 < (int)fVar3) {
          if (local_168 - local_16c <= _DAT_006d9a8c) {
            local_16c = (local_168 - local_16c) / _DAT_006d9a8c;
            local_170 = 1.0 - local_16c;
          }
          else {
            local_170 = 0.0;
          }
        }
        uVar7 = FUN_005febf0(local_54,local_170);
        FUN_005b6e90();
        return uVar7 & 0xff;
      }
      uVar7 = FUN_005febf0(local_a8,0);
      FUN_005b6e90();
      return uVar7 & 0xff;
    }
  }
  else {
    iVar5 = FUN_00603490();
    if ((iVar5 == 0) || (iVar5 = FUN_00603490(), iVar5 == 1)) {
      iVar5 = **(int **)(*(int *)(*(int *)(param_1 + 8) + 8) + 0xb8);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar5 + 0x60);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar5 + 100);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar5 + 0x68);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar5 + 0x6c);
      iVar5 = FUN_00602050(&local_170,*(undefined4 *)(*(int *)(param_1 + 4) + 0x14),&local_16c);
      if (iVar5 != 0) {
LAB_006031df:
        FUN_005b6e90();
        return 1;
      }
      iVar5 = *(int *)(*(int *)(param_1 + 8) + 8);
      uVar7 = 0;
      if ((iVar5 == 0) || (*(int *)(*(int *)(iVar5 + 700) + 0x150) != 0x37)) {
        iVar5 = FUN_006004e0(local_fc,*(undefined4 *)(*(int *)(param_1 + 4) + 0x14),&local_16c);
        if ((iVar5 == 0) && (*(int *)(*(int *)(param_1 + 4) + 4) != 2)) {
          FUN_00600280(local_fc,*(undefined4 *)(*(int *)(param_1 + 4) + 0x14),&local_16c);
        }
        cVar4 = FUN_005febf0(local_fc,0);
        if (cVar4 != '\0') goto LAB_006031df;
      }
    }
    else {
      iVar5 = FUN_00603490();
      if (iVar5 == 4) {
        FUN_005fe480(&local_134);
        FUN_0043ea00(&local_134,*(undefined4 *)(*(int *)(param_1 + 4) + 0x14));
        FUN_004de2e0(0x3000,1);
        uVar8 = 0;
        if (DAT_0070526c != 0) {
          do {
            iVar5 = *(int *)(DAT_00705268 + uVar8 * 4);
            if (((*(int *)(iVar5 + 0x38) == 8) && (iVar1 = *(int *)(iVar5 + 0x34), iVar1 != 0)) &&
               (((byte)*(undefined4 *)(iVar1 + 0x70) & 7) == 7)) {
              thunk_FUN_0042b0b6(iVar1,0x448,0);
            }
            else {
              FUN_005febf0(iVar5,0);
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < DAT_0070526c);
        }
      }
    }
  }
  FUN_005b6e90();
  return uVar7;
}

