/*
二分图的匹配：
http://blog.csdn.net/dark_scope/article/details/8880547
二分图中的子图中，每个节点只连一条边，则称该子图是二分图中的一个匹配。
极大匹配：
无法再向二分图中加入边，使得满足匹配条件。
最大匹配：
所有极大匹配中边数最多的一个匹配。
完美匹配：
如果一个图的某个匹配中，所有的顶点都是匹配点，那么它就是一个完美匹配。
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 555;
const int n = 100;
vector<int> graph[maxn];//二分图中左边对右边的连线
int from[maxn], tot;//from是二分图匹配的结果，tot是匹配数，不过from[i]表示右边的点i指的左边的点
bool use[maxn];//临时做标记的，表示右边的点是否被使用
//给左边的点x找个右边的匹配，注意这个递归
bool match(int x){
  for(int i = 0; i < graph[x].size(); ++i){
    if(!use[graph[x][i]]){
      use[graph[x][i]] = true;
      if(from[graph[x][i]] == -1 || match(from[graph[x][i]])){//这里的match是回溯到之前让之前的点在use[graph[x][i]] = true的情况下重新找个匹配，from[graph[x][i]]是指x的第i条连线的点目前的匹配
        from[graph[x][i]] = x;
        return true;
      }
    }
  }
  return false;
}
int hungary(){
  tot = 0;
  memset(from, -1, sizeof(from));
  for(int i = 1; i <= n; ++i){
    memset(use, 0, sizeof(use));
    if(match(i)){
      ++tot;
    }
  }
  return tot;
}
int main(){
}

