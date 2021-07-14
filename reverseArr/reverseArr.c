#include <stdio.h>

#define LENGTH 6

void swap(int *x, int *y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}
void reverseArr(int *arr, int size) {
  int first, last;
  for (first = 0, last = size - 1; first < last; first++, last--) {
    swap(arr + first, arr + last);
  }
}
void printArr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}
int main() {
  int arr[LENGTH] = {1, 2, 3, 4, 5, 6};
  reverseArr(arr, LENGTH);
  printArr(arr, LENGTH);

  return 0;
}
