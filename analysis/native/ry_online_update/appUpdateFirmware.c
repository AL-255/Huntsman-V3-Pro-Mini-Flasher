/* 10007a20 appUpdateFirmware [[10007a20, 10007af2]] */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl appUpdateFirmware(undefined *param_1)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined4 *puVar4;
  uint uVar5;

                    /* 0x7a20  1  appUpdateFirmware */
  ppuVar3 = FUN_1000f8a0();
  if (ppuVar3 != (undefined **)0x0) {
    puVar4 = (undefined4 *)(**(code **)(*ppuVar3 + 0xc))();
    if (param_1 != (undefined *)0x0) {
      DAT_101d2818 = (code *)param_1;
    }
    uVar5 = FUN_10004000();
    if (((uVar5 & 0xf000) == 0xf000) || ((uVar5 & 0xf000) < 0xa000)) {
      DAT_101ca854 = 1;
      _DAT_101d2814 = 0;
      if (DAT_101d2818 != (code *)0x0) {
        (*DAT_101d2818)(&DAT_101ca854,&DAT_101d2814);
      }
      if (0xf < uVar5) {
        uVar5 = 6;
      }
    }
    else {
      DAT_101ca854 = 1;
      _DAT_101d2814 = uVar5;
      if (DAT_101d2818 != (code *)0x0) {
        (*DAT_101d2818)(&DAT_101ca854,&DAT_101d2814);
      }
      uVar5 = FUN_10006650();
    }
    LOCK();
    piVar1 = puVar4 + 3;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1 || iVar2 + -1 < 0) {
      (**(code **)(*(int *)*puVar4 + 4))(puVar4);
    }
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_10002000(-0x7fffbffb);
}
