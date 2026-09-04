/* 100081c0 FUN_100081c0 [[100081c0, 100082dd]] */

int * __thiscall FUN_100081c0(void *this,int *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined **ppuVar6;
  uint uVar7;
  uint *puVar8;

  puVar8 = *(uint **)this;
  uVar7 = 0;
  if (-1 < (int)param_2) {
    uVar7 = param_2;
  }
  uVar2 = puVar8[-3];
  piVar3 = (int *)puVar8[-4];
  if ((int)uVar7 < (int)uVar2) {
    if ((piVar3 == (int *)0x0) ||
       (puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x10))(), puVar4 == (undefined4 *)0x0)) {
      ppuVar6 = FUN_1000f8a0();
      puVar4 = (undefined4 *)(**(code **)(*ppuVar6 + 0x10))();
      iVar5 = *(int *)this - uVar7;
      if (puVar4 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_10002000(-0x7fffbffb);
      }
    }
    else {
      iVar5 = *(int *)this - uVar7;
    }
    puVar8 = (uint *)(iVar5 + uVar2);
    if ((puVar8 != (uint *)0x0) || (uVar7 == 0)) {
      iVar5 = (**(code **)*puVar4)(uVar7,1);
      if (iVar5 == 0) goto LAB_100082cf;
      *param_1 = iVar5 + 0x10;
      if ((-1 < (int)uVar7) && ((int)uVar7 <= *(int *)(iVar5 + 8))) {
        *(uint *)(iVar5 + 4) = uVar7;
        *(undefined1 *)(uVar7 + *param_1) = 0;
        FUN_10001e00((uint *)*param_1,uVar7,puVar8,uVar7);
        return param_1;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7ff8ffa9);
  }
  puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
  if ((-1 < (int)puVar8[-1]) && (puVar4 == (undefined4 *)puVar8[-4])) {
    LOCK();
    puVar8[-1] = puVar8[-1] + 1;
    UNLOCK();
    *param_1 = (int)puVar8;
    return param_1;
  }
  puVar1 = puVar8 + -3;
  iVar5 = (**(code **)*puVar4)(*puVar1,1);
  if (iVar5 != 0) {
    *(uint *)(iVar5 + 4) = *puVar1;
    FUN_10001e00((uint *)(iVar5 + 0x10),*puVar1 + 1,puVar8,*puVar1 + 1);
    *param_1 = iVar5 + 0x10;
    return param_1;
  }
LAB_100082cf:
                    /* WARNING: Subroutine does not return */
  FUN_10009130();
}
