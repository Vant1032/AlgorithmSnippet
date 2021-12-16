/*
前向星
1.这种存储图的方式相比邻接数组省空间
2.http://blog.csdn.net/lvshubao1314/article/details/22958683
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct Edge {
  int begin, end;
  bool operator<(const Edge &other) const{
    if(begin != other.begin) {
      return begin < other.begin;
    }
    return end < other.end;
  }
};
Edge edge[1000];//edge的大小是边的个数
int start[2000];//start的大小是点的编号的最大值
int main() {
  int nInput;
  cin>>nInput;
  for(int i = 0; i < nInput; i++) {
    cin>>edge[i].begin>>edge[i].end;
  }
  sort(edge, edge + nInput);
  int cnt = 0;
  start[edge[0].begin] = cnt;
  //预处理出起点为begin的第一条的位置
  for(int i = 1; i < nInput; i++){
    if(edge[i].begin != edge[i - 1].begin){
      start[edge[i].begin] = cnt++;
    }
  }
}

