/* 10002af0 FUN_10002af0 [[10002af0, 10002cae]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * __thiscall FUN_10002af0(void *this,LPCSTR param_1,LPCSTR param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  undefined **ppuVar5;
  int iVar6;
  int *piVar7;
  DWORD DVar8;
  char *pcVar9;
  void *local_7c;
  undefined4 local_78;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_10169896;
  local_10 = ExceptionList;
  uVar4 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 3;
  local_7c = this;
  local_14 = uVar4;
  _memset(&local_78,0,100);
  *(undefined4 *)this = 0;
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar6 = (**(code **)(*ppuVar5 + 0xc))(uVar4);
  *(int *)this = iVar6 + 0x10;
  piVar7 = FUN_10007e70((int *)&local_7c,&DAT_101d2834,&DAT_101d2844);
  DVar8 = GetPrivateProfileStringA(param_1,param_2,(LPCSTR)0x0,(LPSTR)&local_78,100,(LPCSTR)*piVar7)
  ;
  LOCK();
  piVar7 = (int *)((int)local_7c + -4);
  iVar6 = *piVar7;
  *piVar7 = *piVar7 + -1;
  UNLOCK();
  if (iVar6 == 1 || iVar6 + -1 < 0) {
    (**(code **)(**(int **)((int)local_7c + -0x10) + 4))((undefined4 *)((int)local_7c + -0x10));
  }
  if (DVar8 == 0) {
    iVar6 = *(int *)this;
    puVar1 = (undefined4 *)(iVar6 + -0x10);
    piVar7 = (int *)*puVar1;
    if (*(int *)(iVar6 + -0xc) != 0) {
      piVar2 = (int *)(iVar6 + -4);
      if (*(int *)(iVar6 + -4) < 0) {
        if (*(int *)(iVar6 + -8) < 0) {
                    /* WARNING: Subroutine does not return */
          FUN_10002000(-0x7ff8ffa9);
        }
        *(undefined4 *)(iVar6 + -0xc) = 0;
        **(undefined1 **)this = 0;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar6 == 1 || iVar6 + -1 < 0) {
          (**(code **)(*(int *)*puVar1 + 4))(puVar1);
        }
        iVar6 = (**(code **)(*piVar7 + 0xc))();
        *(int *)this = iVar6 + 0x10;
      }
    }
  }
  else {
    pcVar9 = (char *)&local_78;
    do {
      cVar3 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar3 != '\0');
    FUN_10009140(this,&local_78,(int)pcVar9 - ((int)&local_78 + 1));
  }
  local_8._0_1_ = 2;
  LOCK();
  piVar7 = (int *)(param_1 + -4);
  iVar6 = *piVar7;
  *piVar7 = *piVar7 + -1;
  UNLOCK();
  if (iVar6 == 1 || iVar6 + -1 < 0) {
    (**(code **)(**(int **)(param_1 + -0x10) + 4))(param_1 + -0x10);
  }
  local_8._0_1_ = 1;
  LOCK();
  piVar7 = (int *)(param_2 + -4);
  iVar6 = *piVar7;
  *piVar7 = *piVar7 + -1;
  UNLOCK();
  if (iVar6 == 1 || iVar6 + -1 < 0) {
    (**(code **)(**(int **)(param_2 + -0x10) + 4))(param_2 + -0x10);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  LOCK();
  piVar7 = (int *)(param_3 + -4);
  iVar6 = *piVar7;
  *piVar7 = *piVar7 + -1;
  UNLOCK();
  if (iVar6 == 1 || iVar6 + -1 < 0) {
    (**(code **)(**(int **)(param_3 + -0x10) + 4))((undefined4 *)(param_3 + -0x10));
  }
  ExceptionList = local_10;
  return this;
}
