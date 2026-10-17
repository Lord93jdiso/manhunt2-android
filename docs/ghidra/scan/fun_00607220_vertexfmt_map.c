
int __fastcall FUN_00607220(int param_1)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(param_1 + 0x70);
  iVar2 = (uVar1 >> 5 & 4) + (uVar1 >> 4 & 4) + (uVar1 >> 3 & 4);
  if ((uVar1 & 0x10) != 0) {
    iVar2 = iVar2 + 8;
  }
  switch(uVar1 & 0x400e) {
  case 2:
    iVar2 = iVar2 + 0xc;
    break;
  case 4:
  case 6:
    iVar2 = iVar2 + 0x10;
    break;
  case 8:
    iVar2 = iVar2 + 0x14;
    break;
  case 10:
    iVar2 = iVar2 + 0x18;
    break;
  case 0xc:
    iVar2 = iVar2 + 0x1c;
    break;
  case 0xe:
    iVar2 = iVar2 + 0x20;
  }
  uVar4 = uVar1 >> 8 & 0xf;
  if (uVar4 != 0) {
    bVar3 = 0x10;
    do {
      switch(uVar1 >> (bVar3 & 0x1f)) {
      case 0:
        iVar2 = iVar2 + 8;
        break;
      case 1:
        iVar2 = iVar2 + 0xc;
        break;
      case 2:
        iVar2 = iVar2 + 0x10;
        break;
      case 3:
        iVar2 = iVar2 + 4;
      }
      bVar3 = bVar3 + 2;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return iVar2;
}

