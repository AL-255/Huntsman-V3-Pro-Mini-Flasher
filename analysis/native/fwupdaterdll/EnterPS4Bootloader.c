/* 10004700 EnterPS4Bootloader [[10004700, 1000489f]] */

void __cdecl EnterPS4Bootloader(undefined4 param_1,SIZE_T param_2,int param_3)

{
  char cVar1;
  undefined1 *_Dst;
  undefined4 uVar2;
  int local_c;

                    /* 0x4700  14  EnterPS4Bootloader */
  uVar2 = 1;
  _Dst = (undefined1 *)FUN_1000744f(param_2);
  for (local_c = 0; local_c < 100; local_c = local_c + 1) {
    _memset(_Dst,0,param_2);
    if (param_3 == 1) {
      *_Dst = 3;
      _Dst[1] = 0x66;
      _Dst[2] = 0x88;
      _Dst[3] = 0x99;
      _Dst[4] = 4;
      _Dst[5] = 1;
    }
    else if (param_3 == 2) {
      *_Dst = 3;
      _Dst[1] = 0x5a;
      _Dst[2] = 0xa5;
      _Dst[3] = 10;
    }
    else if (param_3 == 3) {
      *_Dst = 3;
      _Dst[1] = 0x5a;
      _Dst[2] = 0xa5;
      _Dst[3] = 0xaa;
      _Dst[4] = 6;
      _Dst[5] = 2;
    }
    cVar1 = HidD_SetFeature(param_1,_Dst,param_2,uVar2);
    if (cVar1 != '\0') break;
    delay(DAT_1019c6ec);
  }
  thunk_FUN_101449e8(_Dst);
  return;
}
