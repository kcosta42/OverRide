#include <stdio.h>
#include <string.h>

int main(void)
{
  int iVar1;
  size_t sVar2;
  long lVar3;
  char *puVar4;
  char local_118 [14];
  char local_a8 [6];
  char local_78 [12];
  int local_14;
  FILE *local_10;

  lVar3 = 0xc;
  puVar4 = local_78;
  while (lVar3 != 0) {
    lVar3 = lVar3 + -1;
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *puVar4 = 0;
  lVar3 = 5;
  puVar4 = local_a8;
  while (lVar3 != 0) {
    lVar3 = lVar3 + -1;
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *puVar4 = 0;
  lVar3 = 0xc;
  puVar4 = local_118;
  while (lVar3 != 0) {
    lVar3 = lVar3 + -1;
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *puVar4 = 0;
  local_10 = NULL;
  local_14 = 0;
  local_10 = fopen("/home/users/level03/.pass", "r");
  if (local_10 == NULL) {
    fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
    exit(1);
  }
  sVar2 = fread(local_a8, 1, 41, local_10);
  local_14 = sVar2;
  sVar2 = strcspn(local_a8, "\n");
  *(local_a8 + sVar2) = 0;
  if (local_14 != 41) {
    fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
    fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
    exit(1);
  }
  fclose(local_10);
  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");
  printf("--[ Username: ");
  fgets(local_78, 100, stdin);
  sVar2 = strcspn(local_78, "\n");
  *(local_78 + sVar2) = 0;
  printf("--[ Password: ");
  fgets(local_118, 100, stdin);
  sVar2 = strcspn(local_118, "\n");
  *(local_118 + sVar2) = 0;
  puts("*****************************************");
  iVar1 = strncmp(local_a8, local_118, 41);
  if (iVar1 == 0) {
    printf("Greetings, %s!\n", local_78, local_78);
    system("/bin/sh");
    return 0;
  }
  printf(local_78);
  puts(" does not have access!");
  exit(1);
}
