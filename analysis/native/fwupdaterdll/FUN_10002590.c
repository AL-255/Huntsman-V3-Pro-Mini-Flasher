/* 10002590 FUN_10002590 [[10002590, 10002676] [10002679, 1000279b] [1000279e, 100027d8]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl FUN_10002590(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_7c;
  int local_6c;
  undefined4 local_64;
  char local_60;
  char local_5d;
  char local_5c;
  uint local_8;

  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  if (DAT_101c05b0 == 0xc) {
    *(undefined1 *)((int)param_2 + 2) = 0xe0;
  }
  cVar1 = *(char *)((int)param_2 + 2);
  cVar2 = *(char *)(param_2 + 2);
  cVar3 = *(char *)((int)param_2 + 7);
  if ((param_1 == -1) || (param_1 == 0)) {
    uVar6 = 0;
  }
  else {
    cVar4 = '\0';
    for (local_7c = 0; local_7c < 3; local_7c = local_7c + 1) {
      delay((float)param_4);
      local_6c = 0;
      while (local_6c < 3) {
        local_6c = local_6c + 1;
        FUN_10002530((int)param_2 + 1);
        cVar4 = HidD_SetFeature(param_1,param_2,0x5b);
        if (cVar4 != '\0') break;
        delay((float)param_4);
        if (local_6c == 3) {
          return 4;
        }
      }
      local_6c = 0;
      _memset(&local_64,0,0x5b);
      local_64._0_1_ = *(undefined1 *)param_2;
      do {
        if ((param_3 <= local_6c) || (cVar4 == '\0')) break;
        delay((float)param_4);
        local_6c = local_6c + 1;
        cVar5 = HidD_GetFeature(param_1,&local_64,0x5b);
        if ((((cVar5 != '\0') && ((cVar1 == local_64._2_1_ && (cVar3 == local_5d)))) &&
            ((cVar2 == local_5c ||
             ((((cVar2 == '\x02' && (local_5c == '\x06')) && (local_60 == '\0')) &&
              (local_64._3_1_ == '\0')))))) &&
           ((local_64._1_1_ != '\x01' && (local_64._1_1_ != '\0')))) {
          if (local_64._1_1_ == '\x02') {
            puVar8 = &local_64;
            for (iVar7 = 0x16; iVar7 != 0; iVar7 = iVar7 + -1) {
              *param_2 = *puVar8;
              puVar8 = puVar8 + 1;
              param_2 = param_2 + 1;
            }
            *(undefined2 *)param_2 = *(undefined2 *)puVar8;
            *(undefined1 *)((int)param_2 + 2) = *(undefined1 *)((int)puVar8 + 2);
            return 2;
          }
          break;
        }
      } while (local_6c != param_3);
    }
    uVar6 = 6;
  }
  return uVar6;
}
