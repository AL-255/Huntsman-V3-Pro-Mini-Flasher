/* 1014b4b6 __access [[1014b4b6, 1014b4cd]] */

/* Library Function - Single Match
    __access

   Library: Visual Studio 2019 Release */

int __cdecl __access(char *_Filename,int _AccessMode)

{
  errno_t eVar1;

  eVar1 = __access_s(_Filename,_AccessMode);
  return -(uint)(eVar1 != 0);
}
