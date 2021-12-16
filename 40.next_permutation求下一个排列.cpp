/*
实现了对给定序列求下一个排列 
*/
#include <stdio.h>
using namespace std;

inline void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}
inline void reverse(int *p, int left, int right) {
	while(left < right) {
		swap(p[left++], p[right--]);
	}
}
bool next_permutation(int *p, int len) {
	if(len <= 1)return false;
	int i, j;
	i = len - 2;
  j = len - 1;
	while(p[i] > p[i + 1] && i >= 0)i--;
	if(i == -1)return false;
	while(p[i] > p[j])j--;
	swap(p[i], p[j]);
	reverse(p, i + 1, len - 1);
	return true;
}
int main() {
  int d[5] = {1, 2, 3, 4, 5};
  do{
    for(int i = 0; i < 5; i++)printf("%d ", d[i]);
    putchar('\n');
  }while(next_permutation(d, 5));
}

