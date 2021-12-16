/*
位运算 
*/
#include <stdio.h>
using namespace std;
void DectoBin(int num){//十进制转二进制 
  for(int i = 31; i >= 0; i--){
    printf("%d", ((num >>i) & 1));
  }
  putchar('\n');
}
inline int max(int a, int b){//位运算实现求最大值 
  return b & ((a - b) >> 31) | a & (~(a - b) >> 31);
  /*
  (a - b) >> 31 是求其相减的正负的(结果为0000000或11111111)， >>是带符号右移
  */
}
inline bool ispowoftwo(int n){//因为二的幂必然是类似1000，其减一就是0111，进行与运算就是0，唯一的例外就是0 
  return (!(n & (n - 1)) && n);//判断是否二的幂 
} 
inline bool isSameSign(int x, int y) {//因为真正控制二进制数的正负的是最高位，如果相同则返回0，即一个正数 
  return (x ^ y) >= 0;
} 

int main(){
	
}

