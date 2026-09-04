/* 100090d0 FUN_100090d0 [[100090d0, 10009128]] */

void __thiscall FUN_100090d0(void *this,uint param_1)

{
  int iVar1;
  int iVar2;

  iVar1 = *(int *)this;
  if ((int)param_1 < *(int *)(iVar1 + -0xc)) {
    param_1 = *(uint *)(iVar1 + -0xc);
  }
  if (1 < *(int *)(iVar1 + -4)) {
    FUN_10008ef0(this,param_1);
    return;
  }
  iVar1 = *(int *)(iVar1 + -8);
  if (iVar1 < (int)param_1) {
    if (iVar1 < 0x40000001) {
      iVar2 = iVar1 / 2;
    }
    else {
      iVar2 = 0x100000;
    }
    if ((int)param_1 <= iVar2 + iVar1) {
      param_1 = iVar2 + iVar1;
    }
    FUN_100092e0(this,param_1);
  }
  return;
}
