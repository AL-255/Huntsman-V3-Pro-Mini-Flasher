/* 10004ae0 RebootSystem [[10004ae0, 10004b84]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 RebootSystem(void)

{
  HANDLE ProcessHandle;
  BOOL BVar1;
  undefined4 uVar2;
  DWORD DVar3;
  HANDLE *TokenHandle;
  HANDLE local_1c;
  _TOKEN_PRIVILEGES local_18;
  uint local_8;

                    /* 0x4ae0  35  RebootSystem */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  TokenHandle = &local_1c;
  DVar3 = 0x28;
  ProcessHandle = GetCurrentProcess();
  BVar1 = OpenProcessToken(ProcessHandle,DVar3,TokenHandle);
  if (BVar1 == 0) {
    uVar2 = 0;
  }
  else {
    LookupPrivilegeValueW((LPCWSTR)0x0,L"SeShutdownPrivilege",&local_18.Privileges[0].Luid);
    local_18.PrivilegeCount = 1;
    local_18.Privileges[0].Attributes = 2;
    AdjustTokenPrivileges(local_1c,0,&local_18,0,(PTOKEN_PRIVILEGES)0x0,(PDWORD)0x0);
    DVar3 = GetLastError();
    if (DVar3 == 0) {
      BVar1 = ExitWindowsEx(2,0);
      if (BVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}
