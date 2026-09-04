/* 101498fc common_fseek_nolock [[101498fc, 101499d9]] */

/* Library Function - Single Match
    int __cdecl common_fseek_nolock(class __crt_stdio_stream,__int64,int)

   Library: Visual Studio 2019 Release */

int __cdecl common_fseek_nolock(FILE *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  int *piVar2;
  int unaff_EDI;
  __int64 _Var3;
  longlong lVar4;

  if (((uint)param_1->_flag >> 0xd & 1) == 0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    return -1;
  }
  LOCK();
  param_1->_flag = param_1->_flag & 0xfffffff7;
  UNLOCK();
  lVar4 = CONCAT44(param_3,param_2);
  bVar1 = common_fseek_binary_mode_read_only_fast_track_nolock(param_1,param_2,param_3,param_4);
  if (!bVar1) {
    if (param_4 == 1) {
      _Var3 = FUN_10148fb0();
      lVar4 = _Var3 + lVar4;
      param_4 = 0;
    }
    ___acrt_stdio_flush_nolock(param_1);
    param_1->_base = (char *)0x0;
    param_1->_ptr = (char *)param_1->_cnt;
    if (((uint)param_1->_flag >> 2 & 1) == 0) {
      if ((((byte)param_1->_flag & 0x41) == 0x41) && (((uint)param_1->_flag >> 8 & 1) == 0)) {
        param_1->_bufsiz = 0x200;
      }
    }
    else {
      LOCK();
      param_1->_flag = param_1->_flag & 0xfffffffc;
      UNLOCK();
    }
    lVar4 = __lseeki64_nolock(param_1->_file,CONCAT44(param_4,(int)((ulonglong)lVar4 >> 0x20)),
                              unaff_EDI);
    if (lVar4 == -1) {
      return -1;
    }
  }
  return 0;
}
