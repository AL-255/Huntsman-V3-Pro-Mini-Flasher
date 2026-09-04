/* 100043b0 SendCmd [[100043b0, 10004469]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
SendCmd(HANDLE param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5,
       undefined1 param_6,byte param_7,int param_8,int param_9,uint *param_10,uint *param_11)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_61;
  undefined1 local_60;
  byte local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  uint local_5b [20];
  uint local_8;

                    /* 0x43b0  36  SendCmd */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  if ((param_1 == (HANDLE)0xffffffff) || (param_1 == (HANDLE)0x0)) {
    CloseHandle(param_1);
    iVar1 = 0;
  }
  else {
    _memset(&local_64,0,0x5b);
    local_64 = param_2;
    local_63 = 0;
    local_61 = param_5;
    local_60 = param_6;
    local_5e = param_7;
    local_5d = param_3;
    local_5c = param_4;
    FUN_1013d230(local_5b,param_10,(uint)param_7);
    iVar1 = FUN_10002590((int)param_1,(undefined4 *)&local_64,param_8,param_9);
    if (iVar1 == 2) {
      puVar3 = local_5b;
      for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
        *param_11 = *puVar3;
        puVar3 = puVar3 + 1;
        param_11 = param_11 + 1;
      }
    }
  }
  return iVar1;
}
