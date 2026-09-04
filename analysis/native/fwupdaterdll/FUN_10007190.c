/* 10007190 FUN_10007190 [[10007190, 10007261]] */

void FUN_10007190(wchar_t *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined2 ****ppppuVar2;
  int iVar3;
  int local_1c;
  int *local_18;
  undefined2 ****local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_1015b8fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == (wchar_t *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001f10(-0x7ff8ffa9);
  }
  local_14 = FUN_100022f0((int)param_1,param_2);
  if ((int)local_14 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001f10(-0x7fffbffb);
  }
  piVar1 = (int *)GetManager(local_18);
  CStringT<>(&local_1c,param_1,piVar1);
  local_8 = 0;
  ppppuVar2 = (undefined2 ****)FUN_10006590(local_18,(int)local_14);
  iVar3 = FUN_100065b0(&local_1c);
  FUN_10002340(ppppuVar2,(undefined2 ****)((int)local_14 + 1),iVar3,param_2);
  FUN_100069a0(local_18,(int)local_14);
  local_8 = 0xffffffff;
  FUN_10006410(&local_1c);
  ExceptionList = local_10;
  return;
}
