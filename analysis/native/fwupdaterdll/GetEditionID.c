/* 10005920 GetEditionID [[10005920, 100059a9]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl GetEditionID(int param_1,undefined1 *param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 local_64;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  undefined1 uStack_5b;
  undefined1 local_5a;
  uint local_8;

                    /* 0x5920  21  GetEditionID */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  _memset(&local_64,0,0x5b);
  local_64._0_1_ = 0;
  local_64._1_1_ = 0;
  local_5e = 3;
  local_5d = 0;
  local_5c = 0x86;
  iVar1 = FUN_10002590(param_1,&local_64,2,0x14);
  if (iVar1 == 2) {
    *param_2 = local_5a;
    *param_3 = uStack_5b;
  }
  return iVar1 == 2;
}
