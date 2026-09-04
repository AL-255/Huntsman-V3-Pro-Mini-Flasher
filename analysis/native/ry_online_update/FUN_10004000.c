/* 10004000 FUN_10004000 [[10004000, 10005342]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10004000(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  LPCSTR pCVar8;
  LPCSTR pCVar9;
  int *piVar10;
  errno_t eVar11;
  uchar *puVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  uint *puVar15;
  undefined4 uVar16;
  byte *pbVar17;
  uint *puVar18;
  uchar *extraout_ECX;
  undefined1 (*extraout_ECX_00) [32];
  undefined1 (*extraout_ECX_01) [32];
  bool bVar19;
  char *pcVar20;
  undefined1 (*pauVar21) [32];
  uint *puVar22;
  uchar *puVar23;
  undefined1 *local_290;
  undefined1 local_289;
  uint *local_288;
  uint *local_284;
  uint local_280;
  uint *local_27c;
  char local_275;
  uint *local_274;
  uint *local_270;
  undefined4 local_26c;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 *local_64;
  int local_60;
  uchar *local_5c;
  uint *local_58;
  char local_54 [4];
  short local_50;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_40;
  undefined1 local_3f;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10169c6d;
  local_10 = ExceptionList;
  local_14 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_270 = (uint *)0x0;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  local_58 = (uint *)(iVar5 + 0x10);
  local_8 = 0;
  cVar3 = FUN_10008d30(&local_58,0x101ad0ea);
  if (cVar3 == '\0') {
    FUN_10009140(&local_58,(uint *)&DAT_101ad0ea,0);
  }
  local_8 = 1;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  puVar6 = (undefined4 *)(**(code **)(*ppuVar4 + 0xc))();
  local_64 = puVar6 + 4;
  local_8._0_1_ = 2;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  local_60 = (**(code **)(*ppuVar4 + 0xc))();
  local_60 = local_60 + 0x10;
  local_8._0_1_ = 3;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  local_5c = (uchar *)(iVar5 + 0x10);
  local_8._0_1_ = 4;
  _memset(local_54,0,0x40);
  local_284 = (uint *)&stack0xfffffd58;
  local_27c = (uint *)&stack0xfffffd58;
  local_280 = 3;
  DAT_101d2824 = 0;
  _DAT_101d2820 = 0;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  uVar7 = iVar5 + 0x10;
  local_8 = CONCAT31(local_8._1_3_,5);
  cVar3 = FUN_10008d30(&stack0xfffffd58,0x101ad14c);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd58,(uint *)"update_config.ini",0x11);
  }
  local_27c = (uint *)&stack0xfffffd54;
  local_274 = (uint *)&stack0xfffffd54;
  local_8._0_1_ = 6;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  pCVar8 = (LPCSTR)(iVar5 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,7);
  cVar3 = FUN_10008d30(&stack0xfffffd54,0x101ad190);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd54,(uint *)"bootdev_info",0xc);
  }
  local_274 = (uint *)&stack0xfffffd50;
  local_8._0_1_ = 8;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  pCVar9 = (LPCSTR)(iVar5 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,9);
  cVar3 = FUN_10008d30(&stack0xfffffd50,0x101ad1a0);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd50,(uint *)"BOOTDEVICE_INFO",0xf);
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  piVar10 = FUN_10002af0(&local_270,pCVar9,pCVar8,uVar7);
  local_8._0_1_ = 10;
  FUN_10008860(&DAT_101d283c,piVar10);
  local_8._0_1_ = 4;
  LOCK();
  puVar18 = local_270 + -1;
  uVar7 = *puVar18;
  *puVar18 = *puVar18 - 1;
  UNLOCK();
  if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
    (**(code **)(*(int *)local_270[-4] + 4))();
  }
  uVar7 = *(uint *)(DAT_101d283c + -0xc);
  if ((int)uVar7 < 0) goto LAB_10005258;
  if ((int)(*(int *)(DAT_101d283c + -8) - uVar7 | 1U - *(int *)(DAT_101d283c + -4)) < 0) {
    FUN_100090d0(&DAT_101d283c,uVar7);
  }
  eVar11 = FID_conflict___mbslwr_s(DAT_101d283c,uVar7 + 1);
  FUN_10001f40(eVar11);
  if (*(int *)(DAT_101d283c + -8) < (int)uVar7) goto LAB_10005258;
  *(uint *)(DAT_101d283c + -0xc) = uVar7;
  DAT_101d283c[uVar7] = '\0';
  FUN_10008630(&DAT_101d283c," ",(uint *)&DAT_101ad0ea);
  if (((0 < *(int *)(DAT_101d283c + -0xc)) &&
      (puVar12 = __mbschr(DAT_101d283c,0x3b), puVar12 != (uchar *)0x0)) &&
     (-1 < (int)puVar12 - (int)DAT_101d283c)) {
    if (*(int *)(DAT_101d283c + -0xc) < 1) {
      uVar7 = 0xffffffff;
    }
    else {
      puVar12 = __mbschr(DAT_101d283c,0x3b);
      uVar7 = (int)puVar12 - (int)DAT_101d283c;
      if (puVar12 == (uchar *)0x0) {
        uVar7 = 0xffffffff;
      }
    }
    piVar10 = FUN_100080b0(&DAT_101d283c,(int *)&local_270,uVar7);
    local_8._0_1_ = 0xb;
    FUN_10008860(&DAT_101d283c,piVar10);
    local_8._0_1_ = 4;
    LOCK();
    puVar18 = local_270 + -1;
    uVar7 = *puVar18;
    *puVar18 = *puVar18 - 1;
    UNLOCK();
    if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
      (**(code **)(*(int *)local_270[-4] + 4))();
    }
  }
  local_284 = (uint *)&stack0xfffffd58;
  local_27c = (uint *)&stack0xfffffd58;
  local_289 = 0;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  uVar7 = iVar5 + 0x10;
  local_8 = CONCAT31(local_8._1_3_,0xc);
  cVar3 = FUN_10008d30(&stack0xfffffd58,0x101ad14c);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd58,(uint *)"update_config.ini",0x11);
  }
  local_27c = (uint *)&stack0xfffffd54;
  local_274 = (uint *)&stack0xfffffd54;
  local_8._0_1_ = 0xd;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  pCVar8 = (LPCSTR)(iVar5 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,0xe);
  cVar3 = FUN_10008d30(&stack0xfffffd54,0x101ad1b4);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd54,(uint *)"checksn",7);
  }
  local_274 = (uint *)&stack0xfffffd50;
  local_8._0_1_ = 0xf;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  pCVar9 = (LPCSTR)(iVar5 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,0x10);
  cVar3 = FUN_10008d30(&stack0xfffffd50,0x101ad1a0);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd50,(uint *)"BOOTDEVICE_INFO",0xf);
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  piVar10 = FUN_10002af0(&local_270,pCVar9,pCVar8,uVar7);
  local_8._0_1_ = 0x11;
  FUN_10008860(&local_5c,piVar10);
  local_8._0_1_ = 4;
  LOCK();
  puVar18 = local_270 + -1;
  uVar7 = *puVar18;
  *puVar18 = *puVar18 - 1;
  UNLOCK();
  if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
    (**(code **)(*(int *)local_270[-4] + 4))();
  }
  uVar7 = *(uint *)(local_5c + -0xc);
  if ((int)uVar7 < 0) goto LAB_10005258;
  if ((int)(*(int *)(local_5c + -8) - uVar7 | 1U - *(int *)(local_5c + -4)) < 0) {
    FUN_100090d0(&local_5c,uVar7);
  }
  puVar12 = local_5c;
  eVar11 = FID_conflict___mbslwr_s(local_5c,uVar7 + 1);
  FUN_10001f40(eVar11);
  if (*(int *)(puVar12 + -8) < (int)uVar7) goto LAB_10005258;
  *(uint *)(puVar12 + -0xc) = uVar7;
  puVar12[uVar7] = '\0';
  iVar5 = __mbscmp(puVar12,"TRUE");
  if (iVar5 == 0) {
    local_284 = (uint *)&stack0xfffffd58;
    local_27c = (uint *)&stack0xfffffd58;
    local_289 = 1;
    ppuVar4 = FUN_1000f8a0();
    if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar5 = (**(code **)(*ppuVar4 + 0xc))();
    uVar7 = iVar5 + 0x10;
    local_8 = CONCAT31(local_8._1_3_,0x12);
    cVar3 = FUN_10008d30(&stack0xfffffd58,0x101ad14c);
    if (cVar3 == '\0') {
      FUN_10009140(&stack0xfffffd58,(uint *)"update_config.ini",0x11);
    }
    local_27c = (uint *)&stack0xfffffd54;
    local_274 = (uint *)&stack0xfffffd54;
    local_8._0_1_ = 0x13;
    ppuVar4 = FUN_1000f8a0();
    if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar5 = (**(code **)(*ppuVar4 + 0xc))();
    pCVar8 = (LPCSTR)(iVar5 + 0x10);
    local_8 = CONCAT31(local_8._1_3_,0x14);
    cVar3 = FUN_10008d30(&stack0xfffffd54,0x101ad1c4);
    if (cVar3 == '\0') {
      FUN_10009140(&stack0xfffffd54,(uint *)&DAT_101ad1c4,2);
    }
    local_274 = (uint *)&stack0xfffffd50;
    local_8._0_1_ = 0x15;
    ppuVar4 = FUN_1000f8a0();
    if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar5 = (**(code **)(*ppuVar4 + 0xc))();
    pCVar9 = (LPCSTR)(iVar5 + 0x10);
    local_8 = CONCAT31(local_8._1_3_,0x16);
    cVar3 = FUN_10008d30(&stack0xfffffd50,0x101ad1a0);
    if (cVar3 == '\0') {
      FUN_10009140(&stack0xfffffd50,(uint *)"BOOTDEVICE_INFO",0xf);
    }
    local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
    local_8._0_1_ = 4;
    piVar10 = FUN_10002af0(&local_270,pCVar9,pCVar8,uVar7);
    local_8._0_1_ = 0x17;
    FUN_10008860(&DAT_101d2840,piVar10);
    local_8._0_1_ = 4;
    LOCK();
    puVar18 = local_270 + -1;
    uVar7 = *puVar18;
    *puVar18 = *puVar18 - 1;
    UNLOCK();
    if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
      (**(code **)(*(int *)local_270[-4] + 4))();
    }
  }
  local_284 = (uint *)&stack0xfffffd58;
  local_27c = (uint *)&stack0xfffffd58;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  uVar7 = iVar5 + 0x10;
  local_8 = CONCAT31(local_8._1_3_,0x18);
  cVar3 = FUN_10008d30(&stack0xfffffd58,0x101ad14c);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd58,(uint *)"update_config.ini",0x11);
  }
  local_27c = (uint *)&stack0xfffffd54;
  local_274 = (uint *)&stack0xfffffd54;
  local_8._0_1_ = 0x19;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  pCVar8 = (LPCSTR)(iVar5 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,0x1a);
  cVar3 = FUN_10008d30(&stack0xfffffd54,0x101ad1c8);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd54,(uint *)"upgrade_file",0xc);
  }
  local_274 = (uint *)&stack0xfffffd50;
  local_8._0_1_ = 0x1b;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  pCVar9 = (LPCSTR)(iVar5 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,0x1c);
  cVar3 = FUN_10008d30(&stack0xfffffd50,0x101ad1d8);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd50,(uint *)"BIN_FILE",8);
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  piVar10 = FUN_10002af0(&local_270,pCVar9,pCVar8,uVar7);
  local_8._0_1_ = 0x1d;
  FUN_10008860(&local_58,piVar10);
  local_8._0_1_ = 4;
  LOCK();
  puVar18 = local_270 + -1;
  uVar7 = *puVar18;
  *puVar18 = *puVar18 - 1;
  UNLOCK();
  if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
    (**(code **)(*(int *)local_270[-4] + 4))();
  }
  piVar10 = FUN_10007e70((int *)&local_270,&DAT_101d2834,&local_58);
  local_8._0_1_ = 0x1e;
  FUN_10008860(&local_60,piVar10);
  local_8._0_1_ = 4;
  LOCK();
  puVar18 = local_270 + -1;
  uVar7 = *puVar18;
  *puVar18 = *puVar18 - 1;
  UNLOCK();
  if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
    (**(code **)(*(int *)local_270[-4] + 4))();
  }
  pcVar20 = "%x";
  local_284 = (uint *)&stack0xfffffd50;
  local_27c = (uint *)&stack0xfffffd50;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  uVar7 = iVar5 + 0x10;
  local_8 = CONCAT31(local_8._1_3_,0x1f);
  cVar3 = FUN_10008d30(&stack0xfffffd50,0x101ad14c);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd50,(uint *)"update_config.ini",0x11);
  }
  local_27c = (uint *)&stack0xfffffd4c;
  local_274 = (uint *)&stack0xfffffd4c;
  local_8._0_1_ = 0x20;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  pCVar8 = (LPCSTR)(iVar5 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,0x21);
  cVar3 = FUN_10008d30(&stack0xfffffd4c,0x101ad1e4);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd4c,(uint *)"encryption_en",0xd);
  }
  local_274 = (uint *)&stack0xfffffd48;
  local_8._0_1_ = 0x22;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))();
  pCVar9 = (LPCSTR)(iVar5 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,0x23);
  cVar3 = FUN_10008d30(&stack0xfffffd48,0x101ad1f4);
  if (cVar3 == '\0') {
    FUN_10009140(&stack0xfffffd48,(uint *)"ENCRY_EN",8);
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  piVar10 = FUN_10002af0(&local_270,pCVar9,pCVar8,uVar7);
  iVar5 = FUN_10001f20((char *)*piVar10,pcVar20);
  local_275 = iVar5 == 0;
  LOCK();
  puVar18 = local_270 + -1;
  uVar7 = *puVar18;
  *puVar18 = *puVar18 - 1;
  UNLOCK();
  if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
    (**(code **)(*(int *)local_270[-4] + 4))();
  }
  if (local_275 == '\0') {
    if (DAT_101d2828 != 0) goto LAB_100048ac;
    piVar10 = FUN_100081c0(&local_58,(int *)&local_270,4);
    pbVar17 = &DAT_101ad208;
    pbVar13 = (byte *)*piVar10;
    do {
      bVar2 = *pbVar13;
      bVar19 = bVar2 < *pbVar17;
      if (bVar2 != *pbVar17) {
LAB_10004ac3:
        uVar7 = -(uint)bVar19 | 1;
        goto LAB_10004ac8;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar13[1];
      bVar19 = bVar2 < pbVar17[1];
      if (bVar2 != pbVar17[1]) goto LAB_10004ac3;
      pbVar13 = pbVar13 + 2;
      pbVar17 = pbVar17 + 2;
    } while (bVar2 != 0);
    uVar7 = 0;
LAB_10004ac8:
    LOCK();
    puVar18 = local_270 + -1;
    uVar1 = *puVar18;
    *puVar18 = *puVar18 - 1;
    UNLOCK();
    puVar18 = local_58;
    if ((int)(uVar1 - 1) < 1) {
      (**(code **)(*(int *)local_270[-4] + 4))();
      puVar18 = local_58;
    }
  }
  else {
    DAT_101d2828 = 1;
LAB_100048ac:
    piVar10 = FUN_100081c0(&local_58,(int *)&local_270,4);
    pbVar17 = &DAT_101ad200;
    pbVar13 = (byte *)*piVar10;
    do {
      bVar2 = *pbVar13;
      bVar19 = bVar2 < *pbVar17;
      if (bVar2 != *pbVar17) {
LAB_100048e4:
        uVar7 = -(uint)bVar19 | 1;
        goto LAB_100048e9;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar13[1];
      bVar19 = bVar2 < pbVar17[1];
      if (bVar2 != pbVar17[1]) goto LAB_100048e4;
      pbVar13 = pbVar13 + 2;
      pbVar17 = pbVar17 + 2;
    } while (bVar2 != 0);
    uVar7 = 0;
LAB_100048e9:
    LOCK();
    puVar18 = local_270 + -1;
    uVar1 = *puVar18;
    *puVar18 = *puVar18 - 1;
    UNLOCK();
    puVar18 = local_58;
    if ((int)(uVar1 - 1) < 1) {
      (**(code **)(*(int *)local_270[-4] + 4))();
      puVar18 = local_58;
    }
  }
  local_58 = puVar18;
  if (uVar7 != 0) {
    local_280 = 5;
    goto LAB_100051bb;
  }
  piVar10 = FUN_100081c0(&local_58,(int *)&local_270,0x13);
  local_8._0_1_ = 0x24;
  FUN_10008860(&local_58,piVar10);
  local_8._0_1_ = 4;
  LOCK();
  puVar18 = local_270 + -1;
  uVar7 = *puVar18;
  *puVar18 = *puVar18 - 1;
  UNLOCK();
  if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
    (**(code **)(*(int *)local_270[-4] + 4))();
  }
  piVar10 = FUN_100080b0(&local_58,(int *)&local_270,6);
  local_8._0_1_ = 0x25;
  FUN_10008860(&local_58,piVar10);
  local_8._0_1_ = 4;
  LOCK();
  puVar18 = local_270 + -1;
  uVar7 = *puVar18;
  *puVar18 = *puVar18 - 1;
  UNLOCK();
  if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
    (**(code **)(*(int *)local_270[-4] + 4))();
  }
  piVar10 = FUN_100080b0(&local_58,(int *)&local_27c,1);
  local_8 = CONCAT31(local_8._1_3_,0x26);
  local_288 = (uint *)0x1;
  local_270 = (uint *)0x1;
  iVar5 = __mbscmp((uchar *)*piVar10,"v");
  if (iVar5 == 0) {
LAB_100049ff:
    local_275 = '\0';
  }
  else {
    piVar10 = FUN_100080b0(&local_58,(int *)&local_274,1);
    local_288 = (uint *)0x3;
    iVar5 = __mbscmp((uchar *)*piVar10,"V");
    local_275 = '\x01';
    if (iVar5 == 0) goto LAB_100049ff;
  }
  puVar18 = local_288;
  if (((uint)local_288 & 2) != 0) {
    puVar18 = (uint *)((uint)local_288 & 0xfffffffd);
    puVar15 = local_274 + -4;
    LOCK();
    puVar22 = local_274 + -1;
    uVar7 = *puVar22;
    local_288 = puVar18;
    local_270 = puVar18;
    *puVar22 = *puVar22 - 1;
    UNLOCK();
    if ((int)(uVar7 - 1) < 1) {
      (**(code **)(*(int *)*puVar15 + 4))();
      puVar18 = local_288;
    }
  }
  local_8._0_1_ = 4;
  local_8._1_3_ = 0;
  if (((uint)puVar18 & 1) != 0) {
    puVar22 = local_27c + -4;
    LOCK();
    puVar18 = local_27c + -1;
    uVar7 = *puVar18;
    *puVar18 = *puVar18 - 1;
    UNLOCK();
    if ((int)(uVar7 - 1) < 1) {
      (**(code **)(*(int *)*puVar22 + 4))();
    }
  }
  if (local_275 != '\0') {
    local_280 = 4;
    puVar18 = local_58;
    goto LAB_100051bb;
  }
  uVar7 = local_58[-3];
  if ((int)uVar7 < 1) {
LAB_10005258:
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7ff8ffa9);
  }
  if (1 < (int)local_58[-1]) {
    FUN_10008ef0(&local_58,uVar7);
  }
  *(undefined1 *)local_58 = 0x41;
  if ((int)local_58[-2] < (int)uVar7) goto LAB_10005258;
  local_58[-3] = uVar7;
  *(undefined1 *)(uVar7 + (int)local_58) = 0;
  FUN_10008570(&local_58,'.');
  puVar18 = local_58;
  local_274 = (uint *)&stack0xfffffd58;
  pauVar21 = (undefined1 (*) [32])0x10004b4f;
  puVar23 = extraout_ECX;
  puVar14 = (undefined4 *)(**(code **)(*(int *)local_58[-4] + 0x10))();
  local_27c = puVar18 + -1;
  if (((int)puVar18[-1] < 0) || (puVar14 != (undefined4 *)puVar18[-4])) {
    local_270 = (uint *)(**(code **)*puVar14)();
    if (local_270 == (uint *)0x0) goto LAB_1000533e;
    local_270[1] = puVar18[-3];
    FUN_10001e00(local_270 + 4,puVar18[-3] + 1,puVar18,puVar18[-3] + 1);
    puVar22 = local_270;
  }
  else {
    LOCK();
    *local_27c = *local_27c + 1;
    UNLOCK();
    puVar22 = puVar18 + -4;
  }
  *local_274 = (uint)(puVar22 + 4);
  pcVar20 = FUN_10003cf0(&DAT_101d281c,pauVar21);
  if (pcVar20 == (char *)0x1) {
    FUN_10001f20((char *)puVar18,"%04x");
    local_284 = (uint *)&stack0xfffffd54;
    local_274 = (uint *)&stack0xfffffd54;
    ppuVar4 = FUN_1000f8a0();
    if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar5 = (**(code **)(*ppuVar4 + 0xc))();
    uVar7 = iVar5 + 0x10;
    local_8 = CONCAT31(local_8._1_3_,0x27);
    cVar3 = FUN_10008d30(&stack0xfffffd54,0x101ad14c);
    if (cVar3 == '\0') {
      FUN_10009140(&stack0xfffffd54,(uint *)"update_config.ini",0x11);
    }
    local_274 = (uint *)&stack0xfffffd50;
    local_270 = (uint *)&stack0xfffffd50;
    local_8._0_1_ = 0x28;
    ppuVar4 = FUN_1000f8a0();
    if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar5 = (**(code **)(*ppuVar4 + 0xc))();
    pCVar8 = (LPCSTR)(iVar5 + 0x10);
    local_8 = CONCAT31(local_8._1_3_,0x29);
    cVar3 = FUN_10008d30(&stack0xfffffd50,0x101ad1c8);
    if (cVar3 == '\0') {
      FUN_10009140(&stack0xfffffd50,(uint *)"upgrade_file",0xc);
    }
    local_270 = (uint *)&stack0xfffffd4c;
    local_8._0_1_ = 0x2a;
    ppuVar4 = FUN_1000f8a0();
    if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar5 = (**(code **)(*ppuVar4 + 0xc))();
    pCVar9 = (LPCSTR)(iVar5 + 0x10);
    local_8 = CONCAT31(local_8._1_3_,0x2b);
    cVar3 = FUN_10008d30(&stack0xfffffd4c,0x101ad1d8);
    if (cVar3 == '\0') {
      FUN_10009140(&stack0xfffffd4c,(uint *)"BIN_FILE",8);
    }
    local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
    local_8._0_1_ = 4;
    piVar10 = FUN_10002af0(&local_27c,pCVar9,pCVar8,uVar7);
    local_8._0_1_ = 0x2c;
    FUN_10008860(&local_58,piVar10);
    local_8._0_1_ = 4;
    LOCK();
    puVar18 = local_27c + -1;
    uVar7 = *puVar18;
    *puVar18 = *puVar18 - 1;
    UNLOCK();
    if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
      (**(code **)(*(int *)local_27c[-4] + 4))();
    }
    piVar10 = FUN_100081c0(&local_58,(int *)&local_27c,0xc);
    local_8._0_1_ = 0x2d;
    FUN_10008860(&local_58,piVar10);
    local_8._0_1_ = 4;
    LOCK();
    puVar18 = local_27c + -1;
    uVar7 = *puVar18;
    *puVar18 = *puVar18 - 1;
    UNLOCK();
    if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
      (**(code **)(*(int *)local_27c[-4] + 4))();
    }
    piVar10 = FUN_100080b0(&local_58,(int *)&local_27c,8);
    local_8._0_1_ = 0x2e;
    FUN_10008860(&local_58,piVar10);
    local_8._0_1_ = 4;
    LOCK();
    puVar18 = local_27c + -1;
    uVar7 = *puVar18;
    *puVar18 = *puVar18 - 1;
    UNLOCK();
    pauVar21 = extraout_ECX_00;
    if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
      (**(code **)(*(int *)local_27c[-4] + 4))();
      pauVar21 = extraout_ECX_01;
    }
    puVar18 = local_58;
    local_288 = (uint *)&stack0xfffffd54;
    puVar14 = (undefined4 *)(**(code **)(*(int *)local_58[-4] + 0x10))();
    local_274 = puVar18 + -1;
    if (((int)puVar18[-1] < 0) || (puVar14 != (undefined4 *)puVar18[-4])) {
      local_270 = (uint *)(**(code **)*puVar14)();
      if (local_270 == (uint *)0x0) goto LAB_1000533e;
      local_270[1] = puVar18[-3];
      FUN_10001e00(local_270 + 4,puVar18[-3] + 1,puVar18,puVar18[-3] + 1);
      puVar22 = local_270;
    }
    else {
      LOCK();
      *local_274 = *local_274 + 1;
      UNLOCK();
      puVar22 = puVar18 + -4;
    }
    *local_288 = (uint)(puVar22 + 4);
    pcVar20 = FUN_10003cf0(&DAT_101d282c,pauVar21);
    if (pcVar20 == (char *)0x1) {
      puVar22 = &DAT_101d282c;
      FUN_10001f20((char *)puVar18,"%08x");
      local_270 = (uint *)(DAT_101d2840 + -0x10);
      local_290 = &stack0xfffffd54;
      local_284 = (uint *)&stack0xfffffd54;
      puVar14 = (undefined4 *)(**(code **)(*(int *)*local_270 + 0x10))();
      local_274 = local_270 + 3;
      if (((int)local_270[3] < 0) || (puVar14 != (undefined4 *)*local_270)) {
        local_288 = (uint *)(**(code **)*puVar14)();
        if (local_288 == (uint *)0x0) goto LAB_1000533e;
        local_288[1] = local_270[1];
        FUN_10001e00(local_288 + 4,local_270[1] + 1,local_270 + 4,local_270[1] + 1);
        local_270 = local_288;
      }
      else {
        LOCK();
        *local_274 = *local_274 + 1;
        UNLOCK();
      }
      *local_284 = (uint)(local_270 + 4);
      local_8._0_1_ = 0x2f;
      local_274 = (uint *)&stack0xfffffd50;
      local_270 = (uint *)(DAT_101d283c + -0x10);
      puVar14 = (undefined4 *)(**(code **)(*(int *)*local_270 + 0x10))();
      local_284 = local_270 + 3;
      if (((int)local_270[3] < 0) || (puVar14 != (undefined4 *)*local_270)) {
        local_288 = (uint *)(**(code **)*puVar14)();
        if (local_288 == (uint *)0x0) {
LAB_1000533e:
                    /* WARNING: Subroutine does not return */
          FUN_10009130();
        }
        local_288[1] = local_270[1];
        FUN_10001e00(local_288 + 4,local_270[1] + 1,local_270 + 4,local_270[1] + 1);
        puVar15 = local_288;
      }
      else {
        LOCK();
        *local_284 = *local_284 + 1;
        UNLOCK();
        puVar15 = local_270;
      }
      *local_274 = (uint)(puVar15 + 4);
      local_8._0_1_ = 4;
      cVar3 = FUN_10003350(puVar22,puVar23);
      if (cVar3 != '\0') {
        do {
          DAT_101ca85c = CreateFileA(DAT_101d2838,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,
                                     0x40000000,(HANDLE)0x0);
          if (DAT_101ca85c == (HANDLE)0xffffffff) goto LAB_1000514d;
          local_26c = 0x30;
          local_268 = 4;
          local_264 = 0x76746567;
          local_284 = (uint *)0xc;
          DAT_101ca850 = DAT_101ca85c;
          uVar16 = FUN_10003920((int)&local_26c,(uint *)&local_284,&local_274);
          if ((char)uVar16 == '\0') {
            local_280 = local_280 + -1;
            if (DAT_101ca85c == DAT_101ca850) {
              CloseHandle(DAT_101ca85c);
              DAT_101ca85c = (HANDLE)0xffffffff;
LAB_10005058:
              DAT_101ca850 = (HANDLE)0xffffffff;
            }
            else {
              if (DAT_101ca85c != (HANDLE)0xffffffff) {
                CloseHandle(DAT_101ca85c);
                DAT_101ca85c = (HANDLE)0xffffffff;
              }
              if (DAT_101ca850 != (HANDLE)0xffffffff) {
                CloseHandle(DAT_101ca850);
                goto LAB_10005058;
              }
            }
            Sleep(100);
          }
          else {
            uVar7 = FUN_10003a60((undefined4 *)local_54,(DWORD *)&local_290,&local_274);
            if ((char)uVar7 != '\0') {
              if ((local_54[0] != '0') || (local_50 != 0x10)) goto LAB_1000514d;
              _DAT_101d2820 = (uint)CONCAT11(local_40,local_3f);
              DAT_101d2824 = (uint)CONCAT11(local_44,local_43);
              DAT_101d2830 = 3;
              uVar7 = _DAT_101d2820;
              if (DAT_101d281c <= _DAT_101d2820) {
                uVar7 = _DAT_101d2820 | 0xfffff000;
              }
              local_280 = uVar7 << 0x10 | DAT_101d2824;
              goto LAB_100051c5;
            }
            local_280 = local_280 + -1;
            if (DAT_101ca85c == DAT_101ca850) {
              CloseHandle(DAT_101ca85c);
              DAT_101ca85c = (HANDLE)0xffffffff;
              DAT_101ca850 = (HANDLE)0xffffffff;
            }
            else {
              if (DAT_101ca85c != (HANDLE)0xffffffff) {
                CloseHandle(DAT_101ca85c);
                DAT_101ca85c = (HANDLE)0xffffffff;
              }
              if (DAT_101ca850 != (HANDLE)0xffffffff) {
                CloseHandle(DAT_101ca850);
                DAT_101ca850 = (HANDLE)0xffffffff;
              }
            }
          }
        } while (local_280 != 0);
        if (DAT_101ca85c == DAT_101ca850) {
          CloseHandle(DAT_101ca85c);
          DAT_101ca85c = (HANDLE)0xffffffff;
        }
        else {
          if (DAT_101ca85c != (HANDLE)0xffffffff) {
            CloseHandle(DAT_101ca85c);
            DAT_101ca85c = (HANDLE)0xffffffff;
          }
          if (DAT_101ca850 == (HANDLE)0xffffffff) goto LAB_1000514d;
          CloseHandle(DAT_101ca850);
        }
        DAT_101ca850 = (HANDLE)0xffffffff;
      }
