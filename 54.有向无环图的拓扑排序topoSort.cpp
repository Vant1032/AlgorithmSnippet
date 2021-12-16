/*
拓扑排序：
一个有向图能被拓扑排序的充要条件就是它是一个有向无环图
原理：
 (1)从有向图中选取一个没有前驱(即入度为0)的顶点，并输出之;
 (2)从有向图中删去此顶点以及所有以它为尾的弧;
     重复上述两步，直至图空，或者图不空但找不到无前驱的顶点为止。
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100000 + 5;
vector<int> g[maxn];//对象数组，g[i][j]代表i节点的第j条边
int du[maxn], n, m, L[maxn];//n代表点的个数,L模拟一个栈，存储拓扑排序的结果
//return false 说明此图无法被拓扑排序，图中有环
bool topoSort(){
  memset(du, 0, sizeof(du));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < g[i].size(); j++){
      du[g[i][j]]++;//计算节点入度
    }
  }
  int tot = 0;
  queue<int> q;
  for(int i = 0; i < n; i++){
    if(!du[i]){
      q.push(i);//先将入度为0的点入队
    }
  }
  //queue中的点都是入度为0的点
  while(!q.empty()){
    int x = q.front();
    q.pop();
    L[tot++] = x;
    for(int j = 0; j < g[x].size(); j++){
      int t = g[x][j];
      du[t]--;//删去从x到t的这条边
      if(!du[t]){//如果删去边后t的入度为0，则加入队列
        q.push(t);
      }
    }
  }
  //当queue为空之后，检查图中是否还存在任何边，如果存在的话，说明图中至少存在一条环路。不存在的话则返回true
  return tot == n;
}
int main(){
}

