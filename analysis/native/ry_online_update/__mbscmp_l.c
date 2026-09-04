/* 101490ab __mbscmp_l [[101490ab, 1014918f]] */

/* Library Function - Single Match
    __mbscmp_l

   Library: Visual Studio 2019 Release */

int __cdecl __mbscmp_l(uchar *_Str1,uchar *_Str2,_locale_t _Locale)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  ushort uVar8;
  uint uVar9;
  bool bVar10;
  int local_14 [2];
  int local_c;
  char local_8;

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_14,(__crt_locale_pointers *)_Locale);
  if ((_Str1 == (uchar *)0x0) || (_Str2 == (uchar *)0x0)) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_1014b2cf();
    uVar5 = 0x7fffffff;
  }
  else {
    uVar5 = 0;
    if (*(int *)(local_c + 8) == 0) {
      do {
        bVar1 = *_Str1;
        bVar10 = bVar1 < *_Str2;
        if (bVar1 != *_Str2) {
LAB_10149111:
          uVar5 = -(uint)bVar10 | 1;
          break;
        }
        if (bVar1 == 0) break;
        bVar1 = _Str1[1];
        bVar10 = bVar1 < _Str2[1];
        if (bVar1 != _Str2[1]) goto LAB_10149111;
        _Str1 = _Str1 + 2;
        _Str2 = _Str2 + 2;
      } while (bVar1 != 0);
    }
    else {
      do {
        bVar1 = *_Str1;
        pbVar4 = _Str1 + 1;
        uVar9 = (uint)bVar1;
        if (((*(byte *)(bVar1 + 0x19 + local_c) & 4) != 0) &&
           (bVar2 = *pbVar4, uVar9 = 0, bVar2 != 0)) {
          pbVar4 = _Str1 + 2;
          uVar9 = (uint)CONCAT11(bVar1,bVar2);
        }
        bVar1 = *_Str2;
        pbVar7 = _Str2 + 1;
        uVar5 = 0;
        uVar6 = (uint)bVar1;
        if (((*(byte *)(bVar1 + 0x19 + local_c) & 4) != 0) &&
           (bVar2 = *pbVar7, uVar6 = uVar5, bVar2 != 0)) {
          pbVar7 = _Str2 + 2;
          uVar6 = (uint)CONCAT11(bVar1,bVar2);
        }
        uVar8 = (ushort)uVar9;
        if ((ushort)uVar6 != uVar8) {
          uVar5 = (-(uint)((ushort)uVar6 < uVar8) & 2) - 1;
          break;
        }
        _Str1 = pbVar4;
        _Str2 = pbVar7;
      } while (uVar8 != 0);
    }
  }
  if (local_8 != '\0') {
    *(uint *)(local_14[0] + 0x350) = *(uint *)(local_14[0] + 0x350) & 0xfffffffd;
  }
  return uVar5;
}
