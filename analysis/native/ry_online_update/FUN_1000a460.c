/* 1000a460 FUN_1000a460 [[1000a460, 1000a4db]] */

void __thiscall FUN_1000a460(void *this,uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  code *pcVar3;
  uint uVar4;

  if (param_1 < 0x80000000) {
    puVar2 = *(uint **)((int)this + 4);
    uVar4 = param_1 + 0x1f >> 5;
    if (uVar4 < (uint)((int)puVar2 - *(int *)this >> 2)) {
      puVar1 = (uint *)(*(int *)this + uVar4 * 4);
      if (puVar1 != puVar2) {
        FUN_10145db0(puVar1,puVar2,0);
        *(uint **)((int)this + 4) = puVar1;
      }
    }
    *(uint *)((int)this + 0xc) = param_1;
    if ((param_1 & 0x1f) != 0) {
      puVar2 = (uint *)(*(int *)this + uVar4 * 4 + -4);
      *puVar2 = *puVar2 & (1 << (sbyte)(param_1 & 0x1f)) - 1U;
    }
    return;
  }
  FUN_1000a4e0();
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}
