/* 10002f80 GetBootloaderHandle [[10002f80, 100031f8] [100031fb, 1000325c] [1000325f, 100032bd]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HANDLE __cdecl
GetBootloaderHandle(undefined4 param_1,undefined4 param_2,short param_3,float param_4)

{
  HANDLE pvVar1;
  char cVar2;
  short sVar3;
  undefined1 (*pauVar4) [16];
  CSimpleStringT<wchar_t,0> *pCVar5;
  WCHAR *in_stack_ffffff58;
  int iVar6;
  DWORD local_74;
  undefined1 local_70 [4];
  int local_6c;
  int local_68;
  int local_64;
  PSP_DEVICE_INTERFACE_DATA local_60;
  HANDLE local_5c;
  ULONG_PTR local_58;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_W local_54;
  _SP_DEVINFO_DATA local_50;
  _SP_DEVICE_INTERFACE_DATA local_34;
  GUID local_18;
  uint local_8;

                    /* 0x2f80  17  GetBootloaderHandle */
  local_8 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  CStringT<>(&local_68);
  CStringT<>(&local_64);
  FUN_10007120(&local_68,L"%04X");
  FUN_10007120(&local_64,L"%04X");
  local_5c = (HANDLE)0x0;
  local_58 = 1;
  local_50.cbSize = 0x1c;
  local_18.Data1 = 0xc9348766;
  local_18.Data2 = 0xd27c;
  local_18.Data3 = 0x41ee;
  local_18.Data4[0] = 0xb2;
  local_18.Data4[1] = 0xbe;
  local_18.Data4[2] = 0xea;
  local_18.Data4[3] = 0x94;
  local_18.Data4[4] = '\x12';
  local_18.Data4[5] = 0xf7;
  local_18.Data4[6] = '+';
  local_18.Data4[7] = 'R';
  local_60 = SetupDiGetClassDevsW(&local_18,(PCWSTR)0x0,(HWND)0x0,0x12);
  local_74 = 0;
  do {
    if (local_58 != 1) {
LAB_1000328b:
      SetupDiDestroyDeviceInfoList(local_60);
      FUN_10006410(&local_64);
      FUN_10006410(&local_68);
      return (HANDLE)0x0;
    }
    local_34.cbSize = 0x1c;
    local_58 = SetupDiEnumDeviceInterfaces
                         (local_60,(PSP_DEVINFO_DATA)0x0,&local_18,local_74,&local_34);
    local_74 = local_74 + 1;
    if (local_58 == 0) {
      local_58 = 0;
      goto LAB_1000328b;
    }
    local_70 = (undefined1  [4])0x0;
    local_58 = SetupDiGetDeviceInterfaceDetailW
                         (in_stack_ffffff58,local_60,(PSP_DEVICE_INTERFACE_DETAIL_DATA_W)&local_34,0
                          ,(PDWORD)0x0,(PSP_DEVINFO_DATA)local_70);
    local_54 = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)FUN_10144a03((SIZE_T)local_70);
    local_54->cbSize = 6;
    in_stack_ffffff58 = L"䖉莬걽甀謓끍\xe851᣶\x14쒃위끅";
    local_58 = SetupDiGetDeviceInterfaceDetailW
                         (local_60,&local_34,local_54,(DWORD)local_70,(PDWORD)local_70,&local_50);
    if (local_58 == 0) {
      FUN_101449e8(local_54);
      local_54 = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0;
    }
    CStringT<>(&local_6c,local_54->DevicePath);
    cVar2 = FUN_10006100(&local_68,(char *)L"");
    if ((cVar2 == '\0') ||
       (cVar2 = FUN_10006100(&local_64,(char *)((int)L"atlTraceQI" + 0x17)), cVar2 == '\0')) {
LAB_1000326b:
      FUN_101449e8(local_54);
      local_54 = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0;
    }
    else {
      iVar6 = 0;
      pauVar4 = (undefined1 (*) [16])FUN_100065b0(&local_68);
      pCVar5 = FUN_10006300((CSimpleStringT<wchar_t,0> *)&local_6c);
      iVar6 = FUN_10006350(pCVar5,pauVar4,iVar6);
      if (iVar6 < 1) goto LAB_1000326b;
      iVar6 = 0;
      pauVar4 = (undefined1 (*) [16])FUN_100065b0(&local_64);
      pCVar5 = FUN_10006300((CSimpleStringT<wchar_t,0> *)&local_6c);
      iVar6 = FUN_10006350(pCVar5,pauVar4,iVar6);
      if (iVar6 < 1) goto LAB_1000326b;
      in_stack_ffffff58 = local_54->DevicePath;
      local_5c = CreateFileW(in_stack_ffffff58,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000000,
                             (HANDLE)0x0);
      if ((local_5c == (HANDLE)0xffffffff) || (local_5c == (HANDLE)0x0)) {
        SetupDiDestroyDeviceInfoList(local_60);
        FUN_101449e8(local_54);
        local_54 = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0;
        FUN_10006410(&local_6c);
        FUN_10006410(&local_64);
        FUN_10006410(&local_68);
        return (HANDLE)0x0;
      }
      sVar3 = GetDevPIDInBootloader((int)local_5c,param_4);
      if (param_3 == sVar3) {
        FUN_101449e8(local_54);
        local_54 = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0;
        SetupDiDestroyDeviceInfoList(local_60);
        pvVar1 = local_5c;
        FUN_10006410(&local_6c);
        FUN_10006410(&local_64);
        FUN_10006410(&local_68);
        return pvVar1;
      }
      CloseHandle(local_5c);
    }
    FUN_10006410(&local_6c);
  } while( true );
}
