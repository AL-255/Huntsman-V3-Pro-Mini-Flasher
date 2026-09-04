/* 10007150 AtlAddThrow<int> [[10007150, 10007182]] */

/* Library Function - Single Match
    int __cdecl ATL::AtlAddThrow<int>(int,int)

   Library: Visual Studio 2010 Debug */

int __cdecl ATL::AtlAddThrow<int>(int param_1,int param_2)

{
  int local_c;
  long local_8;

  local_8 = AtlAdd<int>(&local_c,param_1,param_2);
  if (local_8 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001f10(local_8);
  }
  return local_c;
}
