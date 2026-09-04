/* 10006300 FUN_10006300 [[10006300, 10006348]] */

CSimpleStringT<wchar_t,0> * __fastcall FUN_10006300(CSimpleStringT<wchar_t,0> *param_1)

{
  int iVar1;
  char *pcVar2;

  iVar1 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(param_1);
  pcVar2 = (char *)FUN_10006590(param_1,iVar1);
  FUN_100022b0(pcVar2,iVar1 + 1);
  FUN_100069a0(param_1,iVar1);
  return param_1;
}
