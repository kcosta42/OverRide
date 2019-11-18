#include <stdio.h>

typedef struct msg
{
  char    content[140];
  char    username[40];
  size_t  size;
} msg_t;

void secret_backdoor(void)
{
  char shellcode[128];

  fgets(shellcode, 0x80, stdin);
  system(shellcode);
}

void set_msg(msg_t *msg)
{
  char *content[128];

  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(content, 0x400, stdin);
  strncpy(msg->content, content, msg->size);
}

void set_username(msg_t *msg)
{
  char    *username[16];
  size_t  idx;

  puts(">: Enter your username");
  printf(">>: ");
  fgets(username, 0x80, stdin);
  idx = 0;
  while (idx < 41 && *(username + idx))
  {
    *(msg->username + idx) = *(username + idx);
    idx += 1;
  }

  printf(">: Welcome, %s", msg->username);
}

void handle_msg(void)
{
  msg_t msg;

  msg.size = 140;
  set_username(&msg);
  set_msg(&msg);
  puts(">: Msg sent!");
  return;
}

int main(void)
{
  puts("--------------------------------------------\n"
       "|   ~Welcome to l33t-m$n ~    v1337        |\n"
       "--------------------------------------------");
  handle_msg();
  return 0;
}
