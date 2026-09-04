/* 10008860 FUN_10008860 [[10008860, 10008915]] */

int * __thiscall FUN_10008860(void *this,undefined4 *param_1)

{
  uint *puVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint *puVar7;

  puVar3 = (uint *)*param_1;
  iVar4 = *(int *)this;
  puVar7 = (uint *)(iVar4 + -0x10);
  puVar6 = puVar3 + -4;
  if (puVar6 != puVar7) {
    if ((-1 < *(int *)(iVar4 + -4)) && ((int *)*puVar6 == (int *)*puVar7)) {
      puVar5 = (undefined4 *)(**(code **)(*(int *)*puVar6 + 0x10))();
      if (((int)puVar3[-1] < 0) || (puVar5 != (undefined4 *)*puVar6)) {
        puVar1 = puVar3 + -3;
        puVar6 = (uint *)(**(code **)*puVar5)(*puVar1,1);
        if (puVar6 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_10009130();
        }
        puVar6[1] = *puVar1;
        FUN_10001e00(puVar6 + 4,*puVar1 + 1,puVar3,*puVar1 + 1);
      }
      else {
        LOCK();
        puVar3[-1] = puVar3[-1] + 1;
        UNLOCK();
      }
      piVar2 = (int *)(iVar4 + -4);
      LOCK();
      iVar4 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar4 == 1 || iVar4 + -1 < 0) {
        (**(code **)(*(int *)*puVar7 + 4))(puVar7);
      }
      *(uint **)this = puVar6 + 4;
      return this;
    }
    FUN_10009140(this,puVar3,puVar3[-3]);
  }
  return this;
}
