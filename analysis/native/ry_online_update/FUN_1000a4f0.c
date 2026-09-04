/* 1000a4f0 FUN_1000a4f0 [[1000a4f0, 1000a4fb]] */

void FUN_1000a4f0(error_type param_1)

{
  code *pcVar1;

  FUN_1014496f(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}
