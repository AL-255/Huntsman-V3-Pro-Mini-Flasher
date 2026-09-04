/* 10002d30 FUN_10002d30 [[10002d30, 10002f50]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_10002d30(undefined4 param_1,uint *param_2)

{
  undefined1 (*pauVar1) [16];
  char cVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  int local_c8;
  undefined1 local_c0;
  char local_bf [5];
  byte local_ba;
  char local_b9;
  char local_b8;
  uint local_b7 [20];
  undefined1 local_64;
  byte abStack_63 [5];
  undefined2 local_5e;
  char local_5c;
  undefined1 auStack_53 [72];
  byte local_b;
  uint local_8;

  local_8 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  _memset(&local_64,0,0x5b);
  local_5e = 0x16;
  local_5c = -0x7e;
  iVar4 = 2;
  auVar8 = ZEXT816(0);
  auVar7 = ZEXT816(0);
  do {
    auVar8 = auVar8 ^ *(undefined1 (*) [16])(abStack_63 + iVar4);
    pauVar1 = (undefined1 (*) [16])(auStack_53 + iVar4);
    iVar4 = iVar4 + 0x20;
    auVar7 = auVar7 ^ *pauVar1;
  } while (iVar4 < 0x42);
  auVar7 = auVar7 ^ auVar8 ^ (auVar7 ^ auVar8) >> 0x40;
  auVar7 = auVar7 ^ auVar7 >> 0x20;
  auVar7 = auVar7 ^ auVar7 >> 0x10;
  uVar5 = auVar7._0_4_ ^ auVar7._1_4_;
  local_b = (byte)uVar5;
  for (; iVar4 < 0x58; iVar4 = iVar4 + 1) {
    local_b = (byte)uVar5 ^ abStack_63[iVar4];
    uVar5 = (uint)local_b;
  }
  _memset(&local_c0,0,0x5b);
  uVar6 = 0;
  local_c8 = 0;
  do {
    Sleep(100);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      cVar2 = HidD_SetFeature(param_1,&local_64,0x5b);
      if (cVar2 != '\0') break;
      Sleep(100);
      if (iVar4 == 3) {
        return 4;
      }
    } while (iVar4 < 3);
    iVar4 = 0;
    _memset(local_bf,0,0x5a);
    local_c0 = 0;
    while (cVar2 != '\0') {
      Sleep(100);
      iVar4 = iVar4 + 1;
      cVar3 = HidD_GetFeature(param_1,&local_c0,0x5b);
      if (cVar3 == '\0') {
        uVar6 = 5;
      }
      else {
        if (local_bf[0] == '\x06') {
          uVar6 = 6;
        }
        if ((((byte)local_5e == local_ba) && (local_5e._1_1_ == local_b9)) && (local_5c == local_b8)
           ) {
          if (local_bf[0] == '\x01') {
            uVar6 = 1;
          }
          else {
            if (local_bf[0] != '\0') {
              if (local_bf[0] == '\x02') {
                FUN_10145db0(param_2,local_b7,(uint)local_ba);
                return 2;
              }
              uVar6 = 3;
              break;
            }
            uVar6 = 1;
          }
        }
      }
      if ((iVar4 == 3) || (2 < iVar4)) break;
    }
    local_c8 = local_c8 + 1;
    if (2 < local_c8) {
      return uVar6;
    }
  } while( true );
}
