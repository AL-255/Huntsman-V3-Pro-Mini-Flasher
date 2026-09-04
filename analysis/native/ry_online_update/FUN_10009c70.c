/* 10009c70 FUN_10009c70 [[10009c70, 10009de5]] */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_10009c70(void *this,uint *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  undefined **ppuVar7;
  int iVar8;
  uint *puVar9;
  char *pcVar10;
  char *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_1016a295;
  local_10 = ExceptionList;
  uVar3 = DAT_101c9dd4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  if (param_1 == (uint *)0x0) goto LAB_10009ddc;
  puVar4 = (uint *)FUN_10001ea0();
  uVar5 = ___stdio_common_vsprintf
                    (*puVar4 | 2,puVar4[1],(char *)0x0,0,(char *)param_1,
                     (__crt_locale_pointers *)0x0,param_2);
  if ((int)uVar5 < 0) {
    uVar5 = 0xffffffff;
  }
  if ((int)uVar5 < 0) goto LAB_10009dd2;
  if (*(int **)(*(int *)this + -0x10) == (int *)0x0) {
LAB_10009cf5:
    ppuVar7 = FUN_1000f8a0();
    piVar6 = (int *)(**(code **)(*ppuVar7 + 0x10))();
    if (piVar6 == (int *)0x0) {
LAB_10009dd2:
                    /* WARNING: Subroutine does not return */
      FUN_10002000(-0x7fffbffb);
    }
  }
  else {
    piVar6 = (int *)(**(code **)(**(int **)(*(int *)this + -0x10) + 0x10))(uVar3);
    if (piVar6 == (int *)0x0) goto LAB_10009cf5;
  }
  iVar8 = (**(code **)(*piVar6 + 0xc))();
  local_18 = (char *)(iVar8 + 0x10);
  local_8 = 0;
  cVar2 = FUN_10008d30(&local_18,(uint)param_1);
  if (cVar2 == '\0') {
    puVar9 = param_1;
    do {
      uVar3 = *puVar9;
      puVar9 = (uint *)((int)puVar9 + 1);
    } while ((char)uVar3 != '\0');
    FUN_10009140(&local_18,param_1,(int)puVar9 - ((int)param_1 + 1));
  }
  local_8 = 1;
  pcVar10 = *(char **)this;
  if ((int)(1U - *(int *)(pcVar10 + -4) | *(int *)(pcVar10 + -8) - uVar5) < 0) {
    FUN_100090d0(this,uVar5);
    pcVar10 = *(char **)this;
  }
  pcVar1 = local_18;
  ___stdio_common_vsprintf_s
            (*puVar4,puVar4[1],pcVar10,uVar5 + 1,local_18,(__crt_locale_pointers *)0x0,param_2);
  if ((int)uVar5 <= *(int *)(*(int *)this + -8)) {
    *(uint *)(*(int *)this + -0xc) = uVar5;
    pcVar10 = pcVar1 + -0x10;
    local_8 = 0xffffffff;
    *(undefined1 *)(uVar5 + *(int *)this) = 0;
    LOCK();
    piVar6 = (int *)(pcVar1 + -4);
    iVar8 = *piVar6;
    *piVar6 = *piVar6 + -1;
    UNLOCK();
    if (iVar8 == 1 || iVar8 + -1 < 0) {
      (**(code **)(**(int **)pcVar10 + 4))(pcVar10);
    }
    ExceptionList = local_10;
    return;
  }
LAB_10009ddc:
                    /* WARNING: Subroutine does not return */
  FUN_10002000(-0x7ff8ffa9);
}
