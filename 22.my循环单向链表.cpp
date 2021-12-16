/*
单向循环链表 
*/
#include <stdio.h>
using namespace std;
class SList {
	private:
		struct Node {
			int data;
			Node *next;
			Node(){
      } 
			Node(const int &data_,  Node *const &next_) {
				data = data_;
				next = next_;
			}
		};
		
		Node *head, *tail, *tp;
	public:
		SList():head(NULL), tail(NULL) {
		}
		~SList() {
		}
		void push_back(const int &data_);//只能从尾部放入
		void del_back();//在链表空的情况下删除会产生异常 
		bool empty();
		
};
void SList::push_back(const int &data_) {
  if(head == NULL){
    head = tail = new Node(data_, head);
  }else{
    tail->next = new Node(data_, head);
    tail = tail->next;
  }
}
void SList::del_back(){
  if(head == tail && head != NULL){
    delete head;
    head = tail = NULL;
    return;
  }
  tp = head;
  while(tp->next->next){
    tp = tp->next;
  }
  delete tp->next;
  tp->next = head;
  tail = tp;
}
bool SList::empty(){
  return head == tail && head != NULL;
}
int main() {
  SList s;
  
}

