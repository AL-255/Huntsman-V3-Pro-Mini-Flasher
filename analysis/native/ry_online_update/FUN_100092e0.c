/* 100092e0 FUN_100092e0 [[100092e0, 10009316]] */

void __thiscall FUN_100092e0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;

  puVar2 = (undefined4 *)(*(int *)this + -0x10);
  if ((*(int *)(*(int *)this + -8) < param_1) && (0 < param_1)) {
    iVar1 = (**(code **)(*(int *)*puVar2 + 8))(puVar2,param_1,1);
    if (iVar1 != 0) {
      *(int *)this = iVar1 + 0x10;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_10009130();
}
