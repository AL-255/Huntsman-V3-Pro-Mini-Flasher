/* 10004d40 OutData [[10004d40, 10004d81]] */

undefined4 __cdecl
OutData(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 local_10 [4];
  undefined4 local_c;
  int local_8;

                    /* 0x4d40  32  OutData */
  local_8 = WinUsb_Initialize(param_1,&local_c);
  if (local_8 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = WinUsb_WritePipe(local_c,param_2,param_3,param_4,local_10,0);
  }
  return uVar1;
}
