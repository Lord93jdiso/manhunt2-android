
undefined4
FUN_00412900(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  float10 fVar9;
  float local_74;
  int local_70;
  int local_6c;
  undefined1 auStack_58 [12];
  int iStack_4c;
  undefined4 auStack_48 [18];
  
  local_74 = -1.0;
  local_6c = 0;
  piVar4 = (int *)thunk_FUN_0041e650();
  thunk_FUN_004ae6e0(0);
  piVar5 = (int *)FUN_0040e680();
  iVar6 = piVar5[1];
  local_70 = 0;
  if (0 < iVar6) {
    do {
      if ((local_70 < 0) || (iVar6 <= local_70)) {
        FUN_00616f0c(L"nIndex >= 0 && nIndex < m_nSize",
                     L"w:\\manhunt2_pc\\mh2_vs2005\\dxut\\core\\DXUTmisc.h",0x58);
      }
      puVar7 = *(undefined4 **)(*piVar5 + local_70 * 4);
      (**(code **)(*piVar4 + 0x20))(piVar4,*puVar7,auStack_58);
      iVar6 = 0;
      if (0 < (int)puVar7[0x198]) {
        do {
          if ((iVar6 < 0) || ((int)puVar7[0x198] <= iVar6)) {
            FUN_00616f0c(L"nIndex >= 0 && nIndex < m_nSize",
                         L"w:\\manhunt2_pc\\mh2_vs2005\\dxut\\core\\DXUTmisc.h",0x58);
          }
          iVar1 = *(int *)(puVar7[0x197] + iVar6 * 4);
          iVar8 = 0;
          if (0 < *(int *)(iVar1 + 0x13c)) {
            do {
              if ((iVar8 < 0) || (*(int *)(iVar1 + 0x13c) <= iVar8)) {
                FUN_00616f0c(L"nIndex >= 0 && nIndex < m_nSize",
                             L"w:\\manhunt2_pc\\mh2_vs2005\\dxut\\core\\DXUTmisc.h",0x58);
              }
              iVar2 = *(int *)(*(int *)(iVar1 + 0x138) + iVar8 * 4);
              if (((*(int *)(iVar2 + 0x10) == 0) || (*(int *)(iVar2 + 8) == iStack_4c)) &&
                 (cVar3 = thunk_FUN_007a81b0(iVar2,param_2,param_3), cVar3 != '\0')) {
                fVar9 = (float10)FUN_004107b0(iVar2,param_4,auStack_58);
                if (local_74 < (float)fVar9) {
                  local_74 = (float)fVar9;
                  local_6c = iVar2;
                }
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < *(int *)(iVar1 + 0x13c));
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)puVar7[0x198]);
      }
      iVar6 = piVar5[1];
      local_70 = local_70 + 1;
    } while (local_70 < iVar6);
    if (local_6c != 0) {
      FUN_00410c60(auStack_48,local_6c,param_2,param_3);
      puVar7 = auStack_48;
      for (iVar6 = 0x12; iVar6 != 0; iVar6 = iVar6 + -1) {
        *param_1 = *puVar7;
        puVar7 = puVar7 + 1;
        param_1 = param_1 + 1;
      }
      return 0;
    }
  }
  return 0x80040902;
}

