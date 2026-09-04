/* 10008bf0 FUN_10008bf0 [[10008bf0, 10008d28]] */

uint * __thiscall FUN_10008bf0(void *this,uint *param_1,uint param_2)

{
  uint uVar1;
  void *pvVar2;
  code *pcVar3;
  uint *puVar4;
  void *pvVar5;
  uint uVar6;
  uint uVar7;

  uVar1 = *(uint *)((int)this + 0x14);
  if (param_2 <= uVar1) {
    puVar4 = this;
    if (0xf < uVar1) {
      puVar4 = *(uint **)this;
    }
    *(uint *)((int)this + 0x10) = param_2;
    FUN_10145db0(puVar4,param_1,param_2);
    *(undefined1 *)(param_2 + (int)puVar4) = 0;
    return this;
  }
  if (0x7fffffff < param_2) {
    FUN_100023a0();
LAB_10008d23:
    FUN_10002300();
    pcVar3 = (code *)swi(3);
    puVar4 = (uint *)(*pcVar3)();
    return puVar4;
  }
  uVar7 = param_2 | 0xf;
  if (uVar7 < 0x80000000) {
    if (0x7fffffff - (uVar1 >> 1) < uVar1) {
      uVar7 = 0x7fffffff;
    }
    else {
      uVar6 = (uVar1 >> 1) + uVar1;
      if (uVar7 < uVar6) {
        uVar7 = uVar6;
      }
    }
  }
  else {
    uVar7 = 0x7fffffff;
  }
  uVar6 = -(uint)(0xfffffffe < uVar7) | uVar7 + 1;
  if (uVar6 < 0x1000) {
    if (uVar6 == 0) {
      puVar4 = (uint *)0x0;
    }
    else {
      puVar4 = (uint *)FUN_1000f4d7(uVar6);
    }
  }
  else {
    if (uVar6 + 0x23 <= uVar6) goto LAB_10008d23;
    uVar6 = FUN_1000f4d7(uVar6 + 0x23);
    if (uVar6 == 0) goto LAB_10008d19;
    puVar4 = (uint *)(uVar6 + 0x23 & 0xffffffe0);
    puVar4[-1] = uVar6;
  }
  *(uint *)((int)this + 0x10) = param_2;
  *(uint *)((int)this + 0x14) = uVar7;
  FUN_10145db0(puVar4,param_1,param_2);
  *(undefined1 *)(param_2 + (int)puVar4) = 0;
  if (0xf < uVar1) {
    pvVar2 = *(void **)this;
    pvVar5 = pvVar2;
    if ((0xfff < uVar1 + 1) &&
       (pvVar5 = *(void **)((int)pvVar2 + -4), 0x1f < (uint)((int)pvVar2 + (-4 - (int)pvVar5)))) {
LAB_10008d19:
                    /* WARNING: Subroutine does not return */
      FUN_1014b2df();
    }
    FUN_101436ce(pvVar5);
  }
  *(uint **)this = puVar4;
  return this;
}
