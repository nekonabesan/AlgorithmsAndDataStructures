// テスト対象関数のプロトタイプ宣言
#ifndef _TARGET_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define _TARGET_H_
#define RMAX 1000
#define TRUE 1
#define FALSE 0

// 以下のプロトタイプ宣言
void babble(int *a, int n);
void select_sort(int *a, int n);
void insort(int *a, int n);

#endif /* _TARGET_H_ */
