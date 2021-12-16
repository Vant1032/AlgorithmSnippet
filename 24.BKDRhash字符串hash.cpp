/*
字符串hash中挺高效的BKDRhash； 
*/
#include <stdio.h>
using namespace std;
unsigned BKDRhash(const char *p){
  unsigned seed = 131313;//seed为偶数会使碰撞概率大大增加，一定要为奇数 
  unsigned hash = 0;
  while(*p){
    hash = hash * seed + (*p++);
  }
  return hash & 0x7fffffff;
}
int main(){
  
}

