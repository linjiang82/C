#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SHOWNAME 0x01 //0b00000001
#define SHOWAGE 0x02 //0b00000010

void main(){
  u_int8_t options = SHOWNAME|SHOWAGE;
printf(options&SHOWNAME?"ture":"false");
}