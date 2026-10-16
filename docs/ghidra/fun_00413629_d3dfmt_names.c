
undefined ** FUN_00413629(undefined4 param_1,char param_2)

{
  int in_EAX;
  int iVar1;
  undefined **ppuVar2;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  if (in_ZF || in_OF != in_SF) {
    if (in_ZF) {
      ppuVar2 = (undefined **)L"D3DFMT_MULTI2_ARGB8";
      goto LAB_00413894;
    }
    switch(in_EAX) {
    case 0:
      ppuVar2 = (undefined **)L"D3DFMT_UNKNOWN";
      break;
    default:
      goto switchD_00413646_caseD_1;
    case 0x14:
      ppuVar2 = (undefined **)L"D3DFMT_R8G8B8";
      break;
    case 0x15:
      ppuVar2 = (undefined **)L"D3DFMT_A8R8G8B8";
      break;
    case 0x16:
      ppuVar2 = (undefined **)L"D3DFMT_X8R8G8B8";
      break;
    case 0x17:
      ppuVar2 = (undefined **)L"D3DFMT_R5G6B5";
      break;
    case 0x18:
      ppuVar2 = (undefined **)L"D3DFMT_X1R5G5B5";
      break;
    case 0x19:
      ppuVar2 = (undefined **)L"D3DFMT_A1R5G5B5";
      break;
    case 0x1a:
      ppuVar2 = (undefined **)L"D3DFMT_A4R4G4B4";
      break;
    case 0x1b:
      ppuVar2 = (undefined **)L"D3DFMT_R3G3B2";
      break;
    case 0x1c:
      ppuVar2 = (undefined **)L"D3DFMT_A8";
      break;
    case 0x1d:
      ppuVar2 = (undefined **)L"D3DFMT_A8R3G3B2";
      break;
    case 0x1e:
      ppuVar2 = (undefined **)L"D3DFMT_X4R4G4B4";
      break;
    case 0x1f:
      ppuVar2 = (undefined **)L"D3DFMT_A2B10G10R10";
      break;
    case 0x20:
      ppuVar2 = (undefined **)L"D3DFMT_A8B8G8R8";
      break;
    case 0x21:
      ppuVar2 = (undefined **)L"D3DFMT_X8B8G8R8";
      break;
    case 0x22:
      ppuVar2 = (undefined **)L"D3DFMT_G16R16";
      break;
    case 0x23:
      ppuVar2 = (undefined **)L"D3DFMT_A2R10G10B10";
      break;
    case 0x24:
      ppuVar2 = (undefined **)L"D3DFMT_A16B16G16R16";
      break;
    case 0x28:
      ppuVar2 = (undefined **)L"D3DFMT_A8P8";
      break;
    case 0x29:
      ppuVar2 = (undefined **)L"D3DFMT_P8";
      break;
    case 0x32:
      ppuVar2 = (undefined **)L"D3DFMT_L8";
      break;
    case 0x33:
      ppuVar2 = (undefined **)L"D3DFMT_A8L8";
      break;
    case 0x34:
      ppuVar2 = (undefined **)L"D3DFMT_A4L4";
      break;
    case 0x3c:
      ppuVar2 = (undefined **)L"D3DFMT_V8U8";
      break;
    case 0x3d:
      ppuVar2 = (undefined **)L"D3DFMT_L6V5U5";
      break;
    case 0x3e:
      ppuVar2 = (undefined **)L"D3DFMT_X8L8V8U8";
      break;
    case 0x3f:
      ppuVar2 = (undefined **)L"D3DFMT_Q8W8V8U8";
      break;
    case 0x40:
      ppuVar2 = (undefined **)L"D3DFMT_V16U16";
      break;
    case 0x43:
      ppuVar2 = (undefined **)L"D3DFMT_A2W10V10U10";
      break;
    case 0x46:
      ppuVar2 = (undefined **)L"D3DFMT_D16_LOCKABLE";
      break;
    case 0x47:
      ppuVar2 = (undefined **)L"D3DFMT_D32";
      break;
    case 0x49:
      ppuVar2 = (undefined **)L"D3DFMT_D15S1";
      break;
    case 0x4b:
      ppuVar2 = (undefined **)L"D3DFMT_D24S8";
      break;
    case 0x4d:
      ppuVar2 = (undefined **)L"D3DFMT_D24X8";
      break;
    case 0x4f:
      ppuVar2 = (undefined **)L"D3DFMT_D24X4S4";
      break;
    case 0x50:
      ppuVar2 = (undefined **)L"D3DFMT_D16";
      break;
    case 0x51:
      ppuVar2 = (undefined **)L"D3DFMT_L16";
      break;
    case 100:
      ppuVar2 = (undefined **)L"D3DFMT_VERTEXDATA";
      break;
    case 0x65:
      ppuVar2 = (undefined **)L"D3DFMT_INDEX16";
      break;
    case 0x66:
      ppuVar2 = (undefined **)L"D3DFMT_INDEX32";
      break;
    case 0x6e:
      ppuVar2 = (undefined **)L"D3DFMT_Q16W16V16U16";
      break;
    case 0x6f:
      ppuVar2 = (undefined **)L"D3DFMT_R16F";
      break;
    case 0x70:
      ppuVar2 = (undefined **)L"D3DFMT_G16R16F";
      break;
    case 0x71:
      ppuVar2 = (undefined **)L"D3DFMT_A16B16G16R16F";
      break;
    case 0x72:
      ppuVar2 = (undefined **)L"D3DFMT_R32F";
      break;
    case 0x73:
      ppuVar2 = (undefined **)L"D3DFMT_G32R32F";
      break;
    case 0x74:
      ppuVar2 = (undefined **)L"D3DFMT_A32B32G32R32F";
      break;
    case 0x75:
      ppuVar2 = (undefined **)L"D3DFMT_CxV8U8";
    }
  }
  else {
    if (in_EAX < 0x33545845) {
      if (in_EAX == 0x33545844) {
        ppuVar2 = (undefined **)L"D3DFMT_DXT3";
        goto LAB_00413894;
      }
      if (in_EAX == 0x31545844) {
        ppuVar2 = (undefined **)L"D3DFMT_DXT1";
        goto LAB_00413894;
      }
      if (in_EAX == 0x32545844) {
        ppuVar2 = (undefined **)L"D3DFMT_DXT2";
        goto LAB_00413894;
      }
      if (in_EAX == 0x32595559) {
        ppuVar2 = (undefined **)L"D3DFMT_YUY2";
        goto LAB_00413894;
      }
    }
    else {
      if (in_EAX == 0x34545844) {
        ppuVar2 = (undefined **)L"D3DFMT_DXT4";
        goto LAB_00413894;
      }
      if (in_EAX == 0x35545844) {
        ppuVar2 = (undefined **)L"D3DFMT_DXT5";
        goto LAB_00413894;
      }
      if (in_EAX == 0x59565955) {
        ppuVar2 = (undefined **)L"D3DFMT_UYVY";
        goto LAB_00413894;
      }
    }
switchD_00413646_caseD_1:
    ppuVar2 = &PTR_DAT_0063987c;
  }
LAB_00413894:
  if ((param_2 == '\0') && (iVar1 = FUN_006181d7(ppuVar2,L"D3DFMT_"), iVar1 != 0)) {
    iVar1 = lstrlenW(L"D3DFMT_");
    return (undefined **)((int)ppuVar2 + iVar1 * 2);
  }
  return ppuVar2;
}

