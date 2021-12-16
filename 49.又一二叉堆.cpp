/*
此为大顶堆(最大堆)
*/
#include <DB.hpp>

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
template<class T>
class Heap{
  private:
    vector<T> heap;
    void down(const int &i){
      T tmp = heap[i];
      int len = heap.size();
      int current = i;
      for(int child = (i << 1) + 1; child < len; child = (child << 1) + 1){
        child += child + 1 < len && heap[child + 1] > heap[child];
        if(tmp >= heap[child])break;
        heap[current] = heap[child];
        current = child;
      }
      heap[current] = tmp;
    }
    void up(const int &i){
      T tmp = heap[i];
      int current = i;
      for(int parrent = (i - 1) >> 1; parrent >= 0; parrent = (parrent - 1) >> 1){
        if(tmp <= heap[parrent])break;
        heap[current] = heap[parrent];
        current = parrent;
      }
      heap[current] = tmp;
    }
    /*i代表长度,增加至至少支持i大小的长度*/
    void expand(int i){
      if(i > heap.size()){
        heap.resize(i);
      }
    }
  public:
    /*根据数组来初始化一个堆*/
    Heap(const T *arr, const int &len){
      heap.assign(arr, arr + len);
      for(int i = (len - 1) >> 1; i >= 0; i--){
        down(i);
      }
    }
    bool empty(){
      return heap.empty();
    }
    T top(){
      return heap[0];
    }
    void pop(){
      heap[0] = heap.back();
      heap.pop_back();
      down(0);
    }
    void push(const T &key){
      heap.push_back(key);
      up(heap.size() - 1);
    }
    int size(){
      return heap.size();
    }
};
int main(){
  int d[1000], test[10], len, cp[100];
  char str[100];
  while(gets(str)){
    len = 0;
    db.randomArray(d, 10);
    db.showArray(d, 10);
    Heap<int> heap(d, 10);
    db.randomArray(cp, 100);
    for(int i = 0; i < 100; i++){
      heap.push(cp[i]);
    }
    while(!heap.empty()){
      test[len++] = heap.top();
      heap.pop();
    }
    db.showArray(test, 110);
    db.ordered(test, 110, DB<int>::lesser);
  }
}

