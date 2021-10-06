#include <arpa/inet.h>
#include <assert.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = shm_open("/shm1", O_CREAT | O_RDWR, 0666);
  void *shmp = NULL;
  if (fd == -1) {
    perror("cannot open share memery");
    exit(-1);
  }
  if (ftruncate(fd, 5) == -1) {
    perror("cannot truncate");
    exit(-1);
  }
  if ((shmp = mmap(0, sizeof(char) * 5, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
                   0)) == (void *)-1) {
    perror("cannot mmap");
    exit(-1);
  }
  char *pt = (char *)shmp;
  pt[0] = 'A';
  pt[1] = 'B';
  pt[2] = 'C';
  pt[3] = '\0';
  printf("write to share mem ok");
}
