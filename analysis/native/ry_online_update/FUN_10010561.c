/* 10010561 FUN_10010561 [[10010561, 100105a3]] */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */

void FUN_10010561(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;

  uStack_4 = 4;
  local_8 = 0x1001056d;
  local_14[0] = (undefined4 *)FUN_10010208(0xc);
  puVar1 = (undefined4 *)0x0;
  local_8 = 0;
  if (local_14[0] != (undefined4 *)0x0) {
    puVar1 = FUN_100101f2(local_14[0]);
  }
  local_8 = 0xffffffff;
  puVar1[2] = param_1;
  local_14[0] = puVar1;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)local_14,&DAT_101b7fc4);
}
