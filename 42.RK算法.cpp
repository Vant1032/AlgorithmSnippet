/*

*/
#include <stdio.h>
#include <string.h>
using namespace std;
const int prime = 1e8 + 7;
inline bool check(char *src, char *pattern) {
	while(*pattern) {
		if((*pattern) != (*src))return false;
		pattern++;
		src++;
	}
	return true;
}
int RK(char *src, char *pattern) {
	int plen = 0, slen = 0, phash = 0, shash = 0;
	while(*pattern) {
		phash = ((*pattern) + (phash << 10)) % prime;
		plen++;
		pattern++;
	}
	pattern = pattern - plen;
	slen = strlen(src);
	if(slen < plen || plen == 0)return -1;
	int rm = 1;
	for(int i = 1; i < plen; i++)rm = (rm << 10) % prime;//计算出后面用于相减的那个东西
	for(int i = 0; i < plen; i++) {
		shash = (src[i] + (shash << 10)) % prime;
	}
	if(check(src, pattern))return 0;//拉斯维加斯算法，省略后就变成蒙特卡洛算法（有非常小概率出错）
	char *cpysrc = src;
	char *tmp = src + plen;//后一个
	while(*tmp) {
		shash = (((shash - rm * (*src)) << 10) + *tmp) % prime;
		if(shash == phash && check(src + 1, pattern))return src - cpysrc + 1;
		tmp++;
		src++;
	}
	return -1;//代表未找到
}
int main() {
	char src[] = "121213231122313123221232122123131";
	char pattern[] = "";
	printf("%d\n", RK(src, pattern));
}


