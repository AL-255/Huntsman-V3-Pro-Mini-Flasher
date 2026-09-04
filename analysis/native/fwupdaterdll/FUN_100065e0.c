/* 100065e0 FUN_100065e0 [[100065e0, 10006624]] */

undefined1 __thiscall FUN_100065e0(void *this,uint param_1)

{
  uint3 in_stack_fffffff8;
  uint cchBufferMax;

  cchBufferMax = (uint)in_stack_fffffff8;
  if ((param_1 != 0) && (param_1 >> 0x10 == 0)) {
    FID_conflict_LoadStringA
              ((HINSTANCE)(param_1 & 0xffff),(UINT)this,(LPSTR)(param_1 & 0xffff),cchBufferMax);
    cchBufferMax = 0x1000000;
  }
  return (char)(cchBufferMax >> 0x18);
}
