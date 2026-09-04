/* 10002530 FUN_10002530 [[10002530, 10002581]] */

void __cdecl FUN_10002530(int param_1)

{
  undefined4 local_c;
  undefined1 local_5;

  local_5 = 0;
  for (local_c = 2; local_c < 0x58; local_c = local_c + 1) {
    local_5 = *(byte *)(param_1 + local_c) ^ local_5;
  }
  *(byte *)(param_1 + 0x58) = local_5;
  return;
}
