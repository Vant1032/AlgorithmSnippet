/*
初始时数组全为0，然后可以利用modify往里面添加元素 
*/
#include <stdio.h>
using namespace std;
const int SIZE = 10000;
int d[SIZE]; 
inline int lowbit(const int &n) {
	return n&(-n);
}
int modify(int pos, int k) {//将pos位置的元素加上k 
	for(; pos <= n; pos += lowbit(pos)) {
		d[pos] += k;
	}
}
int getSum(int n) {//获取从开头到n位置的数的总和 
	int r = 0;
	for(; n > 0; n -= lowbit(n))
    r += d[n];
	return r;
}

int main() {
}

