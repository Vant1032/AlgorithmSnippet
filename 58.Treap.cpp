/*

*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

class Treap {
  private:
    struct Node {
      int priority;
      int data;
      Node *lc, *rc;
      Node(int key) {
        data = key;
        priority = rand();
        lc = rc = nullptr;
      }
    };
    Node *root;
    void Insert(Node *&p, const int &key) {
      if(key < p->data) {
        if(p->lc) {
          Insert(p->lc, key);
        } else {
          
        }
      } else {
        if(p->rc){
          Insert(p->rc, key);
        }else{
          
        }
      }
    }
  public:
    Treap() {
      srand(time(nullptr));
    }
    void insert(int key) {
      if(root == nullptr){
        root = new Node(key);
      }else{
        Insert(root, key);
      }
    }
};
int main() {
}

