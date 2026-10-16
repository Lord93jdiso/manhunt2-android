
void __thiscall FUN_004122c0(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  LPWSTR lpWideCharStr;
  undefined4 uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  LPWSTR pWVar7;
  int iVar8;
  uint uVar9;
  uint unaff_EDI;
  int iVar10;
  int *piVar11;
  uint uVar12;
  undefined1 auStack_124 [3];
  char cStack_121;
  uint uStack_120;
  undefined4 local_11c;
  int local_118;
  undefined4 local_114;
  uint uStack_110;
  uint *puStack_10c;
  uint *puStack_108;
  uint uStack_104;
  undefined4 auStack_fc [4];
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined1 auStack_d0 [4];
  undefined1 auStack_cc [200];
  uint local_4;
  
  local_4 = DAT_006dc2e0 ^ (uint)auStack_124;
  piVar4 = (int *)thunk_FUN_0041e650();
  if ((piVar4 != (int *)0x0) || (piVar4 = (int *)thunk_FUN_0041e650(), piVar4 != (int *)0x0)) {
    *(undefined4 *)(param_1 + 0xc) = param_3;
    *param_1 = 1;
    *(int **)(param_1 + 4) = piVar4;
    *(undefined4 *)(param_1 + 8) = param_2;
    thunk_FUN_00414ff0();
    local_11c = 0;
    local_118 = 0;
    local_114 = 0;
    local_ec = 0x16;
    local_e8 = 0x18;
    local_e4 = 0x17;
    local_e0 = 0x23;
    uStack_104 = (**(code **)(*piVar4 + 0x10))(piVar4);
    uStack_120 = 0;
    if (uStack_104 != 0) {
      do {
        uVar9 = uStack_120;
        puStack_10c = (uint *)FUN_00580ed0(0x668);
        if (puStack_10c == (uint *)0x0) {
          thunk_FUN_0040eba0(0);
          goto LAB_004126bc;
        }
        puStack_10c[0x194] = 0;
        puStack_10c[0x195] = 0;
        puStack_10c[0x196] = 0;
        puStack_10c[0x197] = 0;
        puStack_10c[0x198] = 0;
        puStack_10c[0x199] = 0;
        *puStack_10c = uVar9;
        piVar11 = piVar4;
        uVar12 = uVar9;
        puStack_108 = puStack_10c;
        (**(code **)(*piVar4 + 0x14))(piVar4,uVar9,0,puStack_10c + 1);
        thunk_FUN_0040eba0(0);
        uStack_120 = 0;
        do {
          uVar1 = auStack_fc[uStack_120];
          uStack_110 = (**(code **)(*piVar4 + 0x18))(piVar4,uVar9,uVar1);
          uVar9 = 0;
          if (uStack_110 != 0) {
            do {
              (**(code **)(*piVar4 + 0x1c))(piVar4,unaff_EDI,uVar1,uVar9,&puStack_10c);
              if (((((*(uint **)(param_1 + 0x3c) <= puStack_10c) &&
                    (*(uint **)(param_1 + 0x44) <= puStack_108)) &&
                   (puStack_10c <= *(uint **)(param_1 + 0x40))) &&
                  ((puStack_108 <= *(uint **)(param_1 + 0x48) &&
                   (*(uint *)(param_1 + 0x4c) <= uStack_104)))) &&
                 (uStack_104 <= *(uint *)(param_1 + 0x50))) {
                FUN_004356a1(piVar11,uVar12);
                return;
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < uStack_110);
          }
          uStack_120 = uStack_120 + 1;
          uVar9 = unaff_EDI;
        } while (uStack_120 < 4);
        (**(code **)(*piVar4 + 0x20))(piVar4,unaff_EDI,&local_ec);
        if ((local_118 < 1) || (iVar5 = thunk_FUN_004b35f2(auStack_d0,0,local_118), iVar5 == -1)) {
          FUN_0040f9a0(auStack_d0);
        }
        puVar3 = puStack_10c;
        _qsort((void *)puStack_10c[0x194],puStack_10c[0x195],0x10,(_PtFuncCompare *)&LAB_0040e7f0);
        iVar5 = FUN_00411cf0(puVar3,&local_11c);
        if ((iVar5 < 0) || ((int)puVar3[0x198] < 1)) {
          thunk_FUN_007a8910();
                    /* WARNING: Subroutine does not return */
          FUN_00580ef0(puVar3);
        }
        iVar5 = FUN_0040f9a0(&puStack_108);
        if (iVar5 < 0) {
          thunk_FUN_0040eba0(0);
          goto LAB_004126bc;
        }
        uStack_120 = unaff_EDI + 1;
      } while (uStack_120 < uStack_104);
    }
    iVar5 = 0;
    cStack_121 = '\x01';
    if (0 < *(int *)(param_1 + 0x5c)) {
      do {
        if ((iVar5 < 0) || (*(int *)(param_1 + 0x5c) <= iVar5)) {
          FUN_00616f0c(L"nIndex >= 0 && nIndex < m_nSize",
                       L"w:\\manhunt2_pc\\mh2_vs2005\\dxut\\core\\DXUTmisc.h",0x58);
        }
        iVar8 = *(int *)(*(int *)(param_1 + 0x58) + iVar5 * 4);
        iVar5 = iVar5 + 1;
        if (iVar5 < *(int *)(param_1 + 0x5c)) {
          iVar10 = iVar5;
          do {
            if ((iVar10 < 0) || (*(int *)(param_1 + 0x5c) <= iVar10)) {
              FUN_00616f0c(L"nIndex >= 0 && nIndex < m_nSize",
                           L"w:\\manhunt2_pc\\mh2_vs2005\\dxut\\core\\DXUTmisc.h",0x58);
            }
            iVar6 = FUN_00617e12(iVar8 + 0x204,
                                 *(int *)(*(int *)(param_1 + 0x58) + iVar10 * 4) + 0x204);
            if (iVar6 == 0) {
              cStack_121 = '\0';
              goto LAB_004125f0;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < *(int *)(param_1 + 0x5c));
        }
      } while (iVar5 < *(int *)(param_1 + 0x5c));
    }
LAB_004125f0:
    if (0 < *(int *)(param_1 + 0x5c)) {
      iVar5 = 0;
      do {
        if ((iVar5 < 0) || (*(int *)(param_1 + 0x5c) <= iVar5)) {
          FUN_00616f0c(L"nIndex >= 0 && nIndex < m_nSize",
                       L"w:\\manhunt2_pc\\mh2_vs2005\\dxut\\core\\DXUTmisc.h",0x58);
        }
        puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x58) + iVar5 * 4);
        lpWideCharStr = (LPWSTR)(puVar2 + 0x114);
        MultiByteToWideChar(0,0,(LPCSTR)(puVar2 + 0x81),-1,lpWideCharStr,100);
        *(undefined2 *)(puVar2 + 0x146) = 0;
        if (cStack_121 == '\0') {
          thunk_FUN_004ae450(auStack_cc,100,L" (#%d)",*puVar2);
          iVar8 = 0x100;
          pWVar7 = lpWideCharStr;
          do {
            if (*pWVar7 == L'\0') {
              if (iVar8 != 0) {
                thunk_FUN_004cc900(lpWideCharStr + (0x100 - iVar8),0x100 - (0x100 - iVar8),
                                   auStack_cc);
              }
              break;
            }
            pWVar7 = pWVar7 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(param_1 + 0x5c));
    }
    thunk_FUN_0040eba0(0);
  }
LAB_004126bc:
  __security_check_cookie(local_4 ^ (uint)auStack_124);
  return;
}

