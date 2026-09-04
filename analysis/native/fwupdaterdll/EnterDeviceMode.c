/* 10002c90 EnterDeviceMode [[10002c90, 10002d59]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl EnterDeviceMode(int param_1,undefined1 param_2,char param_3)

{
  undefined4 local_68;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  undefined1 uStack_5b;
  undefined1 local_5a;
  uint local_8;

                    /* 0x2c90  13  EnterDeviceMode */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  _memset(&local_64,0,0x5b);
  if ((param_3 == '\t') || (param_3 == '\n')) {
    local_64 = 7;
  }
  else if (param_3 == '\v') {
    local_64 = 8;
  }
  else {
    local_64 = 0;
  }
  local_63 = 0;
  local_5e = 2;
  local_5d = 0;
  local_5c = 4;
  uStack_5b = param_2;
  local_5a = 0;
  if ((param_3 == '\t') || (param_3 == '\v')) {
    local_68 = FUN_100027e0(param_1,(undefined4 *)&local_64,5,2);
  }
  else {
    local_68 = FUN_10002590(param_1,(undefined4 *)&local_64,5,2);
  }
  return local_68;
}
