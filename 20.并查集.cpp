/*

*/
#include <stdio.h>
#include <string.h>
using namespace std;
//并查集
const int SIZE = 5000;
int pre[SIZE], rank[SIZE];
void init(){
  memset(rank, 0, sizeof(rank));
  for(int i = 0; i < SIZE; i++){
    pre[i] = i;
  } 
}
int find(int x){
  int r = x;
  while(pre[r] != r){
    r = pre[r];
  }
  int i = x, j;
  while(pre[i] != i){
    j = pre[i];
    pre[i] = r;
    i = j;
  } 
  return r;
} 
void merge(int x, int y){
  int a = find(x), b = find(y);
  if(a == b)return;
  if(rank[a] < rank[b]){
    pre[a] = b;
  }else{
    pre[b] = a;
    if(rank[a] == rank[b]){
      ++rank[a];
    }
  }
}
int main(){
	
}

