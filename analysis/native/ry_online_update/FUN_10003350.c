/* 10003350 FUN_10003350 [[10003350, 10003910]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __cdecl FUN_10003350(uint *param_1,uchar *param_2)

{
  void *this;
  char cVar1;
  undefined **ppuVar2;
  int iVar3;
  int *piVar4;
  uchar *puVar5;
  PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_A DeviceInterfaceDetailData;
  BOOL BVar6;
  uchar *puVar7;
  HANDLE hObject;
  uint *puVar8;
  int iVar9;
  undefined4 *puVar10;
  uint *puVar11;
  uint uVar12;
  CHAR *pCVar13;
  undefined1 uVar14;
  DWORD MemberIndex;
  CHAR *in_stack_ffffff40;
  CHAR *lpFileName;
  HANDLE local_78;
  char local_71;
  undefined1 local_70 [24];
  ULONG_PTR local_58;
  _SP_DEVICE_INTERFACE_DATA local_50;
  GUID local_34;
  uchar *local_24;
  uchar *local_20;
  void *local_1c;
  uchar *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_10169955;
  local_10 = ExceptionList;
  local_14 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  ppuVar2 = FUN_1000f8a0();
  if (ppuVar2 == (undefined **)0x0) {
LAB_100038fd:
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar3 = (**(code **)(*ppuVar2 + 0xc))();
  local_24 = (uchar *)(iVar3 + 0x10);
  local_8._0_1_ = 2;
  ppuVar2 = FUN_1000f8a0();
  if (ppuVar2 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar3 = (**(code **)(*ppuVar2 + 0xc))();
  local_20 = (uchar *)(iVar3 + 0x10);
  local_8._0_1_ = 3;
  if ((int)param_1[-3] < 0) {
    iVar3 = -1;
  }
  else {
    puVar5 = __mbsstr((uchar *)param_1,"vid_");
    iVar3 = (int)puVar5 - (int)param_1;
    if (puVar5 == (uchar *)0x0) {
      iVar3 = -1;
    }
  }
  piVar4 = FUN_100082e0(&param_1,(int *)&local_78,iVar3 + 4,4);
  local_8._0_1_ = 4;
  FUN_10008860(&local_24,piVar4);
  local_8 = CONCAT31(local_8._1_3_,3);
  LOCK();
  piVar4 = (int *)((int)local_78 + -4);
  iVar3 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar3 == 1 || iVar3 + -1 < 0) {
    (**(code **)(**(int **)((int)local_78 + -0x10) + 4))();
  }
  if ((int)param_1[-3] < 0) {
    iVar3 = -1;
  }
  else {
    puVar5 = __mbsstr((uchar *)param_1,"pid_");
    iVar3 = (int)puVar5 - (int)param_1;
    if (puVar5 == (uchar *)0x0) {
      iVar3 = -1;
    }
  }
  piVar4 = FUN_100082e0(&param_1,(int *)&local_78,iVar3 + 4,4);
  local_8._0_1_ = 5;
  FUN_10008860(&local_20,piVar4);
  local_8._0_1_ = 3;
  LOCK();
  piVar4 = (int *)((int)local_78 + -4);
  iVar3 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar3 == 1 || iVar3 + -1 < 0) {
    (**(code **)(**(int **)((int)local_78 + -0x10) + 4))();
  }
  local_70._4_4_ = 0x1c;
  local_50.cbSize = 0x1c;
  HidD_GetHidGuid();
  DeviceInterfaceData = SetupDiGetClassDevsA(&local_34,(PCSTR)0x0,(HWND)0x0,0x12);
  MemberIndex = 0;
  iVar3 = SetupDiEnumDeviceInterfaces
                    (DeviceInterfaceData,(PSP_DEVINFO_DATA)0x0,&local_34,0,&local_50);
  puVar5 = local_24;
  while (iVar3 != 0) {
    MemberIndex = MemberIndex + 1;
    SetupDiGetDeviceInterfaceDetailA
              (in_stack_ffffff40,DeviceInterfaceData,(PSP_DEVICE_INTERFACE_DETAIL_DATA_A)&local_50,0
               ,(PDWORD)0x0,(PSP_DEVINFO_DATA)local_70);
    DeviceInterfaceDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)FUN_10150a71(local_70._0_4_);
    if (DeviceInterfaceDetailData == (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)0x0) break;
    DeviceInterfaceDetailData->cbSize = 5;
    in_stack_ffffff40 = (CHAR *)0x10003528;
    BVar6 = SetupDiGetDeviceInterfaceDetailA
                      (DeviceInterfaceData,&local_50,DeviceInterfaceDetailData,local_70._0_4_,
                       (PDWORD)0x0,(PSP_DEVINFO_DATA)(local_70 + 4));
    lpFileName = DeviceInterfaceDetailData->DevicePath;
    if (lpFileName == (CHAR *)0x0) {
      uVar12 = 0;
    }
    else {
      pCVar13 = lpFileName;
      do {
        cVar1 = *pCVar13;
        pCVar13 = pCVar13 + 1;
      } while (cVar1 != '\0');
      uVar12 = (int)pCVar13 - (int)(DeviceInterfaceDetailData + 1);
    }
    FUN_10009140(&DAT_101d2838,(uint *)lpFileName,uVar12);
    if (local_71 == '\0') {
      FUN_1014b9ae(DeviceInterfaceDetailData);
      if ((((BVar6 != 0) && (param_1 != (uint *)0x0)) && (-1 < *(int *)(DAT_101d2838 + -0xc))) &&
         ((puVar7 = __mbsstr(DAT_101d2838,(uchar *)param_1), puVar7 != (uchar *)0x0 &&
          (0 < (int)puVar7 - (int)DAT_101d2838)))) {
LAB_100038e8:
        SetupDiDestroyDeviceInfoList(DeviceInterfaceData);
        uVar14 = 1;
        goto LAB_10003821;
      }
    }
    else {
      if ((((puVar5 != (uchar *)0x0) &&
           ((-1 < *(int *)(DAT_101d2838 + -0xc) &&
            (puVar7 = __mbsstr(DAT_101d2838,puVar5), puVar7 != (uchar *)0x0)))) &&
          (puVar7 != DAT_101d2838 && -1 < (int)puVar7 - (int)DAT_101d2838)) &&
         ((((local_20 != (uchar *)0x0 && (-1 < *(int *)(DAT_101d2838 + -0xc))) &&
           (puVar7 = __mbsstr(DAT_101d2838,local_20), puVar7 != (uchar *)0x0)) &&
          (((0 < (int)puVar7 - (int)DAT_101d2838 &&
            (hObject = CreateFileA(lpFileName,0,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0),
            in_stack_ffffff40 = lpFileName, local_78 = hObject, hObject != (HANDLE)0xffffffff)) &&
           (hObject != (HANDLE)0x0)))))) {
        iVar3 = FUN_10002cb0(hObject);
        if (iVar3 != 0) {
          puVar8 = (uint *)FUN_1000f514(0x16);
          iVar3 = FUN_10002d30(hObject,puVar8);
          ppuVar2 = FUN_1000f8a0();
          if (ppuVar2 == (undefined **)0x0) goto LAB_100038fd;
          iVar9 = (**(code **)(*ppuVar2 + 0xc))();
          local_18 = (uchar *)(iVar9 + 0x10);
          local_8 = CONCAT31(local_8._1_3_,6);
          cVar1 = FUN_10008d30(&local_18,(uint)puVar8);
          if (cVar1 == '\0') {
            if (puVar8 == (uint *)0x0) {
              uVar12 = 0;
            }
            else {
              puVar11 = puVar8;
              do {
                uVar12 = *puVar11;
                puVar11 = (uint *)((int)puVar11 + 1);
              } while ((char)uVar12 != '\0');
              uVar12 = (int)puVar11 - ((int)puVar8 + 1);
            }
            FUN_10009140(&local_18,puVar8,uVar12);
          }
          local_8._0_1_ = 7;
          FUN_1014b9ae(puVar8);
          puVar7 = local_18;
          if (iVar3 != 2) {
            CloseHandle(hObject);
            FUN_1014b9ae(DeviceInterfaceDetailData);
            local_8._0_1_ = 3;
            LOCK();
            piVar4 = (int *)(local_18 + -4);
            iVar3 = *piVar4;
            *piVar4 = *piVar4 + -1;
            UNLOCK();
            in_stack_ffffff40 = lpFileName;
            if (iVar3 == 1 || iVar3 + -1 < 0) {
              (**(code **)(**(int **)(local_18 + -0x10) + 4))();
              in_stack_ffffff40 = lpFileName;
            }
            goto LAB_100037f5;
          }
          if (param_2 == (uchar *)0x0) goto LAB_100038fd;
          iVar3 = __mbscmp(local_18,param_2);
          if (((iVar3 == 0) && (iVar3 = CM_Get_Parent(&local_1c,local_58), iVar3 == 0)) &&
             (iVar3 = CM_Get_Parent(&local_1c,local_1c), this = local_1c, puVar8 = param_1,
             iVar3 == 0)) {
            puVar11 = param_1 + -4;
            puVar10 = (undefined4 *)(**(code **)(*(int *)*puVar11 + 0x10))();
            if (((int)puVar8[-1] < 0) || (puVar10 != (undefined4 *)*puVar11)) {
              puVar11 = (uint *)(**(code **)*puVar10)(puVar8[-3],1);
              if (puVar11 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
                FUN_10009130();
              }
              puVar11[1] = puVar8[-3];
              FUN_10001e00(puVar11 + 4,puVar8[-3] + 1,puVar8,puVar8[-3] + 1);
            }
            else {
              LOCK();
              puVar8[-1] = puVar8[-1] + 1;
              UNLOCK();
            }
            cVar1 = FUN_10002f60(this,(uchar *)(puVar11 + 4));
            hObject = local_78;
            if (cVar1 != '\0') {
              CloseHandle(local_78);
              FUN_1014b9ae(DeviceInterfaceDetailData);
              local_8._0_1_ = 3;
              LOCK();
              piVar4 = (int *)(puVar7 + -4);
              iVar3 = *piVar4;
              *piVar4 = *piVar4 + -1;
              UNLOCK();
              if (iVar3 == 1 || iVar3 + -1 < 0) {
                (**(code **)(**(int **)(puVar7 + -0x10) + 4))();
              }
              goto LAB_100038e8;
            }
          }
          local_8._0_1_ = 3;
          LOCK();
          piVar4 = (int *)(puVar7 + -4);
          iVar3 = *piVar4;
          *piVar4 = *piVar4 + -1;
          UNLOCK();
          if (iVar3 == 1 || iVar3 + -1 < 0) {
            (**(code **)(**(int **)(puVar7 + -0x10) + 4))();
          }
        }
        CloseHandle(hObject);
        in_stack_ffffff40 = lpFileName;
      }
      FUN_1014b9ae(DeviceInterfaceDetailData);
    }
LAB_100037f5:
    iVar3 = SetupDiEnumDeviceInterfaces
                      (DeviceInterfaceData,(PSP_DEVINFO_DATA)0x0,&local_34,MemberIndex,&local_50);
  }
  SetupDiDestroyDeviceInfoList(DeviceInterfaceData);
  uVar14 = 0;
LAB_10003821:
  local_8._0_1_ = 2;
  LOCK();
  piVar4 = (int *)(local_20 + -4);
  iVar3 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar3 == 1 || iVar3 + -1 < 0) {
    (**(code **)(**(int **)(local_20 + -0x10) + 4))();
  }
  local_8._0_1_ = 1;
  LOCK();
  piVar4 = (int *)(puVar5 + -4);
  iVar3 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar3 == 1 || iVar3 + -1 < 0) {
    (**(code **)(**(int **)(puVar5 + -0x10) + 4))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  LOCK();
  puVar8 = param_1 + -1;
  uVar12 = *puVar8;
  *puVar8 = *puVar8 - 1;
  UNLOCK();
  if (uVar12 == 1 || (int)(uVar12 - 1) < 0) {
    (**(code **)(*(int *)param_1[-4] + 4))();
  }
  local_8 = 0xffffffff;
  LOCK();
  piVar4 = (int *)(param_2 + -4);
  iVar3 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar3 == 1 || iVar3 + -1 < 0) {
    (**(code **)(**(int **)(param_2 + -0x10) + 4))();
  }
  ExceptionList = local_10;
  return uVar14;
}
