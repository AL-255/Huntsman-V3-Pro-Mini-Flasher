/* 10148fc6 __mbsinc [[10148fc6, 10149000]] */

/* Library Function - Single Match
    __mbsinc

   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

uchar * __cdecl __mbsinc(uchar *_Ptr)

{
  int *piVar1;
  uchar *puVar2;
  int iVar3;

  if (_Ptr == (uchar *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_1014b2cf();
    puVar2 = (uchar *)0x0;
  }
  else {
    iVar3 = __ismbblead((uint)*_Ptr);
    puVar2 = _Ptr + 1;
    if ((iVar3 != 0) && (*puVar2 != '\0')) {
      puVar2 = _Ptr + 2;
    }
  }
  return puVar2;
}
