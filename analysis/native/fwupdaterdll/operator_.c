/* 100067a0 operator= [[100067a0, 10006816]] */

/* Library Function - Single Match
    public: class ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> >
   > & __thiscall ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> >
   >::operator=(char const *)

   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> * __thiscall
ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::operator=
          (CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *this,char *param_1)

{
  wchar_t *pwVar1;
  undefined4 local_10;

  if (param_1 == (char *)0x0) {
    local_10 = 0;
  }
  else {
    local_10 = ChTraitsCRT<wchar_t>::GetBaseTypeLength(param_1);
  }
  if (local_10 < 1) {
    Empty((int *)this);
  }
  else {
    pwVar1 = (wchar_t *)FUN_10006590(this,local_10);
    ChTraitsCRT<wchar_t>::ConvertToBaseType(pwVar1,local_10,param_1,-1);
    FUN_100069a0(this,local_10);
  }
  return (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)this;
}
