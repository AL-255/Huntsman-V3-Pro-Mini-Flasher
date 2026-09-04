/* 10149190 __fclose_nolock [[10149190, 10149206]] */

/* Library Function - Single Match
    __fclose_nolock

   Library: Visual Studio 2019 Release */

int __cdecl __fclose_nolock(FILE *_File)

{
  int *piVar1;
  int iVar2;
  int iVar3;

  if (_File == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_1014b2cf();
    iVar2 = -1;
  }
  else {
    iVar2 = -1;
    if (((uint)_File->_flag >> 0xd & 1) != 0) {
      iVar2 = ___acrt_stdio_flush_nolock(_File);
      ___acrt_stdio_free_buffer_nolock(&_File->_ptr);
      iVar3 = __fileno(_File);
      iVar3 = __close(iVar3);
      if (iVar3 < 0) {
        iVar2 = -1;
      }
      else if (_File->_tmpfname != (char *)0x0) {
        FID_conflict__free(_File->_tmpfname);
        _File->_tmpfname = (char *)0x0;
      }
    }
    __acrt_stdio_free_stream(_File);
  }
  return iVar2;
}
