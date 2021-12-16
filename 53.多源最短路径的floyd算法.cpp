/*
求图中任意两点之间的最短距离的floyd算法:
http://developer.51cto.com/art/201403/433874.htm
原理是动态规划，注意，这个算法运行一次，就把图中所有两点间的最短路径求出来了，是多源最短路
对于稠密图，效率要高于执行|V|次Dijkstra算法，也要高于执行|V|次SPFA算法。边权可正可负
*/
#include <iostream>
using namespace std;
const int maxN = 111;
const int inf = 0x3f3f3f3f;
int N, graph[maxN][maxN];//N代表节点个数，g[i][j]代表点i到j的距离如果i到j没有直接连接，则距离为inf，
//经过此算法运行，则graph[i][j]变为点i到j的最短距离
void floyd(){
//如果将k放在最内层，则比较大小时的graph最短距离数据不真实(没有及时更新)，而放在最外层，初始时最短数据真实，推出的数据真实，则根据这些数据产生的最短数据也真实
//换一种思考方式：可以将k看作求i到j的最短路径的辅助点，即看从i到j经过k中转是否会更近
  for(int k = 1; k < N; ++k){
    for(int i = 1; i < N; ++i){
      for(int j = 1; j < N; ++j){
        if(graph[i][j] > graph[i][k] + graph[k][j]){
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }
}
int main(){
}

