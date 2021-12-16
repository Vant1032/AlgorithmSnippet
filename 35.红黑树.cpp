/*
红黑树
 
*/
#include <stdio.h>
using namespace std;
struct Node{
  bool isRed;
  Node *lc, *rc;
  int data;
};
Node * rightRotate(Node *& root){
  Node *tmp = root->lc;
  root->lc = tmp->rc;
  tmp->rc = root;
  return tmp;
}
Node * leftRotate(Node *&root){
  Node *tmp = root->rc;
  root->rc = tmp->lc;
  tmp->lc = root;
  return tmp;
}

int main(){
	
}

