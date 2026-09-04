/* 100080b0 FUN_100080b0 [[100080b0, 100081b8]] */

int * __thiscall FUN_100080b0(void *this,int *param_1,uint param_2)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined **ppuVar5;
  uint *puVar6;
  uint uVar7;

  uVar7 = 0;
  if (-1 < (int)param_2) {
    uVar7 = param_2;
  }
  puVar6 = *(uint **)this;
  piVar2 = (int *)puVar6[-4];
  if ((int)uVar7 < (int)puVar6[-3]) {
    if ((piVar2 == (int *)0x0) ||
       (puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x10))(), puVar3 == (undefined4 *)0x0)) {
      ppuVar5 = FUN_1000f8a0();
      puVar3 = (undefined4 *)(**(code **)(*ppuVar5 + 0x10))();
      puVar6 = *(uint **)this;
      if (puVar3 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_10002000(-0x7fffbffb);
      }
    }
    else {
      puVar6 = *(uint **)this;
    }
    if ((puVar6 != (uint *)0x0) || (uVar7 == 0)) {
      iVar4 = (**(code **)*puVar3)(uVar7,1);
      if (iVar4 == 0) goto LAB_100081aa;
      *param_1 = iVar4 + 0x10;
      if ((-1 < (int)uVar7) && ((int)uVar7 <= *(int *)(iVar4 + 8))) {
        *(uint *)(iVar4 + 4) = uVar7;
        *(undefined1 *)(uVar7 + *param_1) = 0;
        FUN_10001e00((uint *)*param_1,uVar7,puVar6,uVar7);
        return param_1;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7ff8ffa9);
  }
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
  if ((-1 < (int)puVar6[-1]) && (puVar3 == (undefined4 *)puVar6[-4])) {
    LOCK();
    puVar6[-1] = puVar6[-1] + 1;
    UNLOCK();
    *param_1 = (int)puVar6;
    return param_1;
  }
  puVar1 = puVar6 + -3;
  iVar4 = (**(code **)*puVar3)(*puVar1,1);
  if (iVar4 != 0) {
    *(uint *)(iVar4 + 4) = *puVar1;
    FUN_10001e00((uint *)(iVar4 + 0x10),*puVar1 + 1,puVar6,*puVar1 + 1);
    *param_1 = iVar4 + 0x10;
    return param_1;
  }
LAB_100081aa:
                    /* WARNING: Subroutine does not return */
  FUN_10009130();
}
