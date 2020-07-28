#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b){
  while(a>0){
    if(a<b){
      int t=a;
      a=b;
      b=t;
    }
    a=a%b;
  }
  return b;
}

int gcd3(int a,int b,int c){
  int t=gcd(a,b);
  return gcd(t,c);
}
int main(int argc, char * argv[]){
  if(argc<3)
    {
    printf("Usage: gcd 1st 2nd [3rd]");
    exit(-1);
  }
  int rval = gcd3(strtol(argv[1],NULL,10),strtol(argv[2],NULL,10),strtol(argv[3],NULL,10));
  printf("%d",rval);
}