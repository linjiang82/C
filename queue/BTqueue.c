#include "BTqueue.h"

void enqueue(BTqueue *queue, treeNode *newnode) {
  queue->tail->next = newnode;
  queue->tail = newnode;
}
tnode *dequeue(queue *queue) {
  tnode *retNode = queue->head;
  queue->head = queue->head->next;
  return retNode;
}
