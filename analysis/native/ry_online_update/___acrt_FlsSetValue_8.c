/* 1015b80a ___acrt_FlsSetValue@8 [[1015b80a, 1015b84b]] */

/* Library Function - Single Match
    ___acrt_FlsSetValue@8

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_FlsSetValue_8(DWORD param_1,LPVOID param_2)

{
  code *pcVar1;

  pcVar1 = try_get_function(6,"FlsSetValue",(module_id *)&DAT_101a5e98,(module_id *)&DAT_101a5ea0);
  if (pcVar1 != (code *)0x0) {
    (*(code *)PTR_guard_check_icall_101799a0)(param_1,param_2);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x1015b846. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlsSetValue(param_1,param_2);
  return;
}
