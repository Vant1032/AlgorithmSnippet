/*

*/
#include <stdio.h>
#include <algorithm>
using namespace std;
template<class Iterator>
bool next_permutation(Iterator first, Iterator last){
  if(first == last)return false;
  Iterator i = first;
  ++i;
  if(i == last)return false;
  i = last;
  --i;
  Iterator ii;
  
  while(true){
    ii = i;
    --i;
    if(*i < *ii){
      
    }
  }
}
int main(){
	
}

