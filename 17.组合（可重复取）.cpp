/*
求n个数，每个数可重复取时的组合情况 
*/
#include <stdio.h>
#include <iostream>
using namespace std;
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
    combine(i, n - 1);
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

