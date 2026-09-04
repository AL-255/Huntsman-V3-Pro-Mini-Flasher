/* 1000aa40 FUN_1000aa40 [[1000aa40, 1000aada]] */

void __thiscall FUN_1000aa40(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;

  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 == 8) {
    uVar3 = 9;
  }
  else if ((iVar2 == 10) || (uVar3 = 0xe, iVar2 == 0xb)) {
    uVar3 = 0xc;
  }
  puVar1 = (undefined4 *)FUN_1000f4d7(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *(undefined8 *)(puVar1 + 4) = 0;
    puVar1[1] = uVar3;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    *puVar1 = std::_Node_end_group::vftable;
    puVar1[5] = param_1;
  }
  puVar1[4] = *(undefined4 *)((int)this + 4);
  iVar2 = *(int *)((int)this + 4);
  if (*(int *)(iVar2 + 0xc) != 0) {
    puVar1[3] = *(int *)(iVar2 + 0xc);
    *(undefined4 **)(*(int *)(*(int *)((int)this + 4) + 0xc) + 0x10) = puVar1;
    iVar2 = *(int *)((int)this + 4);
  }
  *(undefined4 **)(iVar2 + 0xc) = puVar1;
  *(undefined4 **)((int)this + 4) = puVar1;
  return;
}
