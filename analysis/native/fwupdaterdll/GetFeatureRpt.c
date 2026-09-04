/* 10005240 GetFeatureRpt [[10005240, 10005345] [10005348, 1000537d]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl
GetFeatureRpt(HANDLE param_1,undefined1 param_2,char param_3,char param_4,int param_5,int param_6,
             undefined4 *param_7)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_70;
  undefined1 local_64;
  char local_63;
  char local_5d;
  char local_5c;
  undefined4 local_5b [20];
  uint local_8;

                    /* 0x5240  23  GetFeatureRpt */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  if ((param_1 == (HANDLE)0xffffffff) || (param_1 == (HANDLE)0x0)) {
    CloseHandle(param_1);
    uVar2 = 0;
  }
  else {
    _memset(&local_64,0,0x5b);
    local_64 = param_2;
    local_63 = '\0';
    local_70 = 0;
    do {
      if (param_5 <= local_70) break;
      delay((float)param_6);
      local_70 = local_70 + 1;
      cVar1 = HidD_GetFeature(param_1,&local_64,0x5b);
      if ((((cVar1 != '\0') && (param_4 == local_5c)) && (param_3 == local_5d)) &&
         ((local_63 != '\x01' && (local_63 != '\0')))) {
        if (local_63 == '\x02') {
          puVar4 = local_5b;
          for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
            *param_7 = *puVar4;
            puVar4 = puVar4 + 1;
            param_7 = param_7 + 1;
          }
          return 2;
        }
        break;
      }
    } while (local_70 != param_5);
    uVar2 = 6;
  }
  return uVar2;
}
