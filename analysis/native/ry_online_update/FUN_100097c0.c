/* 100097c0 FUN_100097c0 [[100097c0, 1000998e]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

_Facet_base * __cdecl FUN_100097c0(_Facet_base *param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  _Facet_base *p_Var5;
  char *pcVar6;
  void *pvVar7;
  _Collvec _Var8;
  _Locinfo local_74 [52];
  void *local_40 [4];
  undefined4 local_30;
  uint local_2c;
  _Facet_base *local_28;
  _Lockit local_24 [4];
  _Facet_base *local_20;
  _Facet_base *local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_1016a20d;
  local_10 = ExceptionList;
  local_18 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  bVar2 = false;
  bVar1 = false;
  local_20 = param_1;
  local_28 = (_Facet_base *)0x0;
  std::_Lockit::_Lockit(local_24,0);
  local_8 = 0;
  local_28 = DAT_101d2850;
  if (DAT_101d2860 == 0) {
    std::_Lockit::_Lockit((_Lockit *)&local_1c,0);
    if (DAT_101d2860 == 0) {
      DAT_101d1f68 = DAT_101d1f68 + 1;
      DAT_101d2860 = DAT_101d1f68;
    }
    FUN_101446cb((int *)&local_1c);
  }
  uVar3 = DAT_101d2860;
  iVar4 = *(int *)(param_1 + 4);
  if (DAT_101d2860 < *(uint *)(iVar4 + 0xc)) {
    p_Var5 = *(_Facet_base **)(*(int *)(iVar4 + 8) + DAT_101d2860 * 4);
    if (p_Var5 != (_Facet_base *)0x0) goto LAB_10009964;
  }
  else {
    p_Var5 = (_Facet_base *)0x0;
  }
  if (*(char *)(iVar4 + 0x14) == '\0') {
LAB_10009873:
    if (p_Var5 != (_Facet_base *)0x0) goto LAB_10009964;
  }
  else {
    iVar4 = FUN_10144b15();
    if (uVar3 < *(uint *)(iVar4 + 0xc)) {
      p_Var5 = *(_Facet_base **)(*(int *)(iVar4 + 8) + uVar3 * 4);
      goto LAB_10009873;
    }
  }
  p_Var5 = local_28;
  if (local_28 == (_Facet_base *)0x0) {
    p_Var5 = (_Facet_base *)FUN_1000f4d7(0x10);
    local_8._0_1_ = 1;
    local_1c = p_Var5;
    if (p_Var5 == (_Facet_base *)0x0) {
      p_Var5 = (_Facet_base *)0x0;
    }
    else {
      pcVar6 = (char *)FUN_100025c0(local_20,local_40);
      local_8._0_1_ = 2;
      local_28 = (_Facet_base *)0x1;
      if (0xf < *(uint *)(pcVar6 + 0x14)) {
        pcVar6 = *(char **)pcVar6;
      }
      FUN_100023e0(local_74,pcVar6);
      bVar2 = true;
      bVar1 = true;
      *(undefined4 *)(p_Var5 + 4) = 0;
      *(undefined ***)p_Var5 = std::collate<char>::vftable;
      _Var8 = __Getcoll();
      *(_Collvec *)(p_Var5 + 8) = _Var8;
    }
    if (bVar1) {
      FUN_10002490(local_74);
    }
    local_8 = 0;
    if (bVar2) {
      if (0xf < local_2c) {
        pvVar7 = local_40[0];
        if ((0xfff < local_2c + 1) &&
           (pvVar7 = *(void **)((int)local_40[0] + -4),
           0x1f < (uint)((int)local_40[0] + (-4 - (int)pvVar7)))) {
                    /* WARNING: Subroutine does not return */
          FUN_1014b2df();
        }
        FUN_101436ce(pvVar7);
      }
      local_30 = 0;
      local_2c = 0xf;
      local_40[0] = (void *)((uint)local_40[0] & 0xffffff00);
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    local_20 = p_Var5;
    std::_Facet_Register(p_Var5);
    (**(code **)(*(int *)p_Var5 + 4))();
    DAT_101d2850 = p_Var5;
  }
LAB_10009964:
  FUN_101446cb((int *)local_24);
  ExceptionList = local_10;
  return p_Var5;
}
