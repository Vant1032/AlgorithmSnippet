/*

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h> 
#include <algorithm>
using namespace std;

void csort(int *a, int len, int max){
  int b[max + 1], c[len + 1];
  memset(b, 0, sizeof(b));
  for(int i = 0; i < len; i++){
    b[a[i]]++;//辅助数组，大小是a[i]里的最大值 ,用于确定比某个数小的个数 
  }
  for(int i = 1; i <= max; i++){
    b[i] += b[i - 1];
  }
  for(int i = len - 1; i >= 0; i--){
    c[b[a[i]]] = a[i];
    b[a[i]]--;
  }
  for(int i = 0; i <= len; i++)a[i] = c[i + 1];
}

int main(){
	ios::sync_with_stdio(false);
	int a[100], t;
	srand(time(0));
	while(cin>>t){
	  for(int i = 0; i < 100; i++){
  	  a[i] = rand() % 101;
  	}
  	csort(a, 100, 100);
  	for(int i = 0; i < 100; i++)cout<<a[i]<<endl;
	}
}

