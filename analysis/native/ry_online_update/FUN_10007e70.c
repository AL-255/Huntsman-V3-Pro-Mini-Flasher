/* 10007e70 FUN_10007e70 [[10007e70, 10007f8b]] */

int * __cdecl FUN_10007e70(int *param_1,int *param_2,undefined4 *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int *piVar7;
  undefined **ppuVar8;
  int iVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  puStack_c = &LAB_1016a0de;
  local_10 = ExceptionList;
  uVar6 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *param_1 = 0;
  if (*(int **)(*param_2 + -0x10) != (int *)0x0) {
    piVar7 = (int *)(**(code **)(**(int **)(*param_2 + -0x10) + 0x10))(uVar6);
    if (piVar7 != (int *)0x0) goto LAB_10007edc;
  }
  ppuVar8 = FUN_1000f8a0();
  piVar7 = (int *)(**(code **)(*ppuVar8 + 0x10))();
  if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
LAB_10007edc:
  iVar9 = (**(code **)(*piVar7 + 0xc))();
  *param_1 = iVar9 + 0x10;
  local_8 = 0;
  puVar1 = (uint *)*param_3;
  uVar2 = puVar1[-3];
  puVar3 = (uint *)*param_2;
  uVar4 = puVar3[-3];
  uVar6 = uVar2 + uVar4;
  if (-1 < (int)uVar6) {
    if ((int)(1U - *(int *)(iVar9 + 0xc) | *(int *)(iVar9 + 8) - uVar6) < 0) {
      FUN_100090d0(param_1,uVar6);
    }
    puVar5 = (uint *)*param_1;
    FUN_10001e00(puVar5,uVar4,puVar3,uVar4);
    FUN_10001e00((uint *)((int)puVar5 + uVar4),uVar2,puVar1,uVar2);
    if ((int)uVar6 <= *(int *)(*param_1 + -8)) {
      *(uint *)(*param_1 + -0xc) = uVar6;
      *(undefined1 *)(uVar6 + *param_1) = 0;
      ExceptionList = local_10;
      return param_1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_10002000(-0x7ff8ffa9);
}
