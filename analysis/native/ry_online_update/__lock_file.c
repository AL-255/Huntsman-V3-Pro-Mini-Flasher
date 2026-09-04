/* 10156b14 __lock_file [[10156b14, 10156b27]] */

/* Library Function - Single Match
    __lock_file

   Library: Visual Studio 2019 Release */

void __cdecl __lock_file(FILE *_File)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}
