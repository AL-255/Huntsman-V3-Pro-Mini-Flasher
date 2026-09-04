/* 1014b8b0 common_fsopen<char> [[1014b8b0, 1014b94c]] */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    struct _iobuf * __cdecl common_fsopen<char>(char const * const,char const * const,int)

   Library: Visual Studio 2019 Release */

_iobuf * __cdecl common_fsopen<char>(char *param_1,char *param_2,int param_3)

{
  int *piVar1;
  _iobuf *p_Var2;
  int local_20;
  void *local_14;

  if (((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) || (*param_2 == '\0')) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_1014b2cf();
  }
  else if (*param_1 == '\0') {
    piVar1 = __errno();
    *piVar1 = 0x16;
  }
  else {
    __acrt_stdio_allocate_stream();
    if (local_20 != 0) {
      p_Var2 = (_iobuf *)FUN_1015bf12();
      FUN_1014b950();
      ExceptionList = local_14;
      return p_Var2;
    }
    piVar1 = __errno();
    *piVar1 = 0x18;
  }
  ExceptionList = local_14;
  return (_iobuf *)0x0;
}
