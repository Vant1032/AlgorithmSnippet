/*
归并排序
 
*/
#include <stdio.h>
void arraymerge(int *a, int first, int mid, int last, int temp[]){
  int i = first, j = mid + 1, s = 0;
  while(i <= mid && j <= last){
    if(a[i] <= a[j])temp[s++] = a[i++];
    else temp [s++] = a[j++];
  }
  while(i <= mid)temp[s++] = a[i++];
  while(j <= last)temp[s++] = a[j++]; 
  for(int i = 0; i < s; i++){
    a[first + i] = temp[i];
  }
}
void mergesort(int *a, int left, int right, int temp[]){
  if(left < right){
    int mid = (left + right) / 2;
    mergesort(a, left, mid, temp);
    mergesort(a, mid + 1, right, temp);
    arraymerge(a, left, mid, right, temp);
  }
}
bool Mergesort(int *a, int len){
  int *p = new int[len];
  if(NULL == p)return false;
  mergesort(a, 0, len - 1, p);
  delete[] p;
  return true;
}
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
	  int m;
	  scanf("%d", &m);
	  int a[m];
	  for(int i = 0; i < m; i++)scanf("%d", &a[i]);
	  Mergesort(a, m);
	  for(int i = 0; i < m; i++)printf("%d ", a[i]);
	  putchar('\n');
	}
}

