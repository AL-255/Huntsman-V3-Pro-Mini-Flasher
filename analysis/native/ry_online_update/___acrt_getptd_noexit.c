/* 10157b8c ___acrt_getptd_noexit [[10157b8c, 10157c40]] */

/* Library Function - Single Match
    ___acrt_getptd_noexit

   Library: Visual Studio 2019 Release */

uint ___acrt_getptd_noexit(void)

{
  DWORD dwErrCode;
  __acrt_ptd *_Memory;
  int iVar1;

  dwErrCode = GetLastError();
  if ((DAT_101ca090 == 0xffffffff) ||
     (_Memory = (__acrt_ptd *)___acrt_FlsGetValue_4(DAT_101ca090), _Memory == (__acrt_ptd *)0x0)) {
    iVar1 = ___acrt_FlsSetValue_8(DAT_101ca090,(LPVOID)0xffffffff);
    if (iVar1 != 0) {
      _Memory = __calloc_base(1,0x364);
      if (_Memory == (__acrt_ptd *)0x0) {
        ___acrt_FlsSetValue_8(DAT_101ca090,(LPVOID)0x0);
        _Memory = (__acrt_ptd *)0x0;
      }
      else {
        iVar1 = ___acrt_FlsSetValue_8(DAT_101ca090,_Memory);
        if (iVar1 != 0) {
          construct_ptd(_Memory,(__crt_locale_data **)&DAT_101d25f0);
          FID_conflict__free((void *)0x0);
          goto LAB_10157c2e;
        }
        ___acrt_FlsSetValue_8(DAT_101ca090,(LPVOID)0x0);
      }
      FID_conflict__free(_Memory);
    }
  }
  else if (_Memory != (__acrt_ptd *)0xffffffff) goto LAB_10157c2e;
  _Memory = (__acrt_ptd *)0x0;
LAB_10157c2e:
  SetLastError(dwErrCode);
  return -(uint)(_Memory != (__acrt_ptd *)0x0) & (uint)_Memory;
}
