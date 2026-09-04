/* 100021e0 FUN_100021e0 [[100021e0, 10002211]] */

void __fastcall FUN_100021e0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;

  piVar2 = param_1 + 3;
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar1 == 1 || iVar1 + -1 < 0) {
    (**(code **)(*(int *)*param_1 + 4))(param_1);
  }
  return;
}
