/*
二叉树的遍历 
*/
#include <stdio.h>
using namespace std;
struct Node{
  int data;
  Node *lc, *rc;//即leftchildren，rightchildren，左孩子，右孩子 
  Node(){
    data = 0;
    lc = rc = NULL;
  }
};
void preOrder(Node *&p){//二叉树的前序遍历 
  if(p == NULL)return;
  printf("%d\n", p->data);
  preOrder(p->lc);
  preOrder(p->rc);
}
void inOrder(Node *&p){//中序 
  if(p == NULL)return;
  inOrder(p->lc);
  printf("%d\n", p->data);
  inOrder(p->rc);
}
void postOrder(Node *&p){//后序 
  if(p == NULL)return;
  postOrder(p->lc);
  postOrder(p->rc);
  printf("%d\n", p->data);
}
int main(){
	
}

