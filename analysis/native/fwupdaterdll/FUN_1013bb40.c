/* 1013bb40 FUN_1013bb40 [[1013bb40, 1013bc39]] */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1013bb40(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  uint extraout_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  longlong lVar9;
  undefined4 unaff_retaddr;

  uVar2 = IsProcessorFeaturePresent(0x17);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  lVar9 = (ulonglong)extraout_EDX << 0x20;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    lVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_101bfb80 = (undefined4)((ulonglong)lVar9 >> 0x20);
  _DAT_101bfb88 = (undefined4)lVar9;
  _DAT_101bfb98 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_101bfb9c = &stack0x00000004;
  _DAT_101bfad8 = 0x10001;
  _DAT_101bfa88 = 0xc0000409;
  _DAT_101bfa8c = 1;
  _DAT_101bfa98 = 1;
  DAT_101bfa9c = 2;
  _DAT_101bfa94 = unaff_retaddr;
  _DAT_101bfb64 = in_GS;
  _DAT_101bfb68 = in_FS;
  _DAT_101bfb6c = in_ES;
  _DAT_101bfb70 = in_DS;
  _DAT_101bfb74 = unaff_EDI;
  _DAT_101bfb78 = unaff_ESI;
  _DAT_101bfb7c = unaff_EBX;
  _DAT_101bfb84 = uVar3;
  _DAT_101bfb8c = unaff_EBP;
  DAT_101bfb90 = unaff_retaddr;
  _DAT_101bfb94 = in_CS;
  _DAT_101bfba0 = in_SS;
  FUN_1013bb18((_EXCEPTION_POINTERS *)&PTR_DAT_10196388);
  return;
}
