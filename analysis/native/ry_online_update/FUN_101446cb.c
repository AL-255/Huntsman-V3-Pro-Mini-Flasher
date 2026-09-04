/* 101446cb FUN_101446cb [[101446cb, 101446e9] [10155f48, 10155f50]] */

void __fastcall FUN_101446cb(int *param_1)

{
  int iVar1;

  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (iVar1 < 8) {
      FUN_1014527f((LPCRITICAL_SECTION)(&DAT_101d1ea8 + iVar1 * 0x18));
    }
    return;
  }
  ___acrt_unlock(4);
  return;
}
