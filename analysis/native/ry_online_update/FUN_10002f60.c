/* 10002f60 FUN_10002f60 [[10002f60, 10003343]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __thiscall FUN_10002f60(void *this,uchar *param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  undefined **ppuVar4;
  int iVar5;
  errno_t eVar6;
  uchar *puVar7;
  PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData;
  BOOL BVar8;
  undefined4 *DeviceInterfaceDetailDataSize;
  char *pcVar9;
  uint *puVar10;
  undefined1 uVar11;
  code *pcVar12;
  DWORD MemberIndex;
  uchar *_Str;
  PDWORD pDVar13;
  uint *puVar14;
  PSP_DEVICE_INTERFACE_DATA DeviceInfoSet;
  PDWORD *ppDVar15;
  undefined1 local_16c [32];
  _SP_DEVICE_INTERFACE_DATA local_14c;
  GUID local_130;
  PDWORD local_120;
  uchar *local_11c;
  undefined4 local_118;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;

  puStack_c = &LAB_101698e3;
  local_10 = ExceptionList;
  uVar3 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_16c._0_4_ = this;
  local_18 = uVar3;
  ppuVar4 = FUN_1000f8a0();
  if (ppuVar4 == (undefined **)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10002000(-0x7fffbffb);
  }
  iVar5 = (**(code **)(*ppuVar4 + 0xc))(uVar3);
  local_11c = (uchar *)(iVar5 + 0x10);
  local_8 = CONCAT31(local_8._1_3_,1);
  cVar2 = FUN_10008d30(&local_11c,0x101ad0ea);
  if (cVar2 == '\0') {
    FUN_10009140(&local_11c,(uint *)&DAT_101ad0ea,0);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  pcVar12 = CM_Get_Sibling_exref;
  _Str = local_11c;
  do {
    pDVar13 = this;
    iVar5 = CM_Get_Device_IDA(pDVar13,&local_118,0x100,0);
    if (iVar5 == 0) {
      pcVar9 = (char *)&local_118;
      do {
        cVar2 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar2 != '\0');
      FUN_10009140(&local_11c,&local_118,(int)pcVar9 - ((int)&local_118 + 1));
      uVar3 = *(uint *)(local_11c + -0xc);
      if ((int)uVar3 < 0) {
LAB_1000333a:
                    /* WARNING: Subroutine does not return */
        FUN_10002000(-0x7ff8ffa9);
      }
      if ((int)(*(int *)(local_11c + -8) - uVar3 | 1U - *(int *)(local_11c + -4)) < 0) {
        FUN_100090d0(&local_11c,uVar3);
      }
      _Str = local_11c;
      eVar6 = FID_conflict___mbslwr_s(local_11c,uVar3 + 1);
      FUN_10001f40(eVar6);
      if (*(int *)(_Str + -8) < (int)uVar3) goto LAB_1000333a;
      *(uint *)(_Str + -0xc) = uVar3;
      _Str[uVar3] = '\0';
      pcVar12 = CM_Get_Sibling_exref;
      if (((-1 < *(int *)(_Str + -0xc)) &&
          (puVar7 = __mbsstr(_Str,"hid"), pcVar12 = CM_Get_Sibling_exref, puVar7 != (uchar *)0x0))
         && (puVar7 == _Str)) {
        uVar3 = *(uint *)(_Str + -0xc);
        if ((int)uVar3 < 0) goto LAB_1000333a;
        if ((int)(*(int *)(_Str + -8) - uVar3 | 1U - *(int *)(_Str + -4)) < 0) {
          FUN_100090d0(&local_11c,uVar3);
          _Str = local_11c;
        }
        eVar6 = FID_conflict___mbslwr_s(_Str,uVar3 + 1);
        FUN_10001f40(eVar6);
        if (*(int *)(_Str + -8) < (int)uVar3) goto LAB_1000333a;
        *(uint *)(_Str + -0xc) = uVar3;
        _Str[uVar3] = '\0';
        if (param_1 == (uchar *)0x0) {
          iVar5 = -1;
        }
        else if (*(int *)(_Str + -0xc) < 0) {
          iVar5 = -1;
        }
        else {
          puVar7 = __mbsstr(_Str,param_1);
          iVar5 = (int)puVar7 - (int)_Str;
          if (puVar7 == (uchar *)0x0) {
            iVar5 = -1;
          }
        }
        pcVar12 = CM_Get_Sibling_exref;
        if (0 < iVar5) {
          local_16c._4_4_ = 0x1c;
          HidD_GetHidGuid(&local_130);
          DeviceInterfaceData = SetupDiGetClassDevsA(&local_130,(PCSTR)&local_118,(HWND)0x0,0x12);
          MemberIndex = 0;
          do {
            local_14c.cbSize = 0x1c;
            BVar8 = SetupDiEnumDeviceInterfaces
                              (DeviceInterfaceData,(PSP_DEVINFO_DATA)0x0,&local_130,MemberIndex,
                               &local_14c);
            MemberIndex = MemberIndex + 1;
            local_16c._0_4_ = (PDWORD)0x0;
            DeviceInfoSet = DeviceInterfaceData;
            SetupDiGetDeviceInterfaceDetailA
                      (DeviceInterfaceData,&local_14c,(PSP_DEVICE_INTERFACE_DETAIL_DATA_A)0x0,0,
                       (PDWORD)local_16c,(PSP_DEVINFO_DATA)(local_16c + 4));
            DeviceInterfaceDetailDataSize = (undefined4 *)FUN_10150a71(local_16c._0_4_);
            ppDVar15 = (PDWORD *)(local_16c + 4);
            *DeviceInterfaceDetailDataSize = 5;
            SetupDiGetDeviceInterfaceDetailA
                      (DeviceInfoSet,DeviceInterfaceData,
                       (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)&local_14c,
                       (DWORD)DeviceInterfaceDetailDataSize,(PDWORD)local_16c._0_4_,
                       (PSP_DEVINFO_DATA)local_16c);
            puVar14 = DeviceInterfaceDetailDataSize + 1;
            if (puVar14 == (uint *)0x0) {
              uVar3 = 0;
            }
            else {
              puVar10 = puVar14;
              do {
                uVar3 = *puVar10;
                puVar10 = (uint *)((int)puVar10 + 1);
              } while ((char)uVar3 != '\0');
              uVar3 = (int)puVar10 - ((int)DeviceInterfaceDetailDataSize + 5);
            }
            FUN_10009140(&DAT_101d2838,puVar14,uVar3);
          } while (BVar8 == 1);
          SetupDiDestroyDeviceInfoList(DeviceInterfaceData);
          uVar11 = 1;
          _Str = local_11c;
LAB_100032d5:
          local_8 = local_8 & 0xffffff00;
          LOCK();
          piVar1 = (int *)(_Str + -4);
          iVar5 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar5 == 1 || iVar5 + -1 < 0) {
            (**(code **)(**(int **)(_Str + -0x10) + 4))(_Str + -0x10,ppDVar15);
          }
          local_8 = 0xffffffff;
          LOCK();
          piVar1 = (int *)(param_1 + -4);
          iVar5 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar5 == 1 || iVar5 + -1 < 0) {
            (**(code **)(**(int **)(param_1 + -0x10) + 4))(param_1 + -0x10);
          }
          ExceptionList = local_10;
          return uVar11;
        }
      }
    }
    iVar5 = CM_Get_Child(&local_120,pDVar13,0);
    this = local_120;
    if (iVar5 != 0) {
      iVar5 = (*pcVar12)(&local_120,pDVar13,0);
      while (this = local_120, iVar5 != 0) {
        ppDVar15 = &local_120;
        iVar5 = CM_Get_Parent(ppDVar15,pDVar13,0);
        pDVar13 = local_120;
        if ((iVar5 != 0) || (local_120 == (PDWORD)local_16c._0_4_)) {
          uVar11 = 0;
          goto LAB_100032d5;
        }
        iVar5 = (*pcVar12)(&local_120,local_120,0);
      }
    }
  } while( true );
}
