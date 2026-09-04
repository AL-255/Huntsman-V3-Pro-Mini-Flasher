/* 10156028 FUN_10156028 [[10156028, 10156053]] */

bool __cdecl FUN_10156028(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  bool bVar3;

  pcVar1 = (code *)FUN_10156054();
  if (pcVar1 == (code *)0x0) {
    bVar3 = false;
  }
  else {
    (*(code *)PTR_guard_check_icall_1016a9ac)(param_1);
    iVar2 = (*pcVar1)();
    bVar3 = iVar2 != 0;
  }
  return bVar3;
}
