#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  printf("the parent pid is %d\n", getpid());
  pid_t ret = fork();
  if (ret) {
    printf("I am parent process, the spawned child PId is %d\n", ret);
  } else {
    printf("I am child process, my PId is %d\n", getpid());
  }
  while (1)
    ;
}
