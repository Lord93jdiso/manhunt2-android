
undefined4 FUN_005ccc30(int *param_1,int param_2,code *param_3,undefined4 param_4)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  float in_stack_ffffff7c;
  int local_80 [32];
  
  piVar7 = local_80;
LAB_005ccc50:
  do {
    while( true ) {
      iVar3 = *param_1;
      uVar6 = (-1 < iVar3) - 1 & (uint)param_1;
      if (uVar6 == 0) break;
      cVar4 = FUN_005cc6e0(param_2,uVar6 + 0x10);
      if ((cVar4 != '\0') && (cVar4 = (*param_3)(param_2,uVar6,param_4), cVar4 == '\0')) {
        uVar5 = FUN_0042e9e0(in_stack_ffffff7c);
        return uVar5;
      }
LAB_005ccce9:
      if (piVar7 == local_80) {
        return 1;
      }
      param_1 = (int *)piVar7[-1];
      piVar7 = piVar7 + -1;
    }
    if ((iVar3 < 0) || (0x299 < iVar3)) {
      param_1 = (int *)0x0;
    }
    in_stack_ffffff7c = *(float *)(*param_1 + param_2);
    fVar2 = *(float *)(*param_1 + 0x10 + param_2);
    if ((in_stack_ffffff7c <= (float)param_1[4]) || (fVar2 <= (float)param_1[4])) {
      if ((float)param_1[5] < in_stack_ffffff7c == ((float)param_1[5] == in_stack_ffffff7c)) {
        if ((float)param_1[5] < fVar2 != ((float)param_1[5] == fVar2)) {
          piVar1 = param_1 + 2;
          param_1 = (int *)param_1[1];
          *piVar7 = *piVar1;
          piVar7 = piVar7 + 1;
          goto LAB_005ccc50;
        }
      }
      else {
        *piVar7 = param_1[2];
        piVar7 = piVar7 + 1;
      }
      param_1 = (int *)param_1[1];
      goto LAB_005ccc50;
    }
    if ((float)param_1[5] < in_stack_ffffff7c == ((float)param_1[5] == in_stack_ffffff7c)) {
      if ((float)param_1[5] < fVar2 == ((float)param_1[5] == fVar2)) goto LAB_005ccce9;
    }
    param_1 = (int *)param_1[2];
  } while( true );
}

