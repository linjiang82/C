#include "queue.h"
#include <stdio.h>

void initQueue(queue *queue) {
  queue->head = NULL;
  queue->tail = NULL;
}

void enqueue(queue *queue, tnode *newnode) {
  if (queue->head == NULL) {
    queue->head = newnode;
    queue->tail = newnode;
  } else {
    queue->tail->next = newnode;
    queue->tail = newnode;
  }
}
tnode *dequeue(queue *queue) {
  if (queue->head != NULL) {
    tnode *retNode = queue->head;
    queue->head = queue->head->next;
    return retNode;
  } else
    return NULL;
}
