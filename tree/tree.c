#include <linkedList.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct inode {
  int val;
  struct inode *left;
  struct inode *right;
} node;

node *newTreeNode(int val) {
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

void levelTraversal(node *head) {}

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
  node *n1 = newTreeNode(3);
  node *n2 = newTreeNode(5);
  node *n3 = newTreeNode(6);
  node *n4 = newTreeNode(8);
  node *n5 = newTreeNode(9);
  node *n6 = newTreeNode(19);
  node *n7 = newTreeNode(20);
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n6;
  n4->right = n7;
  n3->left = n5;
  head = n1;

  nlr(head);
  printf("\n");
  /*lnr(head);*/
  /*printf("\n");*/
  /*lrn(head);*/

  /*printf("the result: %d\n", isSymmentry(head));*/
  levelTraversal(head);

  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);
}
