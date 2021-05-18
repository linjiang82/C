#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

tnode *newNode(int key) {
  tnode *node = (tnode *)malloc(sizeof(tnode));
  node->key = key;
  node->next = NULL;
  return node;
}

void addNode(tnode **head, tnode *node) {
  tnode **tracer = head;
  while ((*tracer) != NULL) {
    tracer = &(*tracer)->next;
  }
  *tracer = node;
}

tnode *removeNodeByIndex(tnode **head, int index) {
  tnode **tracer = head;
  int i = 0;
  if (size(head) - 1 < index)
    return NULL;
  while (i < index - 1) {
    tracer = &(*tracer)->next;
    i++;
  }
  tnode *temp = (*tracer)->next;
  (*tracer)->next = (*tracer)->next->next;
  return temp;
}

int size(tnode **head) {
  int i = 0;
  tnode **tracer = head;
  while ((*tracer) != NULL) {
    i++;
    tracer = &(*tracer)->next;
  }
  return i;
}

void printList(tnode **head) {
  tnode **tracer = head;
  while (*tracer != NULL && (*tracer)->next != NULL) {
    printf("%d->", (*tracer)->key);
    tracer = &(*tracer)->next;
  }
  printf("%d", (*tracer)->key);
}
