#include <stdio.h>

char a_user_name[256];

int verify_user_name(void)
{
  puts("verifying username....\n");
  return (strcmp("dat_wil", a_user_name));
}

int verify_user_pass(char *password)
{
  return (strcmp("admin", password));
}

int main(void)
{
  char password[16];
  int ret;

  puts("********* ADMIN LOGIN PROMPT *********");

  printf("Enter Username: ");
  fgets(a_user_name, 256, 0);
  ret = verify_user_name();

  if (ret == 0)
  {
    puts("Enter Password: ");
    fgets(password, 100, 0);
    ret = verify_user_pass(password);
    if (ret == 0 || ret != 0)
      puts("nope, incorrect password...\n");
  }
  puts("nope, incorrect username...\n");
  return (ret);
}
