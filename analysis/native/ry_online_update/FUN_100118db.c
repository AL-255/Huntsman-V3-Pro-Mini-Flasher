/* 100118db FUN_100118db [[100118db, 10011964]] */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_100118db(void *this,undefined *param_1)

{
  int iVar1;

  if (param_1 != (undefined *)0x0) {
    iVar1 = *(int *)this;
    if (iVar1 == 0) {
      if (DAT_101ce3ac == (DWORD *)0x0) {
        DAT_101ce3ac = FUN_10011391((DWORD *)&DAT_101ce378);
        if (DAT_101ce3ac == (DWORD *)0x0) goto LAB_10011960;
      }
      iVar1 = FUN_10011587((int)DAT_101ce3ac);
      *(int *)this = iVar1;
      if (iVar1 == 0) goto LAB_10011960;
    }
    iVar1 = FUN_10011980(DAT_101ce3ac,iVar1);
    if (iVar1 == 0) {
      (*(code *)PTR_guard_check_icall_101799a0)();
      iVar1 = (*(code *)param_1)();
      FUN_10011a28(DAT_101ce3ac,*(int *)this,iVar1);
    }
    return iVar1;
  }
LAB_10011960:
                    /* WARNING: Subroutine does not return */
  FUN_1000fefd();
}
