/*

*/
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
const int num = 40000;//调整范围 
bool a[num + 5];
//暴力法 
bool prime(int n){
  if(n < 2)return false;
  if(n == 2)return true;
  int k = sqrt(n);
  for(int i = 2; i <= k; i++){
    if(n % i == 0)return false;
  }
  return true;
}
int main(){
	memset(a, true, sizeof(a));
  int t = sqrt(num); 
  for (int i = 2; i <= t; i++){
    if(a[i]){
      for(int j = i * i;  j <= num; j += i){//i * i 而不是i + i 是因为i + i必然是二的倍数 
        a[j] = false;
      }
    }
  }
  for(int i = 2; i <= num; i++){
    if(a[i]){
      printf("%d\n", i);
    }
  }
}

