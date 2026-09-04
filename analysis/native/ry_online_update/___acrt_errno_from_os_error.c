/* 1014b824 ___acrt_errno_from_os_error [[1014b824, 1014b866]] */

/* Library Function - Single Match
    ___acrt_errno_from_os_error

   Library: Visual Studio 2019 Release */

int __cdecl ___acrt_errno_from_os_error(int param_1)

{
  uint uVar1;

  uVar1 = 0;
  do {
    if (param_1 == (&DAT_101a3b40)[uVar1 * 2]) {
      return *(int *)(&UNK_101a3b44 + uVar1 * 8);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x2d);
  if (param_1 - 0x13U < 0x12) {
    return 0xd;
  }
  return (-(uint)(0xe < param_1 - 0xbcU) & 0xe) + 8;
}
