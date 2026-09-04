/* 10149001 _LocaleUpdate [[10149001, 10149083]] */

/* Library Function - Single Match
    public: __thiscall _LocaleUpdate::_LocaleUpdate(struct __crt_locale_pointers * const)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_LocaleUpdate * __thiscall
_LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this,__crt_locale_pointers *param_1)

{
  _LocaleUpdate *p_Var1;
  undefined *puVar2;
  uint uVar3;

  this[0xc] = (_LocaleUpdate)0x0;
  p_Var1 = this + 4;
  if (param_1 == (__crt_locale_pointers *)0x0) {
    if (DAT_101d25ec != 0) {
      uVar3 = FUN_10157a35();
      *(uint *)this = uVar3;
      *(int *)p_Var1 = *(int *)(uVar3 + 0x4c);
      *(int *)(this + 8) = *(int *)(uVar3 + 0x48);
      ___acrt_update_locale_info(uVar3,(int *)p_Var1);
      ___acrt_update_multibyte_info(*(int *)this,(int *)(this + 8));
      uVar3 = *(uint *)(*(int *)this + 0x350);
      if ((uVar3 & 2) != 0) {
        return this;
      }
      *(uint *)(*(int *)this + 0x350) = uVar3 | 2;
      this[0xc] = (_LocaleUpdate)0x1;
      return this;
    }
    *(undefined **)p_Var1 = PTR_PTR_101ca150;
    puVar2 = PTR_DAT_101ca154;
  }
  else {
    *(int *)p_Var1 = *(int *)param_1;
    puVar2 = *(undefined **)(param_1 + 4);
  }
  *(undefined **)(this + 8) = puVar2;
  return this;
}
