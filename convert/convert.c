#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int idx = 0, decimal = 0;
  double result =
      0; // has to be double, due to precision issue, float not working here.
  char x;
  int y[128] = {0};
  printf("Please input a decimal number:");
  x = getchar();
  while (x != EOF) {
    if (x <= '9' && x >= '0' || x == '.')
      y[idx++] = (int)x;
    x = getchar();
  }
  for (int i = 0; i < idx; i++) {
    if ((char)y[i] == '.') {
      printf("%c", (char)y[i]);
      decimal = i;
      break;
    }
    printf("%d", y[i]);
    result = result * 10 + (y[i] - (int)'0');
  }
  if (decimal != 0) {
    for (int i = decimal + 1; i < idx; i++) {
      printf("%f\n", result);
      printf("%f", (y[i] - (int)'0') / pow(10, i - decimal));
      result += ((y[i] - (int)'0') / pow(10, i - decimal));
    }
  }
  char buffer[1024];
  snprintf(buffer, sizeof(buffer), "\n%%%d.%df", decimal,
           decimal == 0
               ? 0
               : idx - 1 - decimal); // dynamically build print format specifier
  printf(buffer, result);
}
