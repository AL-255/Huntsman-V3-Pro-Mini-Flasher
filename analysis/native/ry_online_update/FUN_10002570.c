/* 10002570 FUN_10002570 [[10002570, 10002574]] */

void __fastcall FUN_10002570(int param_1)

{
  LOCK();
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  UNLOCK();
  return;
}
