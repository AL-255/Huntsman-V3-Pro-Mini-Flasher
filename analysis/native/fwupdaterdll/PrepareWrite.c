/* 10006920 PrepareWrite [[10006920, 1000697c]] */

/* Library Function - Single Match
    private: char * __thiscall ATL::CSimpleStringT<char,0>::PrepareWrite(int)

   Library: Visual Studio 2010 Debug */

char * __thiscall
ATL::CSimpleStringT<char,0>::PrepareWrite(CSimpleStringT<char,0> *this,int param_1)

{
  int iVar1;

  if (param_1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001f10(-0x7ff8ffa9);
  }
  iVar1 = FUN_10006980((int *)this);
  if ((int)(1U - *(int *)(iVar1 + 0xc) | *(int *)(iVar1 + 8) - param_1) < 0) {
    PrepareWrite2(this,param_1);
  }
  return *(char **)this;
}
