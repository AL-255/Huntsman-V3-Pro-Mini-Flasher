/* 10008ef0 FUN_10008ef0 [[10008ef0, 10008f70]] */

void __thiscall FUN_10008ef0(void *this,uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;

  puVar2 = *(uint **)this;
  uVar3 = puVar2[-3];
  puVar4 = (undefined4 *)(**(code **)(*(int *)puVar2[-4] + 0x10))();
  iVar5 = (**(code **)*puVar4)(param_1,1);
  if (iVar5 != 0) {
    if ((int)uVar3 < (int)param_1) {
      param_1 = uVar3;
    }
    FUN_10001e00((uint *)(iVar5 + 0x10),param_1 + 1,puVar2,param_1 + 1);
    *(uint *)(iVar5 + 4) = uVar3;
    LOCK();
    puVar1 = puVar2 + -1;
    uVar3 = *puVar1;
    *puVar1 = *puVar1 - 1;
    UNLOCK();
    if (uVar3 == 1 || (int)(uVar3 - 1) < 0) {
      (**(code **)(*(int *)puVar2[-4] + 4))(puVar2 + -4);
    }
    *(uint **)this = (uint *)(iVar5 + 0x10);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_10009130();
}
