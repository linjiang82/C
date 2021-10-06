#include <stdio.h>
#include <string.h>

void XorSwap(char * ptr1, char *ptr2){
  if(ptr1!=ptr2){
    *ptr1 ^= *ptr2;
    *ptr2 ^= *ptr1;
    *ptr1 ^= *ptr2;
  }
}

void reverse(char *str){
  int size = strlen(str);
  for(int i=0;i<size/2;i++){
    // char temp = *(str+i);
    // *(str+i)=*(str+size-1-i);
    // *(str+size-1-i)=temp;
    XorSwap(str+i,str+size-1-i);
  }

}
void main(int argc, char* argv[]){
  char allInput[256];
  int idx=0;
  if(argc<2){
    printf("Usage: reverse [string]");
    return;
  }
  for(int i=1;i<argc;i++){
    allInput[idx++]=' ';
      for(int j=0;j<strlen(argv[i]);j++){
        allInput[idx++]=argv[i][j];
  }

  }
  reverse(allInput);
  printf("%s\n",allInput);

}