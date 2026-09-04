/* 100082e0 FUN_100082e0 [[100082e0, 1000842e]] */

int * __thiscall FUN_100082e0(void *this,int *param_1,int param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined **ppuVar7;
  uint uVar8;
  uint uVar9;

  iVar5 = 0;
  if (-1 < param_2) {
    iVar5 = param_2;
  }
  uVar9 = 0;
  if (-1 < (int)param_3) {
    uVar9 = param_3;
  }
  if (0x7fffffff - iVar5 < (int)uVar9) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7ff8fdea);
  }
  puVar2 = *(uint **)this;
  uVar8 = puVar2[-3] - iVar5;
  if ((int)(uVar9 + iVar5) <= (int)puVar2[-3]) {
    uVar8 = uVar9;
  }
  uVar9 = 0;
  if (iVar5 <= (int)puVar2[-3]) {
    uVar9 = uVar8;
  }
  if ((iVar5 == 0) && (uVar9 == puVar2[-3])) {
    puVar4 = (undefined4 *)(**(code **)(*(int *)puVar2[-4] + 0x10))();
    if ((-1 < (int)puVar2[-1]) && (puVar4 == (undefined4 *)puVar2[-4])) {
      LOCK();
      puVar2[-1] = puVar2[-1] + 1;
      UNLOCK();
      *param_1 = (int)puVar2;
      return param_1;
    }
    puVar1 = puVar2 + -3;
    iVar5 = (**(code **)*puVar4)(*puVar1,1);
    if (iVar5 != 0) {
      *(uint *)(iVar5 + 4) = *puVar1;
      FUN_10001e00((uint *)(iVar5 + 0x10),*puVar1 + 1,puVar2,*puVar1 + 1);
      *param_1 = iVar5 + 0x10;
      return param_1;
    }
LAB_10008416:
                    /* WARNING: Subroutine does not return */
    FUN_10009130();
  }
  if (((int *)puVar2[-4] == (int *)0x0) ||
     (puVar4 = (undefined4 *)(**(code **)(*(int *)puVar2[-4] + 0x10))(), puVar4 == (undefined4 *)0x0
     )) {
    ppuVar7 = FUN_1000f8a0();
    puVar4 = (undefined4 *)(**(code **)(*ppuVar7 + 0x10))();
    iVar3 = *(int *)this;
    if (puVar4 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
  }
  else {
    iVar3 = *(int *)this;
  }
  if (((uint *)(iVar3 + iVar5) != (uint *)0x0) || (uVar9 == 0)) {
    iVar6 = (**(code **)*puVar4)(uVar9,1);
    if (iVar6 == 0) goto LAB_10008416;
    *param_1 = iVar6 + 0x10;
    if ((-1 < (int)uVar9) && ((int)uVar9 <= *(int *)(iVar6 + 8))) {
      *(uint *)(iVar6 + 4) = uVar9;
      *(undefined1 *)(uVar9 + *param_1) = 0;
      FUN_10001e00((uint *)*param_1,uVar9,(uint *)(iVar3 + iVar5),uVar9);
      return param_1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_10002000(-0x7ff8ffa9);
}
