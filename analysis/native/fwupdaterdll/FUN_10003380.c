/* 10003380 FUN_10003380 [[10003380, 10003729] [1000372f, 10003819] [1000381f, 100038f6] [100038fc, 10003acb] [10003ace, 10003c4e] [10003c51, 10003d64]] */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HANDLE __cdecl
FUN_10003380(ushort *param_1,ushort *param_2,short param_3,undefined4 param_4,float param_5,
            uint param_6,uint param_7,uint param_8,uint param_9)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  CSimpleStringT<wchar_t,0> *pCVar5;
  BOOL BVar6;
  DWORD DVar7;
  HMODULE hModule;
  int *piVar8;
  undefined1 (*pauVar9) [16];
  wchar_t *pwVar10;
  int iVar11;
  char *lpProcName;
  undefined1 local_2500 [4];
  undefined1 local_24fc [4];
  DWORD local_24f8 [2];
  CSimpleStringT<wchar_t,0> *local_24f0;
  CSimpleStringT<wchar_t,0> *local_24ec;
  DWORD local_24e8;
  CSimpleStringT<wchar_t,0> *local_24e4;
  CSimpleStringT<wchar_t,0> *local_24e0;
  int local_24dc;
  HANDLE local_24d8;
  HANDLE local_24d4;
  HANDLE local_24d0;
  HANDLE local_24cc;
  int local_24c8;
  HANDLE local_24c4;
  HANDLE local_24c0;
  int local_24bc;
  int local_24b8;
  int local_24b4;
  DWORD local_24b0;
  int local_24ac;
  CSimpleStringT<wchar_t,0> local_24a8 [4];
  int local_24a4;
  DWORD local_24a0;
  DWORD local_249c;
  wchar_t *local_2498;
  int local_2494;
  int local_2490;
  HDEVINFO local_248c;
  CSimpleStringT<wchar_t,0> local_2488 [4];
  int local_2484;
  HANDLE local_2480;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_W local_247c;
  _SP_DEVINFO_DATA local_2478;
  _SP_DEVICE_INTERFACE_DATA local_245c;
  _SP_DEVINFO_DATA local_2440;
  GUID local_2424;
  OLECHAR local_2414 [4096];
  GUID local_414 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_1015b88d;
  local_10 = ExceptionList;
  uVar4 = DAT_101b7f64 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2480 = (HANDLE)0x0;
  local_24a4 = 1;
  local_2440.cbSize = 0x1c;
  local_14 = uVar4;
  CStringT<>(&local_2494);
  local_8 = 0;
  FUN_10007120(&local_2494,L"%04X");
  local_24f8[1] = 0;
  HidD_GetHidGuid(&local_2424,uVar4);
  local_248c = SetupDiGetClassDevsW(&local_2424,(PCWSTR)0x0,(HWND)0x0,0x12);
  local_24a0 = 0;
  do {
    while( true ) {
      if (local_24a4 != 1) {
        local_24d8 = (HANDLE)0x0;
        local_8 = 0xffffffff;
        FUN_10006410(&local_2494);
        ExceptionList = local_10;
        return local_24d8;
      }
      local_245c.cbSize = 0x1c;
      local_24e8 = local_24a0;
      local_24a4 = SetupDiEnumDeviceInterfaces
                             (local_248c,(PSP_DEVINFO_DATA)0x0,&local_2424,local_24a0,&local_245c);
      local_24a0 = local_24a0 + 1;
      local_249c = 0;
      SetupDiGetDeviceInterfaceDetailW
                (local_248c,&local_245c,(PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0,0,&local_249c,
                 &local_2440);
      local_247c = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)FUN_10144a03(local_249c);
      local_247c->cbSize = 6;
      SetupDiGetDeviceInterfaceDetailW
                (local_248c,&local_245c,local_247c,local_249c,&local_249c,&local_2440);
      CStringT<>(local_2488,local_247c->DevicePath);
      local_8._0_1_ = 1;
      CStringT<>(&local_2490,(char *)L"");
      local_8._0_1_ = 2;
      CStringT<>(&local_2484,(char *)((int)L"atlTraceRefcount" + 0x23));
      local_8._0_1_ = 3;
      iVar11 = 0;
      pauVar9 = (undefined1 (*) [16])&DAT_1019c40c;
      pCVar5 = FUN_10006300(local_2488);
      local_24ac = FUN_10006350(pCVar5,pauVar9,iVar11);
      uVar4 = 4;
      iVar11 = local_24ac + 4;
      piVar8 = &local_24dc;
      pCVar5 = FUN_10006300(local_2488);
      local_24e4 = FUN_10006220(pCVar5,piVar8,iVar11,uVar4);
      local_8._0_1_ = 4;
      local_24e0 = local_24e4;
      FUN_100063f0(&local_2490,local_24e4);
      local_8._0_1_ = 3;
      FUN_10006410(&local_24dc);
      iVar11 = 0;
      pauVar9 = (undefined1 (*) [16])&DAT_1019c414;
      pCVar5 = FUN_10006300(local_2488);
      local_24ac = FUN_10006350(pCVar5,pauVar9,iVar11);
      uVar4 = 4;
      iVar11 = local_24ac + 4;
      piVar8 = &local_24bc;
      pCVar5 = FUN_10006300(local_2488);
      local_24f0 = FUN_10006220(pCVar5,piVar8,iVar11,uVar4);
      local_8._0_1_ = 5;
      local_24ec = local_24f0;
      FUN_100063f0(&local_2484,local_24f0);
      local_8._0_1_ = 3;
      FUN_10006410(&local_24bc);
      if ((((param_1 != (ushort *)0x0) && (param_2 != (ushort *)0x0)) &&
          (bVar1 = FUN_10006180(&local_2490,param_1), bVar1)) &&
         (bVar1 = FUN_10006180(&local_2484,param_2), bVar1)) break;
LAB_10003cf7:
      local_8._0_1_ = 2;
      FUN_10006410(&local_2484);
      local_8._0_1_ = 1;
      FUN_10006410(&local_2490);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10006410((int *)local_2488);
    }
    local_2480 = (HANDLE)0x0;
    local_2480 = CreateFileW(local_247c->DevicePath,0,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    if ((local_2480 != (HANDLE)0xffffffff) && (local_2480 != (HANDLE)0x0)) {
      cVar2 = FUN_10006140(&local_2484,"1004");
      if ((((cVar2 != '\0') || (cVar2 = FUN_10006140(&local_2484,"1000"), cVar2 != '\0')) ||
          (cVar2 = FUN_10006140(&local_2484,"1007"), cVar2 != '\0')) &&
         (iVar11 = FUN_10006350(local_2488,(undefined1 (*) [16])L"COL01",0), 0 < iVar11)) {
        FUN_101449e8(local_247c);
        local_247c = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0;
        SetupDiDestroyDeviceInfoList(local_248c);
        local_24c0 = local_2480;
        local_8._0_1_ = 2;
        FUN_10006410(&local_2484);
        local_8._0_1_ = 1;
        FUN_10006410(&local_2490);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10006410((int *)local_2488);
        local_8 = 0xffffffff;
        FUN_10006410(&local_2494);
        ExceptionList = local_10;
        return local_24c0;
      }
      iVar11 = FUN_100029e0(local_2480,param_6,param_7,param_8,param_9);
      if (iVar11 == 0) {
        CloseHandle(local_2480);
      }
      else if ((param_6 & 8) == 0) {
        if ((param_6 & 0x10) == 0) {
          FUN_101449e8(local_247c);
          local_247c = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0;
          SetupDiDestroyDeviceInfoList(local_248c);
          local_24d4 = local_2480;
          local_8._0_1_ = 2;
          FUN_10006410(&local_2484);
          local_8._0_1_ = 1;
          FUN_10006410(&local_2490);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10006410((int *)local_2488);
          local_8 = 0xffffffff;
          FUN_10006410(&local_2494);
          ExceptionList = local_10;
          return local_24d4;
        }
        if (DAT_101c05a4 == (FARPROC)0x0) {
          lpProcName = "SetupDiGetDevicePropertyW";
          hModule = GetModuleHandleW(L"Setupapi.dll");
          DAT_101c05a4 = GetProcAddress(hModule,lpProcName);
        }
        _memset(local_414,0,0x400);
        (*DAT_101c05a4)(local_248c,&local_2440,&DAT_1019c6d0,local_2500,local_414,0x400,local_24fc,0
                       );
        StringFromGUID2(local_414,local_2414,0x1000);
        CStringT<>(&local_24b8,local_2414);
        local_8._0_1_ = 7;
        cVar2 = FUN_10006140(&local_24b8,(char *)L"");
        if (cVar2 != '\0') {
          FUN_101449e8(local_247c);
          local_247c = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0;
          SetupDiDestroyDeviceInfoList(local_248c);
          local_24d0 = local_2480;
          local_8._0_1_ = 3;
          FUN_10006410(&local_24b8);
          local_8._0_1_ = 2;
          FUN_10006410(&local_2484);
          local_8._0_1_ = 1;
          FUN_10006410(&local_2490);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10006410((int *)local_2488);
          local_8 = 0xffffffff;
          FUN_10006410(&local_2494);
          ExceptionList = local_10;
          return local_24d0;
        }
        CloseHandle(local_2480);
        local_8._0_1_ = 3;
        FUN_10006410(&local_24b8);
      }
      else {
        sVar3 = GetDevPIDInBootloader((int)local_2480,param_5);
        if (param_3 == sVar3) {
          FUN_101449e8(local_247c);
          local_247c = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0;
          SetupDiDestroyDeviceInfoList(local_248c);
          local_24c4 = local_2480;
          local_8._0_1_ = 2;
          FUN_10006410(&local_2484);
          local_8._0_1_ = 1;
          FUN_10006410(&local_2490);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10006410((int *)local_2488);
          local_8 = 0xffffffff;
          FUN_10006410(&local_2494);
          ExceptionList = local_10;
          return local_24c4;
        }
        local_2498 = (wchar_t *)0x0;
        local_24b0 = 0;
        local_2478.cbSize = 0x1c;
        local_24a4 = SetupDiEnumDeviceInfo(local_248c,local_24a0 - 1,&local_2478);
        if (local_24a4 != 0) {
          while (BVar6 = SetupDiGetDeviceRegistryPropertyW
                                   (local_248c,&local_2478,1,local_24f8,(PBYTE)local_2498,local_24b0
                                    ,&local_24b0), BVar6 == 0) {
            DVar7 = GetLastError();
            if (DVar7 == 0x7a) {
              if (local_2498 != (wchar_t *)0x0) {
                LocalFree(local_2498);
              }
              local_2498 = LocalAlloc(0x40,local_24b0);
            }
          }
        }
        CStringT<>(local_24a8,local_2498);
        local_8._0_1_ = 6;
        LocalFree(local_2498);
        iVar11 = 0;
        pwVar10 = L"REV_";
        pCVar5 = FUN_10006300(local_24a8);
        local_24c8 = FUN_10006350(pCVar5,(undefined1 (*) [16])pwVar10,iVar11);
        FUN_10006220(local_24a8,&local_24b4,local_24c8 + 4,4);
        bVar1 = FUN_100061b0(&local_2494,&local_24b4);
        if (bVar1) {
          FUN_101449e8(local_247c);
          local_247c = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0;
          SetupDiDestroyDeviceInfoList(local_248c);
          local_24cc = local_2480;
          FUN_10006410(&local_24b4);
          local_8._0_1_ = 3;
          FUN_10006410((int *)local_24a8);
          local_8._0_1_ = 2;
          FUN_10006410(&local_2484);
          local_8._0_1_ = 1;
          FUN_10006410(&local_2490);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10006410((int *)local_2488);
          local_8 = 0xffffffff;
          FUN_10006410(&local_2494);
          ExceptionList = local_10;
          return local_24cc;
        }
        CloseHandle(local_2480);
        FUN_10006410(&local_24b4);
        local_8._0_1_ = 3;
        FUN_10006410((int *)local_24a8);
      }
      goto LAB_10003cf7;
    }
    FUN_101449e8(local_247c);
    local_247c = (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)0x0;
    local_8._0_1_ = 2;
    FUN_10006410(&local_2484);
    local_8._0_1_ = 1;
    FUN_10006410(&local_2490);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10006410((int *)local_2488);
  } while( true );
}
