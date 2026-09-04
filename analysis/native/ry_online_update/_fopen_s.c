/* 1014b967 _fopen_s [[1014b967, 1014b9ad]] */

/* Library Function - Single Match
    _fopen_s

   Library: Visual Studio 2019 Release */

errno_t __cdecl _fopen_s(FILE **_File,char *_Filename,char *_Mode)

{
  int *piVar1;
  _iobuf *p_Var2;
  int iVar3;

  if (_File == (FILE **)0x0) {
    piVar1 = __errno();
    iVar3 = 0x16;
    *piVar1 = 0x16;
    FUN_1014b2cf();
  }
  else {
    p_Var2 = common_fsopen<char>(_Filename,_Mode,0x80);
    *_File = p_Var2;
    if (p_Var2 == (_iobuf *)0x0) {
      piVar1 = __errno();
      iVar3 = *piVar1;
    }
    else {
      iVar3 = 0;
    }
  }
  return iVar3;
}
