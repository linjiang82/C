#include <stdio.h>
#define call(type, name)                                                       \
  type name(int a) { return a * a; }

static inline call(int, square);
int main() { printf("%d\n", square(9)); }
