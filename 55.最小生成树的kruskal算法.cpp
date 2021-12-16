/*
Kruskal:
最小生成树的算法，最适合稀疏图，
给定一个无向图，如果它任意两个顶点都联通并且是一棵树，那么我们就称之为生成树(Spanning Tree)。如果是带权值的无向图，那么权值之和最小的生成树，我们就称之为最小生成树(MST, Minimum Spanning Tree)。
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000;//点数
const int M = 1500;//边数
int fa[N + 1];

struct Edge{
  int x, y, w;//w代表边的权重
  Edge(int x = 0, int y = 0, int w = 0){
    this->x = x;
    this->y = y;
    this->w = w;
  }
};
Edge edge[M + 1];
bool cmp(const Edge &a, const Edge &b){
  return a.w < b.w;
}
//并查集的查找
int getFather(const int &x){
  if(x == fa[x])return x;
  return fa[x] = getFather(fa[x]);//路径压缩
}
int kruskal(){
  int ans = 0;
  sort(edge + 1, edge + M + 1, cmp);//按权值从小到大排序，使得先处理权值较小的边，
  int cnt = N;
  for(int i = 1; i <= N; ++i){
    fa[i] = i;//初始化并查集
  }
  for(int i = 1; i <= M; ++i){
    int t1 = getFather(edge[i].x);
    int t2 = getFather(edge[i].y);
    if(t1 != t2){
      fa[t1] = t2;//并查集的合并，将其加入最小生成树集合
      ans += edge[i].w;
      cnt--;
      if(cnt == 1){
        return ans;
      }
    }
  }
  return -1;//表明该无向图不连通,等价于不存在最小生成树
}
int main(){
}

