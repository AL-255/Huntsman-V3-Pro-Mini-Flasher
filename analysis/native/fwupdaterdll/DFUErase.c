/* 10003e90 DFUErase [[10003e90, 10003fec]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl DFUErase(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  undefined1 uStack_5b;
  undefined1 local_5a;
  undefined1 uStack_59;
  undefined1 uStack_58;
  undefined1 uStack_57;
  undefined1 uStack_56;
  undefined1 uStack_55;
  undefined1 uStack_54;
  uint local_8;

                    /* 0x3e90  6  DFUErase */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  _memset(&local_64,0,0x5b);
  local_64 = 0;
  local_63 = 0;
  local_5e = 8;
  local_5d = 0x10;
  local_5c = 1;
  uStack_5b = (undefined1)((uint)param_2 >> 0x18);
  local_5a = (undefined1)((uint)param_2 >> 0x10);
  uStack_59 = (undefined1)((uint)param_2 >> 8);
  uStack_58 = (undefined1)param_2;
  uStack_57 = (undefined1)((uint)param_3 >> 0x18);
  uStack_56 = (undefined1)((uint)param_3 >> 0x10);
  uStack_55 = (undefined1)((uint)param_3 >> 8);
  uStack_54 = (undefined1)param_3;
  uVar1 = FUN_10002590(param_1,(undefined4 *)&local_64,5,2);
  return uVar1;
}
