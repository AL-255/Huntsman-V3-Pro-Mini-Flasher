/* 100066f0 FUN_100066f0 [[100066f0, 10006756]] */

void __thiscall FUN_100066f0(void *this,ushort *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  ushort *puVar2;

  bVar1 = __CrtIsValidPointer((int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    puVar2 = (ushort *)FUN_100065b0(this);
    FUN_10002220(puVar2,param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_10001f10(-0x7fffbffb);
}
