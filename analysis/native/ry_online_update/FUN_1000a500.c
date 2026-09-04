/* 1000a500 FUN_1000a500 [[1000a500, 1000a68f]] */

void __fastcall FUN_1000a500(int *param_1)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;

  if ((char *)*param_1 == (char *)param_1[2]) {
    iVar3 = -1;
    *(undefined1 *)(param_1 + 0x12) = 0xff;
    cVar1 = -1;
  }
  else {
    cVar1 = *(char *)*param_1;
    *(char *)(param_1 + 0x12) = cVar1;
    puVar2 = FUN_10145c80((uint *)&DAT_101ad850,cVar1);
    cVar1 = (char)param_1[0x12];
    if (puVar2 == (uint *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (int)cVar1;
    }
  }
  param_1[0x13] = iVar3;
  switch(cVar1) {
  case '\n':
    if ((*(byte *)(param_1 + 0x14) & 4) == 0) {
      return;
    }
    if (param_1[4] != 0) {
      return;
    }
    param_1[0x13] = 0x7c;
    return;
  default:
    goto switchD_1000a552_caseD_b;
  case '$':
    if ((param_1[0x14] & 0x2000000U) == 0) {
      return;
    }
    if ((char *)(*param_1 + 1) == (char *)param_1[2]) {
      return;
    }
    if (*(char *)(*param_1 + 1) == '\n') {
      return;
    }
    param_1[0x13] = 0;
    return;
  case '(':
  case ')':
    bVar5 = (*(byte *)(param_1 + 0x14) & 8) == 0;
    break;
  case '*':
    if ((param_1[0x14] & 0x4000000U) == 0) {
      return;
    }
    iVar3 = *(int *)(param_1[10] + 4);
    if (((iVar3 != 0x14) && (iVar3 != 8)) && (iVar3 != 0xd)) {
      if (iVar3 != 2) {
        return;
      }
      iVar3 = *(int *)(*(int *)(param_1[10] + 0x10) + 4);
      if ((iVar3 != 0x14) && (iVar3 != 8)) {
        bVar5 = iVar3 == 0xd;
        break;
      }
    }
    goto LAB_1000a687;
  case '+':
  case '?':
    bVar5 = (*(byte *)(param_1 + 0x14) & 1) == 0;
    break;
  case '\\':
    pcVar4 = (char *)(*param_1 + 1);
    if (pcVar4 == (char *)param_1[2]) {
      return;
    }
    if (((*(byte *)(param_1 + 0x14) & 8) != 0) ||
       ((cVar1 = *pcVar4, cVar1 != '(' && (cVar1 != ')')))) {
      if ((*(byte *)(param_1 + 0x14) & 0x10) != 0) {
        return;
      }
      cVar1 = *pcVar4;
      if ((cVar1 != '{') && (cVar1 != '}')) {
        return;
      }
    }
    *(char *)(param_1 + 0x12) = cVar1;
    param_1[0x13] = (int)cVar1;
    return;
  case '^':
    if ((param_1[0x14] & 0x2000000U) == 0) {
      return;
    }
    iVar3 = *(int *)(param_1[10] + 4);
    if (iVar3 == 0x14) {
      return;
    }
    if (iVar3 == 8) {
      return;
    }
    if (iVar3 == 0xd) {
      return;
    }
    if (iVar3 == 2) {
      iVar3 = *(int *)(*(int *)(param_1[10] + 0x10) + 4);
      if (iVar3 == 0x14) {
        return;
      }
      if (iVar3 == 8) {
        return;
      }
      if (iVar3 == 0xd) {
        return;
      }
      param_1[0x13] = 0;
      return;
    }
    goto LAB_1000a687;
  case '{':
  case '}':
    bVar5 = (*(byte *)(param_1 + 0x14) & 0x10) == 0;
    break;
  case '|':
    bVar5 = (*(byte *)(param_1 + 0x14) & 2) == 0;
  }
  if (bVar5) {
LAB_1000a687:
    param_1[0x13] = 0;
  }
switchD_1000a552_caseD_b:
  return;
}
