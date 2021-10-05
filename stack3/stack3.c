#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int win()
{
  printf("code flow successfully changed\n");
  return 0;
}

int main(int argc, char **argv)
{
  volatile int (*fp)();
  char buffer[64];

  fp = 0;

  gets(buffer);

  printf("%p", win);
  if(fp) {
      printf("calling function pointer, jumping to 0x%08x\n", fp);
      fp();
  }
}
