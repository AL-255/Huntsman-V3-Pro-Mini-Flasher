/* 10004480 GetPS4FWVerion [[10004480, 100045dc]] */

uint __cdecl GetPS4FWVerion(undefined4 param_1,SIZE_T param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  char cVar2;
  char *_Dst;
  uint uVar3;
  int local_10;

                    /* 0x4480  25  GetPS4FWVerion */
  _Dst = (char *)FUN_1000744f(param_2);
  local_10 = 0;
  do {
    if (99 < local_10) {
      uVar3 = thunk_FUN_101449e8(_Dst);
      return uVar3 & 0xffffff00;
    }
    _memset(_Dst,0,param_2);
    *_Dst = '\x03';
    _Dst[1] = 'Z';
    _Dst[2] = -0x5b;
    if ((param_3 == 1) || (param_3 == 3)) {
      _Dst[3] = -0x56;
      _Dst[4] = '\x01';
    }
    else if (param_3 == 2) {
      _Dst[3] = '\x01';
    }
    cVar2 = HidD_SetFeature(param_1,_Dst,param_2);
    if (cVar2 != '\0') {
      Sleep(800);
      cVar2 = HidD_GetFeature(param_1,_Dst,param_2);
      if ((cVar2 != '\0') && (*_Dst == '\x01')) {
        *param_4 = 0;
        param_4[1] = 0;
        param_4[2] = 0;
        *param_4 = *(undefined4 *)(_Dst + 1);
        param_4[1] = *(undefined4 *)(_Dst + 5);
        uVar1 = *(undefined4 *)(_Dst + 9);
        param_4[2] = uVar1;
        return CONCAT31((int3)((uint)uVar1 >> 8),1);
      }
    }
    local_10 = local_10 + 1;
  } while( true );
}
