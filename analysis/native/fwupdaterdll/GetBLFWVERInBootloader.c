/* 10003d70 GetBLFWVERInBootloader [[10003d70, 10003e5a] [10003e5d, 10003e8d]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl GetBLFWVERInBootloader(undefined4 param_1,float param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined1 local_24 [4];
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;

                    /* 0x3d70  16  GetBLFWVERInBootloader */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  if (((param_2 == _DAT_1019c6e4) || (param_2 == _DAT_1019c6e8)) || (param_2 == _DAT_1019c700)) {
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    *param_3 = 0;
    *(undefined1 *)(param_3 + 1) = 0;
    local_1c = WinUsb_Initialize(param_1,&local_20);
    if (local_1c == 0) {
      uVar1 = 0;
    }
    else {
      local_1c = WinUsb_GetDescriptor(local_20,3,0,0x409,&local_14,9,local_24);
      if (local_1c == 0) {
        WinUsb_Free(local_20);
        uVar1 = 0;
      }
      else {
        for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
          *(undefined1 *)((int)param_3 + local_18) = *(undefined1 *)((int)&local_10 + local_18);
        }
        WinUsb_Free(local_20);
        uVar1 = 1;
      }
    }
  }
  else if ((double)param_2 == _DAT_1019c6f0) {
    *param_3 = 0;
    *(undefined1 *)(param_3 + 1) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
