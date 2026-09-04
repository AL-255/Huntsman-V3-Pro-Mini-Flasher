/* 100064d0 FUN_100064d0 [[100064d0, 1000664e]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_100064d0(char *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  DWORD local_68;
  uint local_64;
  uint local_60;
  int local_5c;
  uint local_58;
  int local_54;
  undefined4 local_50;
  char *local_4c;
  char local_48 [8];
  char local_40;
  uint local_8;

  local_8 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  local_4c = param_1;
  _memset(local_48,0,0x40);
  local_5c = *(ushort *)(param_1 + 4) + 8;
  local_54 = 3;
  local_64 = *(ushort *)(param_1 + 4) + 7 >> 6;
  local_58 = local_64 + 1;
  do {
    uVar3 = 0;
    pcVar5 = param_1;
    if (local_58 != 0) {
      iVar4 = 0;
      do {
        local_60 = local_5c - iVar4;
        if (0x40 < local_60) {
          local_60 = 0x40;
        }
        uVar1 = FUN_10003920((int)param_1,&local_60,&local_50);
        if ((char)uVar1 == '\0') {
          return 1;
        }
        param_1 = param_1 + 0x40;
        pcVar5 = local_4c;
        if (uVar3 == local_64) break;
        _memset(local_48,0,0x40);
        uVar2 = FUN_10003a60((undefined4 *)local_48,&local_68,&local_50);
        if ((char)uVar2 == '\0') {
          return 3;
        }
        if ((local_48[0] != *local_4c) || (local_40 != '6')) {
          return 2;
        }
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0x40;
        pcVar5 = local_4c;
      } while (uVar3 < local_58);
    }
    uVar3 = FUN_10003a60((undefined4 *)local_48,&local_68,&local_50);
    if ((char)uVar3 != '\0') {
      if ((local_48[0] == *pcVar5) && (local_40 == '4')) {
        return 0;
      }
      return 4;
    }
    local_54 = local_54 + -1;
    param_1 = pcVar5;
    if (local_54 == 0) {
      return 5;
    }
  } while( true );
}
