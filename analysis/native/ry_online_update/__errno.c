/* 1014b89d __errno [[1014b89d, 1014b8af]] */

/* Library Function - Single Match
    __errno

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int * __cdecl __errno(void)

{
  uint uVar1;

  uVar1 = ___acrt_getptd_noexit();
  if (uVar1 == 0) {
    return (int *)&DAT_101c9e20;
  }
  return (int *)(uVar1 + 0x10);
}
