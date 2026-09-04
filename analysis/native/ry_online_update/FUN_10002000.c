/* 10002000 FUN_10002000 [[10002000, 10002018]] */

void FUN_10002000(int param_1)

{
  code *pcVar1;

  if (param_1 == -0x7ff8fff2) {
                    /* WARNING: Subroutine does not return */
    FUN_1000ff17();
  }
  FUN_10010561(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}
