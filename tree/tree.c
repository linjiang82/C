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

bool isSymmentryHelper(node *left, node *right) {
  if (left == NULL && right == NULL) {
    return true;
  } else if (left != NULL && right != NULL && left->val == right->val) {
    return isSymmentryHelper(left->right, right->left) &&
           isSymmentryHelper(left->left, right->right);
  } else {
    return false;
  }
}
bool isSymmentry(node *head) {
  if (head == NULL) {
    return true;
  } else {
    node *left = head->left;
    node *right = head->right;
    return isSymmentryHelper(left, right);
  }
}

int main(int argc, char *argv[]) {
  node *head = NULL;
  node *n1 = newNode(3);
  node *n2 = newNode(5);
  node *n3 = newNode(6);
  node *n4 = newNode(8);
  node *n5 = newNode(9);
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n3->right = n5;
  head = n1;

  nlr(head);
  printf("\n");
  lnr(head);
  printf("\n");
  lrn(head);

  printf("the result: %d\n", isSymmentry(head));

  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);
}
