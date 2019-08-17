#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int part(int *a, int left, int right){
  int tmp;
  int piv;
  int i = left - 1;
  int j = right;
  piv = a[right];
  while(1){
    while(a[i] < piv){
      i++;
    };
    while(i < j && piv <= a[j]){
      j--;
    }
    if(j <= i){
      break;
    }
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }
  tmp = a[i];
  a[i] = a[right];
  a[right] = tmp;
  return i;
}

void quick_sort(int *a, int left, int right){
  int var;

  if(right <= left){
    return;
  }

  var = part(a, left, right);

  quick_sort(a, left, var - 1);

  quick_sort(a, var + 1, right);
}

void quick(int *a, int n){
  quick_sort(a, 0, n - 1);
}
