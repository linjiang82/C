/*
 * =====================================================================================
 *
 *       Filename:  factorial.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/06/20 07:57:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  John Lin 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int factorial(int);

int main(void){
 /*  testing code */
 printf("1! = %i\n", factorial(1));
 printf("3! = %i\n", factorial(3));
 printf("5! = %i\n", factorial(5));
}
int factorial(int i){
 if(i==1) {return 1;}
 else if(i>1) {return i*factorial(--i);}
}


