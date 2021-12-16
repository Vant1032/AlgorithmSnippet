/*
DFS法求全排列 
*/
#include <stdio.h>
using namespace std;
const int size = 5;
int mem[size + 1];
bool mark[size + 1];
void DFS(int i){
  if(i == size + 1){
    for(int i = 1; i <= size; i++)printf("%d ", mem[i]);
    putchar('\n');
    return;
  }
  for(int j = 1; j <= size; j++){
    if(mark[j] == 0){
      mem[i] = j;
      mark[j] = 1;
      DFS(i + 1);
      mark[j] = 0;
    }
  }
} 
int main(){
	DFS(1);
}

