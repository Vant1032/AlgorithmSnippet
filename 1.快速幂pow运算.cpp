/*
快速幂（pow）运算 

*/
#include <stdio.h>
long long pow(long long x, long long n){
  long long result;
  if(n == 0)return 1;
  else{
    while((n & 1) == 0){
      x *= x;
      n >>= 1;
    }
  }
    result = x;
    n >>= 1;
    while(n != 0){
      x *= x;
      if((n & 1))result *= x;
      n >>= 1;
    }
  return result;
} 
int main(){
	long long a, b;
	while(~scanf("%lld%lld", &a, &b))printf("%lld\n", pow(a, b));
}

