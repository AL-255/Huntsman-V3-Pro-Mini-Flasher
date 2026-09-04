/* 1014b0db ___stdio_common_vsprintf [[1014b0db, 1014b0fe]] */

/* Library Function - Single Match
    ___stdio_common_vsprintf

   Library: Visual Studio 2019 Release */

void __cdecl
___stdio_common_vsprintf
          (undefined4 param_1,undefined4 param_2,char *param_3,uint param_4,char *param_5,
          __crt_locale_pointers *param_6,char *param_7)

{
  common_vsprintf<__crt_stdio_output::standard_base,char>
            (CONCAT44(param_2,param_1),param_3,param_4,param_5,param_6,param_7);
  return;
}
