#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *left;
  struct node *right;
} node;

node *newNode(int val) {
  node *newnode = malloc(sizeof(node));
  newnode->val = val;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

void lnr(node *head) {
  if (head != NULL) {
    lnr(head->left);
    printf("%d->", head->val);
    lnr(head->right);
  } else {
    printf("%c", 'X');
  }
}
void lrn(node *head) {
  if (head != NULL) {
    lrn(head->left);
    lrn(head->right);
    printf("%d->", head->val);
  } else {
    printf("%c", 'X');
  }
}

void nlr(node *head) {
  if (head != NULL) {
    printf("%d->", head->val);
    nlr(head->left);
    nlr(head->right);
  } else {
    printf("%c", 'X');
  }
}

bool isSymmentry(node *head) {
  if (head == NULL) {
    return true;
  }
}

int main(int argc, char *argv[]) {
  node *head = NULL;
  node *n1 = newNode(3);
  node *n2 = newNode(5);
  node *n3 = newNode(6);
  node *n4 = newNode(8);
  node *n5 = newNode(10);
  n1->left = n2;
  n2->left = n3;
  n2->right = n4;
  n1->right = n5;
  head = n1;

  nlr(head);
  printf("\n");
  lnr(head);
  printf("\n");
  lrn(head);

  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);
}
