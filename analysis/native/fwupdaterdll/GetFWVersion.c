/* 10002d60 GetFWVersion [[10002d60, 10002e88]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetFWVersion(int param_1,undefined4 *param_2,char param_3)

{
  int local_68;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_62;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  undefined4 local_5b;
  undefined4 local_57;
  undefined1 local_53;
  uint local_8;

                    /* 0x2d60  22  GetFWVersion */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  _memset(&local_64,0,0x5b);
  if ((param_3 == '\x04') || (param_3 == '\f')) {
    local_64 = 0;
    local_5c = 0x93;
  }
  else if ((param_3 == '\t') || (param_3 == '\n')) {
    local_64 = 7;
    local_62 = 0;
    local_5c = 0x87;
  }
  else if (param_3 == '\v') {
    local_64 = 8;
    local_62 = 0;
    local_5c = 0x87;
  }
  else {
    local_64 = 0;
    local_62 = 0;
    local_5c = 0x87;
  }
  local_5d = 0;
  local_5e = 8;
  local_63 = 0;
  if ((param_3 == '\t') || (param_3 == '\v')) {
    local_68 = FUN_100027e0(param_1,(undefined4 *)&local_64,5,0x14);
  }
  else {
    local_68 = FUN_10002590(param_1,(undefined4 *)&local_64,5,0x14);
  }
  if (local_68 == 2) {
    *param_2 = 0;
    param_2[1] = 0;
    *(undefined1 *)(param_2 + 2) = 0;
    *param_2 = local_5b;
    param_2[1] = local_57;
    *(undefined1 *)(param_2 + 2) = local_53;
  }
  return local_68;
}
