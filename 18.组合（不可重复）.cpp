/*

找出从自然数1、2、... 、n（0<n<10）中任取r(0<r<=n)个数的所有组合。
输入
输入n、r。
输出
按特定顺序输出所有组合。
特定顺序：每一个组合中的值从大到小排列，组合之间按逆字典序排列。
样例输入
5 3
样例输出
543
542
541
532
531
521
432
431
421
321
*/
#include <stdio.h>
#include <iostream>
using namespace std;
//十以内 
int d[11], len;
void combine(int k, int n){//从k后面找n个数 
  if(n == 0){
    for(int i = 0; i < len; i++)printf("%d", d[i]);
    printf("\n");
    return;
  }
  int t = len;
  for(int i = k; i > n - 1; i--){
    d[len++] = i;
    combine(i - 1, n - 1);
    len = t;
  }
} 
int main(){
	int n, m;
	while(~scanf("%d%d", &n, &m)){
	  len = 0;
	  combine(n, m);
  }
}

