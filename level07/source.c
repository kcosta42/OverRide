
uint get_unum(void)

{
  uint local_10 [3];

  local_10[0] = 0;
  fflush(stdout);
  __isoc99_scanf(&DAT_08048ad0,local_10);
  clear_stdin();
  return local_10[0];
}

int store_number(int param_1)
{
  uint uVar1;
  uint uVar2;
  int iVar3;

  printf(" Number: ");
  uVar1 = get_unum();
  printf(" Index: ");
  uVar2 = get_unum();
  if ((uVar2 % 3 == 0) || (uVar1 >> 0x18 == 0xb7)) {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    iVar3 = 1;
  }
  else {
    *(uint *)(uVar2 * 4 + param_1) = uVar1;
    iVar3 = 0;
  }
  return iVar3;
}

void read_number(int param_1)
{
  int iVar1;

  printf(" Index: ");
  iVar1 = get_unum();
  printf(" Number at data[%u] is %u\n",iVar1,*(undefined4 *)(iVar1 * 4 + param_1));
  return;
}

int main(int argc,char **argv,char **env)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  byte *pbVar6;
  int in_GS_OFFSET;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  char **local_1c8;
  char **local_1c4;
  undefined4 local_1bc [100];
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;

  bVar10 = 0;
  local_1c4 = argv;
  local_1c8 = env;
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  iVar2 = 100;
  puVar4 = local_1bc;
  while (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  while (*local_1c4 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar5 = *local_1c4;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + (uint)bVar10 * -2 + 1;
    } while (cVar1 != 0);
    memset(*local_1c4,0,~uVar3 - 1);
    local_1c4 = local_1c4 + 1;
  }
  while (*local_1c8 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar5 = *local_1c8;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + (uint)bVar10 * -2 + 1;
    } while (cVar1 != 0);
    memset(*local_1c8,0,~uVar3 - 1);
    local_1c8 = local_1c8 + 1;
  }
  puts(
      "----------------------------------------------------\n  Welcome to wil\'s crappy numberstorage service!   \n----------------------------------------------------\n Commands:                                         \n    store - store a number into the data storage    \n   read  - read a number from the data storage     \n    quit  - exit the program                       \n----------------------------------------------------\n   wil has reserved somestorage :>                 \n----------------------------------------------------\n"
      );
  do {
    printf("Input command: ");
    local_2c = 1;
    fgets((char *)&local_28,0x14,stdin);
    uVar3 = 0xffffffff;
    puVar4 = &local_28;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *(char *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
    } while (cVar1 != 0);
    uVar3 = ~uVar3;
    bVar7 = uVar3 == 1;
    bVar9 = uVar3 == 2;
    *(undefined *)((int)&local_2c + uVar3 + 2) = 0;
    iVar2 = 5;
    puVar4 = &local_28;
    pbVar6 = (byte *)"store";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *(byte *)puVar4 < *pbVar6;
      bVar9 = *(byte *)puVar4 == *pbVar6;
      puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
      pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
    } while (bVar9);
    bVar8 = false;
    bVar7 = (!bVar7 && !bVar9) == bVar7;
    if (bVar7) {
      local_2c = store_number((int)local_1bc);
    }
    else {
      iVar2 = 4;
      puVar4 = &local_28;
      pbVar6 = &DAT_08048d61;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar8 = *(byte *)puVar4 < *pbVar6;
        bVar7 = *(byte *)puVar4 == *pbVar6;
        puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
        pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
      } while (bVar7);
      bVar9 = false;
      bVar7 = (!bVar8 && !bVar7) == bVar8;
      if (bVar7) {
        local_2c = read_number((int)local_1bc);
      }
      else {
        iVar2 = 4;
        puVar4 = &local_28;
        pbVar6 = &DAT_08048d66;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *(byte *)puVar4 < *pbVar6;
          bVar7 = *(byte *)puVar4 == *pbVar6;
          puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
          pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
        } while (bVar7);
        if ((!bVar9 && !bVar7) == bVar9) {
          if (local_14 == *(int *)(in_GS_OFFSET + 0x14)) {
            return 0;
          }
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
      }
    }
    if (local_2c == 0) {
      printf(" Completed %s command successfully\n",&local_28);
    }
    else {
      printf(" Failed to do %s command\n",&local_28);
    }
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
  } while( true );
}
