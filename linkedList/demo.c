#include "linkedList.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  tnode *head = NULL;
  tnode *node1 = newNode(2);
  tnode *node2 = newNode(3);
  tnode *node3 = newNode(7);
  tnode *node4 = newNode(9);
  tnode *node5 = newNode(4);
  tnode *node6 = newNode(5);
  addNode(&head, node1);
  addNode(&head, node2);
  addNode(&head, node3);
  addNode(&head, node4);
  addNode(&head, node5);
  addNode(&head, node6);
  tnode *result = removeNodeByIndex(&head, 2);
  printf("%d\n", result->key);
  printList(&head);
  return 0;
}
