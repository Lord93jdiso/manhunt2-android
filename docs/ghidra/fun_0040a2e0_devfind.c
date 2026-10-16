
void FUN_0040a2e0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *local_74;
  int local_70;
  undefined4 local_6c [10];
  wchar_t awStack_44 [32];
  uint local_4;
  
  local_4 = DAT_006dc2e0 ^ (uint)&local_74;
  local_70 = param_1;
  local_74 = param_2;
  *param_2 = 0;
  cVar2 = FUN_00403fd0();
  if (cVar2 == '\0') {
    local_6c[0] = 0x68;
    thunk_FUN_00436416(param_1,local_6c);
    thunk_FUN_0042cd4c(0,0);
    piVar3 = (int *)FUN_0040ea20();
    iVar5 = piVar3[1];
    iVar7 = 0;
    if (0 < iVar5) {
      do {
        if ((iVar7 < 0) || (iVar5 <= iVar7)) {
          FUN_00616f0c(L"nIndex >= 0 && nIndex < m_nSize",
                       L"w:\\manhunt2_pc\\mh2_vs2005\\dxut\\core\\DXUTmisc.h",0x58);
        }
        puVar1 = *(undefined4 **)(*piVar3 + iVar7 * 4);
        iVar5 = 0;
        if (0 < (int)puVar1[0x8c]) {
          do {
            if ((iVar5 < 0) || ((int)puVar1[0x8c] <= iVar5)) {
              FUN_00616f0c(L"nIndex >= 0 && nIndex < m_nSize",
                           L"w:\\manhunt2_pc\\mh2_vs2005\\dxut\\core\\DXUTmisc.h",0x58);
            }
            iVar6 = _wcsncmp((wchar_t *)(*(int *)(puVar1[0x8b] + iVar5 * 4) + 0xc),awStack_44,0x20);
            if (iVar6 == 0) {
              *local_74 = *puVar1;
              __security_check_cookie(local_4 ^ (uint)&local_74);
              return;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < (int)puVar1[0x8c]);
        }
        iVar5 = piVar3[1];
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar5);
    }
  }
  else {
    thunk_FUN_004ae6e0(0);
    piVar3 = (int *)thunk_FUN_0041e650();
    piVar4 = (int *)FUN_0040e680();
    iVar5 = piVar4[1];
    iVar7 = 0;
    if (0 < iVar5) {
      do {
        if ((iVar7 < 0) || (iVar5 <= iVar7)) {
          FUN_00616f0c(L"nIndex >= 0 && nIndex < m_nSize",
                       L"w:\\manhunt2_pc\\mh2_vs2005\\dxut\\core\\DXUTmisc.h",0x58);
        }
        puVar1 = *(undefined4 **)(*piVar4 + iVar7 * 4);
        iVar5 = (**(code **)(*piVar3 + 0x3c))(piVar3,*puVar1);
        if (iVar5 == local_70) {
          *local_74 = *puVar1;
          __security_check_cookie(local_4 ^ (uint)&local_74);
          return;
        }
        iVar5 = piVar4[1];
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar5);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_74);
  return;
}

