#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void merge(int *a, int left, int sep){
  if(sep == 1){
    return;
  }
  int max = left + (sep * 2);
  int right = left + sep;
  int *buf = (int *)malloc((sep * 2) * sizeof(int));
  for(int i = left; i < (left + sep); i += 2){
    buf[i] = a[left + i];
    buf[i + 1] = a[right + i];
  }
  for(int i = 0; i < sep; i++){
    a[left + i] = buf[left + i];
    a[right + i] = buf[right + i];
  }
  free(buf);
}

void msort(int *a, int sep, int n){
  int index = 0;
  int min = a[index];
  int tmp = 0;
  int tmp_left = 0;
  int tmp_right = 0;
  int end = 0;
  int right = 0;
  int left = 0;
  if(sep <= 0){
    return;
  }
  for(int i = 0; i < n; i += (sep * 2)) {
    if(n <= i){
      break;
    }
    end += (sep * 2);
    for(int j = i; j < (end - sep); j++){

      // 右側と左側の検査対象を指すindexを更新する
      left = j;
      right = j + sep;
      printf("%d\n",right);

      if(end < right){
        if(a[n - 1] < a[left]) {
          tmp_left = a[left];
          tmp_right = a[n - 1];
          a[left] = tmp_right;
          a[n - 1] = tmp_left;
        }
        break;
      }
      // 左右比較し入れ替える処理
      if(a[right] < a[left] && right < n) {
        tmp_left = a[left];
        tmp_right = a[right];
        a[left] = tmp_right;
        a[right] = tmp_left;
      }
    }
    merge(a, i, sep);
    printf("%s\n","/=====================================/");
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

/*void merge(int *a, int n){
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
}*/
