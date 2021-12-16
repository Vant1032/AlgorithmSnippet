/*
Dijkstra最短路径算法 
*/
#include <stdio.h>
#include <string.h>
using namespace std;
/*
给定的地图：map[][]它确定两个点之间是否互联
visit[]判定是否在之前就求出最短路径
d[]存储源点到此点的最短距离
*/

int dis[10001], map[10001][10001];
bool visited[10001];
const int inf = 0x3f3f3f3f;

void Dijkstra(int src, int len){
  memset(dis, inf, sizeof(dis));
  memset(visited, false, sizeof(visited));
  dis[src] = 0;
  int mindis = inf, mark, tmp;
  for(int i = 0; i < len; i++){
    mindis = inf;
    for(int j = 0; j < len; j++){
      if((!visited[j]) && dis[j] < mindis){//在未访问的点中寻找一个距源点最近的点（初始未无穷大）
        mark = j;
        mindis = dis[j];
      }
    }
    visited[mark] = true;//将找到的点标记访问
    for(int j = 0; j < len; j++){//对该点周围的未访问的点进行松弛操作
      if((!visited[j]) && (tmp = map[mark][j] + mindis) < dis[j]){//看到这就知道为什么不能为负权值，因为否则mindist无法保证总是增加的 
        dis[j] = tmp;
      }
    }
  }
}
int main(){
	
}

