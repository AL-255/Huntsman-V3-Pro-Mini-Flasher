/* 101489c3 common_ftell<long> [[101489c3, 10148a26]] */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    long __cdecl common_ftell<long>(class __crt_stdio_stream)

   Library: Visual Studio 2019 Release */

long __cdecl common_ftell<long>(FILE *param_1)

{
  int *piVar1;
  long lVar2;
  undefined4 local_14;

  if (param_1 == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_1014b2cf();
    lVar2 = -1;
  }
  else {
    __lock_file(param_1);
    lVar2 = common_ftell_nolock<long>(param_1);
    FUN_10148a2a();
  }
  ExceptionList = local_14;
  return lVar2;
}
