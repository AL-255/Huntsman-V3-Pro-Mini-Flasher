/* 100029e0 FUN_100029e0 [[100029e0, 10002a94]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl
FUN_100029e0(undefined4 param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_4c;
  undefined1 local_48 [4];
  ushort local_44;
  ushort local_42;
  ushort local_40;
  uint local_8;

  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  cVar1 = HidD_GetPreparsedData(param_1,&local_4c,1);
  if (cVar1 == '\0') {
    uVar2 = 0;
  }
  else {
    iVar3 = HidP_GetCaps(local_4c,local_48);
    if (iVar3 == 0x110000) {
      cVar1 = HidD_FreePreparsedData(local_4c);
      if (cVar1 == '\0') {
        uVar2 = 0;
      }
      else if (((param_2 & 1) == 0) || (local_44 == param_4)) {
        if (((param_2 & 2) == 0) || (local_42 == param_5)) {
          if (((param_2 & 4) == 0) || (local_40 == param_3)) {
            uVar2 = 1;
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}
