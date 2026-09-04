/* 1014b88a ___doserrno [[1014b88a, 1014b89c]] */

/* Library Function - Single Match
    ___doserrno

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

ulong * __cdecl ___doserrno(void)

{
  uint uVar1;

  uVar1 = ___acrt_getptd_noexit();
  if (uVar1 == 0) {
    return (ulong *)&DAT_101c9e24;
  }
  return (ulong *)(uVar1 + 0x14);
}
