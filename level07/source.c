#include <string.h>
#include <stdio.h>

unsigned int get_unum(void)
{
  unsigned int value;

  fflush(stdout);
  scanf("%u", value);
  clear_stdin();
  return value;
}

int read_number(unsigned int *array)
{
  int index;

  printf(" Index: ");
  index = get_unum();
  printf(" Number at data[%u] is %u\n", index, *(index * 4 + array));
  return 0;
}

int store_number(unsigned int *array)
{
  unsigned int  value;
  unsigned int  index;
  int           ret;

  printf(" Number: ");
  value = get_unum();
  printf(" Index: ");
  index = get_unum();
  if ((index % 3 == 0) || (value >> 0x18 == 0xb7))
  {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    ret = 1;
  }
  else
  {
    *(index * 4 + array) = value;
    ret = 0;
  }
  return ret;
}

int main(int argc, char **argv, char **env)
{
  char          cmd[20];
  int           ret;
  unsigned int  array[100];

  while (*argv)
  {
    memset(*argv, 0, strlen(*argv));
    argv += 1;
  }

  while (*env)
  {
    memset(*env, 0, strlen(*env));
    env += 1;
  }

  puts("----------------------------------------------------\n"
       "  Welcome to wil\'s crappy numberstorage service!   \n"
       "----------------------------------------------------\n"
       " Commands:                                          \n"
       "    store - store a number into the data storage    \n"
       "   read  - read a number from the data storage      \n"
       "    quit  - exit the program                        \n"
       "----------------------------------------------------\n"
       "   wil has reserved somestorage :>                  \n"
       "----------------------------------------------------\n"
      );
  do
  {
    printf("Input command: ");
    ret = 1;

    fgets(cmd, 0x14, stdin);
    if (cmd == "store")
      ret = store_number(array);
    else if (cmd == "read")
      ret = read_number(array);
    else if (cmd == "quit")
      return 0;

    if (ret)
      printf(" Failed to do %s command\n", cmd);
    else
      printf(" Completed %s command successfully\n", cmd);

  } while (1);
}
