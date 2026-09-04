/* 10150982 __mbsstr_l [[10150982, 10150a70]] */

/* Library Function - Single Match
    __mbsstr_l

   Library: Visual Studio 2019 Release */

uchar * __cdecl __mbsstr_l(uchar *_Str,uchar *_Substr,_locale_t _Locale)

{
  uchar uVar1;
  byte bVar2;
  undefined1 (*pauVar3) [16];
  int *piVar4;
  uchar *puVar5;
  undefined1 (*pauVar6) [16];
  uchar *puVar7;
  int iVar8;
  int iVar9;
  undefined1 (*pauVar10) [16];
  uchar *puVar11;
  int local_1c [2];
  int local_14;
  char local_10;

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_1c,(__crt_locale_pointers *)_Locale);
  pauVar10 = (undefined1 (*) [16])0x0;
  if (*(int *)(local_14 + 8) == 0) {
    pauVar3 = FUN_10169210((undefined1 (*) [16])_Str,(undefined1 (*) [16])_Substr);
    goto LAB_10150a5a;
  }
  if (_Substr != (uchar *)0x0) {
    pauVar3 = (undefined1 (*) [16])_Str;
    if (*_Substr == '\0') goto LAB_10150a5a;
    puVar7 = _Str;
    if (_Str != (uchar *)0x0) {
      do {
        puVar11 = puVar7;
        puVar7 = puVar11 + 1;
      } while (*puVar11 != '\0');
      puVar7 = _Substr;
      do {
        uVar1 = *puVar7;
        puVar7 = puVar7 + 1;
      } while (uVar1 != '\0');
      pauVar3 = pauVar10;
      if (*_Str != '\0') {
        iVar8 = (int)_Str - (int)_Substr;
        while (pauVar3 = pauVar10,
              _Str <= (undefined1 (*) [16])(puVar11 + -((int)puVar7 - (int)(_Substr + 1)))) {
          puVar5 = _Substr;
          bVar2 = (*(undefined1 (*) [16])_Str)[0];
          while (pauVar3 = (undefined1 (*) [16])_Str, bVar2 != 0) {
            if (*puVar5 == '\0') goto LAB_10150a5a;
            if (puVar5[iVar8] != *puVar5) break;
            puVar5 = puVar5 + 1;
            bVar2 = puVar5[iVar8];
          }
          if (*puVar5 == '\0') break;
          pauVar6 = (undefined1 (*) [16])(*(undefined1 (*) [16])_Str + 1);
          iVar9 = iVar8 + 1;
          if ((*(byte *)((byte)(*(undefined1 (*) [16])_Str)[0] + 0x19 + local_14) & 4) != 0) {
            pauVar3 = pauVar10;
            if ((*pauVar6)[0] == '\0') break;
            pauVar6 = (undefined1 (*) [16])(*(undefined1 (*) [16])_Str + 2);
            iVar9 = iVar8 + 2;
          }
          _Str = (uchar *)pauVar6;
          iVar8 = iVar9;
          pauVar3 = pauVar10;
          if ((*pauVar6)[0] == '\0') break;
        }
      }
      goto LAB_10150a5a;
    }
  }
  piVar4 = __errno();
  *piVar4 = 0x16;
  FUN_1014b2cf();
  pauVar3 = pauVar10;
LAB_10150a5a:
  if (local_10 != '\0') {
    *(uint *)(local_1c[0] + 0x350) = *(uint *)(local_1c[0] + 0x350) & 0xfffffffd;
  }
  return (uchar *)pauVar3;
}
