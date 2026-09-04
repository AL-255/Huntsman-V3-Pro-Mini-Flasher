/* 10003360 CloseDevice [[10003360, 1000337a]] */

void __cdecl CloseDevice(HANDLE param_1)

{
                    /* 0x3360  2  CloseDevice */
  if ((param_1 != (HANDLE)0xffffffff) && (param_1 != (HANDLE)0x0)) {
    CloseHandle(param_1);
  }
  return;
}
