/* 100061e0 FID_conflict:LoadStringA [[100061e0, 10006217]] */

/* Library Function - Multiple Matches With Different Base Names
    public: int __thiscall ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char> >
   >::LoadStringA(unsigned int)
    public: int __thiscall ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class
   ATL::ChTraitsCRT<wchar_t> > >::LoadStringA(unsigned int)
    public: int __thiscall ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char> >
   >::LoadStringW(unsigned int)
    public: int __thiscall ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class
   ATL::ChTraitsCRT<wchar_t> > >::LoadStringW(unsigned int)

   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

int FID_conflict_LoadStringA(HINSTANCE hInstance,UINT uID,LPSTR lpBuffer,int cchBufferMax)

{
  HINSTANCE hInstance_00;
  int iVar1;
  LPWSTR lpBuffer_00;

  hInstance_00 = (HINSTANCE)FindStringResourceInstance();
  if (hInstance_00 == (HINSTANCE)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FID_conflict_LoadStringW(hInstance_00,(UINT)hInstance,lpBuffer_00,(int)hInstance_00);
  }
  return iVar1;
}
