#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int part(int *a, int left, int right){
  int tmp;
  int piv;
  // 引数として与えられた走査範囲の左端をiへ代入
  int i = left - 1;
  //　引数として与えられた走査範囲の右端をjへ代入
  int j = right;
  // 配列の一番右の要素を軸にする処理
  piv = a[right];
  while(1){
    // 配列の左側で軸の値より大きな値のindex取得する処理
    while(a[i] < piv){
      i++;
    };
    // 配列の右側要素で軸に設定した値と等しい若しくは小さい要素のindex取得する処理
    while(i < j && piv <= a[j]){
      j--;
    }
    if(j <= i){
      break;
    }
    //　軸の左側で軸より大きい値と軸の右側で軸より小さい値を交換する処理
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }
  tmp = a[i];
  a[i] = a[right];
  a[right] = tmp;
  // 配列の左側で軸の値より大きな値のindexを返す
  return i;
}

// 再帰を利用したQuick Sort
void qsort_01(int *a, int left, int right){
  int var;

  if(right <= left){
    return;
  }
  // 配列の左側で軸の値より大きな値のindexを閾値に設定する
  var = part(a, left, right);

  qsort_01(a, left, var - 1);

  qsort_01(a, var + 1, right);
}

void quick_01(int *a, int n){
  qsort_01(a, 0, n - 1);
}
