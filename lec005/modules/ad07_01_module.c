#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void babble(int *a, int n){
  int tmp = 0;
  for(int i = 0; i < n; i++){
    for(int j = n - 1; 0 < j; j--){
      if(a[j] < a[j - 1]) {
        tmp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = tmp;
      }
    }
  }
  return;
}

void select_sort(int *a, int n){
  int min;
  int tmp;
  int index;
  for(int i = 0; i < n - 1; i++){
    index = i;
    min = a[i];
    for(int j = i + 1; j < n; j++){
      if(a[j] < min){
        index = j;
        min = a[j];
      }
    }
    tmp = a[i];
    a[i] = a[index];
    a[index] = tmp;
  }
  return;
}

void insort(int *a, int n){
  int tmp;
  int j;
  for(int i = 1; i < n; i++){
    j = i;
    while(1 <= j && a[j - 1] >  a[j]){
      tmp = a[j];
      a[j] = a[j - 1];
      a[j - 1] = tmp;
      j--;
    }
  }
  return;
}
