#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void merge(int *a, int left, int sep, int n, int end){
  // セパレータが2以下の場合、処理対象外
  if(sep <= 1){
    return;
  }
  //printf("%d\n", sep);
  int max = left + (sep * 2);
  int right = left + sep;
  int j = 0;
  int *buf = (int *)malloc((sep * 2) * sizeof(int));
  for(int i = left; i < end; i++){
    buf[j] = a[i];
    buf[j + 1] = a[i + sep];
    //printf("%d\n", i);
    //printf("%s\n","/=====================================/");
    //printf("%d\n", a[i]);
    //printf("%d\n", a[i+1]);
    //printf("%s\n","/=====================================/");
    j += 2;
  }
  //printf("%s\n","/=====================================/");
  for(int i = 0; i < (sep * 2); i++){
    //printf("%d\n", buf[i]);
    a[left + i] = buf[i];
    //a[right + i] = buf[sep + i];
  }
  //printf("%s\n","/=====================================/");
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
  int mid = n / 2;
  int k = 0;
  if(n % 2 != 0){
    mid += 1;
  }
  for(int i = 0; i < (n - sep); i += (sep * 2)) {
    if(n <= i){
      break;
    }
    end += (sep * 2);
    //printf("end : %d\n", end);
    //printf("end : %d\n",end);
    //printf("%s\n","/=====================================/");
    for(int j = i; j < (i + sep); j+=1){
      //printf("%s\n","/=====================================/");
      //printf("i : %d\n", i);
      //printf("j : %d\n",j);
      //printf("%s\n","/=====================================/");
      // 右側と左側の検査対象を指すindexを更新する
      left = j;
      right = left + sep;
      //printf("left : %d\n",left);
      //printf("right : %d\n",right);
      if(end < right){
        if(a[n - 1] < a[left]) {
          tmp_left = a[left];
          tmp_right = a[n - 1];
          //a[left] = tmp_right;
          //a[n - 1] = tmp_left;
        }
        break;
      }
      // 左右比較し入れ替える処理
      if(a[right] < a[left]) {
        tmp_left = a[left];
        tmp_right = a[right];
        a[left] = tmp_right;
        a[right] = tmp_left;
      }
    }
    printf("%s\n","/=====================================/");
    merge(a, i, sep, n, end);
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
