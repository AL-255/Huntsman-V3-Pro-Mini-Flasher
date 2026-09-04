/* 10002cb0 FUN_10002cb0 [[10002cb0, 10002d24]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_10002cb0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_58 [4];
  undefined1 local_54 [4];
  short sStack_50;
  uint local_c;

  local_c = DAT_101c9dd4 ^ (uint)auStack_58;
  puVar3 = local_54;
  cVar1 = HidD_GetPreparsedData(param_1,puVar3);
  if (cVar1 != '\0') {
    iVar2 = HidP_GetCaps(puVar3,auStack_58);
    if (iVar2 == 0x110000) {
      cVar1 = HidD_FreePreparsedData(puVar3);
      if ((cVar1 != '\0') && (sStack_50 == 0x5b)) {
        return 1;
      }
    }
  }
  return 0;
}
