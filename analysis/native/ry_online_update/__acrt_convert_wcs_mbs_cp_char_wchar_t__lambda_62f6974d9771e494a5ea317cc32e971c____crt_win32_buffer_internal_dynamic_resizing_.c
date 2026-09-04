/* 1014b330 __acrt_convert_wcs_mbs_cp<char,wchar_t,<lambda_62f6974d9771e494a5ea317cc32e971c>,__crt_win32_buffer_internal_dynamic_resizing> [[1014b330, 1014b3e1]] */

/* Library Function - Single Match
    int __cdecl __acrt_convert_wcs_mbs_cp<char,wchar_t,class
   <lambda_62f6974d9771e494a5ea317cc32e971c>,struct
   __crt_win32_buffer_internal_dynamic_resizing>(char const * const,class
   __crt_win32_buffer<wchar_t,struct __crt_win32_buffer_internal_dynamic_resizing> &,class
   <lambda_62f6974d9771e494a5ea317cc32e971c> const &,unsigned int)

   Library: Visual Studio 2019 Release */

int __cdecl
__acrt_convert_wcs_mbs_cp<char,wchar_t,<lambda_62f6974d9771e494a5ea317cc32e971c>,__crt_win32_buffer_internal_dynamic_resizing>
          (char *param_1,
          __crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing> *param_2,
          <lambda_62f6974d9771e494a5ea317cc32e971c> *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  int *piVar4;

  if (param_1 == (char *)0x0) {
    deallocate((int)param_2);
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  else {
    if (*param_1 != '\0') {
      uVar2 = ___acrt_MultiByteToWideChar(param_4,9,param_1,-1,(LPWSTR)0x0,0);
      if (uVar2 != 0) {
        if ((*(uint *)(param_2 + 0xc) < uVar2) &&
           (iVar1 = __crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>::
                    allocate(param_2,uVar2), iVar1 != 0)) {
          return iVar1;
        }
        iVar1 = ___acrt_MultiByteToWideChar
                          (param_4,9,param_1,-1,*(LPWSTR *)(param_2 + 8),*(int *)(param_2 + 0xc));
        if (iVar1 != 0) {
          *(int *)(param_2 + 0x10) = iVar1 + -1;
          return 0;
        }
      }
      DVar3 = GetLastError();
      ___acrt_errno_map_os_error(DVar3);
      piVar4 = __errno();
      return *piVar4;
    }
    if ((*(int *)(param_2 + 0xc) == 0) &&
       (iVar1 = __crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>::allocate
                          (param_2,1), iVar1 != 0)) {
      return iVar1;
    }
    **(undefined2 **)(param_2 + 8) = 0;
  }
  *(undefined4 *)(param_2 + 0x10) = 0;
  return 0;
}
