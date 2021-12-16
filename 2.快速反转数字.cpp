/*
将一个数反转 
*/
#include <stdio.h>
int main(){
	int a, r = 0;
  while(a){
    r += r * 10 + a % 10;//将数的取出与合成放在一起 
    a /= 10;
  } 
}

