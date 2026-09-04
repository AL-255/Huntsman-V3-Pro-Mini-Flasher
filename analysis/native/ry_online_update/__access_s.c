/* 1014b4ce __access_s [[1014b4ce, 1014b53f]] */

/* Library Function - Single Match
    __access_s

   Library: Visual Studio 2019 Release */

errno_t __cdecl __access_s(char *_Filename,int _AccessMode)

{
  errno_t eVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_18;
  wchar_t *local_14;
  undefined4 local_10;
  undefined4 local_c;
  char local_8;

  if (_Filename == (char *)0x0) {
    eVar1 = __waccess_s((wchar_t *)0x0,_AccessMode);
    return eVar1;
  }
  local_1c = 0;
  local_18 = 0;
  local_14 = (wchar_t *)0x0;
  local_10 = 0;
  local_c = 0;
  local_8 = '\0';
  uVar2 = __acrt_get_utf8_acp_compatibility_codepage();
  iVar3 = __acrt_mbs_to_wcs_cp<__crt_win32_buffer_internal_dynamic_resizing>
                    (_Filename,
                     (__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing> *)
                     &local_1c,uVar2);
  if (iVar3 == 0) {
    eVar1 = __waccess_s(local_14,_AccessMode);
  }
  else {
    eVar1 = -1;
  }
  if (local_8 != '\0') {
    FID_conflict__free(local_14);
  }
  return eVar1;
}
