#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN(A, B)                                                              \
  ({                                                                           \
    typeof(A) n1 = (A);                                                        \
    typeof(B) n2 = (B);                                                        \
    n1 > n2 ? n2 : n1;                                                         \
  })

int getRand() {
  int n1 = rand() % 100;
  printf("%d\n", n1);
  return n1;
}

int main(int argc, char *argv[]) {
  srand((unsigned)time(NULL));
  printf("%d\n", MIN(getRand(), getRand()));
  printf("%f\n", MIN(14.78, 89.23));
  return 0;
}
