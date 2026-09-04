/* 10148a34 common_ftell_nolock<long> [[10148a34, 10148a5e]] */

/* WARNING: Removing unreachable block (ram,0x10148a48) */
/* Library Function - Single Match
    long __cdecl common_ftell_nolock<long>(class __crt_stdio_stream)

   Library: Visual Studio 2019 Release */

long __cdecl common_ftell_nolock<long>(undefined4 param_1)

{
  int *piVar1;
  long lVar2;
  __int64 _Var3;

  _Var3 = common_ftell_nolock<__int64>(param_1);
  lVar2 = (long)_Var3;
  if (0x7fffffff < _Var3) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    lVar2 = -1;
  }
  return lVar2;
}
