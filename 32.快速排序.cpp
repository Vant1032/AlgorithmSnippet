/*
快速排序
 
*/
#include <stdio.h>
using namespace std;
void swap(int &a, int &b){
  a ^= b;
  b ^= a;
  a ^= b;
} 
void quicksort(int *p, int left, int right){
  if(left >= right)return;
  int i = left, j = right, tmp = p[left];
  while(i < j){
    while(i < j && p[j] >= tmp)j--;
    while(i < j && p[i] <= tmp)i++;
    if(i != j){
      swap(p[i], p[j]);
    }
  }
  p[left] = p[i];
  p[i] = tmp;
  quicksort(p, left, i - 1);
  quicksort(p, i + 1, right);
}
void sort(int *p, int len){
  quicksort(p, 0, len - 1);
}
int main(){
  
}

