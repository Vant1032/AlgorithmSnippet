/*
并查集支持两种操作：
1.合并集合
2.查找祖先（判断是否属于同一个集合）

#include <stdio.h>
#include <string.h>
using namespace std;
//并查集
const int SIZE = 6;
int pre[SIZE], rank[SIZE];//rank 用于支持按秩合并
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
*/
#include <string.h>
class DisjointSet {
  private:
    /*按秩合并*/
    int *rank, *pre, length;
  public:
    /*开个多大的并查集*/
    DisjointSet(int n) {
      length = n + 1;
      rank = new int[n + 1];
      pre = new int[n + 1];
      memset(rank, 0, (n + 1) * sizeof(int));
      for(int i = 0; i <= n; i++) {
        pre[i] = i;
      }
    }
    ~DisjointSet() {
      delete [] rank;
      delete [] pre;
    }
    /*想重用此并查集就用这个函数重新初始化并查集，原有数据丢失*/
    void refresh(int n){
      if(n + 1 <= length)return;
      delete [] rank;
      delete [] pre;
      rank = new int[n + 1];
      pre = new int[n + 1];
      memset(rank, 0, (n + 1) * sizeof(int));
      for(int i = 0; i < n; i++){
        pre[i] = i;
      }
    }
    int find(int x) {
      int r = x;
      while(pre[r] != r) {
        r = pre[r];
      }
      int i;
      while(pre[x] != x) {
        i = pre[x];
        pre[x] = r;
        x = i;
      }
      return r;
    }
    void merge(int x, int y) {
      int i = find(x), j = find(y);
      if(i == j)return;
      if(rank[i] < rank[j]) {
        pre[i] = j;
      } else {
        pre[j] = i;
        if(rank[i] == rank[j]) {
          ++rank[i];
        }
      }
    }
};
int main(){
	
}

