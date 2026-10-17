
void __thiscall FUN_00562680(int param_1,char param_2)

{
  *(char *)(param_1 + 0xf4) = param_2;
  if (param_2 == '\0') {
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}

