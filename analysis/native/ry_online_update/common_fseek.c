/* 10149798 common_fseek [[10149798, 10149815]] */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    int __cdecl common_fseek(class __crt_stdio_stream,__int64,int)

   Library: Visual Studio 2019 Release */

int __cdecl common_fseek(FILE *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 local_14;

  if ((param_1 == (FILE *)0x0) || (((param_4 != 0 && (param_4 != 1)) && (param_4 != 2)))) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_1014b2cf();
    iVar2 = -1;
  }
  else {
    __lock_file(param_1);
    iVar2 = common_fseek_nolock(param_1,param_2,param_3,param_4);
    FUN_10149819();
  }
  ExceptionList = local_14;
  return iVar2;
}
