#include <stdio.h>


int minus(int x,int y){
  return x-y;
}
int add(int x,int y){
  return x+y;
}
//function ptr or function as parameter
void my(int (*func)(int,int),int x,int y){
  printf("%d",func(x,y));
}
void main(int argc, char** argv){
  my(add,2,3);
  my(minus,5,3);
}