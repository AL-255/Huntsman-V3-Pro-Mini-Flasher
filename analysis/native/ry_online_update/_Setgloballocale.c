/* 10144ca3 _Setgloballocale [[10144ca3, 10144cca]] */

/* Library Function - Single Match
    private: static void __cdecl std::locale::_Setgloballocale(void *)

   Library: Visual Studio 2019 Release */

void __cdecl std::locale::_Setgloballocale(void *param_1)

{
  if (DAT_101d1f98 == '\0') {
    DAT_101d1f98 = '\x01';
    _Atexit(tidy_global);
  }
  DAT_101d1f94 = param_1;
  return;
}
