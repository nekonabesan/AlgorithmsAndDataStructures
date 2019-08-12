#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void shell(int *a, int n){
  int tmp;
  int i;
  int k;
  for(i = 1; i < n / 9; i = i * 3 + 1);
  for(; i > 0; i /= 3){
    for(int j = i; j < n; j++){
      k = j;
      while(i <= k && a[k - i] > a[k]){
        tmp = a[k];
        a[k] = a[k - i];
        a[k - i] = tmp;
        k -= i;
      }
    }
  }
  return;
}

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
