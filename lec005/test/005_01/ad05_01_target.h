// テスト対象関数のプロトタイプ宣言
#ifndef _TARGET_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define _TARGET_H_
#define RMAX 1000
#define TRUE 1
#define FALSE 0

void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);
void dest(struct node *p);

#endif /* _TARGET_H_ */
