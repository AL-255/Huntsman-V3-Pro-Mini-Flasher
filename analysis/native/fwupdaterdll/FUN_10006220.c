/* 10006220 FUN_10006220 [[10006220, 100062f3]] */

void * __thiscall FUN_10006220(void *this,void *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;

  if (param_2 < 0) {
    param_2 = 0;
  }
  if ((int)param_3 < 0) {
    param_3 = 0;
  }
  iVar1 = ATL::AtlAddThrow<int>(param_2,param_3);
  iVar2 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(this);
  if (iVar2 < iVar1) {
    iVar1 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(this);
    param_3 = iVar1 - param_2;
  }
  iVar1 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(this);
  if (iVar1 < param_2) {
    param_3 = 0;
  }
  if ((param_2 == 0) &&
     (uVar3 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(this), param_3 == uVar3)) {
    FUN_10006530(param_1,this);
    return param_1;
  }
  puVar4 = (undefined4 *)GetManager(this);
  iVar1 = FUN_100065b0(this);
  CStringT<>(param_1,(wchar_t *)(iVar1 + param_2 * 2),param_3,puVar4);
  return param_1;
}
