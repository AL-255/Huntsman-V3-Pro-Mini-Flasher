/* 10006da0 GetManager [[10006da0, 10006ddb]] */

/* Library Function - Multiple Matches With Same Base Name
    public: struct ATL::IAtlStringMgr * __thiscall
   ATL::CSimpleStringT<char,0>::GetManager(void)const
    public: struct ATL::IAtlStringMgr * __thiscall
   ATL::CSimpleStringT<wchar_t,0>::GetManager(void)const

   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

undefined4 __fastcall GetManager(int *param_1)

{
  int *piVar1;
  undefined4 local_c;

  piVar1 = (int *)FUN_10006980(param_1);
  if ((int *)*piVar1 == (int *)0x0) {
    local_c = 0;
  }
  else {
    local_c = (**(code **)(*(int *)*piVar1 + 0x10))();
  }
  return local_c;
}
