/* 10007990 chipGoToBootFirmware [[10007990, 10007a1b]] */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __cdecl chipGoToBootFirmware(undefined *param_1)

{
  uint *puVar1;

                    /* 0x7990  2  chipGoToBootFirmware */
  if (param_1 != (undefined *)0x0) {
    DAT_101d2818 = (code *)param_1;
  }
  DAT_101d2830 = 1;
  puVar1 = FUN_10005350();
  if (puVar1 != (uint *)0x0) {
    if (puVar1 == (uint *)0x3) {
      _DAT_101d2814 = 0;
      if (DAT_101d2818 != (code *)0x0) {
        (*DAT_101d2818)(&DAT_101ca854,&DAT_101d2814);
      }
      return (uint *)0x3;
    }
    puVar1 = FUN_10005c20();
    if (puVar1 != (uint *)0x0) {
      _DAT_101d2814 = 0;
      if (DAT_101d2818 != (code *)0x0) {
        (*DAT_101d2818)(&DAT_101ca854,&DAT_101d2814);
      }
      return puVar1;
    }
  }
  return (uint *)0x0;
}
