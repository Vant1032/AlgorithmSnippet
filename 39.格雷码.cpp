/*
格雷码 
*/
#include <stdio.h>
#include <string.h>
using namespace std;
/*
给定一个数组，这串数字转换成格雷码，数字为0或1 
*/ 
void numToGray(int *p, int len){
  int array[len];
  array[0] = p[0];
  for(int i = 1; i < len; i++){
    array[i] = p[i - 1] ^ p[i];
  }
  memcpy(p, array, sizeof(array));
}

int main(){
	int p[8] = {1, 0, 1, 1, 0, 1, 0, 0};
	numToGray(p, 8);
	for(int i = 0; i < 8; i++){
	  printf("%d ", p[i]);
  }
}

