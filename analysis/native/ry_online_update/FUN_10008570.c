/* 10008570 FUN_10008570 [[10008570, 1000861f]] */

int __thiscall FUN_10008570(void *this,uchar param_1)

{
  uchar *puVar1;
  uchar *puVar2;
  uint uVar3;
  uchar *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uchar *_Ptr;
  uchar *puVar8;

  puVar8 = *(uchar **)this;
  uVar3 = *(uint *)(puVar8 + -0xc);
  if (-1 < (int)uVar3) {
    if ((int)(1U - *(int *)(puVar8 + -4) | *(int *)(puVar8 + -8) - uVar3) < 0) {
      FUN_100090d0(this,uVar3);
      puVar8 = *(uchar **)this;
    }
    puVar1 = puVar8 + uVar3;
    puVar4 = puVar8;
    while (_Ptr = puVar4, _Ptr < puVar1) {
      puVar4 = __mbsinc(_Ptr);
      if (*_Ptr != param_1) {
        uVar6 = (int)puVar4 - (int)_Ptr;
        puVar2 = puVar8 + uVar6;
        for (uVar5 = 0; (puVar8 != puVar2 && (uVar5 < uVar6)); uVar5 = uVar5 + 1) {
          *puVar8 = *_Ptr;
          _Ptr = _Ptr + 1;
          puVar8 = puVar8 + 1;
        }
      }
    }
    *puVar8 = '\0';
    iVar7 = uVar3 - ((int)_Ptr - (int)puVar8);
    if ((-1 < iVar7) && (iVar7 <= *(int *)(*(int *)this + -8))) {
      *(int *)(*(int *)this + -0xc) = iVar7;
      *(undefined1 *)(iVar7 + *(int *)this) = 0;
      return (int)_Ptr - (int)puVar8;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_10002000(-0x7ff8ffa9);
}
