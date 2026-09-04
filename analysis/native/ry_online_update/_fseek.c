/* 101499da _fseek [[101499da, 101499f4]] */

/* Library Function - Single Match
    _fseek

   Library: Visual Studio 2019 Release */

int __cdecl _fseek(FILE *_File,long _Offset,int _Origin)

{
  int iVar1;

  iVar1 = common_fseek(_File,_Offset,_Offset >> 0x1f,_Origin);
  return iVar1;
}
