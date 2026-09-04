/* 100027e0 FUN_100027e0 [[100027e0, 100028a4] [100028a7, 1000299c] [1000299f, 100029d9]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl FUN_100027e0(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_5c;
  int local_4c;
  undefined4 local_48;
  char local_41;
  char local_40;
  uint local_8;

  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  cVar1 = *(char *)((int)param_2 + 2);
  cVar2 = *(char *)(param_2 + 2);
  cVar3 = *(char *)((int)param_2 + 7);
  if ((param_1 == -1) || (param_1 == 0)) {
    uVar6 = 0;
  }
  else {
    cVar4 = '\0';
    for (local_5c = 0; local_5c < 3; local_5c = local_5c + 1) {
      delay((float)param_4);
      local_4c = 0;
      while (local_4c < 3) {
        local_4c = local_4c + 1;
        cVar4 = HidD_SetFeature(param_1,param_2,0x40);
        if (cVar4 != '\0') break;
        delay((float)param_4);
        if (local_4c == 3) {
          return 4;
        }
      }
      local_4c = 0;
      _memset(&local_48,0,0x40);
      local_48._0_1_ = *(undefined1 *)param_2;
      do {
        if ((param_3 <= local_4c) || (cVar4 == '\0')) break;
        delay((float)param_4);
        local_4c = local_4c + 1;
        cVar5 = HidD_GetFeature(param_1,&local_48,0x40);
        if (((cVar5 != '\0') &&
            (((cVar1 == local_48._2_1_ && (cVar2 == local_40)) && (cVar3 == local_41)))) &&
           ((local_48._1_1_ != '\x01' && (local_48._1_1_ != '\0')))) {
          if (local_48._1_1_ == '\x02') {
            puVar8 = &local_48;
            for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *param_2 = *puVar8;
              puVar8 = puVar8 + 1;
              param_2 = param_2 + 1;
            }
            return 2;
          }
          break;
        }
      } while (local_4c != param_3);
    }
    uVar6 = 6;
  }
  return uVar6;
}
