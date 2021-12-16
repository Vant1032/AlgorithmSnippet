/*
线段树
离散化+扫描
*/
#include <DB.hpp>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
struct Node {
	int max, min;
  int addMark;
	Node *lc, *rc;
	Node():addMark(0), lc(nullptr), rc(nullptr) {}
};
//将延迟标记往下传递
void pushDown(Node *root){
  if(root->addMark){
    root->lc->addMark += root->addMark;
    root->rc->addMark += root->addMark;
    root->lc->max += root->addMark;
    root->lc->min += root->addMark;
    root->rc->max += root->addMark;
    root->rc->min += root->addMark;
    root->addMark = 0;
  }
}
//静态建树
void build(int *a, Node *root, int left, int right) {
	if(left == right) {//叶节点是数组的元素
		root->max = root->min = a[left];
		return;
	}
	int mid = (left+right) >> 1;
	root->lc = new Node;
	root->rc = new Node;
	build(a, root->lc, left, mid);
	build(a, root->rc, mid+1, right);
	root->max = max(root->lc->max, root->rc->max);
	root->min = min(root->lc->min, root->rc->min);
}
//层次遍历
void traversal(Node *p) {
	queue<Node *> q;
	q.push(p);
	Node *tmp;
	while(!q.empty()) {
		tmp = q.front();
		cout << (*tmp).max << endl;
		q.pop();
		if(tmp->lc)q.push(tmp->lc);
		if(tmp->rc)q.push(tmp->rc);
	}
}
//查找
int queryMin(Node *root, const int &nstart, const int &nend,
             const int &qstart, const int &qend) {
	if(qstart > nend || qend < nstart) {
		return INT_MAX;
	}
	if(qstart <= nstart && nend <= qend) {
		return root->min;
	}
	pushDown(root);
	int mid = (nstart + nend) >> 1;
	return min(queryMin(root->lc, nstart, mid, qstart, qend),
	           queryMin(root->rc, mid + 1, nend, qstart, qend));
}
int queryMax(Node *root, const int &nstart, const int &nend,
             const int &qstart, const int &qend) {
	if(qstart > nend || qend < nstart) {
		return INT_MIN;
	}
	if(qstart <= nstart && nend <= qend) {
		return root->max;
	}
	pushDown(root);
	int mid = (nstart + nend) >> 1;
	return max(queryMax(root->lc, nstart, mid, qstart, qend),
	           queryMax(root->rc, mid + 1, nend, qstart, qend));
}

/*只更新线段树某个叶节点的值(叶节点就是源数组的值),把值再加大*/
void modifyNode(Node *root, const int &nstart, const int &nend, const int pos, const int &addVal) {
	if(nstart == nend) {
		if(nstart == pos) {
			root->max += addVal;
			root->min = root->max;
		}
		return;
	}
	pushDown(root);
	int mid = (nstart + nend) >> 1;
	if(pos <= mid)modifyNode(root->lc, nstart, mid, pos, addVal);
	else modifyNode(root->rc, mid + 1, nend, pos, addVal);
	root->max = max(root->lc->max, root->rc->min);
	root->min = min(root->lc->min, root->rc->min);
}

//区间更新，用到了延迟标记的方法
void modifyInterval(Node *root, const int &start, const int &end,
                    const int &modifyStart, const int &modifyEnd, const int &addVal){
  if(modifyStart > end || modifyEnd < start) {
		return;
	}
	if(modifyStart <= start && end <= modifyEnd) {
	  root->addMark = addVal;
	  root->max += addVal;
	  root->min += addVal;
    return;
	}
	pushDown(root);
	int mid = (start + end) >> 1;
	modifyInterval(root->lc, start, mid, modifyStart, modifyEnd, addVal);
	modifyInterval(root->rc, mid + 1, end, modifyStart, modifyEnd, addVal);
	//更据子树更新
	root->max = max(root->lc->max, root->rc->min);
	root->min = min(root->lc->min, root->rc->min);
}
int mem[20];
int main() {
	db.randomArray(mem, 10);
	db.showArray(mem, 10);
	Node *root = new Node;
	build(mem, root, 0, 9);
	traversal(root);
	int k = queryMin(root, 0, 9, 0, 5);
	int t = queryMax(root, 0, 9, 0, 5);
	printf("Min  %d\n", k);
	printf("Max  %d\n", t);
	modifyNode(root, 0, 9, 1, 10);
	modifyInterval(root, 0, 9, 0, 3, 10);
	traversal(root);
	k = queryMin(root, 0, 9, 0, 5);
	t = queryMax(root, 0, 9, 0, 5);
	printf("Min  %d\n", k);
	printf("Max  %d\n", t);
}

