/*
 * =====================================================================================
 *
 *       Filename:  helloworld.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/06/20 11:37:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  John Lin, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


double ave(int num,...){
 va_list alist;
 va_start(alist,num);
 double sum=0;
 for(int i=0;i<num;i++){
  sum+=va_arg(alist,double);
 }
 va_end(alist);
 return sum/num;
}
int main(void){
 /*int a[5]={2,4,6,8,10};*/
 /*printf("%d\n",(int)a);*/
 /*printf("%d",a[1]);*/
printf("%f",ave(3,3.0,6.0,9.0));
}


