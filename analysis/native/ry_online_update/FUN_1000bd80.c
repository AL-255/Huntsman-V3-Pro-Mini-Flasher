/* 1000bd80 FUN_1000bd80 [[1000bd80, 1000bea7]] */

void __thiscall FUN_1000bd80(void *this,uint param_1)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;

  if (0x1fffffff < param_1) goto LAB_1000be9e;
  iVar4 = *(int *)((int)this + 4) - *(int *)this >> 3;
  uVar5 = *(int *)((int)this + 8) - *(int *)this >> 3;
  if ((uVar5 <= 0x1fffffff - (uVar5 >> 1)) &&
     ((uVar5 = (uVar5 >> 1) + uVar5, uVar6 = param_1, uVar5 < param_1 ||
      (uVar6 = uVar5, uVar5 < 0x20000000)))) {
    uVar5 = uVar6 * 8;
    if (uVar5 < 0x1000) {
      if (uVar5 == 0) {
        puVar7 = (uint *)0x0;
      }
      else {
        puVar7 = (uint *)FUN_1000f4d7(uVar5);
      }
    }
    else {
      if (uVar5 + 0x23 <= uVar5) goto LAB_1000be99;
      uVar5 = FUN_1000f4d7(uVar5 + 0x23);
      if (uVar5 == 0) goto LAB_1000bea3;
      puVar7 = (uint *)(uVar5 + 0x23 & 0xffffffe0);
      puVar7[-1] = uVar5;
    }
    iVar2 = param_1 - iVar4;
    if (iVar2 != 0) {
      _memset(puVar7 + iVar4 * 2,0,iVar2 * 8);
    }
    FUN_10145db0(puVar7,*(uint **)this,*(int *)((int)this + 4) - (int)*(uint **)this);
    pvVar1 = *(void **)this;
    if (pvVar1 != (void *)0x0) {
      pvVar3 = pvVar1;
      if ((0xfff < (*(int *)((int)this + 8) - (int)pvVar1 & 0xfffffff8U)) &&
         (pvVar3 = *(void **)((int)pvVar1 + -4), 0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar3)))) {
LAB_1000bea3:
                    /* WARNING: Subroutine does not return */
        FUN_1014b2df();
      }
      FUN_101436ce(pvVar3);
    }
    *(uint **)this = puVar7;
    *(uint **)((int)this + 4) = puVar7 + param_1 * 2;
    *(uint **)((int)this + 8) = puVar7 + uVar6 * 2;
    return;
  }
LAB_1000be99:
  FUN_10002300();
LAB_1000be9e:
                    /* WARNING: Subroutine does not return */
  FUN_1000afa0();
}
