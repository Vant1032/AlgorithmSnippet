/*
RMQ 求区间最大值
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
class ST {
	private:
		struct Node {
			int end;
			int *data;
			~Node() {
				delete [] data;
			}
		}
		Node mem[];
		void init(int *p, int len) {
			mem = new Node[len];
			int r, j;
			for(int i = 0; i < len; i++) {
				r = 1;
				for(j = 0; r < len - i - 1; j++) {
					r <<= 1;
				}
				mem[i].data = new int[j+1];
				mem[i].end = j;
			}
			for(int i = 0; i < len; i++)mem[i].data[0] = data[i];
			for(int i = 0; i < len; i++) {
        int t;
				for(int j = 1; j <= mem[i].end; j++) {
					if((t = (i+(1<<(j-1)))) <= mem[t].end){
					  mem[i].data[j] = max(mem[i].data[j-1], mem[t].data[j-1]);
          }else{
            mem[i].data[j] = mem[i].data[j-1];
          }
				}
			}
		}
	public:
		ST(int *data, int len) {
			init(data, len);
		}
}

int main() {
	int data[101];
	ST ds(data, 101);
}

