/* 10007b00 userSetCfgFilePath [[10007b00, 10007d04]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl userSetCfgFilePath(uint *param_1,uint *param_2)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined **ppuVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  undefined1 local_110 [4];
  uint local_10c [65];
  uint local_8;

                    /* 0x7b00  3  userSetCfgFilePath */
  local_8 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  _memset(local_10c,0,0x104);
  puVar6 = param_1;
  do {
    uVar7 = *puVar6;
    puVar6 = (uint *)((int)puVar6 + 1);
  } while ((char)uVar7 != '\0');
  FUN_10145db0(local_10c,param_1,(int)puVar6 - ((int)param_1 + 1));
  puVar6 = param_2;
  do {
    uVar7 = *puVar6;
    puVar6 = (uint *)((int)puVar6 + 1);
  } while ((char)uVar7 != '\0');
  local_110 = (undefined1  [4])local_10c;
  puVar9 = (uint *)(local_110 + 3);
  do {
    pcVar1 = (char *)((int)puVar9 + 1);
    puVar9 = (uint *)((int)puVar9 + 1);
  } while (*pcVar1 != '\0');
  puVar8 = param_2;
  for (uVar7 = (uint)((int)puVar6 - (int)param_2) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  for (uVar7 = (int)puVar6 - (int)param_2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(char *)puVar9 = (char)*puVar8;
    puVar8 = (uint *)((int)puVar8 + 1);
    puVar9 = (uint *)((int)puVar9 + 1);
  }
  iVar4 = __access((char *)local_110,0);
  if (iVar4 != 0) {
    FUN_10009140(&DAT_101d2834,(uint *)&DAT_101ad0ea,0);
    FUN_10009140(&DAT_101d2844,(uint *)&DAT_101ad0ea,0);
    return 1;
  }
  ppuVar5 = FUN_1000f8a0();
  if (ppuVar5 != (undefined **)0x0) {
    iVar4 = (**(code **)(*ppuVar5 + 0xc))();
    local_110 = (undefined1  [4])(iVar4 + 0x10);
    cVar3 = FUN_10008d30(local_110,(uint)param_1);
    if (cVar3 == '\0') {
      if (param_1 == (uint *)0x0) {
        uVar7 = 0;
      }
      else {
        puVar6 = param_1;
        do {
          uVar7 = *puVar6;
          puVar6 = (uint *)((int)puVar6 + 1);
        } while ((char)uVar7 != '\0');
        uVar7 = (int)puVar6 - ((int)param_1 + 1);
      }
      FUN_10009140(local_110,param_1,uVar7);
    }
    FUN_10008860(&DAT_101d2834,(undefined4 *)local_110);
    LOCK();
    puVar6 = (uint *)((int)local_110 + -4);
    uVar7 = *puVar6;
    *puVar6 = *puVar6 - 1;
    UNLOCK();
    if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {
      (**(code **)(**(int **)((int)local_110 + -0x10) + 4))((uint *)((int)local_110 + -0x10));
    }
    ppuVar5 = FUN_1000f8a0();
    if (ppuVar5 != (undefined **)0x0) {
      iVar4 = (**(code **)(*ppuVar5 + 0xc))();
      local_110 = (undefined1  [4])(iVar4 + 0x10);
      cVar3 = FUN_10008d30(local_110,(uint)param_2);
      if (cVar3 == '\0') {
        if (param_2 == (uint *)0x0) {
          uVar7 = 0;
        }
        else {
          puVar6 = param_2;
          do {
            uVar7 = *puVar6;
            puVar6 = (uint *)((int)puVar6 + 1);
          } while ((char)uVar7 != '\0');
          uVar7 = (int)puVar6 - ((int)param_2 + 1);
        }
        FUN_10009140(local_110,param_2,uVar7);
      }
      FUN_10008860(&DAT_101d2844,(undefined4 *)local_110);
      LOCK();
      piVar2 = (int *)((int)local_110 + -4);
      iVar4 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar4 == 1 || iVar4 + -1 < 0) {
        (**(code **)(**(int **)((int)local_110 + -0x10) + 4))
                  ((undefined4 *)((int)local_110 + -0x10));
      }
      return 0;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_10002000(-0x7fffbffb);
}
