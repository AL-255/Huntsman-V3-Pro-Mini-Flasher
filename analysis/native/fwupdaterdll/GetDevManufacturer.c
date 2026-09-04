/* 10002c20 GetDevManufacturer [[10002c20, 10002c8e]] */

uint __cdecl GetDevManufacturer(undefined4 param_1)

{
  uint uVar1;
  undefined1 local_14 [4];
  undefined1 local_10 [3];
  byte bStack_d;
  undefined4 local_c;
  int local_8;

                    /* 0x2c20  18  GetDevManufacturer */
  local_8 = WinUsb_Initialize(param_1,&local_c);
  if (local_8 == 0) {
    uVar1 = 0;
  }
  else {
    local_8 = WinUsb_GetDescriptor(local_c,3,0,0x409,local_10,4,local_14);
    if (local_8 == 0) {
      uVar1 = WinUsb_Free(local_c);
      uVar1 = uVar1 & 0xffffff00;
    }
    else {
      WinUsb_Free(local_c);
      uVar1 = (uint)bStack_d;
    }
  }
  return uVar1;
}
