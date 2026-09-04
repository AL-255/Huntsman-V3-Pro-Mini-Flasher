/* 10003cf0 FUN_10003cf0 [[10003cf0, 10003fe3]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * __thiscall FUN_10003cf0(void *this,undefined1 (*param_1) [32])

{
  _Facet_base **pp_Var1;
  _Facet_base *p_Var2;
  uint uVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined1 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 extraout_ECX;
  undefined4 ****ppppuVar9;
  undefined1 (*pauVar10) [32];
  char *pcVar11;
  _Facet_base **local_5c;
  undefined4 ***local_58 [4];
  int local_48;
  uint local_44;
  int local_40;
  _Facet_base *p_Stack_3c;
  _Facet_base *p_Stack_38;
  undefined4 uStack_34;
  _Locimp *local_30;
  undefined4 local_2c;
  char *local_28;
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  uint local_14;

  puStack_20 = &stack0xfffffffc;
  puStack_18 = &LAB_10169a23;
  local_1c = ExceptionList;
  uVar3 = DAT_101c9dd4 ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_14 = 0;
  local_24 = uVar3;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))(uVar3);
  pcVar11 = (char *)(iVar5 + 0x10);
  local_14._0_1_ = 1;
  local_2c = 0;
  local_28 = pcVar11;
  uVar3 = FUN_1014b9c9(param_1,*(uint *)(param_1[-1] + 0x18));
  if ((-1 < (int)uVar3) && ((int)uVar3 <= *(int *)(param_1[-1] + 0x18))) {
    *(uint *)(param_1[-1] + 0x14) = uVar3;
    (*param_1)[uVar3] = 0;
    local_5c = &p_Stack_3c;
    p_Stack_3c = (_Facet_base *)0x0;
    p_Stack_38 = (_Facet_base *)0x0;
    uStack_34 = 0;
    local_30 = (_Locimp *)0x0;
    local_40 = 0;
    local_14._0_1_ = 2;
    local_30 = std::locale::_Init(true);
    local_14._0_1_ = 3;
    p_Stack_3c = FUN_100097c0((_Facet_base *)&uStack_34);
    p_Stack_38 = FUN_10009370((_Facet_base *)&uStack_34);
    local_14._0_1_ = 4;
    FUN_10009510(&local_40,extraout_ECX,&DAT_101ad188);
    local_14._0_1_ = 5;
    if (1 < *(int *)(param_1[-1] + 0x1c)) {
      FUN_10008ef0(&param_1,*(uint *)(param_1[-1] + 0x14));
    }
    local_48 = 0;
    local_44 = 0xf;
    local_58[0] = (undefined4 ****)0x0;
    pauVar10 = param_1;
    do {
      puVar6 = *pauVar10;
      pauVar10 = (undefined1 (*) [32])(*pauVar10 + 1);
    } while (*puVar6 != '\0');
    FUN_10008bf0(local_58,(uint *)param_1,(int)pauVar10 - (int)(*param_1 + 1));
    local_14 = CONCAT31(local_14._1_3_,6);
    ppppuVar9 = local_58;
    if (0xf < local_44) {
      ppppuVar9 = (undefined4 ****)local_58[0];
    }
    puVar6 = FUN_10009ed0(ppppuVar9,(int)ppppuVar9 + local_48,local_44,&local_40,0x10);
    if ((char)puVar6 == '\0') {
      local_28 = (char *)0x0;
    }
    else {
      iVar5 = 0;
      if (0 < (int)(*(uint *)(param_1[-1] + 0x14) & 0xfffffffe)) {
        do {
          piVar7 = FUN_100082e0(&param_1,(int *)&local_5c,iVar5 * 2,2);
          local_14._0_1_ = 7;
          FUN_10008860(&local_28,piVar7);
          local_14 = CONCAT31(local_14._1_3_,6);
          LOCK();
          pp_Var1 = local_5c + -1;
          p_Var2 = *pp_Var1;
          *pp_Var1 = *pp_Var1 + -1;
          UNLOCK();
          if (p_Var2 == (_Facet_base *)0x1 || (int)(p_Var2 + -1) < 0) {
            (**(code **)(*(int *)local_5c[-4] + 4))(local_5c + -4);
          }
          pcVar11 = local_28;
          FUN_10001f20(local_28,"%x");
          *(undefined1 *)((int)this + iVar5) = (undefined1)local_2c;
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(param_1[-1] + 0x14) >> 1);
      }
      local_28 = (char *)0x1;
    }
    local_14 = CONCAT31(local_14._1_3_,5);
    if (0xf < local_44) {
      ppppuVar9 = (undefined4 ****)local_58[0];
      if ((0xfff < local_44 + 1) &&
         (ppppuVar9 = (undefined4 ****)local_58[0][-1],
         0x1f < (uint)((int)local_58[0] + (-4 - (int)ppppuVar9)))) {
                    /* WARNING: Subroutine does not return */
        FUN_1014b2df();
      }
      FUN_101436ce(ppppuVar9);
    }
    local_48 = 0;
    local_44 = 0xf;
    local_58[0] = (undefined4 ***)((uint)local_58[0] & 0xffffff00);
    FUN_10008ba0(&local_40);
    if ((local_30 != (_Locimp *)0x0) &&
       (puVar8 = (undefined4 *)(**(code **)(*(int *)local_30 + 8))(), puVar8 != (undefined4 *)0x0))
    {
      (**(code **)*puVar8)(1);
    }
    local_14 = local_14 & 0xffffff00;
    LOCK();
    piVar7 = (int *)(pcVar11 + -4);
    iVar5 = *piVar7;
    *piVar7 = *piVar7 + -1;
    UNLOCK();
    if (iVar5 == 1 || iVar5 + -1 < 0) {
      (**(code **)(**(int **)(pcVar11 + -0x10) + 4))(pcVar11 + -0x10);
    }
    local_14 = 0xffffffff;
    LOCK();
    piVar7 = (int *)(param_1[-1] + 0x1c);
    iVar5 = *piVar7;
    *piVar7 = *piVar7 + -1;
    UNLOCK();
    if (iVar5 == 1 || iVar5 + -1 < 0) {
      (**(code **)(**(int **)(param_1[-1] + 0x10) + 4))(param_1[-1] + 0x10);
    }
    ExceptionList = local_1c;
    return local_28;
  }
                    /* WARNING: Subroutine does not return */
  FUN_10002000(-0x7ff8ffa9);
}
