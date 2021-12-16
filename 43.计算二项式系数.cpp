/*
计算二项式系数
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int m[1001][1001];
void c() {
	for(int i = 1; i <= 1000; i++) {
		m[i][i] = m[i][0] = 1;
	}
	for(int i = 2; i <= 1000; i++) {
		for(int j = 1; j < i; j++) {
			m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
		}
	}
}
int main() {
	c();
	printf("%d\n", m[12][5]);
}

