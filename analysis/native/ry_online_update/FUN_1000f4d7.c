/* 1000f4d7 FUN_1000f4d7 [[1000f4d7, 1000f4f4] [1000f4fa, 1000f50e]] */

int __cdecl FUN_1000f4d7(size_t param_1)

{
  undefined *puVar1;
  int iVar2;

  iVar2 = FUN_10150a71(param_1);
  puVar1 = PTR_thunk_FUN_1000ff17_101c9000;
  if ((iVar2 == 0) && (PTR_thunk_FUN_1000ff17_101c9000 != (undefined *)0x0)) {
    (*(code *)PTR_guard_check_icall_101799a0)(param_1);
    iVar2 = (*(code *)puVar1)();
    return iVar2;
  }
  return iVar2;
}
