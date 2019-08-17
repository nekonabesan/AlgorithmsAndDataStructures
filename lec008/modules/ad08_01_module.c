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
