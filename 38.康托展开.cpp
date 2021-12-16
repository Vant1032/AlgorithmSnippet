/*

*/
#include<iostream>
#include<stdio.h>
//给定一个字符串，求其在是排列中的第几个 
int cantor(char *p, int len) {
	int r = 0, cnt;
	for(int i = 0; i < len - 1; i++) {
		cnt = 0;
		for(int j = i + 1; j < len; j++) {
			if(p[i] > p[j])cnt++;
		}
		r = (r + cnt) * (len - 1 - i);//秦九韶公式 
	}
	return r;
}
int main() {
	char d[] = "213";
	printf("%d\n", cantor(d, 3));
}

