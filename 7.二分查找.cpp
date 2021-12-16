/*

*/
#include <iostream>
using namespace std;
//必须保证数组有序 
int binarysearch(int *a, int len, int key){
  int left = 0, right = len - 1, mid = (right + left) / 2, pos = -1;
  while(left <= right){
    if(a[mid] < key){
      left = mid + 1;
    }else if(a[mid] > key){
      right = mid - 1;
    }else{
      return mid;
    }
    mid = (right + left) / 2;
  }
  return -1;
}
int main(){
	ios::sync_with_stdio(false);
	int a[100], k;
	for(int i = 0; i < 100; i++){
	  a[i] = i;
	}
	while(cin>>k)
	cout<<binarysearch(a, 100, k)<<endl;
}

