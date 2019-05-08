# include <stdio.h>

int main(void)
{
  int password;

  puts("***********************************");
  puts("* \t     -Level00 -\t\t  *");
  puts("***********************************");
  printf("Password:");
  scanf("%d", password);

  if (password != 5276)
    puts("\nInvalid Password!");
  else
  {
    puts("\nAuthenticated!");
    system("/bin/sh");
  }

  return password != 5276;
}
