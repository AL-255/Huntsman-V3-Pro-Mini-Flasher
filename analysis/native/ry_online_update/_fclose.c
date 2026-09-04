/* 10149207 _fclose [[10149207, 1014927d]] */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    _fclose

   Library: Visual Studio 2019 Release */

int __cdecl _fclose(FILE *_File)

{
  int *piVar1;
  int iVar2;
  void *local_14;

  if (_File == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_1014b2cf();
  }
  else {
    if (((uint)_File->_flag >> 0xc & 1) == 0) {
      __lock_file(_File);
      iVar2 = __fclose_nolock(_File);
      FUN_10149281();
      ExceptionList = local_14;
      return iVar2;
    }
    __acrt_stdio_free_stream();
  }
  ExceptionList = local_14;
  return -1;
}
