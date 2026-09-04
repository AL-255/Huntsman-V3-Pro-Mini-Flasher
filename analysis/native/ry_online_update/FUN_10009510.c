/* 10009510 FUN_10009510 [[10009510, 1000977f]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_10009510(void *this,undefined4 param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined *local_80;
  undefined *local_7c;
  undefined *local_78;
  int local_74;
  undefined4 local_70;
  void *local_6c;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 *local_5c;
  undefined4 *local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_30;
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;

  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_1016a1a5;
  local_1c = ExceptionList;
  local_24 = DAT_101c9dd4 ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  _memset(&local_80,0,0x54);
  local_78 = param_2;
  local_80 = &DAT_101ad17c;
  local_7c = &DAT_101ad17c;
  local_74 = 0;
  local_70 = 0;
  local_6c = (void *)0x0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_14 = 0;
  FUN_1000a460(&local_6c,0);
  local_14 = 1;
  local_5c = (undefined4 *)FUN_1000f4d7(0x24);
  if (local_5c == (undefined4 *)0x0) {
    local_5c = (undefined4 *)0x0;
  }
  else {
    *local_5c = 0;
    local_5c[1] = 0;
    local_5c[2] = 0;
    local_5c[3] = 0;
    local_5c[4] = 0;
    local_5c[5] = 0;
    local_5c[6] = 0;
    local_5c[7] = 0;
    local_5c[8] = 0;
    local_5c[1] = 0x14;
    local_5c[2] = 0;
    local_5c[3] = 0;
    local_5c[4] = 0;
    *local_5c = std::_Root_node::vftable;
    local_5c[6] = 0;
    local_5c[7] = 0;
    local_5c[8] = 0;
  }
  local_54 = 1;
  local_4c = 0x100;
  local_48 = 4;
  local_40 = 1;
  local_30 = 0x8775dfb;
  local_58 = local_5c;
  local_50 = (int)this + 4;
  local_44 = (int)this + 4;
  FUN_1000a500((int *)&local_80);
  local_14 = 3;
  puVar2 = FUN_1000aae0(&local_5c,0);
  FUN_1000a730((int *)&local_80);
  if (local_80 == local_78) {
    FUN_1000aa40(&local_5c,(int)puVar2);
    puVar3 = (undefined4 *)FUN_1000f4d7(0x14);
    puVar2 = local_5c;
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      *puVar3 = std::_Node_base::vftable;
      puVar3[1] = 0x15;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
    }
    puVar3[4] = local_58;
    if (local_58[3] != 0) {
      puVar3[3] = local_58[3];
      *(undefined4 **)(local_58[3] + 0x10) = puVar3;
    }
    local_58[3] = puVar3;
    local_5c[5] = local_40;
    local_5c[7] = local_74 + 1;
    local_58 = puVar3;
    FUN_10002a10((int)local_5c,0,0);
    LOCK();
    piVar1 = puVar2 + 8;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    FUN_10008ba0(this);
    *(undefined4 **)this = puVar2;
    if (local_6c != (void *)0x0) {
      pvVar4 = local_6c;
      if (0xfff < (local_64 - (int)local_6c & 0xfffffffcU)) {
        pvVar4 = *(void **)((int)local_6c + -4);
        if (0x1f < (uint)((int)local_6c + (-4 - (int)pvVar4))) {
                    /* WARNING: Subroutine does not return */
          FUN_1014b2df();
        }
      }
      FUN_101436ce(pvVar4);
    }
    ExceptionList = local_1c;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000a4f0(0xe);
}
