#include <stdio.h>

char a_user_name[256];

int verify_user_pass(char *password)
{
  return (strncmp(password, "admin"));
}

int verify_user_name(void)
{
  puts("verifying username....\n");
  return (strncmp(a_user_name, "dat_wil", 7));
}

int main(void)
{
  int ret;
  char password[16];

  puts("********* ADMIN LOGIN PROMPT *********");
  printf("Enter Username: ");
  fgets(a_user_name, 256, stdin);

  ret = verify_user_name();
  if (ret == 0)
  {
    puts("Enter Password: ");
    fgets(password, 100, stdin);

    ret = verify_user_pass(password);
    if ((ret == 0) || (ret != 0))
      puts("nope, incorrect password...\n");
  }
  else
    puts("nope, incorrect username...\n");

  return ret;
}
