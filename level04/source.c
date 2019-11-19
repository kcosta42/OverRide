#include <unistd.h>
#include <stdio.h>

#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
  int   status;
  pid_t pid;
  char  shellcode[32];

  pid = fork();
  if (pid == 0)
  {
    prctl(0x1, 0x1);
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    puts("Give me some shellcode, k");
    gets(shellcode);
  }
  else
  {
    do
    {
      wait(&status);
      if ((status & 0x7f) == 0)
      {
        puts("child is exiting...");
        return 0;
      }
    } while (ptrace(PTRACE_PEEKUSER, pid, 0x2c, 0) != 0xb)
    puts("no exec() for you");
    kill(pid, 0x9);
  }
  return (0);
}
