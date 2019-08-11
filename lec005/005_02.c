#include "modules/ad05_02_module.c"

void main(void){
  double result = 0;
  struct node* n1 = (struct node*)malloc(sizeof(struct node) * 1);
  n1->num = 0;
  n1->ope = MUT;
  struct node* n2 = (struct node*)malloc(sizeof(struct node) * 1);
  n2->num = 0;
  n2->ope = ADD;
  struct node* n3 = (struct node*)malloc(sizeof(struct node) * 1);
  n3->num = 3;
  n3->ope = LOAD;
  struct node* n4 = (struct node*)malloc(sizeof(struct node) * 1);
  n4->num = 4;
  n4->ope = LOAD;
  struct node* n5 = (struct node*)malloc(sizeof(struct node) * 1);
  n5->num = 0;
  n5->ope = SUB;
  struct node* n6 = (struct node*)malloc(sizeof(struct node) * 1);
  n6->num = 6;
  n6->ope = LOAD;
  struct node* n7 = (struct node*)malloc(sizeof(struct node) * 1);
  n7->num = 7;
  n7->ope = LOAD;
  //
  n2->left = n3;
  n2->right = n4;
  n5->left = n6;
  n5->right = n7;
  n1->left = n2;
  n1->right = n5;
  dest(n1);
}
