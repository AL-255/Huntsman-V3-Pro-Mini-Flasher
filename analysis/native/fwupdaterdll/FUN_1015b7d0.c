/* 1015b7d0 FUN_1015b7d0 [[1015b7d0, 1015b810]] */

void __fastcall FUN_1015b7d0(uint param_1,undefined4 param_2)

{
  undefined1 auVar1 [16];

  if (5 < DAT_101bfdac) {
    auVar1 = vpinsrd_avx(ZEXT416(param_1),param_2,1);
    vcvtqq2pd_avx512vl(auVar1);
    return;
  }
  return;
}
