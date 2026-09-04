/* 100042e0 DeviceReset [[100042e0, 100043ae]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl DeviceReset(int param_1,char param_2,undefined1 param_3)

{
  int local_68;
  undefined4 local_64;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  undefined1 uStack_5b;
  uint local_8;

                    /* 0x42e0  11  DeviceReset */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  _memset(&local_64,0,0x5b);
  if ((param_2 == '\t') || (param_2 == '\n')) {
    local_64._0_1_ = 7;
  }
  else if (param_2 == '\v') {
    local_64._0_1_ = 8;
  }
  else {
    local_64._0_1_ = 0;
  }
  local_64._1_1_ = 0;
  local_5e = 1;
  local_5d = 0;
  local_5c = 0xb;
  uStack_5b = param_3;
  if ((param_2 == '\t') || (param_2 == '\v')) {
    local_68 = FUN_100027e0(param_1,&local_64,5,200);
  }
  else {
    local_68 = FUN_10002590(param_1,&local_64,5,200);
  }
  return local_68 == 2;
}
