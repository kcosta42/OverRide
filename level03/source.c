#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void decrypt(key)
{
  char *crypt = "Q}|u`sfg~sf{}|a3";
  size_t len;
  size_t idx;

  len = strlen(crypt);
  idx = 0;
  do
  {
    crypt[idx] = key ^ crypt[idx];
    idx += 1;
  } while (crypt[idx]);

  if (strcmp(crypt, "Congratulations") == 0)
    system("/bin/sh");
  else
    puts("\nInvalid Password");
}

void test(int input, int value)
{
  int key;

  key = value - input;
  if (key > 21)
    key = rand();

  decrypt(key);
}

int main(void)
{
  time_t  seed;
  int     input;

  seed = time(NULL);
  srand(seed);

  puts("***********************************");
  puts("*\t\tlevel03\t\t**");
  puts("***********************************");
  printf("Password:");

  scanf("%d", input);
  test(input, 322424845);
}
