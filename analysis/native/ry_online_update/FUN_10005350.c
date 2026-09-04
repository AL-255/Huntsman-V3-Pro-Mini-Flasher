/* 10005350 FUN_10005350 [[10005350, 10005c1b]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_10005350(void)

{
  char *pcVar1;
  char cVar2;
  undefined **ppuVar3;
  int iVar4;
  int iVar5;
  LPCSTR pCVar6;
  LPCSTR pCVar7;
  int *piVar8;
  errno_t eVar9;
  uchar *puVar10;
  uint *puVar11;
  uint uVar12;
  uchar *extraout_ECX;
  uchar *extraout_ECX_00;
  uchar *puVar13;
  uint *puVar14;
  undefined4 *puVar15;
  undefined1 *local_2c;
  uint *local_28;
  undefined1 local_21;
  uint *local_20;
  char *local_1c;
  uchar *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10169d95;
  local_10 = ExceptionList;
  local_14 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ppuVar3 = FUN_1000f8a0();
  if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar4 = (**(code **)(*ppuVar3 + 0xc))();
  local_1c = (char *)(iVar4 + 0x10);
  local_8 = 0;
  cVar2 = FUN_10008d30(&local_1c,0x101ad0ea);
  if (cVar2 == '\0') {
    FUN_10009140(&local_1c,(uint *)&DAT_101ad0ea,0);
  }
  local_8 = 1;
  ppuVar3 = FUN_1000f8a0();
  if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar4 = (**(code **)(*ppuVar3 + 0xc))();
  local_18 = (uchar *)(iVar4 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,2);
  cVar2 = FUN_10008d30(&local_18,0x101ad0ea);
  if (cVar2 == '\0') {
    FUN_10009140(&local_18,(uint *)&DAT_101ad0ea,0);
  }
  local_28 = (uint *)&stack0xffffffb4;
  local_8._0_1_ = 3;
  ppuVar3 = FUN_1000f8a0();
  if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar4 = (**(code **)(*ppuVar3 + 0xc))();
  iVar4 = iVar4 + 0x10;
  local_8 = CONCAT31(local_8._1_3_,4);
  cVar2 = FUN_10008d30(&stack0xffffffb4,0x101ad14c);
  if (cVar2 == '\0') {
    FUN_10009140(&stack0xffffffb4,(uint *)"update_config.ini",0x11);
  }
  local_28 = (uint *)&stack0xffffffb0;
  local_2c = &stack0xffffffb0;
  local_8._0_1_ = 5;
  ppuVar3 = FUN_1000f8a0();
  if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar3 + 0xc))();
  pCVar6 = (LPCSTR)(iVar5 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,6);
  cVar2 = FUN_10008d30(&stack0xffffffb0,0x101ad190);
  if (cVar2 == '\0') {
    FUN_10009140(&stack0xffffffb0,(uint *)"bootdev_info",0xc);
  }
  local_2c = &stack0xffffffac;
  local_8._0_1_ = 7;
  ppuVar3 = FUN_1000f8a0();
  if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar3 + 0xc))();
  pCVar7 = (LPCSTR)(iVar5 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,8);
  cVar2 = FUN_10008d30(&stack0xffffffac,0x101ad1a0);
  if (cVar2 == '\0') {
    FUN_10009140(&stack0xffffffac,(uint *)"BOOTDEVICE_INFO",0xf);
  }
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 3;
  piVar8 = FUN_10002af0(&local_20,pCVar7,pCVar6,iVar4);
  local_8._0_1_ = 9;
  FUN_10008860(&DAT_101d283c,piVar8);
  local_8._0_1_ = 3;
  LOCK();
  puVar11 = local_20 + -1;
  uVar12 = *puVar11;
  *puVar11 = *puVar11 - 1;
  UNLOCK();
  if (uVar12 == 1 || (int)(uVar12 - 1) < 0) {
    (**(code **)(*(int *)local_20[-4] + 4))();
  }
  uVar12 = *(uint *)(DAT_101d283c + -0xc);
  if (-1 < (int)uVar12) {
    if ((int)(*(int *)(DAT_101d283c + -8) - uVar12 | 1U - *(int *)(DAT_101d283c + -4)) < 0) {
      FUN_100090d0(&DAT_101d283c,uVar12);
    }
    eVar9 = FID_conflict___mbslwr_s(DAT_101d283c,uVar12 + 1);
    FUN_10001f40(eVar9);
    if ((int)uVar12 <= *(int *)(DAT_101d283c + -8)) {
      *(uint *)(DAT_101d283c + -0xc) = uVar12;
      DAT_101d283c[uVar12] = '\0';
      FUN_10008630(&DAT_101d283c," ",(uint *)&DAT_101ad0ea);
      if (0 < *(int *)(DAT_101d283c + -0xc)) {
        puVar10 = __mbschr(DAT_101d283c,0x3b);
        if ((puVar10 != (uchar *)0x0) && (-1 < (int)puVar10 - (int)DAT_101d283c)) {
          if (*(int *)(DAT_101d283c + -0xc) < 1) {
            uVar12 = 0xffffffff;
          }
          else {
            puVar10 = __mbschr(DAT_101d283c,0x3b);
            uVar12 = (int)puVar10 - (int)DAT_101d283c;
            if (puVar10 == (uchar *)0x0) {
              uVar12 = 0xffffffff;
            }
          }
          piVar8 = FUN_100080b0(&DAT_101d283c,(int *)&local_20,uVar12);
          local_8._0_1_ = 10;
          FUN_10008860(&DAT_101d283c,piVar8);
          local_8._0_1_ = 3;
          LOCK();
          puVar11 = local_20 + -1;
          uVar12 = *puVar11;
          *puVar11 = *puVar11 - 1;
          UNLOCK();
          if (uVar12 == 1 || (int)(uVar12 - 1) < 0) {
            (**(code **)(*(int *)local_20[-4] + 4))();
          }
        }
      }
      local_28 = (uint *)&stack0xffffffb4;
      local_21 = 0;
      ppuVar3 = FUN_1000f8a0();
      if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_10002000(-0x7fffbffb);
      }
      iVar4 = (**(code **)(*ppuVar3 + 0xc))();
      iVar4 = iVar4 + 0x10;
      local_8 = CONCAT31(local_8._1_3_,0xb);
      cVar2 = FUN_10008d30(&stack0xffffffb4,0x101ad14c);
      if (cVar2 == '\0') {
        FUN_10009140(&stack0xffffffb4,(uint *)"update_config.ini",0x11);
      }
      local_28 = (uint *)&stack0xffffffb0;
      local_2c = &stack0xffffffb0;
      local_8._0_1_ = 0xc;
      ppuVar3 = FUN_1000f8a0();
      if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_10002000(-0x7fffbffb);
      }
      iVar5 = (**(code **)(*ppuVar3 + 0xc))();
      pCVar6 = (LPCSTR)(iVar5 + 0x10);
      local_8 = CONCAT31(local_8._1_3_,0xd);
      cVar2 = FUN_10008d30(&stack0xffffffb0,0x101ad1b4);
      if (cVar2 == '\0') {
        FUN_10009140(&stack0xffffffb0,(uint *)"checksn",7);
      }
      local_2c = &stack0xffffffac;
      local_8._0_1_ = 0xe;
      ppuVar3 = FUN_1000f8a0();
      if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_10002000(-0x7fffbffb);
      }
      iVar5 = (**(code **)(*ppuVar3 + 0xc))();
      pCVar7 = (LPCSTR)(iVar5 + 0x10);
      local_8 = CONCAT31(local_8._1_3_,0xf);
      cVar2 = FUN_10008d30(&stack0xffffffac,0x101ad1a0);
      if (cVar2 == '\0') {
        FUN_10009140(&stack0xffffffac,(uint *)"BOOTDEVICE_INFO",0xf);
      }
      local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
      local_8._0_1_ = 3;
      piVar8 = FUN_10002af0(&local_20,pCVar7,pCVar6,iVar4);
      local_8._0_1_ = 0x10;
      FUN_10008860(&local_18,piVar8);
      local_8._0_1_ = 3;
      LOCK();
      puVar11 = local_20 + -1;
      uVar12 = *puVar11;
      *puVar11 = *puVar11 - 1;
      UNLOCK();
      if (uVar12 == 1 || (int)(uVar12 - 1) < 0) {
        (**(code **)(*(int *)local_20[-4] + 4))();
      }
      uVar12 = *(uint *)(local_18 + -0xc);
      if (-1 < (int)uVar12) {
        if ((int)(*(int *)(local_18 + -8) - uVar12 | 1U - *(int *)(local_18 + -4)) < 0) {
          FUN_100090d0(&local_18,uVar12);
        }
        puVar10 = local_18;
        eVar9 = FID_conflict___mbslwr_s(local_18,uVar12 + 1);
        FUN_10001f40(eVar9);
        if ((int)uVar12 <= *(int *)(puVar10 + -8)) {
          *(uint *)(puVar10 + -0xc) = uVar12;
          puVar10[uVar12] = '\0';
          iVar4 = __mbscmp(puVar10,"TRUE");
          if (iVar4 == 0) {
            local_28 = (uint *)&stack0xffffffb4;
            local_21 = 1;
            ppuVar3 = FUN_1000f8a0();
            if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
              FUN_10002000(-0x7fffbffb);
            }
            iVar4 = (**(code **)(*ppuVar3 + 0xc))();
            iVar4 = iVar4 + 0x10;
            local_8 = CONCAT31(local_8._1_3_,0x11);
            cVar2 = FUN_10008d30(&stack0xffffffb4,0x101ad14c);
            if (cVar2 == '\0') {
              FUN_10009140(&stack0xffffffb4,(uint *)"update_config.ini",0x11);
            }
            local_28 = (uint *)&stack0xffffffb0;
            local_2c = &stack0xffffffb0;
            local_8._0_1_ = 0x12;
            ppuVar3 = FUN_1000f8a0();
            if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
              FUN_10002000(-0x7fffbffb);
            }
            iVar5 = (**(code **)(*ppuVar3 + 0xc))();
            pCVar6 = (LPCSTR)(iVar5 + 0x10);
            local_8 = CONCAT31(local_8._1_3_,0x13);
            cVar2 = FUN_10008d30(&stack0xffffffb0,0x101ad1c4);
            if (cVar2 == '\0') {
              FUN_10009140(&stack0xffffffb0,(uint *)&DAT_101ad1c4,2);
            }
            local_2c = &stack0xffffffac;
            local_8._0_1_ = 0x14;
            ppuVar3 = FUN_1000f8a0();
            if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
              FUN_10002000(-0x7fffbffb);
            }
            iVar5 = (**(code **)(*ppuVar3 + 0xc))();
            pCVar7 = (LPCSTR)(iVar5 + 0x10);
            local_8 = CONCAT31(local_8._1_3_,0x15);
            cVar2 = FUN_10008d30(&stack0xffffffac,0x101ad1a0);
            if (cVar2 == '\0') {
              FUN_10009140(&stack0xffffffac,(uint *)"BOOTDEVICE_INFO",0xf);
            }
            local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
            local_8._0_1_ = 3;
            piVar8 = FUN_10002af0(&local_20,pCVar7,pCVar6,iVar4);
            local_8._0_1_ = 0x16;
            FUN_10008860(&DAT_101d2840,piVar8);
            local_8._0_1_ = 3;
            LOCK();
            puVar11 = local_20 + -1;
            uVar12 = *puVar11;
            *puVar11 = *puVar11 - 1;
            UNLOCK();
            if (uVar12 == 1 || (int)(uVar12 - 1) < 0) {
              (**(code **)(*(int *)local_20[-4] + 4))();
            }
          }
          local_28 = (uint *)&stack0xffffffb4;
          ppuVar3 = FUN_1000f8a0();
          if (ppuVar3 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
            FUN_10002000(-0x7fffbffb);
          }
          iVar4 = (**(code **)(*ppuVar3 + 0xc))();
          iVar4 = iVar4 + 0x10;
          local_8 = CONCAT31(local_8._1_3_,0x17);
          cVar2 = FUN_10008d30(&stack0xffffffb4,0x101ad14c);
          if (cVar2 == '\0') {
            FUN_10009140(&stack0xffffffb4,(uint *)"update_config.ini",0x11);
          }
          local_28 = (uint *)&stack0xffffffb0;
          local_20 = (uint *)&stack0xffffffb0;
          local_8._0_1_ = 0x18;
          ppuVar3 = FUN_1000f8a0();
          if (ppuVar3 != (undefined **)0x0) {
            iVar5 = (**(code **)(*ppuVar3 + 0xc))();
            pCVar6 = (LPCSTR)(iVar5 + 0x10);
            local_8 = CONCAT31(local_8._1_3_,0x19);
            cVar2 = FUN_10008d30(&stack0xffffffb0,0x101ad228);
            if (cVar2 == '\0') {
              FUN_10009140(&stack0xffffffb0,(uint *)"time_out",8);
            }
            local_20 = (uint *)&stack0xffffffac;
            local_8._0_1_ = 0x1a;
            ppuVar3 = FUN_1000f8a0();
            if (ppuVar3 != (undefined **)0x0) {
              iVar5 = (**(code **)(*ppuVar3 + 0xc))();
              pCVar7 = (LPCSTR)(iVar5 + 0x10);
              local_8 = CONCAT31(local_8._1_3_,0x1b);
              cVar2 = FUN_10008d30(&stack0xffffffac,0x101ad234);
              if (cVar2 == '\0') {
                FUN_10009140(&stack0xffffffac,(uint *)"WAIT_TIME_OUT",0xd);
              }
              local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
              local_8._0_1_ = 3;
              piVar8 = FUN_10002af0(&local_2c,pCVar7,pCVar6,iVar4);
              local_8._0_1_ = 0x1c;
              FUN_10008860(&local_1c,piVar8);
              local_8 = CONCAT31(local_8._1_3_,3);
              puVar15 = (undefined4 *)(local_2c + -0x10);
              LOCK();
              piVar8 = (int *)(local_2c + -4);
              iVar4 = *piVar8;
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if (iVar4 == 1 || iVar4 + -1 < 0) {
                (**(code **)(*(int *)*puVar15 + 4))();
              }
              pcVar1 = local_1c;
              FUN_10001f20(local_1c,"%d");
              if ((100 < DAT_101ca858) || (DAT_101ca858 < 3)) {
                DAT_101ca858 = 0x1e;
              }
              DAT_101ca854 = 0;
              puVar13 = extraout_ECX;
              _DAT_101d2814 = DAT_101ca858;
              if (DAT_101d2818 != (code *)0x0) {
                (*DAT_101d2818)();
                puVar13 = extraout_ECX_00;
              }
              puVar11 = DAT_101d2840;
              local_28 = (uint *)&stack0xffffffb4;
              puVar14 = DAT_101d2840 + -4;
              puVar15 = (undefined4 *)(**(code **)(*(int *)*puVar14 + 0x10))();
              local_20 = puVar11 + -1;
              if (((int)puVar11[-1] < 0) || (puVar15 != (undefined4 *)*puVar14)) {
                local_20 = (uint *)(**(code **)*puVar15)();
                if (local_20 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
                  FUN_10009130();
                }
                local_20[1] = puVar11[-3];
                FUN_10001e00(local_20 + 4,puVar11[-3] + 1,puVar11,puVar11[-3] + 1);
              }
              else {
                LOCK();
                *local_20 = *local_20 + 1;
                UNLOCK();
                local_20 = puVar14;
              }
              *local_28 = (uint)(local_20 + 4);
              local_8 = CONCAT31(local_8._1_3_,0x1d);
              local_20 = (uint *)(DAT_101d283c + -0x10);
              puVar15 = (undefined4 *)(**(code **)(*(int *)*local_20 + 0x10))();
              local_28 = local_20 + 3;
              if (((int)local_20[3] < 0) || (puVar15 != (undefined4 *)*local_20)) {
                puVar11 = (uint *)(**(code **)*puVar15)(local_20[1]);
                if (puVar11 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
                  FUN_10009130();
                }
                puVar11[1] = local_20[1];
                FUN_10001e00(puVar11 + 4,local_20[1] + 1,local_20 + 4,local_20[1] + 1);
              }
              else {
                LOCK();
                *local_28 = *local_28 + 1;
                UNLOCK();
                puVar11 = local_20;
              }
              local_8._0_1_ = 3;
              cVar2 = FUN_10003350(puVar11 + 4,puVar13);
              if (cVar2 == '\0') {
                local_20 = (uint *)0x2;
                DAT_101d2830 = 0;
              }
              else {
                local_20 = (uint *)0x0;
                DAT_101d2830 = 2;
              }
              local_8 = CONCAT31(local_8._1_3_,1);
              LOCK();
              piVar8 = (int *)(puVar10 + -4);
              iVar4 = *piVar8;
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if (iVar4 == 1 || iVar4 + -1 < 0) {
                (**(code **)(**(int **)(puVar10 + -0x10) + 4))();
              }
              local_8 = 0xffffffff;
              LOCK();
              piVar8 = (int *)(pcVar1 + -4);
              iVar4 = *piVar8;
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if (iVar4 == 1 || iVar4 + -1 < 0) {
                (**(code **)(**(int **)(pcVar1 + -0x10) + 4))();
              }
              ExceptionList = local_10;
              return local_20;
            }
                    /* WARNING: Subroutine does not return */
            FUN_10002000(-0x7fffbffb);
          }
                    /* WARNING: Subroutine does not return */
          FUN_10002000(-0x7fffbffb);
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_10002000(-0x7ff8ffa9);
}
