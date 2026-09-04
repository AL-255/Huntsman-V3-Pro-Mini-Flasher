/* 1015b7cb ___acrt_FlsGetValue@4 [[1015b7cb, 1015b809]] */

/* Library Function - Single Match
    ___acrt_FlsGetValue@4

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_FlsGetValue_4(DWORD param_1)

{
  code *pcVar1;

  pcVar1 = try_get_function(5,"FlsGetValue",(module_id *)&DAT_101a5e90,(module_id *)&DAT_101a5e98);
  if (pcVar1 != (code *)0x0) {
    (*(code *)PTR_guard_check_icall_101799a0)(param_1);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x1015b804. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlsGetValue(param_1);
  return;
}
