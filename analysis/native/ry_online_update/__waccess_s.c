/* 1015bb9e __waccess_s [[1015bb9e, 1015bc5b]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    __waccess_s

   Library: Visual Studio 2019 Release */

errno_t __cdecl __waccess_s(wchar_t *_Filename,int _AccessMode)

{
  ulong *puVar1;
  int *piVar2;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  byte local_2c [36];
  uint local_8;

  local_8 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  if (_Filename == (wchar_t *)0x0) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    iVar5 = 0x16;
    *piVar2 = 0x16;
    FUN_1014b2cf();
  }
  else if ((_AccessMode & 0xfffffff9U) == 0) {
    BVar3 = GetFileAttributesExW(_Filename,GetFileExInfoStandard,local_2c);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      ___acrt_errno_map_os_error(DVar4);
    }
    else {
      if ((((local_2c[0] & 0x10) != 0) || ((local_2c[0] & 1) == 0)) ||
         (((uint)_AccessMode >> 1 & 1) == 0)) {
        return 0;
      }
      puVar1 = ___doserrno();
      *puVar1 = 5;
      piVar2 = __errno();
      *piVar2 = 0xd;
    }
    piVar2 = __errno();
    iVar5 = *piVar2;
  }
  else {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    iVar5 = 0x16;
    *piVar2 = 0x16;
    FUN_1014b2cf();
  }
  return iVar5;
}
