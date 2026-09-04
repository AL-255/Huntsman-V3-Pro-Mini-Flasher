/* 1000a730 FUN_1000a730 [[1000a730, 1000aa31]] */

void __fastcall FUN_1000a730(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;

  iVar1 = param_1[10];
  uVar4 = FUN_1000b220(param_1);
  if ((char)uVar4 == '\0') {
    if (param_1[0x13] != 0x7c) {
      return;
    }
    puVar5 = (undefined4 *)FUN_1000f4d7(0x14);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = 0;
      puVar5[1] = 0;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[4] = 0;
      *puVar5 = std::_Node_base::vftable;
      puVar5[1] = 8;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[4] = 0;
    }
    puVar5[4] = param_1[10];
    iVar8 = param_1[10];
    if (*(int *)(iVar8 + 0xc) != 0) {
      puVar5[3] = *(int *)(iVar8 + 0xc);
      *(undefined4 **)(*(int *)(param_1[10] + 0xc) + 0x10) = puVar5;
      iVar8 = param_1[10];
    }
    *(undefined4 **)(iVar8 + 0xc) = puVar5;
    param_1[10] = (int)puVar5;
    FUN_1000aa40(param_1 + 9,(int)puVar5);
  }
  puVar5 = (undefined4 *)FUN_1000f4d7(0x14);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[1] = 0x11;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    *puVar5 = std::_Node_endif::vftable;
  }
  puVar5[4] = param_1[10];
  iVar8 = param_1[10];
  if (*(int *)(iVar8 + 0xc) != 0) {
    puVar5[3] = *(int *)(iVar8 + 0xc);
    *(undefined4 **)(*(int *)(param_1[10] + 0xc) + 0x10) = puVar5;
    iVar8 = param_1[10];
  }
  *(undefined4 **)(iVar8 + 0xc) = puVar5;
  param_1[10] = (int)puVar5;
  puVar6 = (undefined4 *)FUN_1000f4d7(0x1c);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6[3] = 0;
    *(undefined8 *)(puVar6 + 4) = 0;
    puVar6[6] = 0;
    puVar6[1] = 0x10;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = 0;
    *puVar6 = std::_Node_if::vftable;
    puVar6[5] = puVar5;
    puVar6[6] = 0;
  }
  iVar8 = *(int *)(iVar1 + 0xc);
  *(undefined4 **)(*(int *)(iVar8 + 0x10) + 0xc) = puVar6;
  puVar6[4] = *(undefined4 *)(iVar8 + 0x10);
  *(undefined4 **)(iVar8 + 0x10) = puVar6;
  puVar6[3] = iVar8;
  iVar8 = param_1[0x13];
  do {
    if (iVar8 != 0x7c) {
      return;
    }
    pcVar7 = (char *)*param_1;
    if (pcVar7 != (char *)param_1[2]) {
      if (*pcVar7 == '\\') {
        pcVar7 = pcVar7 + 1;
        if (pcVar7 != (char *)param_1[2]) {
          uVar9 = param_1[0x14];
          if ((uVar9 & 8) == 0) {
            uVar9 = param_1[0x14];
            if ((*pcVar7 == '(') || (*pcVar7 == ')')) goto LAB_1000a8f7;
          }
          if (((uVar9 & 0x10) == 0) && ((*pcVar7 == '{' || (*pcVar7 == '}')))) goto LAB_1000a8f7;
        }
        pcVar7 = (char *)*param_1;
      }
LAB_1000a8f7:
      *param_1 = (int)(pcVar7 + 1);
    }
    FUN_1000a500(param_1);
    uVar4 = FUN_1000b220(param_1);
    if ((char)uVar4 == '\0') {
      puVar6 = (undefined4 *)FUN_1000f4d7(0x14);
      if (puVar6 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        *puVar6 = 0;
        puVar6[1] = 0;
        puVar6[2] = 0;
        puVar6[3] = 0;
        puVar6[4] = 0;
        *puVar6 = std::_Node_base::vftable;
        puVar6[1] = 8;
        puVar6[2] = 0;
        puVar6[3] = 0;
        puVar6[4] = 0;
      }
      puVar6[4] = param_1[10];
      iVar8 = param_1[10];
      if (*(int *)(iVar8 + 0xc) != 0) {
        puVar6[3] = *(int *)(iVar8 + 0xc);
        *(undefined4 **)(*(int *)(param_1[10] + 0xc) + 0x10) = puVar6;
        iVar8 = param_1[10];
      }
      *(undefined4 **)(iVar8 + 0xc) = puVar6;
      param_1[10] = (int)puVar6;
      FUN_1000aa40(param_1 + 9,(int)puVar6);
    }
    iVar8 = puVar5[3];
    iVar2 = *(int *)(iVar1 + 0xc);
    puVar5[3] = 0;
    iVar3 = param_1[10];
    param_1[10] = (int)puVar5;
    puVar5[3] = 0;
    *(undefined4 **)(iVar3 + 0xc) = puVar5;
    for (iVar3 = *(int *)(iVar2 + 0x18); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x18)) {
      iVar2 = iVar3;
    }
    puVar6 = (undefined4 *)FUN_1000f4d7(0x1c);
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      *(undefined8 *)(puVar6 + 4) = 0;
      puVar6[6] = 0;
      puVar6[1] = 0x10;
      puVar6[2] = 0;
      puVar6[3] = 0;
      puVar6[4] = 0;
      *puVar6 = std::_Node_if::vftable;
      puVar6[5] = puVar5;
      puVar6[6] = 0;
    }
    *(undefined4 **)(iVar2 + 0x18) = puVar6;
    puVar6[3] = iVar8;
    *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(iVar2 + 0x18);
    iVar8 = param_1[0x13];
  } while( true );
}
