/* 101593a7 FID_conflict:_free [[101593a7, 101593e0]] */

/* Library Function - Multiple Matches With Different Base Names
    __free_base
    _free

   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

void __cdecl FID_conflict__free(void *_Memory)

{
  BOOL BVar1;
  int *piVar2;
  DWORD DVar3;
  int iVar4;

  if (_Memory != (void *)0x0) {
    BVar1 = HeapFree(DAT_101d27b8,0,_Memory);
    if (BVar1 == 0) {
      piVar2 = __errno();
      DVar3 = GetLastError();
      iVar4 = ___acrt_errno_from_os_error(DVar3);
      *piVar2 = iVar4;
    }
  }
  return;
}
