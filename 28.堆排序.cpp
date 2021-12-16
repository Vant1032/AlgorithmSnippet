/*
实现堆排序(最大堆)
由于数组是从0开始，所以有所不同
*/
#include <stdio.h>
#include <iostream>
using namespace std;
void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}
void down(int *p, int len, int i) {
	int tmp = p[i];
	for(int j = (i << 1) + 1; j < len; j = (j << 1) + 1) {
		if(j < len - 1 && p[j + 1] > p[j]) {
			j++;
		}
		if(tmp >= p[j]) {
			break;
		} else {
			p[i] = p[j];
			i = j;
		}
	}
  p[i] = tmp;
}
void buildHeap(int *p, int len) {
	for(int i = (len - 1) >> 1; i >= 0; i--) {
		down(p, len, i);
	}
}
void heapSort(int *p, int len) {
	buildHeap(p, len);
	for(int i  = len - 1; i >= 1; i--) {
		swap(p[0], p[i]);
		down(p, i, 0);
	}
}
int main() {
	int d[9];
	d[8] = 111111;
	heapSort(d, 8);
}

