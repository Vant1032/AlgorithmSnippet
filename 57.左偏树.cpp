/*
这是小顶堆
http://www.cnblogs.com/yc_sunniwell/archive/2010/06/28/1766756.html
左偏树，也可以称之为左式堆。高级堆结构的核心就是如何有效地进行合并
首先看左偏树的性质：
1.【堆性质】：任意节点的关键字大于等于其孩子节点的关键字
2.【左偏性质】：定义到最近的孩子的距离为节点距离dist，那么任意节点的左孩子的距离大于右孩子的距离。
                                A->lchild->dist >= A->rchild->dist
3.一颗N个节点的左偏树距离最多为log(N+1)-1
堆性质是为了让最小的结点始终在根的位置，这是所有堆都有的性质。
而左偏性质，则是为了让树状存储的堆，树的深度不能过大，且利于合并。
左偏树就是对其任意子树而言，往右到插入点的距离（下面简称为“距离”）始终小于等于往左到插入点的距离，当然了，和二叉堆一样，父节点的值要小于左右子节点的值
父节点的距离 = 右子节点距离 + 1

(1)左偏树的合并

c <- Merge(A,B)

Merge()把A、B两颗左偏树合并，返回一颗新的左偏树C，包含A和B中的所有元素。这里一颗左偏树用它的根节点指针表示。

在合并操作中，最简单的情况是其中一棵树为NULL，这时只需要返回另一棵树。

若A和B都非空，假设A的根节点小于等于B的根节点(否则交换A、B)，把A的根节点作为新树C的根节点，剩下的事就是合并A的右子树和B了

合并Right(A)和B之后，right(A)的距离可能会变大，当right(A)的距离大于left(A)的距离时，左偏树的性质(2)会被破坏，在这时，只需要交换left(A)和right(B);

最后，由于right(A)的距离可能发生改变，必须更新A的距离。

(2)插入新节点

单节点的树一定是左偏树，因此向左偏树插入一个节点可以看做是对两颗左偏树的合并。

(3)删除节点

删除根节点后，只需要把左子树和右子树合并。
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node{
  int data;
  int dist;
  Node *lc, *rc;
  Node(){
  }
  Node(const int key, const int dist = 0, Node *lc = nullptr, Node *rc = nullptr){
    data = key;
    this->dist = dist;
    this->lc = lc;
    this->rc = rc;
  }
};
//返回merge之后的堆顶元素的指针，a、b分别为待合并的两个左偏堆
Node *merge(Node *&a, Node *&b){
  if(a == nullptr){
    return b;
  }
  if(b == nullptr){
    return a;
  }
  if(a->data > b->data){//维护堆的性质，a作为被插入的树，b插入a中
    swap(a, b);
  }
  //先合并到距离小的合并得更快，左偏堆的精髓
  a->rc = merge(a->rc, b);//将b堆合并到a的右子树（注意：由于a,b本身是左偏堆，左边距离大于右边）
  if(a->lc == nullptr || a->rc->dist > a->lc->dist){//保证左边距离大于右边
    swap(a->lc, a->rc);
  }
  //更新距离,由于只改动了右子树，所以。。。
  if(a->rc == nullptr){//在递归中最底层就会碰到这种情况,若右子树为空则dis为0
    a->dist = 0;
  }else{
    a->dist = a->rc->dist + 1;
  }
  return a;
}
void insert(Node *&tree, const int &key){//新建一颗只有key的左偏树，再合并
  Node *p = new Node(key);
  tree = merge(tree, p);
}
int top(Node *&tree){
  return tree->data;
}
void pop(Node *&tree){//合并根节点的两颗子树
  Node *p = tree;
  tree = merge(tree->lc, tree->rc);
  delete p;
}
int main(){
  srand(time(nullptr));
  Node *t1 = new Node(50);
  Node *t2 = new Node(60);
  int tnum;
  for(int i = 0; i < 10; i++){
    tnum = rand() % 100;
    insert(t1, tnum);
    cout << tnum << " ";
  }
  cout << endl;
  for(int i = 0; i < 10; i++){
    tnum = rand() % 100;
    insert(t2, tnum);
    cout << tnum << " ";
  }
  cout << endl;
//  cout << "t1: ";
//  while(t1){
//    cout << top(t1) << " ";
//    pop(t1);
//  }
//  cout << endl;
//  cout << "t2: ";
//  while(t2){
//    cout << top(t2) << " ";
//    pop(t2);
//  }
//  cout << endl;
  Node *tp = merge(t1, t2);
  cout << "tp: ";
  while(tp){
    cout << top(tp) << " ";
    pop(tp);
  }
  cout << endl;
}

