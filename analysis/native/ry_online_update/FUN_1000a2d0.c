/* 1000a2d0 FUN_1000a2d0 [[1000a2d0, 1000a369]] */

void __fastcall FUN_1000a2d0(int param_1)

{
  void *pvVar1;
  void *pvVar2;

  pvVar1 = *(void **)(param_1 + 0x14);
  if (pvVar1 != (void *)0x0) {
    pvVar2 = pvVar1;
    if ((0xfff < (*(int *)(param_1 + 0x1c) - (int)pvVar1 & 0xfffffff8U)) &&
       (pvVar2 = *(void **)((int)pvVar1 + -4), 0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar2))))
    goto LAB_1000a365;
    FUN_101436ce(pvVar2);
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  pvVar1 = *(void **)(param_1 + 4);
  if (pvVar1 != (void *)0x0) {
    pvVar2 = pvVar1;
    if ((0xfff < (*(int *)(param_1 + 0xc) - (int)pvVar1 & 0xfffffffcU)) &&
       (pvVar2 = *(void **)((int)pvVar1 + -4), 0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar2)))) {
LAB_1000a365:
                    /* WARNING: Subroutine does not return */
      FUN_1014b2df();
    }
    FUN_101436ce(pvVar2);
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}
