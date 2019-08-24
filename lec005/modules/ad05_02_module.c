#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
//==========================================//
// ope
// LOAD   = 0x4c
// ADD(+) = 0x41
// SUB(-) = 0x53
// MUT(x) = 0x4d
// DIV(/) = 0x44
//==========================================//
#define LOAD 0x4c
#define ADD 0x41
#define SUB 0x53
#define MUT 0x4d
#define DIV 0x44

struct node {
  struct node *left;
  struct node *right;
  char ope;
  double num;
  double result;
};

/* 行きがけ順でなぞる */
void preorder(struct node *p){
  if(p == NULL){
    return;
  }
  preorder(p->left);
  preorder(p->right);
  //printf("%fl\n", p->num);
  if (p->ope == LOAD) {
    // LOADの時は何もしない
  } else if(p->ope == ADD) {
    // ADD(+)
    p->num = p->left->num + p->right->num;
  } else if(p->ope == SUB) {
    // SUB(-)
    p->num = p->left->num - p->right->num;
  } else if(p->ope == MUT) {
    // MUT(x)
    p->num = p->left->num * p->right->num;
  } else if(p->ope == DIV) {
    // DIV(/)
    p->num = p->left->num / p->right->num;
  }
}

void dest(struct node *p){
    if(p == NULL){
      return;
    }
    dest(p->left);
    dest(p->right);
    free(p);
    p = NULL;
}
