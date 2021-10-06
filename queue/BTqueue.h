#ifndef _BTQUEUE_H_
#define _BTQUEUE_H_

#include <linkedList.h>

typedef struct treeNode {
  treeNode *left;
  treeNode *right;
} treeNode;

typedef struct BTqueue {
  treeNode *head;
  treeNode *tail;
} queue;
void enqueue(BTqueue *queue, treeNode *newnode);
treeNode *dequeue(BTqueue *queue);

#endif
