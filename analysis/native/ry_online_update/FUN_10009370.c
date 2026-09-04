/* 10009370 FUN_10009370 [[10009370, 1000950b]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

_Facet_base * __cdecl FUN_10009370(_Facet_base *param_1)

{
  short *psVar1;
  wchar_t *pwVar2;
  uint uVar3;
  int iVar4;
  _Facet_base *p_Var5;
  char *pcVar6;
  _Ctypevec *p_Var7;
  _Locinfo local_7c [52];
  _Ctypevec local_48;
  _Facet_base *local_38;
  uint local_34;
  _Lockit local_30 [4];
  _Lockit local_2c [4];
  _Facet_base *local_28;
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;

  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_1016a154;
  local_1c = ExceptionList;
  local_24 = DAT_101c9dd4 ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_28 = param_1;
  local_34 = 0;
  std::_Lockit::_Lockit(local_30,0);
  local_14 = 0;
  local_38 = DAT_101d284c;
  if (DAT_101d1f80 == 0) {
    std::_Lockit::_Lockit(local_2c,0);
    if (DAT_101d1f80 == 0) {
      DAT_101d1f68 = DAT_101d1f68 + 1;
      DAT_101d1f80 = DAT_101d1f68;
    }
    FUN_101446cb((int *)local_2c);
  }
  uVar3 = DAT_101d1f80;
  iVar4 = *(int *)(param_1 + 4);
  if (DAT_101d1f80 < *(uint *)(iVar4 + 0xc)) {
    p_Var5 = *(_Facet_base **)(*(int *)(iVar4 + 8) + DAT_101d1f80 * 4);
    if (p_Var5 != (_Facet_base *)0x0) goto LAB_100094e4;
  }
  else {
    p_Var5 = (_Facet_base *)0x0;
  }
  if (*(char *)(iVar4 + 0x14) == '\0') {
LAB_1000943d:
    if (p_Var5 != (_Facet_base *)0x0) goto LAB_100094e4;
  }
  else {
    iVar4 = FUN_10144b15();
    if (uVar3 < *(uint *)(iVar4 + 0xc)) {
      p_Var5 = *(_Facet_base **)(*(int *)(iVar4 + 8) + uVar3 * 4);
      goto LAB_1000943d;
    }
  }
  p_Var5 = local_38;
  if (local_38 == (_Facet_base *)0x0) {
    p_Var5 = (_Facet_base *)FUN_1000f4d7(0x18);
    local_14 = CONCAT31(local_14._1_3_,1);
    local_38 = p_Var5;
    if (p_Var5 == (_Facet_base *)0x0) {
      p_Var5 = (_Facet_base *)0x0;
    }
    else {
      iVar4 = *(int *)(local_28 + 4);
      if (iVar4 == 0) {
        pcVar6 = "";
      }
      else {
        pcVar6 = *(char **)(iVar4 + 0x18);
        if (pcVar6 == (char *)0x0) {
          pcVar6 = (char *)(iVar4 + 0x1c);
        }
      }
      FUN_100023e0(local_7c,pcVar6);
      local_34 = 1;
      *(undefined4 *)(p_Var5 + 4) = 0;
      *(undefined ***)p_Var5 = std::ctype<char>::vftable;
      p_Var7 = __Getctype(&local_48);
      psVar1 = p_Var7->_Table;
      iVar4 = p_Var7->_Delfl;
      pwVar2 = p_Var7->_LocaleName;
      *(uint *)(p_Var5 + 8) = p_Var7->_Page;
      *(short **)(p_Var5 + 0xc) = psVar1;
      *(int *)(p_Var5 + 0x10) = iVar4;
      *(wchar_t **)(p_Var5 + 0x14) = pwVar2;
    }
    if ((local_34 & 1) != 0) {
      FUN_10002490(local_7c);
    }
    local_14 = CONCAT31(local_14._1_3_,2);
    local_28 = p_Var5;
    std::_Facet_Register(p_Var5);
    (**(code **)(*(int *)p_Var5 + 4))();
    DAT_101d284c = p_Var5;
  }
LAB_100094e4:
  FUN_101446cb((int *)local_30);
  ExceptionList = local_1c;
  return p_Var5;
}
