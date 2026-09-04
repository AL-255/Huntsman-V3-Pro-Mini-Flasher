/* 10003a60 FUN_10003a60 [[10003a60, 10003ce4]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint __fastcall FUN_10003a60(undefined4 *param_1,DWORD *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined **ppuVar2;
  int iVar3;
  int *piVar4;
  BOOL BVar5;
  DWORD DVar6;
  LPCSTR extraout_ECX;
  LPCSTR extraout_ECX_00;
  LPCSTR pCVar7;
  LPCSTR extraout_ECX_01;
  LPCSTR extraout_ECX_02;
  LPCSTR pCVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int local_7c;
  int *local_78;
  _OVERLAPPED local_74;
  DWORD local_60;
  uint local_5c;
  undefined1 local_58;
  undefined4 local_57;
  undefined4 uStack_53;
  undefined4 uStack_4f;
  undefined4 uStack_4b;
  undefined4 local_47;
  undefined4 uStack_43;
  undefined4 uStack_3f;
  undefined4 uStack_3b;
  undefined4 local_37;
  undefined4 uStack_33;
  undefined4 uStack_2f;
  undefined4 uStack_2b;
  undefined4 local_27;
  undefined4 uStack_23;
  undefined4 uStack_1f;
  undefined4 uStack_1b;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_101699ad;
  local_10 = ExceptionList;
  local_14 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  local_60 = 0;
  local_5c = 1000;
  if (DAT_101ca85c == (HANDLE)0xffffffff) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0xffffffff;
    }
    if (param_2 != (DWORD *)0x0) {
      *param_2 = 0;
      return (uint)param_3 & 0xffffff00;
    }
  }
  else {
    pcVar10 = "%d";
    local_78 = (int *)&stack0xffffff64;
    ExceptionList = &local_10;
    puVar9 = param_1;
    ppuVar2 = FUN_1000f8a0();
    if (ppuVar2 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar3 = (**(code **)(*ppuVar2 + 0xc))();
    piVar4 = local_78;
    *local_78 = iVar3 + 0x10;
    local_8 = 0;
    cVar1 = FUN_10008d30(piVar4,0x101ad14c);
    pCVar7 = extraout_ECX;
    if (cVar1 == '\0') {
      FUN_10009140(local_78,(uint *)"update_config.ini",0x11);
      pCVar7 = extraout_ECX_00;
    }
    local_78 = (int *)&stack0xffffff60;
    local_8 = 1;
    ppuVar2 = FUN_1000f8a0();
    if (ppuVar2 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar3 = (**(code **)(*ppuVar2 + 0xc))();
    piVar4 = local_78;
    *local_78 = iVar3 + 0x10;
    local_8 = CONCAT31(local_8._1_3_,2);
    cVar1 = FUN_10008d30(piVar4,0x101ad160);
    pCVar8 = extraout_ECX_01;
    if (cVar1 == '\0') {
      FUN_10009140(local_78,(uint *)"add_time",8);
      pCVar8 = extraout_ECX_02;
    }
    local_78 = (int *)&stack0xffffff5c;
    local_8._0_1_ = 3;
    ppuVar2 = FUN_1000f8a0();
    if (ppuVar2 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
    iVar3 = (**(code **)(*ppuVar2 + 0xc))();
    piVar4 = local_78;
    *local_78 = iVar3 + 0x10;
    local_8 = CONCAT31(local_8._1_3_,4);
    cVar1 = FUN_10008d30(piVar4,0x101ad16c);
    if (cVar1 == '\0') {
      FUN_10009140(local_78,(uint *)"UPDATE_ADD_WAIT",0xf);
    }
    local_8 = 0xffffffff;
    piVar4 = FUN_10002af0(&local_7c,pCVar8,pCVar7,(int)puVar9);
    FUN_10001f20((char *)*piVar4,pcVar10);
    LOCK();
    piVar4 = (int *)(local_7c + -4);
    iVar3 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar3 == 1 || iVar3 + -1 < 0) {
      (**(code **)(**(int **)(local_7c + -0x10) + 4))();
    }
    if ((3000 < local_5c) || (local_5c < 100)) {
      local_5c = 1000;
    }
    local_74.hEvent = (HANDLE)0x0;
    local_74.Internal = 0;
    local_74.InternalHigh = 0;
    local_74.u.s.Offset = 0;
    local_74.u.s.OffsetHigh = 0;
    local_74.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    SetEvent(local_74.hEvent);
    param_3 = _memset(&local_58,0,0x41);
    if (local_74.hEvent != (HANDLE)0x0) {
      BVar5 = ReadFile(DAT_101ca85c,&local_58,0x41,&local_60,&local_74);
      if ((BVar5 != 0) || (DVar6 = WaitForSingleObject(local_74.hEvent,local_5c), DVar6 == 0)) {
        if (param_2 != (DWORD *)0x0) {
          *param_2 = local_60;
        }
        *param_1 = local_57;
        param_1[1] = uStack_53;
        param_1[2] = uStack_4f;
        param_1[3] = uStack_4b;
        param_1[4] = local_47;
        param_1[5] = uStack_43;
        param_1[6] = uStack_3f;
        param_1[7] = uStack_3b;
        param_1[8] = local_37;
        param_1[9] = uStack_33;
        param_1[10] = uStack_2f;
        param_1[0xb] = uStack_2b;
        param_1[0xc] = local_27;
        param_1[0xd] = uStack_23;
        param_1[0xe] = uStack_1f;
        param_1[0xf] = uStack_1b;
        ExceptionList = local_10;
        return CONCAT31((int3)((uint)((int)param_1 + 0x3f) >> 8),1);
      }
      param_3 = (undefined4 *)CloseHandle(local_74.hEvent);
    }
  }
  ExceptionList = local_10;
  return (uint)param_3 & 0xffffff00;
}
