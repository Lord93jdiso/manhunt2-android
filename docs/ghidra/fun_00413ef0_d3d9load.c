
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00413ef0(void)

{
  if (DAT_006ddbe0 != (HMODULE)0x0) {
    return true;
  }
  DAT_006ddbe0 = LoadLibraryW(L"d3d9.dll");
  if (DAT_006ddbe0 != (HMODULE)0x0) {
    DAT_006ddbe4 = GetProcAddress(DAT_006ddbe0,"Direct3DCreate9");
    _DAT_006ddbe8 = GetProcAddress(DAT_006ddbe0,"D3DPERF_BeginEvent");
    _DAT_006ddbec = GetProcAddress(DAT_006ddbe0,"D3DPERF_EndEvent");
    _DAT_006ddbf0 = GetProcAddress(DAT_006ddbe0,"D3DPERF_SetMarker");
    _DAT_006ddbf4 = GetProcAddress(DAT_006ddbe0,"D3DPERF_SetRegion");
    _DAT_006ddbf8 = GetProcAddress(DAT_006ddbe0,"D3DPERF_QueryRepeatFrame");
    _DAT_006ddbfc = GetProcAddress(DAT_006ddbe0,"D3DPERF_SetOptions");
    _DAT_006ddc00 = GetProcAddress(DAT_006ddbe0,"D3DPERF_GetStatus");
  }
  return DAT_006ddbe0 != (HMODULE)0x0;
}

