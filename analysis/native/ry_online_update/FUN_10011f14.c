/* 10011f14 FUN_10011f14 [[10011f14, 10011f46]] */

void FUN_10011f14(void)

{
  int iVar1;

  iVar1 = FUN_100118db(&DAT_101c91ec,&LAB_1000ff4b);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) == 0) {
      iVar1 = FUN_1001187f(&DAT_101c91f0,&LAB_10011f7a);
      if (iVar1 == 0) goto LAB_10011f41;
    }
    return;
  }
LAB_10011f41:
                    /* WARNING: Subroutine does not return */
  FUN_1000fefd();
}
