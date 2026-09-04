/* 10159596 __acrt_stdio_allocate_stream [[10159596, 101595f2]] */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    class __crt_stdio_stream __cdecl __acrt_stdio_allocate_stream(void)

   Library: Visual Studio 2019 Release */

undefined4 * __cdecl __acrt_stdio_allocate_stream(void)

{
  undefined4 *puVar1;
  undefined4 *in_stack_00000004;
  void *local_14;

  *in_stack_00000004 = 0;
  ___acrt_lock(8);
  puVar1 = (undefined4 *)find_or_allocate_unused_stream_nolock();
  puVar1 = (undefined4 *)*puVar1;
  *in_stack_00000004 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = 0;
    puVar1[7] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[4] = 0xffffffff;
  }
  FUN_101595f6();
  ExceptionList = local_14;
  return in_stack_00000004;
}
