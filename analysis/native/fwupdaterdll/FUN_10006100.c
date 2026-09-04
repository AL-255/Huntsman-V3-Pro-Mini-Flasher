/* 10006100 FUN_10006100 [[10006100, 1000613c]] */

undefined1 __cdecl FUN_10006100(int *param_1,char *param_2)

{
  int *piVar1;
  int local_c;
  undefined1 local_5;

  piVar1 = (int *)GetManager(param_1);
  CStringT<>(&local_c,param_2,piVar1);
  local_5 = FUN_10006630(param_1,&local_c);
  FUN_10006410(&local_c);
  return local_5;
}
