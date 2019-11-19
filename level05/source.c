#include <stdio.h>
#include <string.h>

int main(void)
{
  char          buffer[100];
  unsigned int  idx;

  fgets(buffer, 100, stdin);
  idx = 0;
  do
  {
    if ('@' < buffer[idx] && buffer[idx] < '[')
      buffer[idx] = buffer[idx] ^ 0x20; // tolower()
    if (idx >= strlen(buffer))
    {
      printf(buffer);
      exit(0);
    }
    idx += 1;
  } while (1);
}
