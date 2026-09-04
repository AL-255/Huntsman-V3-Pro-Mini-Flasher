/* 1001187f FUN_1001187f [[1001187f, 100118c4]] */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_1001187f(void *this,undefined *param_1)

{
  undefined4 uVar1;

  if (*(int *)this == 0) {
    FUN_10012ca5(0x10);
    if (*(int *)this == 0) {
      (*(code *)PTR_guard_check_icall_101799a0)();
      uVar1 = (*(code *)param_1)();
      *(undefined4 *)this = uVar1;
    }
    FUN_10012d19(0x10);
  }
  return *(int *)this;
}
