
undefined4 FUN_005c9b50(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined1 local_18 [20];
  
  FUN_005fddf0(0x100);
  FUN_005fddf0(0x100);
  FUN_005fda60();
  if (param_1 == '\0') {
    uVar2 = FUN_0053cf10();
    FUN_005fdd40(uVar2);
    puVar4 = &DAT_007596bc;
  }
  else {
    uVar2 = FUN_005b6f40(&DAT_007597ac);
    FUN_005fdd40(uVar2);
    puVar4 = &DAT_0075968c;
  }
  FUN_005fe050(puVar4);
  cVar1 = FUN_0053bde0(local_18,0);
  if (cVar1 != '\0') {
    cVar1 = FUN_0053b0a0(&stack0xffffffd8);
    while (cVar1 != '\0') {
      cVar1 = FUN_005fda80(&DAT_0066bc38);
      if ((((cVar1 == '\0') && (cVar1 = FUN_005fda80("RAINY"), cVar1 == '\0')) &&
          (cVar1 = FUN_005fda80("THUNDERSTORM"), cVar1 == '\0')) &&
         (((cVar1 = FUN_005fda80(&DAT_0066bc18), cVar1 == '\0' &&
           (cVar1 = FUN_005fda80("CLEAR"), cVar1 == '\0')) &&
          ((cVar1 = FUN_005fda80("WINDY"), cVar1 == '\0' &&
           (cVar1 = FUN_005fda80("THUNDERNORAIN"), cVar1 == '\0')))))) {
        cVar1 = FUN_005fda80("ARTFILTER");
        if (cVar1 != '\0') {
          FUN_005c78f0(&DAT_006ecd10);
        }
      }
      else {
        uVar2 = FUN_005f5bb0(&stack0xffffffd8);
        FUN_005c7690(uVar2,&DAT_006ecd10);
      }
      cVar1 = FUN_005fda80("INSIDE");
      if (cVar1 == '\0') {
        iVar3 = FUN_005fdbb0("DEFAULT_SETTINGS");
        if (iVar3 == 0) {
          cVar1 = FUN_005fda80("FOGPATCHES");
          if (cVar1 == '\0') {
            cVar1 = FUN_005fda80("GLOBAL_SETTINGS");
            if (cVar1 == '\0') {
              cVar1 = FUN_005fda80("FILTERS");
              if (cVar1 == '\0') {
                cVar1 = FUN_005fda80("CAM_SETTINGS");
                if (cVar1 == '\0') {
                  cVar1 = FUN_005fda80("VIDEO_EFFECT_SETTINGS");
                  if (cVar1 == '\0') {
                    cVar1 = FUN_005fda80("GLOBAL_LIGHT_DIRECTION");
                    if (cVar1 == '\0') {
                      cVar1 = FUN_005fda80("PLAYER");
                      if (cVar1 == '\0') {
                        cVar1 = FUN_005fda80("COLLECTABLE_FX");
                        if (cVar1 == '\0') {
                          cVar1 = FUN_005fda80("PED_FX");
                          if (cVar1 == '\0') {
                            cVar1 = FUN_005fda80("PLAYER_FX");
                            if (cVar1 == '\0') {
                              cVar1 = FUN_005fda80("SPOTLIGHT_PARAMS");
                              if (cVar1 != '\0') {
                                FUN_005c8ec0(&DAT_006ecd10);
                              }
                            }
                            else {
                              FUN_005c9b10(2,&DAT_006ecd10);
                            }
                          }
                          else {
                            FUN_005c9b10(1,&DAT_006ecd10);
                          }
                        }
                        else {
                          FUN_005c9b10(0,&DAT_006ecd10);
                        }
                      }
                      else {
                        FUN_005c8650(&DAT_006ecd10);
                      }
                    }
                    else {
                      FUN_005c84b0(&DAT_006ecd10);
                    }
                  }
                  else {
                    FUN_005c7f60(&DAT_006ecd10);
                  }
                }
                else {
                  FUN_005c87e0(&DAT_006ecd10);
                }
              }
              else {
                FUN_005c7d40(&DAT_006ecd10);
              }
            }
            else {
              FUN_005c7ab0(&DAT_006ecd10);
            }
          }
          else {
            FUN_005c77c0(&DAT_006ecd10);
          }
        }
        else {
          FUN_005c7230(&DAT_006ecd10);
        }
      }
      cVar1 = FUN_0053b0a0(&stack0xffffffd8);
    }
    FUN_0053afa0();
    thunk_FUN_005fdb40();
    thunk_FUN_005fdb40();
    thunk_FUN_005fdb40();
    return 1;
  }
  thunk_FUN_005fdb40();
  thunk_FUN_005fdb40();
  thunk_FUN_005fdb40();
  return 0;
}

