/* 10001e00 FUN_10001e00 [[10001e00, 10001e96]] */

undefined4 __fastcall FUN_10001e00(uint *param_1,uint param_2,uint *param_3,uint param_4)

{
  int *piVar1;

  if (param_4 == 0) {
    return 0;
  }
  if (param_1 == (uint *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_1014b2cf();
    return 0x16;
  }
  if ((param_3 != (uint *)0x0) && (param_4 <= param_2)) {
    FUN_10145db0(param_1,param_3,param_4);
    return 0;
  }
  _memset(param_1,0,param_2);
  if (param_3 == (uint *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_1014b2cf();
  }
  else if (param_2 < param_4) {
    piVar1 = __errno();
    *piVar1 = 0x22;
    FUN_1014b2cf();
    return 0x22;
  }
  return 0x16;
}
