/* 1014ee18 FUN_1014ee18 [[1014ee18, 1014ee51]] */

void __cdecl FUN_1014ee18(LPVOID param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  __acrt_ptd *p_Var4;

  if (param_1 != (LPVOID)0x0) {
    BVar1 = HeapFree(DAT_101c0330,0,param_1);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      iVar3 = FID_conflict____acrt_errno_from_os_error(DVar2);
      p_Var4 = FUN_1014476c();
      *(int *)p_Var4 = iVar3;
    }
  }
  return;
}
