
undefined4 FUN_006155c0(undefined4 param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  LANGID LVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  undefined4 uVar10;
  
  uVar4 = FUN_00615420(L"Manhunt2");
  if (1 < uVar4) {
    LVar3 = GetUserDefaultUILanguage();
    switch(LVar3 & 0x3ff) {
    case 7:
      iVar5 = 1;
      break;
    default:
      iVar5 = 0;
      break;
    case 10:
      iVar5 = 4;
      break;
    case 0xc:
      iVar5 = 2;
      break;
    case 0x10:
      iVar5 = 3;
    }
    MessageBoxW((HWND)0x0,(LPCWSTR)(&PTR_u_Manhunt_2_is_already_running__006dc290)[iVar5 * 2],
                (LPCWSTR)(&PTR_u_Game_Error_006dc294)[iVar5 * 2],0x10);
    return 0;
  }
  if (param_3 != 0) {
    iVar5 = FUN_006181d7(param_3,L"-safe");
    bVar1 = true;
    if (iVar5 != 0) goto LAB_0061564f;
  }
  bVar1 = false;
LAB_0061564f:
  if ((param_3 == 0) || (iVar5 = FUN_006181d7(param_3,&PTR_DAT_0066f784), iVar5 == 0)) {
    cVar9 = '\0';
  }
  else {
    cVar9 = '\x01';
  }
  FUN_00404740(FUN_006151d0,0);
  FUN_004047c0(&LAB_00615260,0);
  FUN_00404840(&LAB_00615270,0);
  FUN_004049c0(FUN_00615360,0);
  FUN_004048c0(&LAB_006152b0,0);
  FUN_00404940(&LAB_006152f0,0);
  FUN_004044f0(&LAB_00615250,0);
  FUN_004046c0(&LAB_00615410,0);
  FUN_00404570(&LAB_00615330,0);
  FUN_004045f0(&LAB_006153b0,0);
  FUN_00404670(&LAB_006153f0);
  cVar2 = FUN_0053cc10("global/pictures/legal_fr.tex");
  if (cVar2 == '\0') {
    DAT_0079e704 = 1;
  }
  if ((bVar1) || (cVar2 = FUN_0056c2d0(), cVar2 == '\0')) {
    FUN_0056c190();
  }
  if (cVar9 != '\0') {
    DAT_007604ec = 0;
    DAT_007604e4 = 0;
  }
  DAT_007604f8 = cVar9;
  FUN_0040a590(1,1,0,0);
  FUN_004083d0(0,0,0);
  FUN_00408480(1,1);
  thunk_FUN_007a70d0(L"Manhunt 2",0,0,0,0x80000000,0x80000000);
  FUN_00403f30(0);
  uVar8 = DAT_007604d0;
  uVar10 = DAT_007604f4;
  uVar6 = FUN_00618eb0(DAT_007604d0,DAT_007604f4);
  uVar7 = FUN_00618eb0(uVar6);
  iVar5 = FUN_0040dc80(DAT_007604d4 == '\0',uVar7,uVar6,uVar8,uVar10);
  if (iVar5 < 0) {
    return 0;
  }
  FUN_006154f0();
  FUN_0056f560();
  FUN_0040e3a0(0);
  FUN_0056f9a0();
  FUN_0056c0c0();
  *(undefined4 *)(DAT_0079e700 + 0x20) = 1;
  FUN_00594420();
  FUN_005943d0();
  FUN_004df4a0();
  FUN_004ce710();
  uVar8 = thunk_FUN_0044c1a0();
  return uVar8;
}

