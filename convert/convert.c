#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
  int idx=0,result=0,decimal=0;
  char x;
  int y[128]={0};
  printf("Please input a decimal number:");
  x = getchar();
  while( x!=' '){
    if(x<='9' && x>='0' || x=='.')
    y[idx++]=strtol(&x,NULL,10);
    x = getchar();
  }
  for(int i=0;i<idx;i++){
    if((char)y[i]=='.'){
      decimal=idx;
      continue;
  }
  printf("%d",y[i]);
  result = result*10+y[i];
}
printf("%9.1f",result);
}