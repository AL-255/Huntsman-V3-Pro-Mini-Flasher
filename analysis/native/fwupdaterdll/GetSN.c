/* 10002e90 GetSN [[10002e90, 10002f7d]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetSN(int param_1,undefined4 *param_2,char param_3)

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
  undefined4 local_53;
  undefined2 local_4f;
  undefined1 local_4d;
  uint local_8;

                    /* 0x2e90  26  GetSN */
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
  local_62 = 0;
  local_63 = 0;
  local_5e = 0xf;
  local_5d = 0;
  local_5c = 0x82;
  if ((param_3 == '\t') || (param_3 == '\v')) {
    local_68 = FUN_100027e0(param_1,(undefined4 *)&local_64,5,0x14);
  }
  else {
    local_68 = FUN_10002590(param_1,(undefined4 *)&local_64,5,0x14);
  }
  if (local_68 == 2) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    *(undefined2 *)(param_2 + 3) = 0;
    *(undefined1 *)((int)param_2 + 0xe) = 0;
    *param_2 = local_5b;
    param_2[1] = local_57;
    param_2[2] = local_53;
    *(undefined2 *)(param_2 + 3) = local_4f;
    *(undefined1 *)((int)param_2 + 0xe) = local_4d;
  }
  return local_68;
}
