
ushort FUN_005cc6e0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  ushort uVar5;
  
  if ((((*param_2 < *param_1 != (*param_2 == *param_1)) && (*param_1 <= param_2[4])) &&
      (param_2[1] < param_1[1] != (param_2[1] == param_1[1]))) &&
     ((param_1[1] <= param_2[5] && (param_2[2] < param_1[2] != (param_2[2] == param_1[2]))))) {
    fVar1 = param_1[2];
    fVar2 = param_2[6];
    bVar4 = fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8);
    if (fVar2 >= fVar1) goto LAB_005cc902;
  }
  if (((*param_2 < param_1[4] != (*param_2 == param_1[4])) && (param_1[4] <= param_2[4])) &&
     ((param_2[1] < param_1[5] != (param_2[1] == param_1[5]) &&
      ((param_1[5] <= param_2[5] && (param_2[2] < param_1[6] != (param_2[2] == param_1[6]))))))) {
    fVar1 = param_1[6];
    fVar2 = param_2[6];
    bVar4 = fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8);
    if (fVar2 >= fVar1) goto LAB_005cc902;
  }
  if (*param_1 < *param_2) {
    fVar1 = param_1[4];
    fVar2 = *param_2;
    if (fVar2 >= fVar1 && (fVar2 == fVar1) == 0) {
      return (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
             (ushort)(fVar2 == fVar1) << 0xe;
    }
  }
  if (param_2[4] < *param_1) {
    fVar1 = param_1[4];
    fVar2 = param_2[4];
    if (fVar2 < fVar1) {
      return (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
             (ushort)(fVar2 == fVar1) << 0xe;
    }
  }
  if (param_1[1] < param_2[1]) {
    fVar1 = param_1[5];
    fVar2 = param_2[1];
    if (fVar2 >= fVar1 && (fVar2 == fVar1) == 0) {
      return (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
             (ushort)(fVar2 == fVar1) << 0xe;
    }
  }
  if (param_2[5] < param_1[1]) {
    fVar1 = param_1[5];
    fVar2 = param_2[5];
    if (fVar2 < fVar1) {
      return (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
             (ushort)(fVar2 == fVar1) << 0xe;
    }
  }
  if (param_1[2] < param_2[2]) {
    fVar1 = param_1[6];
    fVar2 = param_2[2];
    if (fVar2 >= fVar1 && (fVar2 == fVar1) == 0) {
      return (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
             (ushort)(fVar2 == fVar1) << 0xe;
    }
  }
  if (param_2[6] < param_1[2]) {
    fVar1 = param_1[6];
    fVar2 = param_2[6];
    if (fVar2 < fVar1) {
      return (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
             (ushort)(fVar2 == fVar1) << 0xe;
    }
  }
  fVar1 = *param_2 - *param_1;
  if (fVar1 * (*param_2 - param_1[4]) < 0.0) {
    fVar1 = fVar1 / (fVar1 - (*param_2 - param_1[4]));
    fVar2 = param_1[1] + fVar1 * (param_1[5] - param_1[1]);
    fVar1 = (param_1[6] - param_1[2]) * fVar1 + param_1[2];
    if (((param_2[1] < fVar2 != (param_2[1] == fVar2)) && (fVar2 <= param_2[5])) &&
       (param_2[2] < fVar1 != (param_2[2] == fVar1))) {
      fVar2 = param_2[6];
      bVar4 = fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8);
      if (fVar2 >= fVar1) {
LAB_005cc902:
        return CONCAT11(bVar4,1);
      }
    }
  }
  fVar1 = param_2[1] - param_1[1];
  if (fVar1 * (param_2[1] - param_1[5]) < 0.0) {
    fVar1 = fVar1 / (fVar1 - (param_2[1] - param_1[5]));
    fVar2 = *param_1 + fVar1 * (param_1[4] - *param_1);
    fVar1 = (param_1[6] - param_1[2]) * fVar1 + param_1[2];
    if (((*param_2 < fVar2 != (*param_2 == fVar2)) && (fVar2 <= param_2[4])) &&
       (param_2[2] < fVar1 != (param_2[2] == fVar1))) {
      fVar2 = param_2[6];
      if (fVar2 >= fVar1) {
        return CONCAT11(fVar2 < fVar1 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8),1);
      }
    }
  }
  fVar1 = param_2[2] - param_1[2];
  if (fVar1 * (param_2[2] - param_1[6]) < 0.0) {
    fVar1 = fVar1 / (fVar1 - (param_2[2] - param_1[6]));
    fVar2 = *param_1 + fVar1 * (param_1[4] - *param_1);
    fVar1 = (param_1[5] - param_1[1]) * fVar1 + param_1[1];
    if (((*param_2 < fVar2 != (*param_2 == fVar2)) && (fVar2 <= param_2[4])) &&
       (param_2[1] < fVar1 != (param_2[1] == fVar1))) {
      fVar2 = param_2[5];
      if (fVar2 >= fVar1) {
        return CONCAT11(fVar2 < fVar1 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8),1);
      }
    }
  }
  fVar1 = *param_1 - param_2[4];
  if (fVar1 * (param_1[4] - param_2[4]) < 0.0) {
    fVar1 = fVar1 / (fVar1 - (param_1[4] - param_2[4]));
    fVar2 = param_1[1] + fVar1 * (param_1[5] - param_1[1]);
    fVar1 = (param_1[6] - param_1[2]) * fVar1 + param_1[2];
    if (((param_2[1] < fVar2 != (param_2[1] == fVar2)) && (fVar2 <= param_2[5])) &&
       (param_2[2] < fVar1 != (param_2[2] == fVar1))) {
      fVar2 = param_2[6];
      if (fVar2 >= fVar1) {
        return CONCAT11(fVar2 < fVar1 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8),1);
      }
    }
  }
  fVar1 = param_1[1] - param_2[5];
  if (fVar1 * (param_1[5] - param_2[5]) < 0.0) {
    fVar1 = fVar1 / (fVar1 - (param_1[5] - param_2[5]));
    fVar2 = *param_1 + fVar1 * (param_1[4] - *param_1);
    fVar1 = (param_1[6] - param_1[2]) * fVar1 + param_1[2];
    if (((*param_2 < fVar2 != (*param_2 == fVar2)) && (fVar2 <= param_2[4])) &&
       (param_2[2] < fVar1 != (param_2[2] == fVar1))) {
      fVar2 = param_2[6];
      if (fVar2 >= fVar1) {
        return CONCAT11(fVar2 < fVar1 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8),1);
      }
    }
  }
  fVar2 = param_1[2] - param_2[6];
  fVar1 = fVar2 * (param_1[6] - param_2[6]);
  uVar5 = (ushort)(fVar1 < 0.0) << 8 | (ushort)NAN(fVar1) << 10 | (ushort)(fVar1 == 0.0) << 0xe;
  if (fVar1 < 0.0) {
    fVar2 = fVar2 / (fVar2 - (param_1[6] - param_2[6]));
    fVar3 = *param_1 + fVar2 * (param_1[4] - *param_1);
    fVar2 = (param_1[5] - param_1[1]) * fVar2 + param_1[1];
    fVar1 = *param_2;
    uVar5 = (ushort)(fVar1 < fVar3) << 8 | (ushort)(NAN(fVar1) || NAN(fVar3)) << 10 |
            (ushort)(fVar1 == fVar3) << 0xe;
    if (fVar1 < fVar3 != (fVar1 == fVar3)) {
      fVar1 = param_2[4];
      uVar5 = (ushort)(fVar1 < fVar3) << 8 | (ushort)(NAN(fVar1) || NAN(fVar3)) << 10 |
              (ushort)(fVar1 == fVar3) << 0xe;
      if (fVar1 >= fVar3) {
        fVar1 = param_2[1];
        uVar5 = (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                (ushort)(fVar1 == fVar2) << 0xe;
        if (fVar1 < fVar2 != (fVar1 == fVar2)) {
          fVar1 = param_2[5];
          uVar5 = (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                  (ushort)(fVar1 == fVar2) << 0xe;
          if (fVar1 >= fVar2) {
            return CONCAT11((char)(uVar5 >> 8),1);
          }
        }
      }
    }
  }
  return uVar5;
}

