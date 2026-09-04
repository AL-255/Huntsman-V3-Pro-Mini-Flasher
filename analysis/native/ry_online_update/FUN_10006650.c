/* 10006650 FUN_10006650 [[10006650, 10007978]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10006650(void)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  undefined **ppuVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  LPCSTR pCVar10;
  LPCSTR pCVar11;
  int *piVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  uint *puVar15;
  errno_t eVar16;
  size_t sVar17;
  byte *pbVar18;
  uint *puVar19;
  undefined1 (*extraout_ECX) [32];
  undefined1 (*extraout_ECX_00) [32];
  undefined1 (*extraout_ECX_01) [32];
  undefined1 (*pauVar20) [32];
  uint uVar21;
  int *piVar22;
  char *pcVar23;
  bool bVar24;
  char *pcVar25;
  undefined4 local_468;
  int *local_464;
  uint *local_460;
  uint *local_45c;
  char local_455;
  uint *local_454;
  FILE *local_450;
  char local_44c;
  char local_44b;
  undefined2 local_44a;
  short local_448;
  undefined1 local_446;
  undefined1 local_445;
  uint *local_444;
  undefined4 local_440;
  undefined1 local_43c;
  undefined1 local_43b;
  WORD local_43a;
  uint local_41c [119];
  undefined4 *local_240;
  _SYSTEMTIME local_23c;
  char *local_22c;
  int local_228;
  char *local_224;
  undefined1 *local_220;
  uint *local_21c;
  byte local_215;
  uint local_214;
  uint local_210 [127];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_1016a093;
  local_10 = ExceptionList;
  local_14 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_454 = (uint *)0x0;
  local_228 = 0;
  local_468 = 0;
  local_450 = (FILE *)0x0;
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar6 = (**(code **)(*ppuVar5 + 0xc))();
  local_21c = (uint *)(iVar6 + 0x10);
  local_8 = 0;
  cVar3 = FUN_10008d30(&local_21c,0x101ad0ea);
  if (cVar3 == '\0') {
    FUN_10009140(&local_21c,(uint *)&DAT_101ad0ea,0);
  }
  local_8 = 1;
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  puVar7 = (undefined4 *)(**(code **)(*ppuVar5 + 0xc))();
  local_240 = puVar7 + 4;
  local_8._0_1_ = 2;
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar6 = (**(code **)(*ppuVar5 + 0xc))();
  pcVar23 = (char *)(iVar6 + 0x10);
  local_8._0_1_ = 3;
  local_22c = pcVar23;
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar6 = (**(code **)(*ppuVar5 + 0xc))();
  local_224 = (char *)(iVar6 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,4);
  cVar3 = FUN_10008d30(&local_224,0x101ad0ea);
  if (cVar3 == '\0') {
    FUN_10009140(&local_224,(uint *)&DAT_101ad0ea,0);
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  cVar3 = '\0';
  local_220 = (undefined1 *)0x0;
  local_215 = 0;
  _memset(&local_214,0,0x200);
  uVar21 = 0;
  uVar8 = DAT_101d2824 & 0xfff | 0xa000;
  if (uVar8 < 0xa122) {
    if (0xa104 < uVar8) {
      local_214 = 0x1b8;
      puVar19 = &DAT_101ad578;
      puVar15 = local_210;
      for (iVar6 = 0x6e; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar15 = *puVar19;
        puVar19 = puVar19 + 1;
        puVar15 = puVar15 + 1;
      }
      uVar8 = 0x1b8;
      goto LAB_1000681a;
    }
    bVar2 = true;
  }
  else {
    local_214 = 0x19c;
    puVar19 = &DAT_101ad3d8;
    puVar15 = local_210;
    for (iVar6 = 0x67; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar15 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar15 = puVar15 + 1;
    }
    uVar8 = 0x19c;
LAB_1000681a:
    uVar9 = 0;
    do {
      uVar21 = uVar21 ^ *(uint *)((int)local_210 + uVar9);
      uVar9 = uVar9 + 4;
    } while (uVar9 < uVar8);
    *(uint *)((int)local_210 + uVar8) = uVar21;
    bVar2 = false;
    pcVar23 = local_22c;
  }
  local_460 = (uint *)&stack0xfffffb78;
  local_464 = (int *)&stack0xfffffb78;
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar6 = (**(code **)(*ppuVar5 + 0xc))();
  uVar8 = iVar6 + 0x10;
  local_8 = CONCAT31(local_8._1_3_,6);
  cVar4 = FUN_10008d30(&stack0xfffffb78,0x101ad14c);
  if (cVar4 == '\0') {
    FUN_10009140(&stack0xfffffb78,(uint *)"update_config.ini",0x11);
  }
  local_464 = (int *)&stack0xfffffb74;
  local_45c = (uint *)&stack0xfffffb74;
  local_8._0_1_ = 7;
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar6 = (**(code **)(*ppuVar5 + 0xc))();
  pCVar10 = (LPCSTR)(iVar6 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,8);
  cVar4 = FUN_10008d30(&stack0xfffffb74,0x101ad1c8);
  if (cVar4 == '\0') {
    FUN_10009140(&stack0xfffffb74,(uint *)"upgrade_file",0xc);
  }
  local_45c = (uint *)&stack0xfffffb70;
  local_8._0_1_ = 9;
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar6 = (**(code **)(*ppuVar5 + 0xc))();
  pCVar11 = (LPCSTR)(iVar6 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,10);
  cVar4 = FUN_10008d30(&stack0xfffffb70,0x101ad1d8);
  if (cVar4 == '\0') {
    FUN_10009140(&stack0xfffffb70,(uint *)"BIN_FILE",8);
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 5;
  piVar12 = FUN_10002af0(&local_454,pCVar11,pCVar10,uVar8);
  local_8._0_1_ = 0xb;
  FUN_10008860(&local_21c,piVar12);
  local_8._0_1_ = 5;
  LOCK();
  puVar19 = local_454 + -1;
  uVar8 = *puVar19;
  *puVar19 = *puVar19 - 1;
  UNLOCK();
  if (uVar8 == 1 || (int)(uVar8 - 1) < 0) {
    (**(code **)(*(int *)local_454[-4] + 4))();
  }
  piVar12 = FUN_10007e70((int *)&local_454,&DAT_101d2834,&local_21c);
  local_8._0_1_ = 0xc;
  FUN_10008860(&local_224,piVar12);
  local_8._0_1_ = 5;
  LOCK();
  puVar19 = local_454 + -1;
  uVar8 = *puVar19;
  *puVar19 = *puVar19 - 1;
  UNLOCK();
  if (uVar8 == 1 || (int)(uVar8 - 1) < 0) {
    (**(code **)(*(int *)local_454[-4] + 4))();
  }
  pcVar25 = "%x";
  local_460 = (uint *)&stack0xfffffb70;
  local_464 = (int *)&stack0xfffffb70;
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar6 = (**(code **)(*ppuVar5 + 0xc))();
  uVar8 = iVar6 + 0x10;
  local_8 = CONCAT31(local_8._1_3_,0xd);
  cVar4 = FUN_10008d30(&stack0xfffffb70,0x101ad14c);
  if (cVar4 == '\0') {
    FUN_10009140(&stack0xfffffb70,(uint *)"update_config.ini",0x11);
  }
  local_464 = (int *)&stack0xfffffb6c;
  local_45c = (uint *)&stack0xfffffb6c;
  local_8._0_1_ = 0xe;
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar6 = (**(code **)(*ppuVar5 + 0xc))();
  pCVar10 = (LPCSTR)(iVar6 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,0xf);
  cVar4 = FUN_10008d30(&stack0xfffffb6c,0x101ad1e4);
  if (cVar4 == '\0') {
    FUN_10009140(&stack0xfffffb6c,(uint *)"encryption_en",0xd);
  }
  local_45c = (uint *)&stack0xfffffb68;
  local_8._0_1_ = 0x10;
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar6 = (**(code **)(*ppuVar5 + 0xc))();
  pCVar11 = (LPCSTR)(iVar6 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,0x11);
  cVar4 = FUN_10008d30(&stack0xfffffb68,0x101ad1f4);
  if (cVar4 == '\0') {
    FUN_10009140(&stack0xfffffb68,(uint *)"ENCRY_EN",8);
  }
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),5);
  piVar12 = FUN_10002af0(&local_454,pCVar11,pCVar10,uVar8);
  iVar6 = FUN_10001f20((char *)*piVar12,pcVar25);
  local_455 = iVar6 == 0;
  LOCK();
  puVar19 = local_454 + -1;
  uVar8 = *puVar19;
  *puVar19 = *puVar19 - 1;
  UNLOCK();
  if (uVar8 == 1 || (int)(uVar8 - 1) < 0) {
    (**(code **)(*(int *)local_454[-4] + 4))();
  }
  if (local_455 == '\0') {
    if (local_228 == 0) {
      piVar12 = FUN_100081c0(&local_21c,(int *)&local_454,4);
      pbVar18 = &DAT_101ad208;
      pbVar13 = (byte *)*piVar12;
      do {
        bVar1 = *pbVar13;
        bVar24 = bVar1 < *pbVar18;
        if (bVar1 != *pbVar18) goto LAB_10006b90;
        if (bVar1 == 0) break;
        bVar1 = pbVar13[1];
        bVar24 = bVar1 < pbVar18[1];
        if (bVar1 != pbVar18[1]) goto LAB_10006b90;
        pbVar13 = pbVar13 + 2;
        pbVar18 = pbVar18 + 2;
      } while (bVar1 != 0);
LAB_10006b8c:
      uVar8 = 0;
      goto LAB_10006b95;
    }
  }
  else {
    local_228 = 1;
  }
  piVar12 = FUN_100081c0(&local_21c,(int *)&local_454,4);
  pbVar18 = &DAT_101ad200;
  pbVar13 = (byte *)*piVar12;
  do {
    bVar1 = *pbVar13;
    bVar24 = bVar1 < *pbVar18;
    if (bVar1 != *pbVar18) goto LAB_10006b90;
    if (bVar1 == 0) goto LAB_10006b8c;
    bVar1 = pbVar13[1];
    bVar24 = bVar1 < pbVar18[1];
    if (bVar1 != pbVar18[1]) goto LAB_10006b90;
    pbVar13 = pbVar13 + 2;
    pbVar18 = pbVar18 + 2;
  } while (bVar1 != 0);
  uVar8 = 0;
LAB_10006b95:
  LOCK();
  puVar19 = local_454 + -1;
  uVar21 = *puVar19;
  *puVar19 = *puVar19 - 1;
  UNLOCK();
  if ((int)(uVar21 - 1) < 1) {
    (**(code **)(*(int *)local_454[-4] + 4))();
  }
  puVar19 = local_21c;
  if (uVar8 == 0) {
    piVar12 = FUN_100081c0(&local_21c,(int *)&local_454,0x13);
    local_8._0_1_ = 0x12;
    FUN_10008860(&local_21c,piVar12);
    local_8._0_1_ = 5;
    LOCK();
    puVar19 = local_454 + -1;
    uVar8 = *puVar19;
    *puVar19 = *puVar19 - 1;
    UNLOCK();
    if (uVar8 == 1 || (int)(uVar8 - 1) < 0) {
      (**(code **)(*(int *)local_454[-4] + 4))();
    }
    piVar12 = FUN_100080b0(&local_21c,(int *)&local_454,6);
    local_8._0_1_ = 0x13;
    FUN_10008860(&local_21c,piVar12);
    local_8._0_1_ = 5;
    LOCK();
    puVar19 = local_454 + -1;
    uVar8 = *puVar19;
    *puVar19 = *puVar19 - 1;
    UNLOCK();
    if (uVar8 == 1 || (int)(uVar8 - 1) < 0) {
      (**(code **)(*(int *)local_454[-4] + 4))();
    }
    piVar12 = FUN_100080b0(&local_21c,(int *)&local_460,1);
    local_8 = CONCAT31(local_8._1_3_,0x14);
    local_45c = (uint *)0x1;
    local_454 = (uint *)0x1;
    iVar6 = __mbscmp((uchar *)*piVar12,"v");
    if (iVar6 == 0) {
LAB_10006cbd:
      local_455 = '\0';
    }
    else {
      piVar12 = FUN_100080b0(&local_21c,(int *)&local_464,1);
      local_45c = (uint *)0x3;
      iVar6 = __mbscmp((uchar *)*piVar12,"V");
      local_455 = '\x01';
      if (iVar6 == 0) goto LAB_10006cbd;
    }
    puVar19 = local_45c;
    if (((uint)local_45c & 2) != 0) {
      puVar19 = (uint *)((uint)local_45c & 0xfffffffd);
      piVar22 = local_464 + -4;
      LOCK();
      piVar12 = local_464 + -1;
      iVar6 = *piVar12;
      local_45c = puVar19;
      local_454 = puVar19;
      *piVar12 = *piVar12 + -1;
      UNLOCK();
      if (iVar6 + -1 < 1) {
        (**(code **)(*(int *)*piVar22 + 4))();
        puVar19 = local_45c;
      }
    }
    local_8 = 5;
    if (((uint)puVar19 & 1) != 0) {
      puVar15 = local_460 + -4;
      LOCK();
      puVar19 = local_460 + -1;
      uVar8 = *puVar19;
      *puVar19 = *puVar19 - 1;
      UNLOCK();
      if ((int)(uVar8 - 1) < 1) {
        (**(code **)(*(int *)*puVar15 + 4))();
      }
    }
    puVar19 = local_21c;
    if (local_455 != '\0') goto LAB_10007815;
    uVar8 = local_21c[-3];
    if ((int)uVar8 < 1) goto LAB_1000796f;
    if (1 < (int)local_21c[-1]) {
      FUN_10008ef0(&local_21c,uVar8);
    }
    *(undefined1 *)local_21c = 0x41;
    if ((int)local_21c[-2] < (int)uVar8) goto LAB_1000796f;
    local_21c[-3] = uVar8;
    *(undefined1 *)(uVar8 + (int)local_21c) = 0;
    FUN_10008570(&local_21c,'.');
    puVar19 = local_21c;
    local_464 = (int *)&stack0xfffffb78;
    pauVar20 = extraout_ECX;
    puVar14 = (undefined4 *)(**(code **)(*(int *)local_21c[-4] + 0x10))();
    local_460 = puVar19 + -1;
    if (((int)puVar19[-1] < 0) || (puVar14 != (undefined4 *)puVar19[-4])) {
      local_454 = (uint *)(**(code **)*puVar14)();
      if (local_454 == (uint *)0x0) goto LAB_1000796a;
      local_454[1] = puVar19[-3];
      FUN_10001e00(local_454 + 4,puVar19[-3] + 1,puVar19,puVar19[-3] + 1);
      puVar15 = local_454;
    }
    else {
      LOCK();
      *local_460 = *local_460 + 1;
      UNLOCK();
      puVar15 = puVar19 + -4;
    }
    *local_464 = (int)(puVar15 + 4);
    pcVar25 = FUN_10003cf0(&DAT_101d281c,pauVar20);
    if (pcVar25 != (char *)0x1) goto LAB_10007815;
    FUN_10001f20((char *)puVar19,"%04x");
    local_464 = (int *)&stack0xfffffb78;
    local_454 = (uint *)&stack0xfffffb78;
    ppuVar5 = FUN_1000f8a0();
    if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar6 = (**(code **)(*ppuVar5 + 0xc))();
    uVar8 = iVar6 + 0x10;
    local_8 = CONCAT31(local_8._1_3_,0x15);
    cVar4 = FUN_10008d30(&stack0xfffffb78,0x101ad14c);
    if (cVar4 == '\0') {
      FUN_10009140(&stack0xfffffb78,(uint *)"update_config.ini",0x11);
    }
    local_454 = (uint *)&stack0xfffffb74;
    local_45c = (uint *)&stack0xfffffb74;
    local_8._0_1_ = 0x16;
    ppuVar5 = FUN_1000f8a0();
    if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar6 = (**(code **)(*ppuVar5 + 0xc))();
    pCVar10 = (LPCSTR)(iVar6 + 0x10);
    local_8 = CONCAT31(local_8._1_3_,0x17);
    cVar4 = FUN_10008d30(&stack0xfffffb74,0x101ad1c8);
    if (cVar4 == '\0') {
      FUN_10009140(&stack0xfffffb74,(uint *)"upgrade_file",0xc);
    }
    local_45c = (uint *)&stack0xfffffb70;
    local_8._0_1_ = 0x18;
    ppuVar5 = FUN_1000f8a0();
    if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar6 = (**(code **)(*ppuVar5 + 0xc))();
    pCVar11 = (LPCSTR)(iVar6 + 0x10);
    local_8 = CONCAT31(local_8._1_3_,0x19);
    cVar4 = FUN_10008d30(&stack0xfffffb70,0x101ad1d8);
    if (cVar4 == '\0') {
      FUN_10009140(&stack0xfffffb70,(uint *)"BIN_FILE",8);
    }
    local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
    local_8._0_1_ = 5;
    piVar12 = FUN_10002af0(&local_460,pCVar11,pCVar10,uVar8);
    local_8._0_1_ = 0x1a;
    FUN_10008860(&local_21c,piVar12);
    local_8._0_1_ = 5;
    LOCK();
    puVar19 = local_460 + -1;
    uVar8 = *puVar19;
    *puVar19 = *puVar19 - 1;
    UNLOCK();
    if (uVar8 == 1 || (int)(uVar8 - 1) < 0) {
      (**(code **)(*(int *)local_460[-4] + 4))();
    }
    piVar12 = FUN_100081c0(&local_21c,(int *)&local_460,0xc);
    local_8._0_1_ = 0x1b;
    FUN_10008860(&local_21c,piVar12);
    local_8._0_1_ = 5;
    LOCK();
    puVar19 = local_460 + -1;
    uVar8 = *puVar19;
    *puVar19 = *puVar19 - 1;
    UNLOCK();
    if (uVar8 == 1 || (int)(uVar8 - 1) < 0) {
      (**(code **)(*(int *)local_460[-4] + 4))();
    }
    piVar12 = FUN_100080b0(&local_21c,(int *)&local_460,8);
    local_8._0_1_ = 0x1c;
    FUN_10008860(&local_21c,piVar12);
    local_8 = CONCAT31(local_8._1_3_,5);
    LOCK();
    puVar19 = local_460 + -1;
    uVar8 = *puVar19;
    *puVar19 = *puVar19 - 1;
    UNLOCK();
    pauVar20 = extraout_ECX_00;
    if (uVar8 == 1 || (int)(uVar8 - 1) < 0) {
      (**(code **)(*(int *)local_460[-4] + 4))();
      pauVar20 = extraout_ECX_01;
    }
    puVar19 = local_21c;
    local_464 = (int *)&stack0xfffffb78;
    puVar14 = (undefined4 *)(**(code **)(*(int *)local_21c[-4] + 0x10))();
    local_460 = puVar19 + -1;
    if (((int)puVar19[-1] < 0) || (puVar14 != (undefined4 *)puVar19[-4])) {
      local_454 = (uint *)(**(code **)*puVar14)();
      if (local_454 == (uint *)0x0) {
LAB_1000796a:
                    /* WARNING: Subroutine does not return */
        FUN_10009130();
      }
      local_454[1] = puVar19[-3];
      FUN_10001e00(local_454 + 4,puVar19[-3] + 1,puVar19,puVar19[-3] + 1);
      puVar15 = local_454;
    }
    else {
      LOCK();
      *local_460 = *local_460 + 1;
      UNLOCK();
      puVar15 = puVar19 + -4;
    }
    *local_464 = (int)(puVar15 + 4);
    pcVar25 = FUN_10003cf0(&DAT_101d282c,pauVar20);
    if (pcVar25 != (char *)0x1) goto LAB_10007815;
    FUN_10001f20((char *)puVar19,"%08x");
    eVar16 = _fopen_s(&local_450,local_224,"rb");
    if ((eVar16 != 0) || (local_450 == (FILE *)0x0)) {
      local_460 = (uint *)GetLastError();
      ppuVar5 = FUN_1000f8a0();
      if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_10002000(-0x7fffbffb);
      }
      iVar6 = (**(code **)(*ppuVar5 + 0xc))();
      local_220 = (undefined1 *)(iVar6 + 0x10);
      local_8 = CONCAT31(local_8._1_3_,0x1d);
      cVar3 = FUN_10008d30(&local_220,0x101ad0ea);
      if (cVar3 == '\0') {
        FUN_10009140(&local_220,(uint *)&DAT_101ad0ea,0);
      }
      local_8._0_1_ = 0x1e;
      FUN_10009350(&local_220,(uint *)&DAT_101ad0e4);
      local_8 = CONCAT31(local_8._1_3_,5);
      DAT_101d2830 = 0;
      LOCK();
      piVar12 = (int *)(local_220 + -4);
      iVar6 = *piVar12;
      *piVar12 = *piVar12 + -1;
      UNLOCK();
      if (iVar6 + -1 < 1) {
        (**(code **)(**(int **)(local_220 + -0x10) + 4))();
      }
      local_468 = 7;
      goto LAB_10007829;
    }
    _fseek(local_450,0,0);
    uVar8 = _fread(&local_444,1,0x200,local_450);
    while (uVar8 != 0) {
      uVar21 = 0;
      if (uVar8 != 0) {
        do {
          local_220 = (undefined1 *)((uint)local_220 ^ *(uint *)((int)&local_444 + uVar21));
          uVar21 = uVar21 + 4;
        } while (uVar21 < uVar8);
      }
      uVar8 = _fread(&local_444,1,0x200,local_450);
    }
    if (local_220 == DAT_101d282c) {
      local_454 = (uint *)0x0;
      _fseek(local_450,0,2);
      iVar6 = FUN_10148fbb();
      local_45c = (uint *)(iVar6 - 0x20);
      _fseek(local_450,0,0);
      local_464 = (int *)&stack0xfffffb78;
      local_220 = &stack0xfffffb78;
      ppuVar5 = FUN_1000f8a0();
      if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_10002000(-0x7fffbffb);
      }
      iVar6 = (**(code **)(*ppuVar5 + 0xc))();
      uVar8 = iVar6 + 0x10;
      local_8 = CONCAT31(local_8._1_3_,0x1f);
      cVar4 = FUN_10008d30(&stack0xfffffb78,0x101ad14c);
      if (cVar4 == '\0') {
        FUN_10009140(&stack0xfffffb78,(uint *)"update_config.ini",0x11);
      }
      local_220 = &stack0xfffffb74;
      local_8._0_1_ = 0x20;
      ppuVar5 = FUN_1000f8a0();
      if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_10002000(-0x7fffbffb);
      }
      iVar6 = (**(code **)(*ppuVar5 + 0xc))();
      pCVar10 = (LPCSTR)(iVar6 + 0x10);
      local_8 = CONCAT31(local_8._1_3_,0x21);
      cVar4 = FUN_10008d30(&stack0xfffffb74,0x101ad248);
      if (cVar4 == '\0') {
        FUN_10009140(&stack0xfffffb74,(uint *)"app_start",9);
      }
      local_8._0_1_ = 0x22;
      ppuVar5 = FUN_1000f8a0();
      if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_10002000(-0x7fffbffb);
      }
      iVar6 = (**(code **)(*ppuVar5 + 0xc))();
      pCVar11 = (LPCSTR)(iVar6 + 0x10);
      local_8 = CONCAT31(local_8._1_3_,0x23);
      cVar4 = FUN_10008d30(&stack0xfffffb70,0x101ad254);
      if (cVar4 == '\0') {
        FUN_10009140(&stack0xfffffb70,(uint *)"APP_START_ADDR",0xe);
      }
      local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
      local_8._0_1_ = 5;
      piVar12 = FUN_10002af0(&local_460,pCVar11,pCVar10,uVar8);
      local_8._0_1_ = 0x24;
      FUN_10008860(&local_22c,piVar12);
      local_8 = CONCAT31(local_8._1_3_,5);
      LOCK();
      puVar15 = local_460 + -1;
      uVar8 = *puVar15;
      *puVar15 = *puVar15 - 1;
      UNLOCK();
      if (uVar8 == 1 || (int)(uVar8 - 1) < 0) {
        (**(code **)(*(int *)local_460[-4] + 4))();
      }
      pcVar23 = local_22c;
      if (*(int *)(local_22c + -0xc) < 0) {
LAB_1000796f:
                    /* WARNING: Subroutine does not return */
        FUN_10002000(-0x7ff8ffa9);
      }
      if (*local_22c == '0') {
        if (*(int *)(local_22c + -0xc) < 1) goto LAB_1000796f;
        if (local_22c[1] != 'x') goto LAB_100072fb;
        pcVar25 = "0x%hhx";
      }
      else {
LAB_100072fb:
        pcVar25 = "%hhd";
      }
      iVar6 = FUN_10001f20(local_22c,pcVar25);
      if (((iVar6 != 1) || (uVar8 = (uint)local_215, local_215 == 0)) ||
         ((uint *)0x20000 < local_45c + uVar8 * 0x80)) {
        uVar8 = 0xff;
        local_215 = 0xff;
      }
      if (DAT_101d2830 != 0) {
        local_220 = (undefined1 *)0x0;
        do {
          switch(DAT_101ca854) {
          case 1:
            DAT_101ca85c = CreateFileA(DAT_101d2838,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,
                                       0x40000000,(HANDLE)0x0);
            if (DAT_101ca85c != (HANDLE)0xffffffff) {
              DAT_101ca854 = 2;
              _DAT_101d2814 = 0;
              DAT_101ca850 = DAT_101ca85c;
              if (DAT_101d2818 != (code *)0x0) goto LAB_10007599;
              goto LAB_100075b2;
            }
            Sleep(100);
            local_468 = 2;
            _DAT_101d2814 = 0;
            DAT_101ca854 = 5;
            goto LAB_100076e2;
          case 2:
            local_44a = (undefined2)((uint)local_45c >> 2);
            local_440 = DAT_101d281c;
            local_44c = '1';
            local_446 = 1;
            local_445 = (undefined1)uVar8;
            local_444 = local_45c;
            local_44b = cVar3;
            sVar17 = _fread(&local_43c,1,0x20,local_450);
            local_448 = (short)sVar17 + 8;
            if (!bVar2) {
              local_464 = (int *)(DAT_101d2824 & 0xfff);
              FUN_10145db0(local_41c,&local_214,(-(uint)(local_464 < (int *)0x122) & 0x1c) + 0x1a4);
              local_448 = local_448 + (-(ushort)(local_464 < (int *)0x122) & 0x1c) + 0x1a4;
            }
            iVar6 = FUN_100064d0(&local_44c);
            _DAT_101d2814 = 0;
            if (iVar6 != 0) goto switchD_10007361_default;
            DAT_101ca854 = 3;
            if (DAT_101d2818 != (code *)0x0) {
              (*DAT_101d2818)();
            }
            cVar3 = cVar3 + '\x01';
            local_220 = local_220 + 0xc800;
            break;
          case 3:
            sVar17 = _fread(&local_444,1,0x200,local_450);
            local_448 = (short)sVar17;
            if ((short)sVar17 == 0) {
              DAT_101ca854 = 4;
              if (DAT_101d2818 == (code *)0x0) goto LAB_100075b2;
            }
            else {
              uVar8 = 0;
              if ((sVar17 & 0xffff) != 0) {
                do {
                  local_454 = (uint *)((uint)local_454 ^ *(uint *)((int)&local_444 + uVar8));
                  uVar8 = uVar8 + 4;
                } while (uVar8 < (sVar17 & 0xffff));
              }
              local_44c = '2';
              local_44b = cVar3;
              iVar6 = FUN_100064d0(&local_44c);
              if (iVar6 != 0) goto switchD_10007361_default;
              local_220 = local_220 + 0xc800;
              cVar3 = cVar3 + '\x01';
              _DAT_101d2814 = (uint)local_220 / (uint)local_45c;
              if (100 < _DAT_101d2814) {
                _DAT_101d2814 = 100;
              }
              if (DAT_101d2818 == (code *)0x0) break;
            }
LAB_10007599:
            (*DAT_101d2818)();
            break;
          case 4:
            goto switchD_10007361_caseD_4;
          default:
switchD_10007361_default:
            _DAT_101d2814 = 0;
            DAT_101ca854 = 5;
            goto LAB_100076d8;
          }
          if (DAT_101ca854 == 5) goto LAB_100076e2;
LAB_100075b2:
          if (DAT_101d2830 == 0) break;
          uVar8 = (uint)local_215;
        } while( true );
      }
