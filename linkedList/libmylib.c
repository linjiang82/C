/*
 * =====================================================================================
 *
 *       Filename:  linkedList.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/06/20 03:36:57
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
#include "mylib.h"

// typedef struct node{
//  int value;
//  struct node * next;
// } node_t;

int rval;
node_t * newNode(int val){
  node_t *newnode = (node_t *)malloc(sizeof(node_t));
  newnode->value=val;
  newnode->next=NULL;
  return newnode;
}

bool isEmpty(node_t * head){
  return head==NULL;
}

int size(node_t * head){
  int count=0;
  while(head){
    count++;
    head = head->next;
  }
  return count;
}
void addNode(node_t ** head, node_t * newnode){
 node_t **tracer = head;
 while(*tracer!=NULL && (*tracer)->value<newnode->value){
   tracer=&(*tracer)->next;
 }
  newnode->next=*tracer;
  *tracer = newnode;
} 
void addToBegin(node_t ** head, node_t * newnode){
 node_t **tracer = head;
  newnode->next=*tracer;
  *tracer = newnode;
}

void addToEnd(node_t ** head, node_t * newnode){
 node_t **tracer = head;
 while(*tracer!=NULL){
   tracer=&(*tracer)->next;
 }
  newnode->next=*tracer;
  *tracer = newnode;
} 

int removeFromBegin(node_t **head){
  node_t ** tracer=head;
  node_t *toBeFreed;
     toBeFreed = *tracer;
     rval = toBeFreed->value;
     *tracer = (*tracer)->next;
     free(toBeFreed);
     return rval;
  }

int removeFromEnd(node_t **head){
  node_t ** tracer=head;
  node_t *toBeFreed;
  while(*tracer){
    if((*tracer)->next==NULL){
      toBeFreed = *tracer;
      rval = toBeFreed->value;
      *tracer=NULL;
      free(toBeFreed);
    }
    else {
      tracer=&(*tracer)->next;
    }
  }
  return rval;
  }
int removeNode(node_t **head, node_t * beRemoved){
  node_t ** tracer=head;
  node_t *toBeFreed;
  while(*tracer){
   if((*tracer)->value==beRemoved->value){
     toBeFreed = *tracer;
     rval = toBeFreed->value;
     *tracer = (*tracer)->next;
     free(toBeFreed);
     return rval;
   }
   tracer=&(*tracer)->next;

  }
  }

 void printList(node_t *head){
   node_t **tracer = &head;
   while(*tracer!=NULL){
     printf("%d-",(*tracer)->value);
     tracer = &(*tracer)->next;
   }
   printf("\n");
 }

//  int main(int argc,char *argv[]){
//     node_t * head=NULL;
//     printf("%s\n",isEmpty(head)?"True":"False");
//     addNode(&head,newNode(1));
//     addNode(&head,newNode(3));
//     addNode(&head,newNode(2));
//     printf("%s\n",isEmpty(head)?"True":"False");
//     addNode(&head,newNode(0));
//     removeNode(&head,newNode(0));
//     removeNode(&head,newNode(3));
//     removeNode(&head,newNode(2));
//     addNode(&head,newNode(4));
//     printf("%d\n",size(head));
//     printList(head);
//  }


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

