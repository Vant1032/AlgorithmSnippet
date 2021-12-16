/*
	Author: vant 
	Date: 05/02/17 19:22
	Description: 我的stack
*/
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Stack {
	private:
		struct Node {
			int data;
			Node *next;
			Node(int data_ = 0, Node *next_ = NULL) {
				data = data_;
				next = next_;
			}
		};
		Node *top, *tmp;
	public:
		Stack();
		~Stack();
		int pop();
		void push(int data_);
		bool empty() {
			return top->next == NULL;
		};
		void clear();
};
Stack::Stack() {
	top = new Node;
}
Stack::~Stack() {
  clear();
  delete top;
}
void Stack::clear() {
  while(!empty())pop();
}

void Stack::push(int data_){
  tmp = new Node(data_, top->next);
  top->next = tmp;
}
int Stack::pop(){
  int tt = top->next->data;
  tmp = top->next;
  top->next = top->next->next;
  delete tmp;
  return tt;
}
int main() {
	Stack s;
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	while(!s.empty()){
	  cout<<s.pop()<<endl;
  }
  s.clear();
}

