/*
KMP算法 

*/

#include <stdio.h>
#include <string.h>
using namespace std;

int KMP(char *str, char *pattern){
  int plen = strlen(pattern);
  int slen = strlen(str);
  //makeNext
  int next[plen];
  next[0] = -1;
  int i = 0, k = -1;
  while(i < plen - 1){
    if(k == -1 || pattern[i] == pattern[k]){
      if(pattern[i + 1] == pattern[k + 1]){//在这对相同前后缀中，k是在前的那个的位置，i是较后的那个的位置 
        next[++i] = next[++k];
      }else{
        next[++i] = ++k;
      }
    }else{
      k = next[k];
    }
  }
  //search
  k = i = 0;
  while(i < slen && k < plen){
    if(k == -1 || str[i] == pattern[k]){
      ++i;
      ++k;
    }else{
      k = next[k];
    }
  }
  if(k == plen)return i - k;
  return -1;
}
int main(){
	char p[] = "265";
	char str[] = "5265626562652652";
	printf("%d\n", KMP(str, p));
}

