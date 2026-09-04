/* 10003920 FUN_10003920 [[10003920, 10003a50]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint __fastcall FUN_10003920(int param_1,uint *param_2,undefined4 *param_3)

{
  DWORD DVar1;
  undefined1 *puVar2;
  uint uVar3;
  _OVERLAPPED local_64;
  uint local_50;
  undefined1 local_4c;
  undefined8 local_4b;
  undefined8 local_43;
  undefined8 local_3b;
  undefined8 local_33;
  undefined8 local_2b;
  undefined8 local_23;
  undefined8 local_1b;
  undefined8 local_13;
  uint local_8;

  local_8 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  local_4b = 0;
  local_43 = 0;
  local_3b = 0;
  local_33 = 0;
  local_2b = 0;
  local_23 = 0;
  local_1b = 0;
  local_13 = 0;
  if (DAT_101ca850 == (HANDLE)0xffffffff) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0xffffffff;
    }
    if (param_2 != (uint *)0x0) {
      *param_2 = 0;
    }
    return (uint)param_3 & 0xffffff00;
  }
  local_50 = 0x41;
  if (param_2 != (uint *)0x0) {
    local_50 = *param_2;
  }
  uVar3 = 0;
  local_4c = 0;
  do {
    if (local_50 <= uVar3) break;
    puVar2 = (undefined1 *)((int)&local_4b + uVar3);
    uVar3 = uVar3 + 1;
    *puVar2 = puVar2[param_1 - (int)&local_4b];
  } while (uVar3 < 0x40);
  local_64.hEvent = (HANDLE)0x0;
  local_64.Internal = 0;
  local_64.InternalHigh = 0;
  local_64.u.s.Offset = 0;
  local_64.u.s.OffsetHigh = 0;
  local_64.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
  SetEvent(local_64.hEvent);
  uVar3 = WriteFile(DAT_101ca850,&local_4c,0x41,&local_50,&local_64);
  if (uVar3 == 0) {
    DVar1 = WaitForSingleObject(local_64.hEvent,3000);
    uVar3 = 0;
    if (DVar1 != 0) {
      uVar3 = CloseHandle(local_64.hEvent);
      return uVar3 & 0xffffff00;
    }
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = local_50;
    uVar3 = local_50;
  }
  return CONCAT31((int3)(uVar3 >> 8),1);
}
