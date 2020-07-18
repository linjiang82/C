#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define BIG 100000000UL
u_int32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * countToBig(void *arg){

  for(u_int32_t i=0;i<BIG;i++){
    pthread_mutex_lock(&lock);
    counter++;
    pthread_mutex_unlock(&lock);
  }
}

int main(){
  pthread_t t1;
  pthread_t t2;
  pthread_create(&t1,NULL,countToBig,NULL);
  pthread_create(&t2,NULL,countToBig,NULL);
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  printf("%u",counter);
}