/* 10008d30 FUN_10008d30 [[10008d30, 10008e50]] */

undefined1 __thiscall FUN_10008d30(void *this,uint param_1)

{
  ushort *puVar1;
  HMODULE hModule;
  HRSRC hResInfo;
  HGLOBAL hResData;
  ushort *puVar2;
  DWORD DVar3;
  undefined1 uVar4;
  LPSTR lpMultiByteStr;
  uint uVar5;

  uVar4 = 0;
  if ((param_1 != 0) && ((param_1 & 0xffff0000) == 0)) {
    hModule = (HMODULE)FUN_1000fe18();
    if ((hModule != (HMODULE)0x0) &&
       (((hResInfo = FindResourceW(hModule,(LPCWSTR)(((param_1 & 0xffff) >> 4) + 1),(LPCWSTR)0x6),
         hResInfo != (HRSRC)0x0 &&
         (hResData = LoadResource(hModule,hResInfo), hResData != (HGLOBAL)0x0)) &&
        (puVar2 = LockResource(hResData), puVar2 != (ushort *)0x0)))) {
      DVar3 = SizeofResource(hModule,hResInfo);
      puVar1 = (ushort *)((int)puVar2 + DVar3);
      for (uVar5 = param_1 & 0xf; uVar5 != 0; uVar5 = uVar5 - 1) {
        if (puVar1 <= puVar2) goto LAB_10008e3b;
        puVar2 = puVar2 + *puVar2 + 1;
      }
      if ((puVar2 < puVar1) && (*puVar2 != 0)) {
        uVar5 = WideCharToMultiByte(3,0,(LPCWSTR)(puVar2 + 1),(uint)*puVar2,(LPSTR)0x0,0,(LPCSTR)0x0
                                    ,(LPBOOL)0x0);
        if ((int)uVar5 < 0) {
LAB_10008e47:
                    /* WARNING: Subroutine does not return */
          FUN_10002000(-0x7ff8ffa9);
        }
        lpMultiByteStr = *(LPSTR *)this;
        if ((int)(1U - *(int *)(lpMultiByteStr + -4) | *(int *)(lpMultiByteStr + -8) - uVar5) < 0) {
          FUN_100090d0(this,uVar5);
          lpMultiByteStr = *(LPSTR *)this;
        }
        WideCharToMultiByte(3,0,(LPCWSTR)(puVar2 + 1),(uint)*puVar2,lpMultiByteStr,uVar5,(LPCSTR)0x0
                            ,(LPBOOL)0x0);
        if (*(int *)(*(int *)this + -8) < (int)uVar5) goto LAB_10008e47;
        *(uint *)(*(int *)this + -0xc) = uVar5;
        *(undefined1 *)(uVar5 + *(int *)this) = 0;
      }
    }
LAB_10008e3b:
    uVar4 = 1;
  }
  return uVar4;
}
