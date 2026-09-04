/* 10004c00 CheckPipeID [[10004c00, 10004d34]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl CheckPipeID(HANDLE param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  byte local_29;
  int local_28;
  byte local_21;
  undefined1 local_20 [4];
  byte local_1c;
  undefined1 local_14 [4];
  char local_10;
  uint local_8;

                    /* 0x4c00  1  CheckPipeID */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  local_28 = WinUsb_Initialize(param_1,&local_30);
  if (local_28 == 0) {
    CloseHandle(param_1);
    uVar1 = 0;
  }
  else {
    local_28 = WinUsb_QueryInterfaceSettings(local_30,0,local_20);
    if (local_28 == 0) {
      uVar1 = 0;
    }
    else {
      local_29 = local_1c;
      for (local_21 = 0; local_21 < local_29; local_21 = local_21 + 1) {
        local_28 = WinUsb_QueryPipe(local_30,0,local_21,local_14);
        if (local_28 == 0) {
          return 0;
        }
        if (local_10 == '\x01') {
          *param_3 = 1;
          local_34 = 5000;
          local_28 = WinUsb_SetPipePolicy(local_30,1,3,4,&local_34);
          if (local_28 == 0) {
            return 0;
          }
        }
        else if (local_10 == -0x7f) {
          *param_2 = 0x81;
          local_38 = 5000;
          local_28 = WinUsb_SetPipePolicy(local_30,0x81,3,4,&local_38);
          if (local_28 == 0) {
            return 0;
          }
        }
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}
