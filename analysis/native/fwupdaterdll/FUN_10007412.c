/* 10007412 FUN_10007412 [[10007412, 1000742f] [10007435, 10007449]] */

int __cdecl FUN_10007412(SIZE_T param_1)

{
  undefined *puVar1;
  int iVar2;

  iVar2 = FUN_10144a03(param_1);
  puVar1 = PTR_thunk_FUN_10007b13_101b7000;
  if ((iVar2 == 0) && (PTR_thunk_FUN_10007b13_101b7000 != (undefined *)0x0)) {
    (*(code *)PTR_guard_check_icall_1016a9ac)(param_1);
    iVar2 = (*(code *)puVar1)();
    return iVar2;
  }
  return iVar2;
}
