/* 1014b0ff ___stdio_common_vsprintf_s [[1014b0ff, 1014b122]] */

/* Library Function - Single Match
    ___stdio_common_vsprintf_s

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
___stdio_common_vsprintf_s
          (undefined4 param_1,undefined4 param_2,char *param_3,uint param_4,char *param_5,
          __crt_locale_pointers *param_6,char *param_7)

{
  common_vsprintf_s<char>(CONCAT44(param_2,param_1),param_3,param_4,param_5,param_6,param_7);
  return;
}
