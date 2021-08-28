#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int little : 2;
  unsigned int medium : 4;
  unsigned int large : 6;
} __attribute__((packed)) counters;

int main() {
  int count = 50;
  counters c;
  for (int i = 0; i < count; i++) {
    printf("%d\n", c.little = i);
    printf("%d\n", c.medium = i);
    printf("%d\n", c.large = i);
  }
  printf("%lu", sizeof(counters));
}
