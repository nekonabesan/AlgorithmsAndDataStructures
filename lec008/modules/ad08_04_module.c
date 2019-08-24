//============================================================================//
// マージソート(再帰)
//============================================================================//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void mearge(int *a, int left, int mid, int right){
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

void msort(int *a, int left, int right){
  int mid = (left + right) / 2;
  if(left == right || left == right - 1){
    return;
  }
  msort(a, left, mid);
  msort(a, mid, right);
  mearge(a, left, mid, right);
}
