/* 1000ab60 FUN_1000ab60 [[1000ab60, 1000ac4a]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_1000ab60(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_14 [2];
  char local_c [4];
  uint local_8;

  local_8 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  local_c[0] = '\0';
  uVar3 = *(uint *)((int)this + 0xc);
  if (uVar3 < param_1) {
    if (((int)uVar3 < 0) && (uVar3 != 0)) {
      iVar1 = -((~uVar3 >> 5) * 4 + 4);
    }
    else {
      iVar1 = (uVar3 >> 5) * 4;
    }
    FUN_1000ac50(this,local_14,param_1 - uVar3,local_c,*(int *)this + iVar1,uVar3 & 0x1f);
    return;
  }
  if (param_1 < uVar3) {
    if (((int)uVar3 < 0) && (uVar3 != 0)) {
      iVar1 = -((~uVar3 >> 5) * 4 + 4);
    }
    else {
      iVar1 = (uVar3 >> 5) * 4;
    }
    if (((int)param_1 < 0) && (param_1 != 0)) {
      iVar2 = -((~param_1 >> 5) * 4 + 4);
    }
    else {
      iVar2 = (param_1 >> 5) * 4;
    }
    FUN_1000adc0(this,local_14,*(int *)this + iVar2,param_1 & 0x1f,*(int *)this + iVar1,uVar3 & 0x1f
                );
  }
  return;
}
