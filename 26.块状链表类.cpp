/*
块状链表类
描述：
1.构造时确定块大小
2.从0开始 
*/
#include <stdio.h>
#include <cmath>
using namespace std;
template <class T>
class BlockList {
	private:
		int block_size;//每一块的大小
		int real_size; 
		struct data {
			int len;
			data *next;
			T *p;
			data() {
				p = new T[real_size];
				next = NULL;
			}
		};
		data *root;
		void clear(data *p);
	public:
		BlockList(int block_size_ = 150) {
			block_size = block_size_;
			real_size = block_size << 1;
			root = new data;
		}
		~BlockList() {
			clear(root);
		}
		BlockList operator=(BlockList && n);
		BlockList operator=(BlockList &n);
		bool insert(const T &key, int pos); //插入时要分裂
		void del(int pos);//删除时要合并
		void clear();//清除块状链表 
		void push_back(const T &key);//尾部添加元素 
};
template <class T>
BlockList<T> BlockList<T>::operator=(BlockList<T> && n) {

}
template <class T>
BlockList<T> BlockList<T>::operator=(BlockList<T> &n) {

}
template <class T>
void BlockList<T>::del(int pos) {
}
template <class T>
bool BlockList<T>::insert(const T &key, int pos) {
	data *t = root;
	while(pos >= t->len && t->next){// >= 可能要改下 
	  pos -= t->len;
	  t = t->next;
  }
  t->p[pos] = key; 
  
   
}
template<class T>
void BlockList<T>::clear(){
  clear(root);
} 
template<class T>
void BlockList<T>::clear(data *p){
  if(p){
    clear(p->data);
    delete[] p;
  }
}
int main() {
  
}

