/* 10006570 GetAllocLength [[10006570, 10006585]] */

/* Library Function - Single Match
    public: int __thiscall ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(void)const

   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int __thiscall ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(CSimpleStringT<wchar_t,0> *this)

{
  int iVar1;

  iVar1 = FUN_10006980((int *)this);
  return *(int *)(iVar1 + 4);
}
