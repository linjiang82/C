#include <stdio.h>
#include <stdlib.h>


int gcd(int a,int b);
typedef struct {
  int numerator;
  int denominator;
}fraction;
fraction reduceFraction(fraction x){
  int i = gcd(x.numerator,x.denominator);
  x.numerator /= i;
  x.denominator /= i;
  return x;
}
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
  // int rval = gcd3(strtol(argv[1],NULL,10),strtol(argv[2],NULL,10),strtol(argv[3],NULL,10));
  fraction x;
  x.numerator=strtol(argv[1],NULL,10);
  x.denominator=strtol(argv[2],NULL,10);
  x = reduceFraction(x);
  printf("%d,%d",x.numerator,x.denominator);
}