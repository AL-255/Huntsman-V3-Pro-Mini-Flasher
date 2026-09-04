/* 10002aa0 GetDevPIDInBootloader [[10002aa0, 10002b75] [10002b7b, 10002c14]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl GetDevPIDInBootloader(int param_1,float param_2)

{
  undefined1 local_8c [4];
  undefined4 local_88;
  int local_84;
  undefined2 local_7c;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_72;
  undefined1 local_71;
  undefined1 local_70;
  undefined1 uStack_68;
  undefined1 uStack_67;
  undefined1 local_1c [12];
  undefined2 local_10;
  uint local_8;

                    /* 0x2aa0  19  GetDevPIDInBootloader */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  if (((param_2 == _DAT_1019c6e4) || (param_2 == _DAT_1019c6e8)) || (param_2 == _DAT_1019c700)) {
    local_7c = 0;
    local_84 = WinUsb_Initialize(param_1,&local_88);
    if (local_84 != 0) {
      local_84 = WinUsb_GetDescriptor(local_88,1,0,0x409,local_1c,0x12,local_8c);
      if (local_84 == 0) {
        WinUsb_Free(local_88);
      }
      else {
        local_7c = local_10;
        WinUsb_Free(local_88);
      }
    }
  }
  else if (param_2 == DAT_1019c6ec) {
    _memset(&local_78,0,0x5b);
    local_78 = 0;
    local_77 = 0;
    local_72 = 9;
    local_71 = 0x10;
    local_70 = 0x80;
    FUN_10002590(param_1,(undefined4 *)&local_78,5,2);
    local_7c = CONCAT11(uStack_68,uStack_67);
  }
  else {
    local_7c = 0;
  }
  return local_7c;
}
