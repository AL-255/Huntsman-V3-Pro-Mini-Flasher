/* 1015096b __mbsstr [[1015096b, 10150981]] */

/* Library Function - Single Match
    __mbsstr

   Library: Visual Studio 2019 Release */

uchar * __cdecl __mbsstr(uchar *_Str,uchar *_Substr)

{
  uchar *puVar1;

  puVar1 = __mbsstr_l(_Str,_Substr,(_locale_t)0x0);
  return puVar1;
}
