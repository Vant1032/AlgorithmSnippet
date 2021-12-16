/*

*/
#include <iostream>
#include <string.h>
#include <algorithm>
#define NDEBUG //在调试结束后启用这个宏以取消assert的作用
#include <assert.h>
using namespace std;
/**
 *1.frontIterator是从左往右从上至下push的，backIterator是从下至上从右至左push的
 */
template<class T>
class Deque {
  private:
    int nodeLength = 40;
    int nodeCount = 10;
    size_t elementCount = 0;
    struct Node {
      T *data;
    };
    struct Iterator {
      int pos;
      int nodePos;//node所在的位置
    };
    Node *controller;
    Iterator frontIterator, backIterator;
  public:
    Deque() {
      controller = new Node[nodeCount];
      frontIterator.nodePos = backIterator.nodePos = nodeCount / 2;
      controller[frontIterator.nodePos].data = new T[nodeLength];
      frontIterator.pos = 0;
      backIterator.pos = 1;//防止一开始来个pushBack产生bug(多出一个随机元素)
    }
    ~Deque() {
      for(; frontIterator.nodePos <= backIterator.nodePos; ++frontIterator.nodePos) {
        delete[] controller[frontIterator.nodePos].data;
      }
      delete[] controller;
    }
    T front() {
      return controller[frontIterator.nodePos].data[frontIterator.pos];
    }
    T back() {
      return controller[backIterator.nodePos].data[backIterator.pos];
    }
    void popFront() {
      --elementCount;
      if(frontIterator.pos == 0) {
        delete[] controller[frontIterator.nodePos].data;
        ++frontIterator.nodePos;
        frontIterator.pos = nodeLength - 1;
      } else {
        --frontIterator.pos;
      }
    }
    void popBack() {
      --elementCount;
      if(backIterator.pos + 1 == nodeLength) {
        delete[] controller[backIterator.nodePos].data;
        --backIterator.nodePos;
        backIterator.pos = 0;
      } else {
        ++backIterator.pos;
      }
    }
    void pushBack(const T &key) {
      ++elementCount;
      if(backIterator.pos == 0) {
        if(backIterator.nodePos + 1 == nodeCount) {
          int lineCount = backIterator.nodePos - frontIterator.nodePos + 1;
          Node *tmpCtrl = controller;
          nodeCount <<= 1;
          controller = new Node[nodeCount];
          int offSet = (nodeCount - lineCount) / 2;
          copy(tmpCtrl + frontIterator.nodePos, tmpCtrl + backIterator.nodePos + 1, controller + offSet);
          frontIterator.nodePos = offSet;
          backIterator.nodePos = frontIterator.nodePos + lineCount;//因为是Back满了，所以backIterator.nodePos的位置要加一
          controller[backIterator.nodePos].data = new int[nodeLength];
          backIterator.pos = nodeLength - 1;
          delete[] tmpCtrl;
        } else {
          ++backIterator.nodePos;
          controller[backIterator.nodePos].data = new int[nodeLength];
          backIterator.pos = nodeLength - 1;
        }
      } else {
        --backIterator.pos;
      }
      controller[backIterator.nodePos].data[backIterator.pos] = key;
    }
    void pushFront(const T &key) {
      ++elementCount;
      if(frontIterator.pos + 1 == nodeLength) {
        if(frontIterator.nodePos == 0) {
          int lineCount = backIterator.nodePos - frontIterator.nodePos + 1;
          Node *tmpCtrl = controller;
          nodeCount <<= 1;
          controller = new Node[nodeCount];
          int offSet = (nodeCount - lineCount) / 2;
          copy(tmpCtrl, tmpCtrl + lineCount, controller + offSet);
          frontIterator.nodePos = offSet - 1;
          backIterator.nodePos = frontIterator.nodePos + lineCount;
          frontIterator.pos = 0;
          delete[] tmpCtrl;
        } else {
          --frontIterator.nodePos;
          controller[frontIterator.nodePos].data = new int[nodeLength];
          frontIterator.pos = 0;
        }
      } else {
        ++frontIterator.pos;
      }
      controller[frontIterator.nodePos].data[frontIterator.pos] = key;
    }
    bool empty() {
      return elementCount == 0;
    }
    size_t size() {
      return elementCount;
    }
};

int main() {
  Deque<int> d;
  for(int i = 1; i < 111; i++) {
    d.pushFront(i);
  }
  while(!d.empty()) {
    cout << d.front() << endl;
    d.popFront();
  }
}

