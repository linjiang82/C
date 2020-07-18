#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>


// int main(int argc, char **argv){
//   int fd = open("./randText", O_RDONLY, S_IRUSR| S_IWUSR);
//   struct stat sb;

//   if(fstat(fd,&sb)==-1){
//     perror("couldn't get file size. \n");
//   }
//   printf("file size is %ld\n", sb.st_size);

//   char *file = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd,0);

//   for(int i=0;i<sb.st_size;i++){
//     printf("%c",file[i]);
//   }
//   printf("\n");

// munmap(file,sb.st_size);
// close(fd);


// }

int main(){
  int fd = open("./randText", O_RDONLY);
  struct stat sb;
  if(fstat(fd,&sb)!=-1){
    char *file = mmap(NULL, sb.st_size,PROT_READ,MAP_PRIVATE,fd,0);
    for(int i=0;i<sb.st_size;i++){
      printf("%c",file[i]);
    }
    munmap(file,sb.st_size);
  }
  close(fd);
}