#include <unistd.h>
#include <stdio.h>

#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
  pid_t pid;
  char shellcode[32];

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
    do {
      wait(&local_a4);
      local_20 = local_a4;
      if (((local_a4 & 0x7f) == 0) ||
         (local_1c = local_a4, '\0' < (char)(((byte)local_a4 & 0x7f) + 1) >> 1)) {
        puts("child is exiting...");
        return 0;
      }
      local_18 = ptrace(PTRACE_PEEKUSER,local_14,0x2c,0);
    } while (local_18 != 0xb);
    puts("no exec() for you");
    kill(local_14,9);
  }
  return (0);
}
