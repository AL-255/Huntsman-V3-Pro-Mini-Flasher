/* 10003ff0 DFUProgram [[10003ff0, 100040f3]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl DFUProgram(int param_1,byte param_2,undefined4 param_3,int param_4,uint *param_5)

{
  undefined4 uVar1;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  byte bStack_5b;
  undefined1 local_5a;
  undefined1 uStack_59;
  undefined1 uStack_58;
  undefined1 uStack_57;
  uint local_56 [19];
  uint local_8;

                    /* 0x3ff0  8  DFUProgram */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  _memset(&local_64,0,0x5b);
  local_64 = 0;
  local_63 = 0;
  local_5e = 8;
  local_5d = 0x10;
  local_5c = 2;
  bStack_5b = param_2;
  local_5a = (undefined1)((uint)param_3 >> 0x18);
  uStack_59 = (undefined1)((uint)param_3 >> 0x10);
  uStack_58 = (undefined1)((uint)param_3 >> 8);
  uStack_57 = (undefined1)param_3;
  FUN_1013d230(local_56,param_5,(uint)param_2);
  uVar1 = FUN_10002590(param_1,(undefined4 *)&local_64,5,param_4);
  return uVar1;
}
