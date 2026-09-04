/* 10005120 SetFeatureRpt [[10005120, 10005203] [10005206, 10005236]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl
SetFeatureRpt(HANDLE param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
             undefined1 param_5,undefined1 param_6,byte param_7,int param_8,int param_9,
             uint *param_10)

{
  undefined4 uVar1;
  uint uVar2;
  int local_68;
  undefined1 local_64;
  undefined1 local_63 [2];
  undefined1 local_61;
  undefined1 local_60;
  byte local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  uint local_5b [20];
  uint local_8;

                    /* 0x5120  39  SetFeatureRpt */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  if ((param_1 == (HANDLE)0xffffffff) || (param_1 == (HANDLE)0x0)) {
    CloseHandle(param_1);
  }
  else {
    _memset(&local_64,0,0x5b);
    local_64 = param_2;
    local_63[0] = 0;
    local_61 = param_5;
    local_60 = param_6;
    local_5e = param_7;
    local_5d = param_3;
    local_5c = param_4;
    FUN_1013d230(local_5b,param_10,(uint)param_7);
    uVar1 = 0;
    uVar2 = 0;
    for (local_68 = 0; local_68 < param_8; local_68 = local_68 + 1) {
      delay((float)param_9);
      FUN_10002530((int)local_63);
      uVar2 = HidD_SetFeature(param_1,&local_64,0x5b,uVar1,uVar2);
      uVar2 = uVar2 & 0xff;
      if (uVar2 != 0) {
        return 1;
      }
      delay((float)param_9);
      if (local_68 == param_8) {
        return 0;
      }
    }
  }
  return 0;
}
