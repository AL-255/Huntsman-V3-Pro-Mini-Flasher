/* 10144e99 __Getcoll [[10144e99, 10144eb9]] */

/* Library Function - Single Match
    __Getcoll

   Library: Visual Studio 2019 Release */

_Collvec __cdecl __Getcoll(void)

{
  wchar_t **ppwVar1;
  wchar_t *pwVar2;
  _Collvec _Var3;

  _Var3._Page = ____lc_collate_cp_func();
  ppwVar1 = ____lc_locale_name_func();
  pwVar2 = (wchar_t *)0x0;
  if (ppwVar1[1] != (wchar_t *)0x0) {
    pwVar2 = FUN_101563b4(ppwVar1[1]);
  }
  _Var3._LocaleName = pwVar2;
  return _Var3;
}
