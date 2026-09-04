/* 10144b1b _Init [[10144b1b, 10144baa]] */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    private: static class std::locale::_Locimp * __cdecl std::locale::_Init(bool)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_Locimp * __cdecl std::locale::_Init(bool param_1)

{
  code *pcVar1;
  _Locimp *p_Var2;
  _Lockit local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;

  uStack_4 = 4;
  local_8 = 0x10144b27;
  _Lockit::_Lockit(local_14,0);
  local_8 = 0;
  p_Var2 = DAT_101d1f94;
  if (DAT_101d1f94 == (_Locimp *)0x0) {
    p_Var2 = _Locimp::_New_Locimp(false);
    _Setgloballocale(p_Var2);
    *(undefined4 *)(p_Var2 + 0x10) = 0x3f;
    _Yarn<char>::operator=((_Yarn<char> *)(p_Var2 + 0x18),"C");
    pcVar1 = *(code **)(*(int *)p_Var2 + 4);
    DAT_101d1f6c = p_Var2;
    (*(code *)PTR_guard_check_icall_101799a0)();
    (*pcVar1)();
    _DAT_101d1f88 = DAT_101d1f6c;
  }
  if (param_1) {
    pcVar1 = *(code **)(*(int *)p_Var2 + 4);
    (*(code *)PTR_guard_check_icall_101799a0)();
    (*pcVar1)();
  }
  FUN_101446cb((int *)local_14);
  return p_Var2;
}
