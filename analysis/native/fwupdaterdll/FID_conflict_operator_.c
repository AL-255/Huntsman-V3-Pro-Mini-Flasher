/* 100069e0 FID_conflict:operator= [[100069e0, 10006a69]] */

/* Library Function - Multiple Matches With Different Base Names
    public: class ATL::CSimpleStringT<char,0> & __thiscall
   ATL::CSimpleStringT<char,0>::operator=(class ATL::CSimpleStringT<char,0> const &)
    public: class ATL::CSimpleStringT<wchar_t,0> & __thiscall
   ATL::CSimpleStringT<wchar_t,0>::operator=(class ATL::CSimpleStringT<wchar_t,0> const &)

   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

CSimpleStringT<wchar_t,0> * __thiscall
FID_conflict_operator_(void *this,CSimpleStringT<wchar_t,0> *param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  wchar_t *pwVar5;

  piVar2 = (int *)FUN_10006980((int *)param_1);
  piVar3 = (int *)FUN_10006980(this);
  if (piVar2 != piVar3) {
    bVar1 = FUN_10002180((int)piVar3);
    if ((bVar1) || (*piVar2 != *piVar3)) {
      iVar4 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(param_1);
      pwVar5 = (wchar_t *)FUN_100065b0((undefined4 *)param_1);
      ATL::CSimpleStringT<wchar_t,0>::SetString(this,pwVar5,iVar4);
    }
    else {
      piVar2 = FUN_10006b40(piVar2);
      FUN_100021e0(piVar3);
      FUN_10006c90(this,(int)piVar2);
    }
  }
  return this;
}
