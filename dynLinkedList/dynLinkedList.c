#include "dynLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void printList(list *l);
tnode *createNode(void *data) {

  tnode *newNode = (tnode *)malloc(sizeof(tnode));
  newNode->val = data;
  newNode->next = NULL;
  return NULL;
};
void addToList(list *l, tnode *newNode);
void removeFromList(list *l, void *data);
