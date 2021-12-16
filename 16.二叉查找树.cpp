/*

*/
#include <stdio.h>
#include <iostream>
using namespace std;
template <class T>
class node{
  public:
    node():left(NULL), right(NULL), fre(1){}
    T data;
    unsigned fre;
    node<T> *left, *
    right;
}; 
template <class T>
class BST{
  private:
    node<T>* root;
    void inserttree(node<T>* &nd, T x);
    node<T>* findtree(node<T>* nd, T x);
    void insubtree(node<T>* node);//中序遍历
    void deltree(node<T>* &node, T x);
  public:
    BST():root(NULL){}
    void insert(T x);
    node<T>* find(T x);
    void del(T x);
    void travel();
};
template <class T>
void BST<T>::inserttree(node<T>* &nd, T x){
  if(nd == NULL){
    nd = new node<T>;
    nd->data = x;
    return;
  }
  if(nd->data > x){
    inserttree(nd->right, x);
  }else if(nd->data < x){
    inserttree(nd->left, x);
  }else nd->fre++;
} 
template<class T>
void BST<T>::insert(T x){
  inserttree(root, x);
}
template<class T>
node<T>* BST<T>::findtree(node<T>* nd, T x){//从某个节点查找 
  if(nd == NULL){
    return NULL;
  }
  if(nd->data > x){
    return findtree(nd->left, x);
  }else if(nd->data < x){
    return findtree(nd->right, x);
  }else return nd;
}
template <class T>
node<T>* BST<T>::find(T x){
  return findtree(root, x);
}
template <class T>
void BST<T>::deltree(node<T>* &p, T x){
  if(p == NULL)return;
  if(x > p->data)deltree(p->right, x);
  else if(x < p->data)deltree(p->left, x);
  else{
    if(p->left != NULL && p->right != NULL){
      node<T>* temp = p->right;
      while(temp->left)temp = temp->left;
      p->data = temp->data;
      p->fre = temp->fre;
      deltree(temp, x);
    }else {
      node<T>* temp = p;
      if(p->left == NULL)p = p->right;
      else if(p->right == NULL)p = p->left;
      delete temp;
    }
  }
}
template <class T>
void BST<T>::del(T x){
  deltree(root, x);
}
template <class T>
void BST<T>::insubtree(node<T>* nd){//从小到大输出 
  if(nd == NULL)return;
  insubtree(nd->left);
  for(int i = 0; i < nd->fre; i++)cout<<nd->data<<" ";
  insubtree(nd->right);
}
template <class T>
void BST<T>::travel(){
  insubtree(root);
}
int main(){
	BST<int> tree;
	int n;
	while(~scanf("%d", &n)){
	  tree.insert(n);
  }
  tree.travel();
}

