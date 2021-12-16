#include <iostream>
#include <algorithm>
#include <string.h> 
using namespace std;
int w[105], v[105], m[100000];
//空间复杂度O(n) 
int main(){
	ios::sync_with_stdio(false);
	int n, W;//n种物品，W为最大重量 
	while(cin>>n>>W){
	  memset(m, 0, sizeof(m));
	  for(int i = 1; i <= n; i++)cin>>w[i]>>v[i];
	  for(int i = 1; i <= W; i++){
	    if(i >= w[1])m[i] = v[1];//i背包负重 
	    else m[i] = 0;
	  }
	  for(int i = 2; i <= n; i++){
	    for(int j = W; j > 0; j--){
	      if(j >= w[i])m[j] = max(m[j], m[j - w[i]] + v[i]);
	    }
	  }
	  cout<<m[W]<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	
}

