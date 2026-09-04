/* 10009140 FUN_10009140 [[10009140, 1000925f]] */

void __thiscall FUN_10009140(void *this,uint *param_1,uint param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  uint *puVar8;

  if (param_2 == 0) {
    iVar4 = *(int *)this;
    puVar1 = (undefined4 *)(iVar4 + -0x10);
    piVar7 = (int *)*puVar1;
    if (*(int *)(iVar4 + -0xc) != 0) {
      piVar2 = (int *)(iVar4 + -4);
      if (-1 < *(int *)(iVar4 + -4)) {
        LOCK();
        iVar4 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar4 == 1 || iVar4 + -1 < 0) {
          (**(code **)(*(int *)*puVar1 + 4))(puVar1);
        }
        iVar4 = (**(code **)(*piVar7 + 0xc))();
        *(int *)this = iVar4 + 0x10;
        return;
      }
      if (*(int *)(iVar4 + -8) < 0) goto LAB_10009256;
      *(undefined4 *)(iVar4 + -0xc) = 0;
      **(undefined1 **)this = 0;
    }
    return;
  }
  if (param_1 != (uint *)0x0) {
    puVar8 = *(uint **)this;
    uVar3 = puVar8[-3];
    uVar5 = (int)param_1 - (int)puVar8;
    if (-1 < (int)param_2) {
      if ((int)(1 - puVar8[-1] | puVar8[-2] - param_2) < 0) {
        FUN_100090d0(this,param_2);
        puVar8 = *(uint **)this;
      }
      if (uVar3 < uVar5) {
        FUN_10001e00(puVar8,puVar8[-2],param_1,param_2);
      }
      else {
        puVar6 = (uint *)(uVar5 + (int)puVar8);
        if (puVar6 == (uint *)0x0) {
          piVar7 = __errno();
          *piVar7 = 0x16;
          FUN_1014b2cf();
        }
        else if (puVar8[-2] < param_2) {
          piVar7 = __errno();
          *piVar7 = 0x22;
          FUN_1014b2cf();
        }
        else {
          FUN_10145db0(puVar8,puVar6,param_2);
        }
      }
      if ((int)param_2 <= *(int *)(*(int *)this + -8)) {
        *(uint *)(*(int *)this + -0xc) = param_2;
        *(undefined1 *)(param_2 + *(int *)this) = 0;
        return;
      }
    }
  }
LAB_10009256:
                    /* WARNING: Subroutine does not return */
  FUN_10002000(-0x7ff8ffa9);
}
