
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node {
  struct node *left;
  struct node *right;
  char label;
};

/* 行きがけ順でなぞる */
void preorder(struct node *p){
  if(p == NULL){
    return;
  }
  printf("%c\n", p->label);
  preorder(p->left);
  preorder(p->right);
}

/*  */
void inorder(struct node *p){
  if(p == NULL){
    return;
  }
  inorder(p->left);
  printf("%c\n", p->label);
  inorder(p->right);
}

/*  */
void postorder(struct node *p){
  if(p == NULL){
    return;
  }
  preorder(p->left);
  preorder(p->right);
  printf("%c\n", p->label);
}

void dest(struct node* p){
  if(p == NULL){
    return;
  }
  if(p->left->left == NULL && p->left->right == NULL){
    free(p->left);
  } else {
    dest(p->left);
  }
  if(p->left->left == NULL && p->left->right == NULL){
    free(p->right);
  } else {
    dest(p->right);
  }
}
