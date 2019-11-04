#include <stdio.h>
#include <string.h>

int main(void)
{
  char *username;
  char *password;
  char *true_password;
  size_t len;
  size_t idx;
  FILE *fs;

  fs = fopen("/home/users/level03/.pass", "r");
  if (!fs)
  {
    fwrite("ERROR: failed to open password file\n", sizeof(char), 36, stderr);
    exit(1);
  }

  len = fread(true_password, sizeof(char), 41, fs);
  idx = strcspn(true_password, "\n");
  true_password[idx] = '\0';
  if (len != 41)
  {
    fwrite("ERROR: failed to read password file\n", sizeof(char), 36, stderr);
    fwrite("ERROR: failed to read password file\n", sizeof(char), 36, stderr);
    exit(1);
  }
  fclose(fs);

  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");

  printf("--[ Username:");
  fgets(username, 100, stdin);
  idx = strcspn(username, "\n");
  username[idx] = '\0';

  printf("--[ Password: ");
  fgets(password, 100, stdin);
  idx = strcspn(password, "\n");
  password[idx] = '\0';

  puts("*****************************************");
  if (strncmp(true_password, password, 41) == 0)
  {
    printf("Greetings, %s!\n", username);
    system("/bin/sh");
    return (0);
  }

  printf(username);
  puts(" does not have access!");
  return (1);
}