LAB_1000514d:
      local_280 = 2;
      goto LAB_100051bb;
    }
  }
  local_280 = 4;
LAB_100051bb:
  DAT_101d2830 = 0;
LAB_100051c5:
  local_8._0_1_ = 3;
  LOCK();
  piVar10 = (int *)(puVar12 + -4);
  iVar5 = *piVar10;
  *piVar10 = *piVar10 + -1;
  UNLOCK();
  if (iVar5 == 1 || iVar5 + -1 < 0) {
    (**(code **)(**(int **)(puVar12 + -0x10) + 4))();
  }
  local_8._0_1_ = 2;
  LOCK();
  piVar10 = (int *)(local_60 + -4);
  iVar5 = *piVar10;
  *piVar10 = *piVar10 + -1;
  UNLOCK();
  if (iVar5 == 1 || iVar5 + -1 < 0) {
    (**(code **)(**(int **)(local_60 + -0x10) + 4))();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  LOCK();
  piVar10 = puVar6 + 3;
  iVar5 = *piVar10;
  *piVar10 = *piVar10 + -1;
  UNLOCK();
  if (iVar5 == 1 || iVar5 + -1 < 0) {
    (**(code **)(*(int *)*puVar6 + 4))();
  }
  local_8 = 0xffffffff;
  LOCK();
  puVar22 = puVar18 + -1;
  uVar7 = *puVar22;
  *puVar22 = *puVar22 - 1;
  UNLOCK();
  if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
    (**(code **)(*(int *)puVar18[-4] + 4))();
  }
  ExceptionList = local_10;
  return local_280;
}
