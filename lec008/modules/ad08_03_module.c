#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void msort(int *a, int start, int end){
  int index = 0;
  int min = a[index];
  int tmp;
  for(int i = start; i < end; i++){
    for(){

    }
  }
}

int* separator(int n){
  int cnt = 0;
  int tmp;
  int i = n;
  int j = 1;
  // 戻り値の要素数を取得する処理
  for(j = 1; j <= n; j *= 2){
    if(n <= j){
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
    if(sep[cnt + 1] % 2 != 0){
      sep[cnt] += 1;
      i++;
    }
    cnt--;
  }
  return sep;
}

void merge(int *a, int n){
  int mid = 1;
  int start = 0;
  int end = 0;
  int num1;
  int num2;
  int cnt = 0;
  int i = 0;
  // 戻り値の要素数を取得する処理
  for(int j = 1; j <= n; j *= 2){
    if(n <= j){
      break;
    }
    cnt++;
  }
  int *sep = separator(n);
  for(int i = 0; i < cnt; i++){
    num1 = sep[i];
    if(sep[i] % 2 != 0){
      num2 = sep[i] - 1;
    } else {
      num2 = sep[i];
    }
    while(1){
      msort(a, start, end);
      if(i % 2 == 0){
        start += num2;
        end += (start + num2);
      } else {
        start += num1;
        end += (start + num1);
      }
      if(n < end){
        break;
      }
      i++;
    }
  }
}
