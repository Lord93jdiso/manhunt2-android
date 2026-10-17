
void FUN_00614630(float param_1,float param_2,float param_3,float param_4,int param_5,int param_6,
                 float param_7)

{
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  float *pfVar3;
  float *pfVar4;
  int local_88;
  float local_80 [4];
  uint local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60 [6];
  undefined4 local_48;
  float local_40 [7];
  undefined4 local_24;
  float local_20 [7];
  undefined4 local_4;
  
  local_80[0] = param_1 - 0.5;
  local_80[1] = param_2 - 0.5;
  local_80[2] = 0.0;
  local_80[3] = 1.0;
  local_88 = (int)(longlong)ROUND(param_7 * 255.0);
  local_70 = local_88 << 0x18 | 0xffffff;
  local_6c = local_70;
  iVar1 = *unaff_EBX;
  local_68 = 0;
  local_64 = 0;
  pfVar3 = local_80;
  pfVar4 = local_60;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  local_60[0] = ((float)param_5 * param_3 + param_1) - 0.5;
  local_48 = 0x3f800000;
  pfVar3 = local_80;
  pfVar4 = local_40;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  local_20[1] = ((float)param_6 * param_4 + param_2) - 0.5;
  local_40[1] = local_20[1];
  local_24 = 0x3f800000;
  pfVar3 = local_60;
  pfVar4 = local_20;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  local_4 = 0x3f800000;
  (**(code **)(iVar1 + 0x170))();
  (**(code **)(*unaff_EBX + 0x164))();
  (**(code **)(*unaff_EBX + 0x14c))();
  return;
}

