// It won't work if line 23 written like pthread_create(&(thread[i]), NULL,
// rollDice, &i); due to when rollDice exec, the value in the address
// has been incremented
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREADSIZE 8
pthread_barrier_t barrier;
pthread_t thread[THREADSIZE];
int result[THREADSIZE];
int idx[THREADSIZE] = {0, 1, 2, 3, 4, 5, 6, 7};
int Max = 0;

void *rollDice(void *i) {
  int idx = *(int *)i;
  result[idx] = rand() % 6 + 1;
  printf("%d %d\n", result[idx], idx);
  pthread_barrier_wait(&barrier); // wait for all threads finishe rolling dice;
  pthread_barrier_wait(&barrier); // wait for the main thread getting the Max;
  printf("I am the No.%d and I %s\n", idx, result[idx] < Max ? "Lose" : "Win");
  pthread_barrier_wait(&barrier);
}

int main(int argc, char *argv[]) {
  srand((unsigned)time(NULL));
  pthread_barrier_init(&barrier, NULL, THREADSIZE + 1);
  for (int i = 0; i < THREADSIZE; i++) {
    pthread_create(&(thread[i]), NULL, rollDice, idx + i);
    /*[ > pthread_join(thread[i], NULL); < ]*/
  }
  pthread_barrier_wait(&barrier); // wait for all threads finish rolling dice;
  for (int i = 0; i < THREADSIZE; i++) {
    if (result[i] > Max) {
      Max = result[i];
    }
  }
  pthread_barrier_wait(&barrier); // wait for getting the Max;
  pthread_barrier_wait(&barrier); // wait for threads finish printing result;

  return 0;
}
