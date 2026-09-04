/* 10009ed0 FUN_10009ed0 [[10009ed0, 1000a0f8]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined1 * __fastcall
FUN_10009ed0(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,uint param_5)

{
  uint *puVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint *extraout_EDX;
  uint *extraout_EDX_00;
  uint *puVar6;
  void *pvVar7;
  int iVar8;
  undefined1 auStackY_100 [68];
  undefined4 uStackY_bc;
  int local_94 [5];
  uint *local_80;
  uint *local_7c;
  int local_78;
  undefined1 local_74 [4];
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  void *local_54;
  undefined4 local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  uint local_34;
  undefined2 local_30;
  uint local_2c;
  undefined1 local_28;
  int *local_24;
  undefined1 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_1016a2eb;
  local_10 = ExceptionList;
  local_14 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar8 = *param_4;
  if (iVar8 == 0) {
    puVar4 = auStackY_100;
  }
  else {
    uStackY_bc = 0x10009f29;
    _memset(local_94,0,0x80);
    local_38 = *(undefined4 *)(iVar8 + 0x14);
    local_2c = *(uint *)(iVar8 + 0x1c);
    local_94[1] = 0;
    local_94[2] = 0;
    local_94[3] = 0;
    local_94[4] = 0;
    local_80 = (uint *)0x0;
    local_7c = (uint *)0x0;
    local_78 = 0;
    local_70 = 0;
    uStack_6c = 0;
    uStack_68 = 0;
    uStack_64 = 0;
    local_60 = 0;
    local_5c = 0;
    local_58 = 0;
    local_54 = (void *)0x0;
    local_50 = 0;
    local_4c = 0;
    local_8 = 2;
    local_34 = param_5;
    local_30 = (ushort)local_30._1_1_ << 8;
    if (((*(byte *)(iVar8 + 8) & 8) == 0) || (local_28 = 1, (param_5 & 0x10) != 0)) {
      local_28 = 0;
    }
    local_24 = param_4 + 1;
    local_44 = param_2;
    local_40 = param_1;
    local_3c = iVar8;
    if (*(uint *)(iVar8 + 0x18) != 0) {
      FUN_1000bd80(&local_54,*(uint *)(iVar8 + 0x18));
    }
    local_8 = 3;
    local_94[0] = local_40;
    local_48 = local_40;
    FUN_1000ab60(local_94 + 1,local_2c);
    puVar1 = local_7c;
    uVar5 = (int)local_7c - (int)local_80 >> 3;
    puVar6 = local_80;
    if (local_2c < uVar5) {
      local_7c = local_80 + local_2c * 2;
    }
    else if (uVar5 < local_2c) {
      if ((uint)(local_78 - (int)local_80 >> 3) < local_2c) {
        FUN_1000bd80(&local_80,local_2c);
        puVar6 = extraout_EDX;
      }
      else {
        iVar8 = local_2c - uVar5;
        if (iVar8 != 0) {
          uStackY_bc = 0x1000a047;
          _memset(local_7c,0,iVar8 * 8);
          local_7c = puVar1 + iVar8 * 2;
          puVar6 = extraout_EDX_00;
        }
      }
    }
    local_30 = 0;
    local_20 = 1;
    local_1c = 10000000;
    local_18 = 1000;
    bVar2 = FUN_1000b760(local_94,puVar6,local_3c);
    if (local_54 != (void *)0x0) {
      pvVar7 = local_54;
      if ((0xfff < (local_4c - (int)local_54 & 0xfffffff8U)) &&
         (pvVar7 = *(void **)((int)local_54 + -4), 0x1f < (uint)((int)local_54 + (-4 - (int)pvVar7))
         )) {
                    /* WARNING: Subroutine does not return */
        FUN_1014b2df();
      }
      FUN_101436ce(pvVar7);
      local_54 = (void *)0x0;
      local_50 = 0;
      local_4c = 0;
    }
    FUN_1000a2d0((int)local_74);
    uVar3 = FUN_1000a2d0((int)local_94);
    puVar4 = (undefined1 *)CONCAT31((int3)((uint)uVar3 >> 8),bVar2);
  }
  ExceptionList = local_10;
  return puVar4;
}
