/* 10144673 _Lockit [[10144673, 101446a3]] */

/* Library Function - Single Match
    public: __thiscall std::_Lockit::_Lockit(int)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_Lockit * __thiscall std::_Lockit::_Lockit(_Lockit *this,int param_1)

{
  *(int *)this = param_1;
  if (param_1 == 0) {
    __lock_locales();
  }
  else if (param_1 < 8) {
    __Mtxlock((_Rmtx *)(&DAT_101d1ea8 + param_1 * 0x18));
  }
  return this;
}
