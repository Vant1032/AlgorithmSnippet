/*

*/
#include <stdio.h>
#include <queue>
using namespace std;
struct Node{
  int data;
  Node *lc, *rc;
};
void BFS(Node *root){
  queue<Node *> q;
  q.push(root);
  Node *tmp;
  while(!q.empty()){
    tmp = q.top();
    q.pop();
    printf("%d\n", tmp.data);
    if(tmp->lc)q.push(tmp->lc);
    if(tmp->rc)q.push(tmp->rc);
  }
  printf("end\n");
}
int main(){
	 
}

