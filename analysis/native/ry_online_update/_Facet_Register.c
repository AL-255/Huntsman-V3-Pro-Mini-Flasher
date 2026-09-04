/* 10144ae9 _Facet_Register [[10144ae9, 10144b14]] */

/* Library Function - Single Match
    void __cdecl std::_Facet_Register(class std::_Facet_base *)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl std::_Facet_Register(_Facet_base *param_1)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)FUN_1000f4d7(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = DAT_101d1f8c;
    puVar1[1] = param_1;
  }
  DAT_101d1f8c = puVar1;
  return;
}
