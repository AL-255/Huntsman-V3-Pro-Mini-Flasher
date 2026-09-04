/* 1014b658 FID_conflict:__mbslwr_s [[1014b658, 1014b66e]] */

/* Library Function - Multiple Matches With Different Base Names
    __mbslwr_s
    __mbsupr_s

   Library: Visual Studio 2019 Release */

errno_t __cdecl FID_conflict___mbslwr_s(uchar *_Str,size_t _SizeInBytes)

{
  errno_t eVar1;

  eVar1 = __mbsupr_s_l(_Str,_SizeInBytes,(_locale_t)0x0);
  return eVar1;
}
