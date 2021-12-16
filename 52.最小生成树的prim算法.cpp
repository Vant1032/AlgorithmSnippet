/*
最小生成树的prim算法：
1.
*/
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
const int dotNum = 1000;
//graph[i][j]代表节点i的第j条相连的边
struct graphNode{
  int number, dis;//number代表相连的边的编号，dis是距离
};
vector<vector<graphNode>> graph;
bool visited[dotNum + 1];//标记节点是否加入最小生成树
int dis[dotNum + 1];//记录未标记的节点i加入最小生成树的最小权值
//输出最小生成树的边权和
int prim(){
  memset(visited, false, sizeof(visited));
  memset(dis, inf, sizeof(dis));
  dis[1] = 0;
  int ans = 0;
  for(int i = 1; i <= dotNum; ++i){
    int mark = -1;
    //从未加入树的节点中选一个最接近树的节点
    for(int j = 1; j <= dotNum; ++j){
      if(!visited[j]){
        if(mark == -1 || dis[j] < dis[mark]){
          mark = j;
        }
      }
    }
    if(mark == -1){
      return ans;
    }
    visited[mark] = true;
    ans += dis[mark];
    //根据新加入树的节点更新距离树的距离
    for(int j = 0; j < graph[mark].size(); ++j){
      int x = graph[mark][j].number;
      if(!visited[x]){
        if(dis[x] < graph[mark][j].dis){
          dis[x] = graph[mark][j].dis;
        }
      }
    }
  }
  
}
int main(){
  
}
