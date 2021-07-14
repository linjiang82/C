#ifndef _DYNLINKEDLIST_H
#define _DYNLINKEDLIST_H

typedef enum type { INT, CHAR, FLOAT, DOUBLE } type;

typedef struct node {
  struct node *next;
  void *val;
  type dt;
} tnode;

typedef struct list {
  tnode *head;
  type dt;
} list;

void printList(list *l);
tnode *createNode(void *data);
void addToList(list *l, tnode *newNode);
void removeFromList(list *l, void *data);
#endif
