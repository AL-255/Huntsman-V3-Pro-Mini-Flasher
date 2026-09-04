/* 100068d0 FUN_100068d0 [[100068d0, 10006918]] */

void __thiscall FUN_100068d0(void *this,int param_1)

{
  int iVar1;

  if (-1 < param_1) {
    iVar1 = FUN_10006980(this);
    if (param_1 <= *(int *)(iVar1 + 8)) {
      iVar1 = FUN_10006980(this);
      *(int *)(iVar1 + 4) = param_1;
      *(undefined2 *)(*(int *)this + param_1 * 2) = 0;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_10001f10(-0x7ff8ffa9);
}