LAB_100076d8:
      local_468 = 9;
LAB_100076e2:
      _fclose(local_450);
      if (DAT_101ca85c == DAT_101ca850) {
        CloseHandle(DAT_101ca85c);
        DAT_101ca85c = (HANDLE)0xffffffff;
LAB_1000773e:
        DAT_101ca850 = (HANDLE)0xffffffff;
      }
      else {
        if (DAT_101ca85c != (HANDLE)0xffffffff) {
          CloseHandle(DAT_101ca85c);
          DAT_101ca85c = (HANDLE)0xffffffff;
        }
        if (DAT_101ca850 != (HANDLE)0xffffffff) {
          CloseHandle(DAT_101ca850);
          goto LAB_1000773e;
        }
      }
      if (DAT_101d2818 != (code *)0x0) {
        (*DAT_101d2818)();
      }
      goto LAB_10007829;
    }
    _fclose(local_450);
    local_468 = 8;
  }
  else {
LAB_10007815:
    local_468 = 1;
  }
  DAT_101d2830 = 0;
LAB_10007829:
  local_8._0_1_ = 3;
  LOCK();
  piVar12 = (int *)(local_224 + -4);
  iVar6 = *piVar12;
  *piVar12 = *piVar12 + -1;
  UNLOCK();
  if (iVar6 + -1 < 1) {
    (**(code **)(**(int **)(local_224 + -0x10) + 4))();
  }
  local_8._0_1_ = 2;
  LOCK();
  piVar12 = (int *)(pcVar23 + -4);
  iVar6 = *piVar12;
  *piVar12 = *piVar12 + -1;
  UNLOCK();
  if (iVar6 == 1 || iVar6 + -1 < 0) {
    (**(code **)(**(int **)(pcVar23 + -0x10) + 4))();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  LOCK();
  piVar12 = puVar7 + 3;
  iVar6 = *piVar12;
  *piVar12 = *piVar12 + -1;
  UNLOCK();
  if (iVar6 == 1 || iVar6 + -1 < 0) {
    (**(code **)(*(int *)*puVar7 + 4))();
  }
  local_8 = 0xffffffff;
  LOCK();
  puVar15 = puVar19 + -1;
  uVar8 = *puVar15;
  *puVar15 = *puVar15 - 1;
  UNLOCK();
  if (uVar8 == 1 || (int)(uVar8 - 1) < 0) {
    (**(code **)(*(int *)puVar19[-4] + 4))();
  }
  ExceptionList = local_10;
  return local_468;
LAB_10006b90:
  uVar8 = -(uint)bVar24 | 1;
  goto LAB_10006b95;
switchD_10007361_caseD_4:
  GetLocalTime(&local_23c);
  local_44a = (undefined2)((uint)local_45c >> 2);
  local_444 = local_454;
  local_440 = CONCAT22(local_23c.wYear,
                       CONCAT11((undefined1)local_23c.wMonth,(undefined1)local_23c.wDay));
  local_43c = (undefined1)local_23c.wSecond;
  local_43b = (undefined1)local_23c.wMinute;
  local_43a = local_23c.wHour;
  local_44c = '3';
  local_448 = 0xc;
  local_44b = cVar3;
  iVar6 = FUN_100064d0(&local_44c);
  if (iVar6 == 0) {
    _DAT_101d2814 = 100;
    DAT_101ca854 = 5;
  }
  else {
    local_468 = 9;
    DAT_101ca854 = 5;
  }
  goto LAB_100076e2;
}
