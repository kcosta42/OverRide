#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int password;

  puts("***********************************");
  puts("* \t     -Level00 -\t\t  *");
  puts("***********************************");

  printf("Password:");
  scanf("%d", password);

  if (password == 5276)
  {
    puts("\nAuthenticated!");
    system("/bin/sh");
  }
  else
    puts("\nInvalid Password!");

  return (password != 5276);
}
