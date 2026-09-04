/* 10008630 FUN_10008630 [[10008630, 1000869c] [100086a0, 10008852]] */

int __thiscall FUN_10008630(void *this,uchar *param_1,uint *param_2)

{
  uchar uVar1;
  uint uVar2;
  uchar *puVar3;
  uchar *puVar4;
  uint *puVar5;
  uint *puVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  uchar *puVar11;
  int iVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  uint *_Str;
  int local_18;

  if (param_1 != (uchar *)0x0) {
    puVar11 = param_1;
    do {
      uVar1 = *puVar11;
      puVar11 = puVar11 + 1;
    } while (uVar1 != '\0');
    iVar12 = (int)puVar11 - (int)(param_1 + 1);
    if (iVar12 != 0) {
      if (param_2 == (uint *)0x0) {
        uVar15 = 0;
      }
      else {
        puVar14 = param_2;
        do {
          uVar15 = *puVar14;
          puVar14 = (uint *)((int)puVar14 + 1);
        } while ((char)uVar15 != '\0');
        uVar15 = (int)puVar14 - ((int)param_2 + 1);
      }
      puVar11 = *(uchar **)this;
      local_18 = 0;
      puVar3 = puVar11 + *(int *)(puVar11 + -0xc);
      if (puVar11 < puVar3) {
        iVar16 = 0;
        do {
          puVar4 = __mbsstr(puVar11,param_1);
          while (puVar4 != (uchar *)0x0) {
            puVar11 = puVar4 + iVar12;
            iVar16 = iVar16 + 1;
            puVar4 = __mbsstr(puVar11,param_1);
            local_18 = iVar16;
          }
          if (puVar11 == (uchar *)0x0) {
            iVar9 = 0;
          }
          else {
            puVar4 = puVar11;
            do {
              uVar1 = *puVar4;
              puVar4 = puVar4 + 1;
            } while (uVar1 != '\0');
            iVar9 = (int)puVar4 - (int)(puVar11 + 1);
          }
          puVar11 = puVar11 + iVar9 + 1;
        } while (puVar11 < puVar3);
        if (0 < iVar16) {
          puVar14 = *(uint **)this;
          uVar2 = puVar14[-3];
          uVar10 = (uVar15 - iVar12) * local_18 + uVar2;
          uVar13 = uVar2;
          if ((int)uVar2 < (int)uVar10) {
            uVar13 = uVar10;
          }
          if (-1 < (int)uVar13) {
            if ((int)(1 - puVar14[-1] | puVar14[-2] - uVar13) < 0) {
              FUN_100090d0(this,uVar13);
              puVar14 = *(uint **)this;
            }
            puVar5 = (uint *)((int)puVar14 + uVar2);
            for (_Str = puVar14; _Str < puVar5; _Str = (uint *)((int)_Str + iVar16 + 1)) {
              puVar6 = (uint *)__mbsstr((uchar *)_Str,param_1);
              while (puVar6 != (uint *)0x0) {
                _Str = (uint *)((int)puVar6 + uVar15);
                uVar13 = (int)puVar14 + uVar2 + (-iVar12 - (int)puVar6);
                if (uVar13 == 0) {
LAB_100087af:
                  uVar8 = 0;
                }
                else {
                  if ((_Str != (uint *)0x0) && ((uint *)((int)puVar6 + iVar12) != (uint *)0x0)) {
                    FUN_10145db0(_Str,(uint *)((int)puVar6 + iVar12),uVar13);
                    goto LAB_100087af;
                  }
                  piVar7 = __errno();
                  *piVar7 = 0x16;
                  FUN_1014b2cf();
                  uVar8 = 0x16;
                }
                FUN_10001f40(uVar8);
                uVar8 = FUN_10001e00(puVar6,uVar15,param_2,uVar15);
                FUN_10001f40(uVar8);
                *(undefined1 *)((int)puVar6 + uVar15 + uVar13) = 0;
                uVar2 = uVar2 + (uVar15 - iVar12);
                puVar6 = (uint *)__mbsstr((uchar *)_Str,param_1);
              }
              if (_Str == (uint *)0x0) {
                iVar16 = 0;
              }
              else {
                puVar6 = _Str;
                do {
                  uVar13 = *puVar6;
                  puVar6 = (uint *)((int)puVar6 + 1);
                } while ((char)uVar13 != '\0');
                iVar16 = (int)puVar6 - ((int)_Str + 1);
              }
            }
            if ((-1 < (int)uVar10) && ((int)uVar10 <= *(int *)(*(int *)this + -8))) {
              *(uint *)(*(int *)this + -0xc) = uVar10;
              *(undefined1 *)(uVar10 + *(int *)this) = 0;
              return local_18;
            }
          }
                    /* WARNING: Subroutine does not return */
          FUN_10002000(-0x7ff8ffa9);
        }
      }
      return local_18;
    }
  }
  return 0;
}
