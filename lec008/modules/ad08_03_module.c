//============================================================================//
// マージソート(NOT 再帰)
//============================================================================//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

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
