#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>

int auth(char *login, unsigned int serial)
{
  size_t  len;
  int     ret;

  len = strcspn(login, "\n");
  login[len] = '\0';
  len = strnlen(login, 0x20);
  if (len < 6)
    return 1;
  if (ptrace(PTRACE_TRACEME) == -1)
  {
    puts("\x1b[32m.---------------------------.");
    puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
    puts("\x1b[32m\'---------------------------\'");
    ret = 1;
  }
  else
    ret = (serial == hash(login));
  return ret;
}

int main(void)
{
  char          login[32];
  unsigned int  serial;
  int           success;

  puts("***********************************");
  puts("*\t\tlevel06\t\t  *");
  puts("***********************************");
  printf("-> Enter Login: ");
  fgets(login, 0x20, stdin);

  puts("***********************************");
  puts("***** NEW ACCOUNT DETECTED ********");
  puts("***********************************");
  printf("-> Enter Serial: ");
  scanf("%u", serial);

  success = auth(login, serial);
  if (success == 0)
  {
    puts("Authenticated!");
    system("/bin/sh");
  }
  return success;
}
