/* 1014b9c9 FUN_1014b9c9 [[1014b9c9, 1014baea]] */

uint __cdecl FUN_1014b9c9(undefined1 (*param_1) [32],uint param_2)

{
  undefined1 auVar1 [32];
  undefined1 *puVar2;
  uint uVar3;
  undefined1 (*pauVar4) [32];
  uint uVar5;
  undefined1 auVar6 [16];

  if (DAT_101d1e50 < 5) {
    if (DAT_101d1e50 < 1) {
      for (pauVar4 = param_1;
          (pauVar4 != (undefined1 (*) [32])(*param_1 + param_2) && ((*pauVar4)[0] != '\0'));
          pauVar4 = (undefined1 (*) [32])(*pauVar4 + 1)) {
      }
      uVar3 = (int)pauVar4 - (int)param_1;
    }
    else {
      uVar5 = -(uint)(((uint)param_1 & 0xf) != 0) & 0x10 - ((uint)param_1 & 0xf);
      if (param_2 < uVar5) {
        uVar5 = param_2;
      }
      for (pauVar4 = param_1;
          (pauVar4 != (undefined1 (*) [32])(*param_1 + uVar5) && ((*pauVar4)[0] != '\0'));
          pauVar4 = (undefined1 (*) [32])(*pauVar4 + 1)) {
      }
      uVar3 = (int)pauVar4 - (int)param_1;
      if (uVar3 == uVar5) {
        puVar2 = *pauVar4;
        while ((pauVar4 != (undefined1 (*) [32])(puVar2 + (param_2 - uVar5 & 0xfffffff0)) &&
               (auVar6[0] = -((*pauVar4)[0] == '\0'), auVar6[1] = -((*pauVar4)[1] == '\0'),
               auVar6[2] = -((*pauVar4)[2] == '\0'), auVar6[3] = -((*pauVar4)[3] == '\0'),
               auVar6[4] = -((*pauVar4)[4] == '\0'), auVar6[5] = -((*pauVar4)[5] == '\0'),
               auVar6[6] = -((*pauVar4)[6] == '\0'), auVar6[7] = -((*pauVar4)[7] == '\0'),
               auVar6[8] = -((*pauVar4)[8] == '\0'), auVar6[9] = -((*pauVar4)[9] == '\0'),
               auVar6[10] = -((*pauVar4)[10] == '\0'), auVar6[0xb] = -((*pauVar4)[0xb] == '\0'),
               auVar6[0xc] = -((*pauVar4)[0xc] == '\0'), auVar6[0xd] = -((*pauVar4)[0xd] == '\0'),
               auVar6[0xe] = -((*pauVar4)[0xe] == '\0'), auVar6[0xf] = -((*pauVar4)[0xf] == '\0'),
               (((((((((((((((SUB161(auVar6 >> 7,0) & 1) == 0 && (SUB161(auVar6 >> 0xf,0) & 1) == 0)
                           && (SUB161(auVar6 >> 0x17,0) & 1) == 0) &&
                          (SUB161(auVar6 >> 0x1f,0) & 1) == 0) &&
                         (SUB161(auVar6 >> 0x27,0) & 1) == 0) && (SUB161(auVar6 >> 0x2f,0) & 1) == 0
                        ) && (SUB161(auVar6 >> 0x37,0) & 1) == 0) &&
                      (SUB161(auVar6 >> 0x3f,0) & 1) == 0) && (SUB161(auVar6 >> 0x47,0) & 1) == 0)
                    && (SUB161(auVar6 >> 0x4f,0) & 1) == 0) && (SUB161(auVar6 >> 0x57,0) & 1) == 0)
                  && (SUB161(auVar6 >> 0x5f,0) & 1) == 0) && (SUB161(auVar6 >> 0x67,0) & 1) == 0) &&
                (SUB161(auVar6 >> 0x6f,0) & 1) == 0) && (SUB161(auVar6 >> 0x77,0) & 1) == 0) &&
               -1 < auVar6[0xf]))) {
          pauVar4 = (undefined1 (*) [32])(*pauVar4 + 0x10);
        }
        for (; (pauVar4 != (undefined1 (*) [32])(*param_1 + param_2) && ((*pauVar4)[0] != '\0'));
            pauVar4 = (undefined1 (*) [32])(*pauVar4 + 1)) {
        }
        uVar3 = (int)pauVar4 - (int)param_1;
      }
    }
  }
  else {
    uVar5 = -(uint)(((uint)param_1 & 0x1f) != 0) & 0x20 - ((uint)param_1 & 0x1f);
    if (param_2 < uVar5) {
      uVar5 = param_2;
    }
    for (pauVar4 = param_1;
        (pauVar4 != (undefined1 (*) [32])(*param_1 + uVar5) && ((*pauVar4)[0] != '\0'));
        pauVar4 = (undefined1 (*) [32])(*pauVar4 + 1)) {
    }
    uVar3 = (int)pauVar4 - (int)param_1;
    if (uVar3 == uVar5) {
      puVar2 = *pauVar4;
      while ((pauVar4 != (undefined1 (*) [32])(puVar2 + (param_2 - uVar5 & 0xffffffe0)) &&
             (auVar1 = vpcmpeqb_avx2(SUB6432(ZEXT1664((undefined1  [16])0x0),0),*pauVar4),
             (((((((((((((((((((((((((((((((SUB321(auVar1 >> 7,0) & 1) == 0 &&
                                          (SUB321(auVar1 >> 0xf,0) & 1) == 0) &&
                                         (SUB321(auVar1 >> 0x17,0) & 1) == 0) &&
                                        (SUB321(auVar1 >> 0x1f,0) & 1) == 0) &&
                                       (SUB321(auVar1 >> 0x27,0) & 1) == 0) &&
                                      (SUB321(auVar1 >> 0x2f,0) & 1) == 0) &&
                                     (SUB321(auVar1 >> 0x37,0) & 1) == 0) &&
                                    (SUB321(auVar1 >> 0x3f,0) & 1) == 0) &&
                                   (SUB321(auVar1 >> 0x47,0) & 1) == 0) &&
                                  (SUB321(auVar1 >> 0x4f,0) & 1) == 0) &&
                                 (SUB321(auVar1 >> 0x57,0) & 1) == 0) &&
                                (SUB321(auVar1 >> 0x5f,0) & 1) == 0) &&
                               (SUB321(auVar1 >> 0x67,0) & 1) == 0) &&
                              (SUB321(auVar1 >> 0x6f,0) & 1) == 0) &&
                             (SUB321(auVar1 >> 0x77,0) & 1) == 0) &&
                            SUB321(auVar1 >> 0x7f,0) == '\0') && (SUB321(auVar1 >> 0x87,0) & 1) == 0
                           ) && (SUB321(auVar1 >> 0x8f,0) & 1) == 0) &&
                         (SUB321(auVar1 >> 0x97,0) & 1) == 0) && (SUB321(auVar1 >> 0x9f,0) & 1) == 0
                        ) && (SUB321(auVar1 >> 0xa7,0) & 1) == 0) &&
                      (SUB321(auVar1 >> 0xaf,0) & 1) == 0) && (SUB321(auVar1 >> 0xb7,0) & 1) == 0)
                    && SUB321(auVar1 >> 0xbf,0) == '\0') && (SUB321(auVar1 >> 199,0) & 1) == 0) &&
                  (SUB321(auVar1 >> 0xcf,0) & 1) == 0) && (SUB321(auVar1 >> 0xd7,0) & 1) == 0) &&
                (SUB321(auVar1 >> 0xdf,0) & 1) == 0) && (SUB321(auVar1 >> 0xe7,0) & 1) == 0) &&
              (SUB321(auVar1 >> 0xef,0) & 1) == 0) && (SUB321(auVar1 >> 0xf7,0) & 1) == 0) &&
             -1 < auVar1[0x1f]))) {
        pauVar4 = pauVar4 + 1;
      }
      for (; (pauVar4 != (undefined1 (*) [32])(*param_1 + param_2) && ((*pauVar4)[0] != '\0'));
          pauVar4 = (undefined1 (*) [32])(*pauVar4 + 1)) {
      }
      uVar3 = (int)pauVar4 - (int)param_1;
    }
  }
  return uVar3;
}
