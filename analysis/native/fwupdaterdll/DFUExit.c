/* 10004280 DFUExit [[10004280, 100042db]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl DFUExit(int param_1)

{
  undefined4 uVar1;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  uint local_8;

                    /* 0x4280  7  DFUExit */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  _memset(&local_64,0,0x5b);
  local_64 = 0;
  local_63 = 0;
  local_5e = 0;
  local_5d = 0x10;
  local_5c = 5;
  uVar1 = FUN_10002590(param_1,(undefined4 *)&local_64,1,2);
  return uVar1;
}
