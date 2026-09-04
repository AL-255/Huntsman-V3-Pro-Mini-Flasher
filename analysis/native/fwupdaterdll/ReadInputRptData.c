/* 10006030 ReadInputRptData [[10006030, 100060e7]] */

BOOL __cdecl ReadInputRptData(HANDLE param_1,undefined4 *param_2,DWORD param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  _OVERLAPPED local_24;
  DWORD local_10;
  DWORD local_c;
  BOOL local_8;

                    /* 0x6030  34  ReadInputRptData */
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  *(undefined1 *)(param_2 + 3) = 0;
  local_8 = 0;
  local_24.u.s.Offset = 0;
  local_24.u.s.OffsetHigh = 0;
  local_24.hEvent = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  do {
    local_8 = ReadFile(param_1,param_2,param_3,&local_10,&local_24);
    if (local_8 != 0) {
      return local_8;
    }
    local_c = GetLastError();
  } while ((local_c != 0x3e5) ||
          (DVar1 = WaitForSingleObject(local_24.hEvent,0xffffffff), DVar1 != 0));
  BVar2 = GetOverlappedResult(param_1,&local_24,&param_3,0);
  return BVar2;
}
