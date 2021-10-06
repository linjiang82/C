#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <linkedList.h>

typedef struct queue {
  tnode *head;
  tnode *tail;
} queue;
void enqueue(queue *queue, tnode *newnode);
tnode *dequeue(queue *queue);

#endif
