/* 100032c0 OpenDevice [[100032c0, 10003357]] */

HANDLE __cdecl
OpenDevice(undefined4 param_1,undefined4 param_2,short param_3,float param_4,uint param_5,
          uint param_6,uint param_7,uint param_8,undefined4 param_9)

{
  ushort *puVar1;
  ushort *puVar2;
  HANDLE pvVar3;
  int local_c;
  int local_8;

                    /* 0x32c0  31  OpenDevice */
  CStringT<>(&local_c);
  CStringT<>(&local_8);
  FUN_10007120(&local_c,L"%04X");
  FUN_10007120(&local_8,L"%04X");
  puVar1 = (ushort *)FUN_100065b0(&local_8);
  puVar2 = (ushort *)FUN_100065b0(&local_c);
  pvVar3 = FUN_10003380(puVar2,puVar1,param_3,param_9,param_4,param_5,param_6,param_7,param_8);
  FUN_10006410(&local_8);
  FUN_10006410(&local_c);
  return pvVar3;
}
