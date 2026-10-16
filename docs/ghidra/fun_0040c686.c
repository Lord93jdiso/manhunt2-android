
void FUN_0040c686(void)

{
  char cVar1;
  int *piVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  
  cVar1 = thunk_FUN_004af140();
  if (cVar1 != '\0') {
    thunk_FUN_0043189b();
    cVar1 = thunk_FUN_004c3930();
    if (cVar1 != '\0') {
      thunk_FUN_0043189b();
      cVar1 = thunk_FUN_007a5e30();
      if (cVar1 != '\0') {
        fVar6 = (float10)FUN_00404250();
        fVar7 = (float10)FUN_004042a0();
        cVar1 = FUN_00403fd0();
        if (cVar1 == '\0') {
          iVar5 = thunk_FUN_007a6a80();
          if (iVar5 != 0) {
            thunk_FUN_0043189b();
            pcVar3 = (code *)thunk_FUN_00464030();
            if (pcVar3 != (code *)0x0) {
              thunk_FUN_0043189b();
              cVar1 = thunk_FUN_007a5600();
              if (cVar1 == '\0') {
                thunk_FUN_0043189b();
                uVar4 = thunk_FUN_007a6660();
                (*pcVar3)(iVar5,(double)fVar6,(float)fVar7,uVar4);
              }
            }
            thunk_FUN_0043189b();
            cVar1 = thunk_FUN_007a5600();
            if (cVar1 == '\0') {
              thunk_FUN_0043189b();
              thunk_FUN_004a1020();
            }
            piVar2 = (int *)thunk_FUN_00435f90();
            iVar5 = *piVar2;
            thunk_FUN_0043189b();
            thunk_FUN_004a1020();
            iVar5 = (**(code **)(iVar5 + 0x20))();
            if (iVar5 == 0x87a0001) {
              uVar4 = 1;
              thunk_FUN_0043189b(1);
              thunk_FUN_00401597(uVar4);
            }
            else if (-1 < iVar5) {
              thunk_FUN_0043189b();
              cVar1 = thunk_FUN_007a5600();
              if (cVar1 != '\0') {
                uVar4 = 0;
                thunk_FUN_0043189b(0);
                thunk_FUN_00401597(uVar4);
              }
            }
          }
        }
        else {
          piVar2 = (int *)FUN_00404010();
          if (piVar2 != (int *)0x0) {
            thunk_FUN_0043189b();
            pcVar3 = (code *)thunk_FUN_00463e50();
            if (pcVar3 != (code *)0x0) {
              thunk_FUN_0043189b();
              uVar4 = thunk_FUN_007a65a0();
              (*pcVar3)(piVar2,(double)fVar6,(float)fVar7,uVar4);
            }
            iVar5 = (**(code **)(*piVar2 + 0x44))(piVar2,0,0,0,0);
            if (iVar5 == -0x7789f798) {
              uVar4 = 1;
              thunk_FUN_0043189b(1);
              thunk_FUN_004027b7(uVar4);
            }
            else if (iVar5 == -0x7789f7d9) {
              uVar4 = 1;
              thunk_FUN_0043189b(1);
              thunk_FUN_004027b7(uVar4);
            }
          }
        }
      }
    }
  }
  thunk_FUN_0043189b();
  FUN_0041c926();
  return;
}

