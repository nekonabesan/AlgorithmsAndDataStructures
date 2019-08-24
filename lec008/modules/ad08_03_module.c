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

/*int convert(int *a, int left, int sep){
  int max = left + (sep * 2);
  int med = left + sep;
  int right = left + sep;

  end += (sep * 2);
  for(int j = 0; j < (left + sep); j+=1){
    left = j;
    right = left + sep;
    if(end < right){
      if(a[n - 1] < a[left]) {
        tmp_left = a[left];
        tmp_right = a[n - 1];
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
}*/

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
  for(int i = 0; i < mid; i += (sep * 2)) {
    if(n <= i){
      break;
    }
    //convert(a,  i, sep);
    printf("%s\n","/=====================================/");
    merge(a, i, i, n);
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
