/* 10006ad0 FUN_10006ad0 [[10006ad0, 10006b31]] */

void * __thiscall FUN_10006ad0(void *this,int *param_1)

{
  int iVar1;

  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0xc))();
    FUN_10006c90(this,iVar1);
    return this;
  }
                    /* WARNING: Subroutine does not return */
  FUN_10001f10(-0x7fffbffb);
}
