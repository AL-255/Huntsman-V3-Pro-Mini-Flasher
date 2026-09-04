/* 100045e0 ControlIn [[100045e0, 1000466f]] */

undefined4 __cdecl
ControlIn(undefined4 param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4,
         undefined2 param_5,undefined4 param_6)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;

                    /* 0x45e0  3  ControlIn */
  local_10 = WinUsb_Initialize(param_1,&local_8);
  if (local_10 == 0) {
    local_c = 0;
  }
  else {
    local_14 = 0;
    local_1c = CONCAT22(param_5,param_4);
    local_20 = CONCAT22(param_3,CONCAT11(param_2,0xc0));
    local_c = WinUsb_ControlTransfer(local_8,local_20,local_1c,param_6,param_5,&local_14,0);
    GetLastError();
    WinUsb_Free(local_8);
  }
  return local_c;
}
