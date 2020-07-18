#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h> //for mmap
#include <wait.h>
#include <stdint.h>
#include <unistd.h>
#include <assert.h>


#define PAGESIZE 4096
#define _GNU_SOURCE

    
int v =80;
int main(){
  int * sharedMem = mmap(NULL,PAGESIZE,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS, -1,0);

  *sharedMem = 34;
  
  if(fork()==0){
    v=15;
    *sharedMem=35;
  }
  else {
    wait(NULL);
  }
  printf("not shared, %i, id is %d\n",v,getpid());
  printf("shared, %i, id is %d\n",*sharedMem,getpid());
}