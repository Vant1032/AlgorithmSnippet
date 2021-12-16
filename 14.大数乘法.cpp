/*
简单高精度乘法 
*/
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 5001;
int a[maxn], b[maxn], c[2 * maxn], la, lb;
char str1[maxn], str2[maxn];
void init(int *a, char *str,int len){//字符串转成数字，同时反转 
  int i, k = 0;
  for(i = len - 1; i >= 0; i--){
    a[k++] = str[i] - '0';
  } 
}
void multiply(){ 
  memset(c, 0, sizeof(c));
  int maxlen = la + lb, k, i, j;
  for(i = 0; i < la; i++) {
    for(j = 0; j < lb; ++j) { 
      c[i + j] += b[j] * a[i];
    }
    for(k = 0; k < maxlen; ++k){//整理数字 
      if(c[k] >= 10){
        c[k + 1] += c[k] / 10;
        c[k] %= 10;
      }
    }
  }
  for(i = maxlen; c[i] == 0; --i);
  for(; i >= 0; i--)printf("%d", c[i]);
  printf("\n"); 
}

int main(){
	while(~scanf("%s%s", str1, str2)){
	  la = strlen(str1);
	  lb = strlen(str2);
	  if((la == 1 && str1[0] == '0') || (lb == 1 && str2[0] == '0')){
	    printf("0\n");
    }else{
      init(a, str1, la);
	    init(b, str2, lb);
      multiply();
    }
  }
}

