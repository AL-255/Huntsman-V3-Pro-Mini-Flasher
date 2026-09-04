/* 100022f0 FUN_100022f0 [[100022f0, 1000233c]] */

undefined2 **** __cdecl FUN_100022f0(int param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined2 ****ppppuVar2;
  undefined2 ****ppppuVar3;
  undefined4 *puVar4;
  undefined2 ****local_c;

  puVar4 = (undefined4 *)0x0;
  ppppuVar3 = (undefined2 ****)0x0;
  ppppuVar2 = (undefined2 ****)0x0;
  puVar1 = (uint *)FUN_10001d90();
  local_c = FUN_10144298(*puVar1 | 6,puVar1[1],ppppuVar2,ppppuVar3,param_1,puVar4,param_2);
  if ((int)local_c < 0) {
    local_c = (undefined2 ****)0xffffffff;
  }
  return local_c;
}
