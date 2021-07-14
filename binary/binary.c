#include <stdio.h>
#include <stdlib.h>

static int rval[64];
static int idx=0;
int binary(unsigned int a){
  while(a>0){
    if(a&1) rval[idx++]=1;
    else rval[idx++]=0;
    a >>=1;
  }
}
int main(int argc, char* argv[]){
  if(argc<2){
    printf("Usage: binary 1st");
    exit(-1);
  }
  printf("%u\n",strtoul(argv[1],NULL,10));
  binary(strtoul(argv[1],NULL,10));
  for(;idx>0;){
    printf("%d",rval[--idx]);
  }

}
