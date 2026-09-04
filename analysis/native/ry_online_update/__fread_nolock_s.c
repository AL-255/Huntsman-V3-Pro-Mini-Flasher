/* 1014bdc3 __fread_nolock_s [[1014bdc3, 1014bfa8]] */

/* Library Function - Single Match
    __fread_nolock_s

   Library: Visual Studio 2019 Release */

size_t __cdecl
__fread_nolock_s(void *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File)

{
  undefined1 *_Dst;
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 *_DstBuf_00;
  char *local_14;
  char *local_c;

  if ((_ElementSize != 0) && (_Count != 0)) {
    if (_DstBuf != (void *)0x0) {
      if ((_File != (FILE *)0x0) && (_Count <= (uint)(0xffffffff / (ulonglong)_ElementSize))) {
LAB_1014be32:
        piVar1 = &_File->_flag;
        if ((*piVar1 & 0x4c0U) == 0) {
          local_14 = (char *)0x1000;
        }
        else {
          local_14 = (char *)_File->_bufsiz;
        }
        pcVar3 = (char *)(_ElementSize * _Count);
        _Dst = _DstBuf;
        local_c = (char *)_DstSize;
        do {
          if (pcVar3 == (char *)0x0) {
            return _Count;
          }
          if ((_File->_flag & 0x4c0U) == 0) {
LAB_1014bec3:
            if (pcVar3 < local_14) {
              iVar2 = FUN_1015c0a7();
              if (iVar2 == -1) goto code_r0x1014bf85;
              if (local_c == (char *)0x0) goto LAB_1014bf59;
              *_Dst = (char)iVar2;
              local_14 = (char *)_File->_bufsiz;
              pcVar3 = pcVar3 + -1;
              local_c = local_c + -1;
              pcVar4 = (char *)0x1;
            }
            else {
              pcVar4 = pcVar3;
              if ((char *)0x7fffffff < pcVar3) {
                pcVar4 = (char *)0x7fffffff;
              }
              if (local_14 != (char *)0x0) {
                pcVar4 = pcVar4 + -((uint)pcVar4 % (uint)local_14);
              }
              if (local_c < pcVar4) {
LAB_1014bf59:
                if (_DstSize != 0xffffffff) {
                  _memset(_DstBuf,0,_DstSize);
                }
                piVar1 = __errno();
                *piVar1 = 0x22;
                goto LAB_1014bdeb;
              }
              _File->_base = (char *)0x0;
              _File->_ptr = (char *)_File->_cnt;
              _DstBuf_00 = _Dst;
              iVar2 = __fileno(_File);
              pcVar4 = (char *)__read_nolock(iVar2,_DstBuf_00,(uint)pcVar4);
              if (pcVar4 == (char *)0x0) {
                LOCK();
                *piVar1 = *piVar1 | 8;
                UNLOCK();
                goto code_r0x1014bf85;
              }
              if ((int)pcVar4 < 0) goto LAB_1014bf7c;
              pcVar3 = pcVar3 + -(int)pcVar4;
              local_c = local_c + -(int)pcVar4;
            }
          }
          else {
            pcVar4 = _File->_base;
            if (pcVar4 == (char *)0x0) goto LAB_1014bec3;
            if ((int)pcVar4 < 0) {
LAB_1014bf7c:
              LOCK();
              *piVar1 = *piVar1 | 0x10;
              UNLOCK();
code_r0x1014bf85:
              return (uint)((int)(_ElementSize * _Count) - (int)pcVar3) / _ElementSize;
            }
            if (pcVar3 < pcVar4) {
              pcVar4 = pcVar3;
            }
            if (local_c < pcVar4) goto LAB_1014bf59;
            _memcpy_s(_Dst,(rsize_t)local_c,_File->_ptr,(rsize_t)pcVar4);
            pcVar3 = pcVar3 + -(int)pcVar4;
            _File->_base = _File->_base + -(int)pcVar4;
            _File->_ptr = pcVar4 + (int)_File->_ptr;
            local_c = local_c + -(int)pcVar4;
          }
          _Dst = _Dst + (int)pcVar4;
        } while( true );
      }
      if (_DstSize != 0xffffffff) {
        _memset(_DstBuf,0,_DstSize);
      }
      if ((_File != (FILE *)0x0) && (_Count <= (uint)(0xffffffff / (ulonglong)_ElementSize)))
      goto LAB_1014be32;
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
LAB_1014bdeb:
    FUN_1014b2cf();
  }
  return 0;
}
