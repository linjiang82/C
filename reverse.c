#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define EMPTY (-1)
#define STACKSIZE 255

typedef struct{
  char arr[STACKSIZE];
  int top;
}stack;

bool push(stack * x,char val){
  if(x->top==STACKSIZE) return -1;
  (x->top)++; 
  x->arr[x->top]=val;
  return 1;
}
char pop(stack * x){
  char temp;
  if(x->top==EMPTY) return -1;
   temp=x->arr[x->top];
   (x->top)--; 
   return temp;
}
int len(stack * x){
  return x->top;
}
bool isEmpty(stack *x){
  return x->top==EMPTY;
}
void printStack(stack *x){
  for(int i=0;i<=x->top;i++)
    printf("%c",x->arr[i]);
}


bool isValid(char * s){
  char pairMe(char x){
    switch(x){
      case ')':
      return '(';
      case ']':
      return '[';
      case '}':
      return '{';
    }
  }
  stack s1;
  s1.top=-1;
  while(*s!='\0')
  {
    if(*s=='('||*s=='['||*s=='{')
      push(&s1,*s);
    else 
      if(isEmpty(&s1) || pop(&s1)!=pairMe(*s))
      return false;
    s++;
  }
  return isEmpty(&s1)?true:false;
}

int main(int argc, char* argv[]){
  printf("%s",isValid("(([{}]))")?"true":"false");
}



int removeDuplicates(int* nums, int numsSize){
  int ret=0;
  for(int i=1;i<numsSize;i++){
  int current=nums[ret];
    if(nums[i]!=val))
      {
        int temp=nums[ret];
        nums[ret]= nums[i];
        numb[i]=temp;
        ret++;
      }
  }
}