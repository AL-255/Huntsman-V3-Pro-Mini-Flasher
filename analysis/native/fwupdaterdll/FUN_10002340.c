/* 10002340 FUN_10002340 [[10002340, 1000238d]] */

undefined2 **** __cdecl
FUN_10002340(undefined2 ****param_1,undefined2 ****param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined2 ****local_c;

  puVar2 = (undefined4 *)0x0;
  puVar1 = (uint *)FUN_10001d90();
  local_c = FUN_101442d9(*puVar1 | 4,puVar1[1],param_1,param_2,param_3,puVar2,param_4);
  if ((int)local_c < 0) {
    local_c = (undefined2 ****)0xffffffff;
  }
  return local_c;
}
