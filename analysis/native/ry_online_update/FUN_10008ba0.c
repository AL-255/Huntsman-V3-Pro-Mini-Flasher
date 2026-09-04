/* 10008ba0 FUN_10008ba0 [[10008ba0, 10008be7]] */

int __fastcall FUN_10008ba0(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_EAX;

  if (*param_1 != 0) {
    LOCK();
    piVar1 = (int *)(*param_1 + 0x20);
    iVar2 = *piVar1;
    in_EAX = *piVar1;
    *piVar1 = iVar2 + -1;
    UNLOCK();
    if (iVar2 + -1 == 0) {
      puVar4 = (undefined4 *)*param_1;
      while (puVar4 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)puVar4[3];
        puVar4[3] = 0;
        in_EAX = (**(code **)*puVar4)(1);
        puVar4 = puVar3;
      }
      *param_1 = 0;
      return in_EAX;
    }
  }
  *param_1 = 0;
  return in_EAX;
}
