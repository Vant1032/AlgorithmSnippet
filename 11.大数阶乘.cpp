/*
大数阶乘
//此代码亦可以 
#include <iostream>
using namespace std;
int d[100000];

int main(){
	ios::sync_with_stdio(false);
	int n, t, len, sum;
	while(cin>>n){
	  len = 1;
	  d[0] = 1;
	  t = 0; 
	  for(int i = 1; i <= n; i++){
	    for(int j = 0; j < len; j++){
	      t += d[j] * i;
  	    d[j] = t % 10;
  	    t /= 10;
	    }
	    while(t){
        d[len++] = t % 10;
        t /= 10;
      }
	  }
    
    for(int i = len - 1; i >= 0; i--)cout<<d[i];
    cout<<endl;
	}
	
   
}
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> d;

int main(){
	ios::sync_with_stdio(false);
	int n, t, len, sum;
	d.reserve(100000);
	while(cin>>n){
	  len = 1;
	  d[0] = 1;
	  t = 0; 
	  for(int i = 1; i <= n; i++){
	    for(int j = 0; j < len; j++){
	      t += d[j] * i;
  	    d[j] = t % 10;
  	    t /= 10;
	    }
	    while(t){
        d[len++] = t % 10;
        t /= 10;
      }
	  }
    
    for(int i = len - 1; i >= 0; i--)cout<<d[i];
    cout<<endl;
	}
}


