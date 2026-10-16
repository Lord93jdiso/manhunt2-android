
/* WARNING: Type propagation algorithm not settling */

void __fastcall FUN_006081d0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  undefined **ppuVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 uVar15;
  int aiStack_48 [7];
  char acStack_2c [40];
  uint local_4;
  
  local_4 = DAT_006dc2e0 ^ (uint)aiStack_48;
  piVar1 = (int *)(param_1 + 0x10);
  if (*piVar1 == 0) {
    uVar15 = 0;
    piVar14 = piVar1;
    FUN_0060d7d0(piVar1,0);
    uVar2 = FUN_004c6d20();
    uVar5 = *(undefined4 *)(param_1 + 8);
    uVar9 = *(undefined4 *)(param_1 + 0xc);
    uVar13 = 0;
    uVar12 = 0;
    uVar11 = 0;
    uVar10 = 0;
    uVar3 = thunk_FUN_00404010(uVar5,uVar9,0,0,0,0,uVar2);
    iVar4 = D3DXCreateEffectEx(uVar3,uVar5,uVar9,uVar10,uVar11,uVar12,uVar13,uVar2,piVar14,uVar15);
    if ((iVar4 != 0) || (piVar14 = (int *)*piVar1, piVar14 == (int *)0x0)) {
      __security_check_cookie(local_4 ^ (uint)aiStack_48);
      return;
    }
    uVar5 = (**(code **)(*piVar14 + 0x24))(piVar14,0,"g_mWorld");
    *(undefined4 *)(param_1 + 0x14) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_mWorldInverseTranspose");
    *(undefined4 *)(param_1 + 0x18) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_mWorldViewProjection");
    *(undefined4 *)(param_1 + 0x1c) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_mInverseView");
    *(undefined4 *)(param_1 + 0x20) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_mView");
    *(undefined4 *)(param_1 + 0x24) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_amBoneMtx");
    *(undefined4 *)(param_1 + 0x28) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_oDiffuseSampler");
    *(undefined4 *)(param_1 + 0x2c) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_oDiffuseTex");
    *(undefined4 *)(param_1 + 0x30) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_oSecondSampler");
    *(undefined4 *)(param_1 + 0x34) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_oSecondTex");
    *(undefined4 *)(param_1 + 0x38) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_vLightAmbient");
    *(undefined4 *)(param_1 + 0x3c) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_avLightPosX");
    *(undefined4 *)(param_1 + 0x40) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_avLightPosY");
    *(undefined4 *)(param_1 + 0x44) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_avLightPosZ");
    *(undefined4 *)(param_1 + 0x48) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_avLightColR");
    *(undefined4 *)(param_1 + 0x4c) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_avLightColG");
    *(undefined4 *)(param_1 + 0x50) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_avLightColB");
    *(undefined4 *)(param_1 + 0x54) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_avLight4OneOverRange");
    *(undefined4 *)(param_1 + 0x58) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_avLight4SpecularIntensity");
    *(undefined4 *)(param_1 + 0x5c) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_vFogAttributes");
    *(undefined4 *)(param_1 + 0x60) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_vFogColor");
    *(undefined4 *)(param_1 + 100) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_vDiffuseTransform");
    *(undefined4 *)(param_1 + 0x68) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_vAlphaTest");
    *(undefined4 *)(param_1 + 0x6c) = uVar5;
    uVar5 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,0,"g_vTexCoordOffset");
    *(undefined4 *)(param_1 + 0x70) = uVar5;
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined4 *)(param_1 + 0x88) = 0;
    *(undefined4 *)(param_1 + 0x8c) = 0;
    *(undefined4 *)(param_1 + 0x90) = 0;
    *(undefined4 *)(param_1 + 0x94) = 0;
    *(undefined4 *)(param_1 + 0x98) = 0;
    aiStack_48[0] = 0;
    if (PTR_DAT_006da234 != (undefined *)0x0) {
      ppuVar8 = &PTR_DAT_006da234;
      puVar7 = (undefined4 *)(param_1 + 0x78);
      puVar6 = PTR_DAT_006da234;
      do {
        _sprintf(acStack_2c + 8,"Render%s",puVar6);
        uVar5 = (**(code **)(*(int *)*piVar1 + 0x34))((int *)*piVar1,acStack_2c + 8);
        puVar7[-1] = uVar5;
        _sprintf(acStack_2c,"RenderSkinned%s",*ppuVar8);
        uVar5 = (**(code **)(*(int *)*piVar1 + 0x34))((int *)*piVar1,acStack_2c);
        *puVar7 = uVar5;
        aiStack_48[0] = aiStack_48[0] + 1;
        ppuVar8 = &PTR_DAT_006da234 + aiStack_48[0];
        puVar6 = *ppuVar8;
        puVar7 = puVar7 + 2;
      } while (puVar6 != (undefined *)0x0);
    }
    aiStack_48[5] = 0;
    aiStack_48[6] = 0;
    acStack_2c[0] = '\0';
    acStack_2c[1] = '\0';
    acStack_2c[2] = '\0';
    acStack_2c[3] = '\0';
    aiStack_48[1] = 0;
    aiStack_48[2] = 0;
    acStack_2c[4] = '\0';
    acStack_2c[5] = '\0';
    acStack_2c[6] = -0x80;
    acStack_2c[7] = '?';
    aiStack_48[3] = 0;
    aiStack_48[4] = 0;
    FUN_00607eb0(aiStack_48 + 1);
    FUN_00607da0(0,0x3f800000,0);
    FUN_00607c10(aiStack_48 + 5);
    FUN_00607e60(0,0x3f800000,0);
  }
  __security_check_cookie(local_4 ^ (uint)aiStack_48);
  return;
}

