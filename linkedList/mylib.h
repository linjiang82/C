#ifndef _MYLIB_H_
#define _MYLIB_H_

#include <stdbool.h>
typedef struct node{
 int value;
 struct node * next;
} node_t;


node_t * newNode(int val);
bool isEmpty(node_t * head);
int size(node_t * head);
void addNode(node_t ** head, node_t * newnode); 
void addToBegin(node_t ** head, node_t * newnode); 
void addToEnd(node_t ** head, node_t * newnode); 
int removeNode(node_t **head, node_t * beRemoved);
int removeFromBegin(node_t **head);
int removeFromEnd(node_t **head);
void printList(node_t *head);

#endif