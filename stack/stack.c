/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/07/20 
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  John Lin 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../linkedList/mylib.h"

void push(node_t **head, node_t * newnode)
  addToEnd(head,newnode);
}
void pop(node_t **head){
  removeFromEnd(head);
}
 int main(int argc,char *argv[]){
    node_t * stack=NULL;
    push(&stack,newNode(1));
    printList(stack);
    push(&stack,newNode(3));
    printList(stack);
    push(&stack,newNode(2));
    printList(stack);
    push(&stack,newNode(0));
    printList(stack);
    pop(&stack);
    printList(stack);
    pop(&stack);
    printList(stack);
    pop(&stack);
    printList(stack);
    push(&stack,newNode(4));
    printList(stack);
 }


// //have to use **, due to c only pass arguments by value;
// int addNode(node_t ** phead,int i){
//  //the NULL means the head is empty;
//  if(*phead==NULL){
//   node_t * newNode = malloc(sizeof(node_t));
//   //the NULL means not enough memory;
//   if(newNode==NULL){
//    return 1;
//   } else {
//   newNode->value = i;
//   newNode->next=NULL;
//     *phead = newNode;
//   }
//  } else {
//   node_t * current = *phead;
//   while(current->next!=NULL){
//    current = current->next;
//   }
//   node_t * newNode = malloc(sizeof(node_t));
//   newNode->value = i;
//   newNode->next=NULL;
//   current->next=newNode;
//  }
// }
// int removeNode(node_t **head, int i){
//     node_t * toBeFreed = NULL;
//   if(*head==NULL){
//     return -1;
//   }
//   if((*head)->value==i){
//     toBeFreed = *head;
//     *head = (*head)->next;
//     free(toBeFreed);
//   }
//   else {
//   node_t * current = (*head)->next;
//   node_t * previous = *head;
//     while(current!=NULL){
//       if(current->value!=i){
//         previous = current;
//         current = current->next;
//       }
//       else {
//         previous->next = current->next;
//         free(current);
//         break;
//       }
//     }
//   }
// }
// bool isEmpty(node_t * head){
//   return head==NULL;
// }
// int length(node_t *head){
//   node_t * current = head;
//   int size = 0;
//   while(current!=NULL){
//     size++;
//     current = current->next;
//   }
//   return size;
// }
// int printList(node_t * head){
//  node_t * current = head;
//  while(current!=NULL){
//   printf("%d-",current->value);
//   current = current->next;
//  }
//  printf("\n");
// }
// int main(void){
// node_t * head=NULL;
// addNode(&head,1);
// addNode(&head,3);
// addNode(&head,5);
// addNode(&head,8);
// printList(head);
// printf("before removing\n");
// removeNode(&head,3);
// addNode(&head,6);
// printList(head);
// printf("The list is %s empty.\n",isEmpty(head)?"":"not");
// printf("The size of the list is %d\n",length(head));

// }

