/* 100025c0 FUN_100025c0 [[100025c0, 100026f1]] */

undefined4 * __thiscall FUN_100025c0(void *this,undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  void **ppvVar7;
  uint *puVar8;
  void *pvVar9;
  uint *puVar10;
  void *local_3c [4];
  undefined4 local_2c;
  uint uStack_28;
  undefined4 *local_24;
  void *local_20 [4];
  undefined4 local_10;
  uint local_c;

  iVar1 = *(int *)((int)this + 4);
  local_24 = param_1;
  if (iVar1 == 0) {
    local_20[0] = (void *)0x0;
    ppvVar7 = local_20;
    local_10 = 0;
    bVar4 = true;
    local_c = 0xf;
    bVar5 = false;
  }
  else {
    puVar10 = *(uint **)(iVar1 + 0x18);
    if (puVar10 == (uint *)0x0) {
      puVar10 = (uint *)(iVar1 + 0x1c);
    }
    local_3c[0] = (void *)0x0;
    local_2c = 0;
    uStack_28 = 0xf;
    puVar8 = puVar10;
    do {
      uVar6 = *puVar8;
      puVar8 = (uint *)((int)puVar8 + 1);
    } while ((char)uVar6 != '\0');
    FUN_10008bf0(local_3c,puVar10,(int)puVar8 - ((int)puVar10 + 1));
    bVar4 = false;
    ppvVar7 = local_3c;
    bVar5 = true;
  }
  *param_1 = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  pvVar9 = ppvVar7[1];
  pvVar2 = ppvVar7[2];
  pvVar3 = ppvVar7[3];
  *param_1 = *ppvVar7;
  param_1[1] = pvVar9;
  param_1[2] = pvVar2;
  param_1[3] = pvVar3;
  *(undefined8 *)(param_1 + 4) = *(undefined8 *)(ppvVar7 + 4);
  ppvVar7[4] = (void *)0x0;
  ppvVar7[5] = (void *)0xf;
  *(undefined1 *)ppvVar7 = 0;
  if ((bVar4) && (0xf < local_c)) {
    pvVar9 = local_20[0];
    if (0xfff < local_c + 1) {
      pvVar9 = *(void **)((int)local_20[0] + -4);
      if (0x1f < (uint)((int)local_20[0] + (-4 - (int)pvVar9))) goto LAB_100026ed;
    }
    FUN_101436ce(pvVar9);
  }
  if ((bVar5) && (0xf < uStack_28)) {
    pvVar9 = local_3c[0];
    if (0xfff < uStack_28 + 1) {
      pvVar9 = *(void **)((int)local_3c[0] + -4);
      if (0x1f < (uint)((int)local_3c[0] + (-4 - (int)pvVar9))) {
LAB_100026ed:
                    /* WARNING: Subroutine does not return */
        FUN_1014b2df();
      }
    }
    FUN_101436ce(pvVar9);
  }
  return param_1;
}
