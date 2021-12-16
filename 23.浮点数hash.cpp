/*
浮点数hash 
*/
#include <stdio.h>
using namespace std;
const int MOD = 13;
int d[14];
int fhash(const double &k){
  unsigned int t = *(unsigned int *) &k;
  return t % MOD;
}
int main(){
  int t;
	for(double i = 30.0; i <= 60.0; i += 0.1){
	  t = fhash(i);
	  ++d[t];
	  printf("%lf   %d\n", i, t);
  }
  for(int i = 0; i < 13; i++){
    printf("@ %d  %d\n", i, d[i]);
  }
}

