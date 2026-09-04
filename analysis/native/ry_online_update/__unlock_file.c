/* 10156b28 __unlock_file [[10156b28, 10156b3b]] */

/* Library Function - Single Match
    __unlock_file

   Library: Visual Studio 2019 Release */

void __cdecl __unlock_file(FILE *_File)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}
