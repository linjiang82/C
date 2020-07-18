#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
 unsigned int little:2;
 unsigned int medium:4;
 unsigned int large:6;
}__attribute__( (packed) ) counters;

int main(){
  int i=0;
  int count=50;
  counters c;
  for(i;i<count;i++){
    printf("%d\n",c.little=i);
    printf("%d\n",c.medium=i);
    printf("%d\n",c.large=i);
  }
  printf("%d",sizeof(counters));
}