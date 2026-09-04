/* 1014b787 __mbschr_l [[1014b787, 1014b823]] */

/* Library Function - Single Match
    __mbschr_l

   Library: Visual Studio 2019 Release */

uchar * __cdecl __mbschr_l(uchar *_Str,uint _Ch,_locale_t _Locale)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  int local_14 [2];
  int local_c;
  char local_8;

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_14,(__crt_locale_pointers *)_Locale);
  if (_Str == (uchar *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_1014b2cf();
    puVar5 = (uint *)0x0;
  }
  else {
    puVar5 = (uint *)0x0;
    if (*(int *)(local_c + 8) == 0) {
      puVar5 = FUN_10145c80((uint *)_Str,(char)_Ch);
    }
    else {
      while( true ) {
        bVar1 = (byte)*(uint *)_Str;
        uVar3 = (uint)bVar1;
        if (bVar1 == 0) break;
        if ((*(byte *)(uVar3 + 0x19 + local_c) & 4) == 0) {
          puVar4 = (uint *)_Str;
          if (_Ch == uVar3) break;
        }
        else {
          puVar4 = (uint *)((int)_Str + 1);
          if (*(byte *)puVar4 == 0) goto LAB_1014b80b;
          if (_Ch == CONCAT11(bVar1,*(byte *)puVar4)) goto LAB_1014b80d;
        }
        _Str = (uchar *)((int)puVar4 + 1);
      }
      if (_Ch == uVar3) goto LAB_1014b80d;
    }
  }
LAB_1014b80b:
  _Str = (uchar *)puVar5;
LAB_1014b80d:
  if (local_8 != '\0') {
    *(uint *)(local_14[0] + 0x350) = *(uint *)(local_14[0] + 0x350) & 0xfffffffd;
  }
  return (uchar *)(uint *)_Str;
}
