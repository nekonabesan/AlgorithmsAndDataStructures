//============================================================================//
// マージソート(NOT 再帰)
//============================================================================//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int* separator(int n){
  int cnt = 0;
  int tmp;
  int i = n;
  int j = 1;
  // 戻り値の要素数を取得する処理
  for(j = 1; j < n; j *= 2){
    if(n < j){
      break;
    }
    cnt++;
  }
  int *sep = (int *)malloc(cnt * sizeof(int));
  sep[cnt] = i;
  cnt--;
  while(1){
    if(cnt < 0){
      break;
    }
    i /= 2;
    sep[cnt] = i;
    cnt--;
  }
  return sep;
}

void merge(int *a, int left, int mid, int right){
  int l = left;
  int r = mid;
  int index = 0;
  int *b = (int *)malloc((right - left) * sizeof(int));
  while(l < mid && r < right){
    if(a[l] < a[r]){
      b[index] = a[l];
      l++;
    }else{
      b[index] = a[r];
      r++;
    }
    index++;
  }
  if(l == mid){
    while(r < right){
      b[index] = a[r];
      r++;
      index++;
    }
  } else {
    while(l < mid){
      b[index] = a[l];
      l++;
      index++;
    }
  }
  for(int j = 0; j < index; j++){
    a[left + j] = b[j];
  }
  free(b);
}

void msort(int *a, int n){
  int mid = 1;
  int left = 0;
  int right = 2;
  int c = 0;
  int sep = 1;
  bool flg = false;
  for(int i = (n / 2) - 1; 0 <= i; i--) {
    for(int j = 0; j < n; j+=sep){
      left = j;
      right = left + sep;
      mid = (left + right) / 2;
      if(mid < 1){
        break;
      }
      merge(a, left, mid, right);
      if(n < right + sep){
        mid = right;
        right = n;
        merge(a, left, mid, right);
        break;
      }
    }
    if(n / 2 + 1 < sep){
      left = mid;
      mid = right;
      right = n;
      merge(a, left, mid, right);
      mid = left;
      left = 0;
      right = n;
      merge(a, left, mid, right);
      break;
    }
    sep *= 2;
  }
}
