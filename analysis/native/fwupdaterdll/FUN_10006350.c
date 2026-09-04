/* 10006350 FUN_10006350 [[10006350, 100063c9]] */

int __thiscall FUN_10006350(void *this,undefined1 (*param_1) [16],int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_10;

  if (param_1 == (undefined1 (*) [16])0x0) {
    local_10 = -1;
  }
  else {
    iVar1 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength(this);
    if ((param_2 < 0) || (iVar1 < param_2)) {
      local_10 = -1;
    }
    else {
      iVar1 = FUN_100065b0(this);
      iVar1 = FUN_10002290((undefined1 (*) [16])(iVar1 + param_2 * 2),param_1);
      if (iVar1 == 0) {
        local_10 = -1;
      }
      else {
        iVar2 = FUN_100065b0(this);
        local_10 = iVar1 - iVar2 >> 1;
      }
    }
  }
  return local_10;
}
