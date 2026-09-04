/* 10149094 __mbscmp [[10149094, 101490aa]] */

/* Library Function - Single Match
    __mbscmp

   Library: Visual Studio 2019 Release */

int __cdecl __mbscmp(uchar *_Str1,uchar *_Str2)

{
  int iVar1;

  iVar1 = __mbscmp_l(_Str1,_Str2,(_locale_t)0x0);
  return iVar1;
}
