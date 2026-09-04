/* 10002450 delay [[10002450, 1000251e]] */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl delay(float param_1)

{
  BOOL BVar1;
  double in_XMM0_Qa;
  double dVar2;
  LARGE_INTEGER local_1c;
  LARGE_INTEGER local_14;
  LARGE_INTEGER local_c;

                    /* 0x2450  42  delay */
  BVar1 = QueryPerformanceFrequency(&local_1c);
  if (BVar1 != 0) {
    QueryPerformanceCounter(&local_14);
    do {
      QueryPerformanceCounter(&local_c);
      FUN_1015b7d0(local_c.s.LowPart - local_14._0_4_,
                   (local_c.s.HighPart - local_14._4_4_) -
                   (uint)(local_c.s.LowPart < local_14.s.LowPart));
      dVar2 = in_XMM0_Qa;
      FUN_1015b7d0(local_1c.s.LowPart,local_1c.s.HighPart);
      in_XMM0_Qa = (in_XMM0_Qa / dVar2) * _DAT_1019c6f8 * _DAT_1019c6f8 * _DAT_1019c6f8 *
                   _DAT_1019c6f8 * _DAT_1019c6f8 * _DAT_1019c6f8;
    } while (in_XMM0_Qa < (double)(param_1 * _DAT_1019c704 * _DAT_1019c704 * _DAT_1019c704));
  }
  return;
}
