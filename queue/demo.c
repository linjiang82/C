#include "BTqueue.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  tnode *n1 = newNode(1);
  tnode *n2 = newNode(2);
  tnode *n3 = newNode(3);
  tnode *n4 = newNode(4);
  tnode *n5 = newNode(5);
  tnode *n6 = newNode(6);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;

  BTqueue *myqueue = malloc(sizeof(BTqueue));
  myqueue->head = n1;
  myqueue->tail = n6;

  printf("%d\n", myqueue->head->key);
  tnode *n7 = newNode(7);
  enqueue(myqueue, n7);
  printf("%d\n", myqueue->tail->key);
  tnode *dequeuedNode = dequeue(myqueue);
  printf("%d\n", dequeuedNode->key);

  printf("%d\n", myqueue->head->key);

  return 1;
}
