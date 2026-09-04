/* 1000b760 FUN_1000b760 [[1000b760, 1000bd24]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __fastcall FUN_1000b760(int *param_1,uint *param_2,int param_3)

{
  uint **this;
  uint **ppuVar1;
  uint *puVar2;
  int iVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  uint **ppuVar7;
  char *pcVar8;
  uint uVar9;
  byte bVar10;
  int iVar11;
  uint *extraout_EDX;
  uint *extraout_EDX_00;
  uint *extraout_EDX_01;
  uint *puVar12;
  uint *extraout_EDX_02;
  uint *extraout_EDX_03;
  undefined4 uVar13;
  undefined4 extraout_EDX_04;
  uint *extraout_EDX_05;
  undefined4 extraout_EDX_06;
  uint *extraout_EDX_07;
  uint *extraout_EDX_08;
  uint uVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  uint *local_74;
  int local_70;
  uint *local_6c;
  int local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int local_28;
  uint *puStack_24;
  uint *puStack_20;
  int iStack_1c;
  uint **local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_1016a36d;
  local_10 = ExceptionList;
  local_14 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar11 = param_1[0x1f];
  if (0 < iVar11) {
    iVar11 = iVar11 + -1;
    param_1[0x1f] = iVar11;
    if (iVar11 < 1) {
LAB_1000bd12:
      FUN_1014496f(0xc);
      goto LAB_1000bd19;
    }
  }
  if ((0 < param_1[0x1e]) && (iVar6 = param_1[0x1e] + -1, param_1[0x1e] = iVar6, iVar6 < 1)) {
LAB_1000bd19:
    FUN_1014496f(0xb);
LAB_1000bd20:
                    /* WARNING: Subroutine does not return */
    FUN_1014b2df();
  }
  local_6c = (uint *)((uint)local_6c & 0xffffff00);
  if (param_3 != 0) {
LAB_1000b7d0:
    iVar11 = *(int *)(param_3 + 4);
    bVar10 = (byte)local_6c;
    switch(iVar11) {
    default:
      FUN_1014496f(0xd);
      goto LAB_1000bd12;
    case 1:
    case 8:
    case 9:
    case 0x11:
    case 0x14:
      goto switchD_1000b7dc_caseD_1;
    case 2:
      if (((param_1[0x18] & 0x100U) == 0) && (*param_1 == param_1[0x13])) {
        local_6c = (uint *)(param_1[0x18] & 0xffffff01);
      }
      else {
        local_6c = (uint *)CONCAT31((int3)((uint)*param_1 >> 8),*(char *)(*param_1 + -1) != '\n');
      }
      break;
    case 3:
      pcVar8 = (char *)*param_1;
      if (pcVar8 == (char *)param_1[0x14]) {
        local_6c = (uint *)(CONCAT31((uint3)((uint)param_1[0x18] >> 9),
                                     (char)((uint)param_1[0x18] >> 1)) & 0xffffff01);
      }
      else {
        local_6c = (uint *)CONCAT31((int3)((uint)pcVar8 >> 8),*pcVar8 != '\n');
      }
      break;
    case 4:
      uVar9 = FUN_1000cb10(param_1);
      local_6c = (uint *)CONCAT31((int3)(uVar9 >> 8),
                                  (byte)uVar9 == ((byte)*(undefined4 *)(param_3 + 8) & 1));
      param_2 = extraout_EDX;
      break;
    case 5:
      pcVar8 = (char *)*param_1;
      if (((pcVar8 != (char *)param_1[0x14]) && (*pcVar8 != '\n')) && (*pcVar8 != '\r')) {
        pcVar8 = pcVar8 + 1;
        goto LAB_1000b85b;
      }
LAB_1000b899:
      local_6c = (uint *)0x1;
LAB_1000b89d:
      iVar11 = param_1[0x1f];
      goto LAB_1000b8a0;
    case 6:
      pcVar8 = FUN_1000cb80((char *)*param_1,(char *)param_1[0x14],*(char **)(param_3 + 0x1c),
                            *(char **)(param_3 + 0x1c) + *(int *)(param_3 + 0x18),param_1[0x1c],
                            param_1[0x17]);
      param_2 = extraout_EDX_00;
      if (pcVar8 == (char *)*param_1) goto LAB_1000b899;
LAB_1000b85b:
      *param_1 = (int)pcVar8;
      goto switchD_1000b7dc_caseD_1;
    case 7:
      if ((*param_1 == param_1[0x14]) ||
         (iVar11 = FUN_1000c900(param_1,param_3), (char)iVar11 == '\0')) goto LAB_1000b899;
      local_6c = (uint *)((uint)local_6c & 0xffffff00);
      param_2 = extraout_EDX_01;
      goto LAB_1000b864;
    case 10:
    case 0xb:
      iVar6 = *param_1;
      puVar12 = (uint *)param_1[1];
      local_18 = (uint **)0x0;
      local_74 = (uint *)0x0;
      puStack_24 = (uint *)0x0;
      puStack_20 = (uint *)0x0;
      iStack_1c = 0;
      local_28 = iVar6;
      if (puVar12 != (uint *)param_1[2]) {
        uVar9 = param_1[2] - (int)puVar12;
        uVar14 = (int)uVar9 >> 2;
        FUN_1000afb0(&puStack_24,uVar14);
        puVar2 = puStack_24;
        local_74 = puStack_24;
        uVar15 = FUN_10145db0(puStack_24,puVar12,uVar9);
        puVar12 = (uint *)(uVar15 >> 0x20);
        puStack_20 = puVar2 + uVar14;
      }
      iVar3 = iStack_1c;
      puVar2 = puStack_20;
      ppuVar1 = (uint **)param_1[4];
      local_8 = 0;
      local_18 = ppuVar1;
      bVar4 = FUN_1000b760(param_1,puVar12,*(int *)(param_3 + 0x14));
      if (bVar4 == (iVar11 == 0xb)) {
        this = (uint **)(param_1 + 1);
        *param_1 = local_28;
        ppuVar7 = &puStack_24;
        if (this != &puStack_24) {
          uVar9 = (int)puVar2 - (int)local_74;
          puVar12 = *this;
          if ((uint)(param_1[3] - (int)puVar12 >> 2) < (uint)((int)uVar9 >> 2)) {
            FUN_1000e290(this,(int)uVar9 >> 2);
            puVar12 = (uint *)param_1[1];
          }
          FUN_10145db0(puVar12,local_74,uVar9);
          param_1[2] = uVar9 + (int)puVar12;
          param_1[4] = (int)ppuVar1;
          ppuVar7 = ppuVar1;
        }
        local_6c = (uint *)CONCAT31((int3)((uint)ppuVar7 >> 8),1);
      }
      else {
        *param_1 = iVar6;
      }
      local_8 = 0xffffffff;
      param_2 = (uint *)0x0;
      if (local_74 != (uint *)0x0) {
        puVar12 = local_74;
        if (((iVar3 - (int)local_74 & 0xfffffffcU) < 0x1000) ||
           (puVar12 = (uint *)local_74[-1], (uint)((int)local_74 + (-4 - (int)puVar12)) < 0x20)) {
          FUN_101436ce(puVar12);
          puStack_24 = (uint *)0x0;
          puStack_20 = (uint *)0x0;
          iStack_1c = 0;
          param_2 = extraout_EDX_02;
          goto switchD_1000b7dc_caseD_1;
        }
        goto LAB_1000bd20;
      }
      break;
    case 0xc:
      param_3 = 0;
      goto switchD_1000b7dc_caseD_1;
    case 0xd:
      param_2 = *(uint **)(param_3 + 0x14);
      *(int *)(param_1[5] + (int)param_2 * 8) = *param_1;
      uVar9 = param_1[4];
      if (*(uint *)(param_3 + 0x14) < uVar9) {
        do {
          uVar9 = uVar9 - 1;
          param_2 = (uint *)(param_1[1] + (uVar9 >> 5) * 4);
          *param_2 = *param_2 & ~(1 << (uVar9 & 0x1f));
        } while (*(uint *)(param_3 + 0x14) < uVar9);
      }
      goto switchD_1000b7dc_caseD_1;
    case 0xe:
      iVar11 = *(int *)(param_3 + 0x14);
      if ((*(char *)((int)param_1 + 0x65) != '\0') || (*(int *)(iVar11 + 0x14) != 0)) {
        puVar12 = (uint *)(param_1[1] + (*(uint *)(iVar11 + 0x14) >> 5) * 4);
        *puVar12 = *puVar12 | 1 << (*(uint *)(iVar11 + 0x14) & 0x1f);
        param_2 = *(uint **)(iVar11 + 0x14);
        *(int *)(param_1[5] + 4 + (int)param_2 * 8) = *param_1;
      }
      goto switchD_1000b7dc_caseD_1;
    case 0xf:
      param_2 = (uint *)(param_1[1] + (*(uint *)(param_3 + 0x14) >> 5) * 4);
      if ((*param_2 & 1 << ((byte)*(undefined4 *)(param_3 + 0x14) & 0x1f)) != 0) {
        pcVar8 = (char *)*param_1;
        puVar12 = *(uint **)(param_1[5] + *(int *)(param_3 + 0x14) * 8);
        param_2 = *(uint **)(param_1[5] + 4 + *(int *)(param_3 + 0x14) * 8);
        if ((puVar12 != param_2) &&
           (pcVar8 = FUN_1000cb80(pcVar8,(char *)param_1[0x14],(char *)puVar12,(char *)param_2,
                                  param_1[0x1c],param_1[0x17]), param_2 = extraout_EDX_03,
           pcVar8 == (char *)*param_1)) goto LAB_1000b899;
        *param_1 = (int)pcVar8;
      }
switchD_1000b7dc_caseD_1:
      break;
    case 0x10:
      local_68 = 0;
      uStack_64 = 0;
      uStack_60 = 0;
      uStack_5c = 0;
      local_58 = 0;
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      uVar16 = FUN_1000cdf0(&local_68,param_1);
      uVar13 = (undefined4)((ulonglong)uVar16 >> 0x20);
      local_8 = 1;
      do {
        uVar16 = FUN_1000beb0(param_1,uVar13,&local_68);
        bVar4 = FUN_1000b760(param_1,(uint *)((ulonglong)uVar16 >> 0x20),*(int *)(param_3 + 0xc));
        if (bVar4) {
          if ((char)param_1[0x1b] != '\0') {
            local_48 = 0;
            uStack_44 = 0;
            uStack_40 = 0;
            uStack_3c = 0;
            local_38 = 0;
            uStack_34 = 0;
            uStack_30 = 0;
            uStack_2c = 0;
            uVar16 = FUN_1000cdf0(&local_48,param_1);
            uVar13 = (undefined4)((ulonglong)uVar16 >> 0x20);
            local_8 = CONCAT31(local_8._1_3_,2);
            local_70 = *param_1 - local_68;
            for (iVar11 = *(int *)(param_3 + 0x18); iVar11 != 0; iVar11 = *(int *)(iVar11 + 0x18)) {
              uVar16 = FUN_1000beb0(param_1,uVar13,&local_68);
              bVar4 = FUN_1000b760(param_1,(uint *)((ulonglong)uVar16 >> 0x20),
                                   *(int *)(iVar11 + 0xc));
              uVar13 = extraout_EDX_06;
              if ((bVar4) && (iVar6 = *param_1 - local_68, local_70 < iVar6)) {
                uVar16 = FUN_1000beb0(&local_48,extraout_EDX_06,param_1);
                uVar13 = (undefined4)((ulonglong)uVar16 >> 0x20);
                local_70 = iVar6;
              }
            }
            FUN_1000beb0(param_1,uVar13,&local_48);
            FUN_1000a2d0((int)&local_48);
          }
          local_8 = 0xffffffff;
          FUN_1000a2d0((int)&local_68);
          param_2 = extraout_EDX_07;
          goto LAB_1000bc3e;
        }
        param_3 = *(int *)(param_3 + 0x18);
        uVar13 = extraout_EDX_04;
      } while (param_3 != 0);
      local_8 = 0xffffffff;
      FUN_1000a2d0((int)&local_68);
      local_6c = (uint *)0x1;
      param_3 = 0;
      param_2 = extraout_EDX_05;
      break;
    case 0x12:
      cVar5 = FUN_1000c770(param_1,param_3,(byte)(*(uint *)(param_3 + 8) >> 1) & 1,0);
      if (cVar5 == '\0') {
        bVar10 = 1;
      }
      param_3 = 0;
      param_2 = local_6c;
      local_6c = (uint *)(uint)bVar10;
      break;
    case 0x13:
      param_2 = *(uint **)(param_3 + 0x14);
      if (param_2[9] == 0) {
        cVar5 = FUN_1000c770(param_1,(int)param_2,(byte)(param_2[2] >> 1) & 1,
                             *(int *)(param_1[0x10] + param_2[8] * 8));
        if (cVar5 == '\0') {
          bVar10 = 1;
        }
        param_3 = 0;
        param_2 = local_6c;
        local_6c = (uint *)(uint)bVar10;
      }
      else {
LAB_1000bc3e:
        param_3 = 0;
      }
      break;
    case 0x15:
      if ((((param_1[0x18] & 0x2020U) == 0) || (iVar11 = param_1[0x13], iVar11 != *param_1)) &&
         (((char)param_1[0x1d] == '\0' || (iVar11 = *param_1, iVar11 == param_1[0x14])))) {
        if (((char)param_1[0x19] == '\0') ||
           (uVar9 = FUN_1000ca50((int)param_1), param_2 = extraout_EDX_08, (char)uVar9 != '\0')) {
          uVar16 = FUN_1000beb0(param_1 + 8,param_2,param_1);
          param_2 = (uint *)((ulonglong)uVar16 >> 0x20);
          *(undefined1 *)(param_1 + 0x19) = 1;
        }
        param_3 = 0;
      }
      else {
        param_3 = 0;
        local_6c = (uint *)CONCAT31((int3)((uint)iVar11 >> 8),1);
      }
    }
    if ((char)local_6c != '\0') goto LAB_1000b89d;
LAB_1000b864:
    if ((param_3 == 0) || (param_3 = *(int *)(param_3 + 0xc), param_3 == 0)) goto LAB_1000b89d;
    goto LAB_1000b7d0;
  }
LAB_1000b8a0:
  if (0 < iVar11) {
    param_1[0x1f] = iVar11 + 1;
  }
  ExceptionList = local_10;
  return (char)local_6c == '\0';
}
