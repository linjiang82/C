#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct node {
  int key;
  struct node *next;
} tnode;

tnode *newNode(int key);
void addNode(tnode **head, tnode *node);
tnode *removeNodeByIndex(tnode **head, int index);
int size(tnode **head);
void printList(tnode **head);
void destroyList(tnode **head);
#endif /* ifndef _LINKEDLIST_H */
