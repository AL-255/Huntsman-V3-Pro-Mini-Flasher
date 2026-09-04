/* 1014b66f __mbsupr_s_l [[1014b66f, 1014b76f]] */

/* Library Function - Single Match
    __mbsupr_s_l

   Library: Visual Studio 2019 Release */

errno_t __cdecl __mbsupr_s_l(uchar *_Str,size_t _SizeInBytes,_locale_t _Locale)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  errno_t eVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  int local_1c;
  __crt_locale_pointers local_18 [4];
  int local_14;
  char local_10;
  uint local_c;
  undefined4 local_8;

  if (_Str == (uchar *)0x0) {
    if (_SizeInBytes != 0) goto LAB_1014b696;
  }
  else if (_SizeInBytes == 0) goto LAB_1014b696;
  if (_Str == (uchar *)0x0) {
    return 0;
  }
  uVar4 = FUN_1014b9c9((undefined1 (*) [32])_Str,_SizeInBytes);
  if (uVar4 < _SizeInBytes) {
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_1c,(__crt_locale_pointers *)_Locale);
    bVar2 = *_Str;
    pbVar8 = _Str;
    pbVar9 = _Str;
    iVar7 = local_14;
    do {
      if (bVar2 == 0) {
        eVar6 = 0;
        *pbVar9 = 0;
LAB_1014b744:
        if (local_10 == '\0') {
          return eVar6;
        }
        *(uint *)(local_1c + 0x350) = *(uint *)(local_1c + 0x350) & 0xfffffffd;
        return eVar6;
      }
      local_c = (uint)bVar2;
      bVar1 = *(byte *)(local_c + 0x19 + iVar7);
      if ((bVar1 & 4) == 0) {
        if ((bVar1 & 0x20) != 0) {
          bVar2 = *(byte *)(local_c + 0x119 + iVar7);
        }
        *pbVar9 = bVar2;
LAB_1014b738:
        pbVar9 = pbVar9 + 1;
      }
      else {
        iVar5 = ___acrt_LCMapStringA
                          (local_18,*(wchar_t **)(iVar7 + 0x21c),0x200,(char *)pbVar8,2,
                           (char *)&local_8,2,*(int *)(iVar7 + 4),1);
        if (iVar5 == 0) {
          piVar3 = __errno();
          *piVar3 = 0x2a;
          *_Str = '\0';
          piVar3 = __errno();
          eVar6 = *piVar3;
          goto LAB_1014b744;
        }
        *pbVar9 = (byte)local_8;
        pbVar9 = pbVar9 + 1;
        pbVar8 = pbVar8 + 1;
        iVar7 = local_14;
        if (1 < iVar5) {
          *pbVar9 = (byte)((uint)local_8 >> 8);
          goto LAB_1014b738;
        }
      }
      pbVar8 = pbVar8 + 1;
      bVar2 = *pbVar8;
    } while( true );
  }
  *_Str = '\0';
LAB_1014b696:
  piVar3 = __errno();
  *piVar3 = 0x16;
  FUN_1014b2cf();
  return 0x16;
}
