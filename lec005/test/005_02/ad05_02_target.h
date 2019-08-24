// テスト対象関数のプロトタイプ宣言
#ifndef _TARGET_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define _TARGET_H_
#define TRUE 1
#define FALSE 0

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

void preorder(struct node *p);
void dest(struct node *p);

#endif /* _TARGET_H_ */
