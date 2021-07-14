#include <stdio.h>
#include "mylib.h"

 int main(int argc,char *argv[]){
    node_t * head=NULL;
    addNode(&head,newNode(1));
    addNode(&head,newNode(3));
    addNode(&head,newNode(2));
    printList(head);
    addToBegin(&head,newNode(5));
    printList(head);
    addToEnd(&head,newNode(9));
    printList(head);
    addNode(&head,newNode(0));
    addNode(&head,newNode(4));
    printList(head);
    removeFromBegin(&head);
    printList(head);
    removeFromEnd(&head);
    printList(head);
 }