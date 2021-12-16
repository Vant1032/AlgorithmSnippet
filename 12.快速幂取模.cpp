/*
快速幂取模算法 
*/
#include <stdio.h>

int powmod(int x, int n, int mod){
  x %= mod;
  int r = 1;
  while(n){
    if(n & 1)r = (r * x) % mod;
    n >>= 1;
    x = (x * x) % mod;
  }
  return r;
}

using namespace std;
int main(){
	printf("%d\n", powmod(50, 100, 6));
}

