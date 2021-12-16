/*

*/
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
//块状链表 
const int m = 300;//块大小 
struct data{
  int len;
  data *next;
  int mem[2 * m + 1];//mem[2 * m + 1]
};
data *root;
int insert(int n, int pos){//插入不存在的位置则返回-1 
  if(root == NULL){
    root = new data;
    root->len = 1;
    root->mem[1] = n;
    return 1;
  }
  data *k = root;
  while(pos > k->len && k->next != NULL){
    pos -= k->len;
    k = k->next;
  }
  if(pos > k->len)return -1;
  memmove(k->mem + pos + 1, k->mem + pos, sizeof(int) * (k->len - pos + 1));
  k->mem[pos] = n;
  k->len++;
  if(k->len == (m << 1)){//过大则分裂,维护 
    data *t = new data;
    t->next = k->next;
    k->next = t;
    k->len = m;
    t->len = m;
    memcpy(t->mem + 1, k->mem + m + 1, m * sizeof(int));
  }
  return 0;
} 
int del(int pos){
  data *t = root;
  while(pos > t->len && t->next != NULL){
    pos -= t->len;
    t = t->next;
  }
  if(t->len > pos)return -1;
  t->len--;
  memmove(t->mem + pos, t->mem + pos + 1, (t->len - pos) * sizeof(int));
  return 0;
}
void destroy(data *k){
  if(k){
    destroy(k->next);
    delete k;
  }
}
int find(int pos){
  data *t = root;
  while(pos > t->len && t->next){
    pos -= t->len;
    t = t->next;
  }
  return t->mem[pos];
}
int main(){
	
}

