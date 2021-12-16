/*
二叉堆，数组实现
18/02/17 11:44 
*/
#include <DBTest.hpp> 
#include <iostream>
#include <string.h>
using namespace std;
template <class T>
class BinaryHeap { //此为最小堆，若要最大堆，修改比较运算符即可
	private:
		T *heap;//堆中的元素
		int len;//二叉堆真实大小，因为heap[0]不被用到，所以比能存放的元素大一 
		int n;//堆中当前元素的个数
		int *pos;//第i个插入堆中的元素在堆中的位置
		int *id;//记录堆中位置为i的元素是第几个插入堆中的
		void up(int i) { //
			T tmp = heap[i];
			int y = id[i];
			for(int j = i >> 1; j >= 1; j >>= 1) {
				if(heap[j] > tmp) {
					heap[i] = heap[j];
					id[i] = id[j];
					pos[id[i]] = i;
					i = j;
				} else {
					break;
				}
			}
			heap[i] = tmp;
			id[i] = y;
			pos[y] = i;
		}
		void down(int i) {
			int x = heap[i], y = id[i];
			for(int j = i << 1; j <= n; j <<= 1) {
				j += (j < n) && (heap[j] > heap[j + 1]);
				if(x > heap[j]) {
					heap[i] = heap[j];
					id[i] = id[j];
					pos[id[i]] = i;
					i = j;
				} else {
					break;
				}
			}
			heap[i] = x;
			id[i] = y;
			pos[y] = i;
		}
	public:
		BinaryHeap(T *array, const int &len_) {//利用一个数组构建二叉堆 
			len = len_ + 1;
			heap = new T[len];
			pos = new int [len];
			id = new int[len];
      n = len_;
			memcpy(heap + 1, array, len_ * sizeof(T));
			for(int i = 1; i < len; i++){
			  id[i] = pos[i] = i;
      }
			for(int i = len >> 1; i >= 1; i--) {
				down(i);
			}
		}
		~BinaryHeap() {
			delete[] heap;
			delete[] pos;
			delete[] id;
		}
		T top() { //返回顶部元素
			return heap[1];
		}
		bool empty() {
			return n == 0;
		}
		int size() {//当前放了多少元素 
			return n;
		}
		int totalSize(){//总共可以放下多少元素 
		  return len - 1;
    }
		void push(const T &v) { //加入堆中，如果堆已经满了，就不能再增加元素 
			heap[++n] = v;
			id[n] = n;
			pos[id[n]] = n;
			up(n);
		}
		void pop() { //将顶部元素删除
			heap[1] = heap[n];
      id[1] = id[n];
      n--;
			pos[id[1]] = 1;
			down(1);
		}
		void change(int i, const T &value) { //修改第i个加入的元素为value
			if(heap[pos[i]] > value) {
				heap[pos[i]] = value;
				up(pos[i]);
			} else {
				heap[pos[i]] = value;
				down(pos[i]);
			}
		}
		T get(const int &i) { //返回第i个加入的元素的值
			return heap[pos[i]];
		}
};
int main() {
	double d[10];
	DBTest<double>::randomArray(d, 10);
	DBTest<double>::showArray(d, 10);
	BinaryHeap<double> h(d, 10);
	while(!h.empty()) {
		cout<<h.top()<<endl;
		h.pop();
	}
}

