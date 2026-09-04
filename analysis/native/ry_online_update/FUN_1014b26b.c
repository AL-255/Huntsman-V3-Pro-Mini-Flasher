/* 1014b26b FUN_1014b26b [[1014b26b, 1014b2cd]] */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_1014b26b(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5)

{
  uint uVar1;
  byte bVar2;
  code *pcVar3;

  uVar1 = ___acrt_getptd_noexit();
  if (((uVar1 == 0) || (pcVar3 = *(code **)(uVar1 + 0x35c), pcVar3 == (code *)0x0)) &&
     (bVar2 = (byte)DAT_101c9dd4 & 0x1f,
     pcVar3 = (code *)((DAT_101c9dd4 ^ _DAT_101d2114) >> bVar2 |
                      (DAT_101c9dd4 ^ _DAT_101d2114) << 0x20 - bVar2), pcVar3 == (code *)0x0)) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson(param_1,param_2,param_3,param_4,param_5);
  }
  (*(code *)PTR_guard_check_icall_101799a0)(param_1,param_2,param_3,param_4,param_5);
  (*pcVar3)();
  return;
}
