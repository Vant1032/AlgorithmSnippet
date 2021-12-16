/*
矩阵类实现：
功能：
1.实现矩阵加、减、乘法、数乘 
2.实现矩阵的转置
3.实现矩阵交换两行、两列
4.实现矩阵的快速幂运算
5.实现交换矩阵两行/列
6.实现获取零矩阵、获取单位矩阵 
ps:
1.部分功能采用了C++11标准
*/
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;
class Matrix { //分块链表实现
	private:
		int ilen, jlen;
		struct Node {
			double *data;
		};
		Node *root;
		bool isMultipliable(const Matrix &n)const {//判断是否可以相乘
			return this->getColLen() == n.getRowLen();
		}
	public:
		Matrix():ilen(0), jlen(0), root(NULL) {//创造一个空矩阵
		}
		Matrix(const int &row, const int &col);//创造一个row行col列的矩阵
		template<class T>
		Matrix(const T &a, const int &row, const int &col);//使用数组初始化
		Matrix(Matrix &&n);//移动构造函数
		~Matrix();
		Matrix(const Matrix&);//自定义的复制构造函数，深度拷贝
		Matrix &operator=(const Matrix &n);//自定义赋值构造函数，防止内存泄露
		Matrix &operator=(Matrix &&n);//移动赋值运算符，提高性能
		Matrix operator*(const Matrix &n)const;
		friend const Matrix operator*(const double &t, Matrix n);//矩阵数乘 (左)
		friend const Matrix operator*(Matrix n, const double &t);//矩阵数乘(右)
		const Matrix operator+(const Matrix &n)const;
		const Matrix operator-(const Matrix &n)const;
		friend ostream &operator<<(ostream &os, const Matrix &n);//将矩阵输出
		void set(const int &row, const int &col, const double &key);//设置指定位置的值
		double get(const int &row, const int &col)const;//取得给定位置的值
		int getRowLen()const {
			return ilen;
		}
		int getColLen()const {
			return jlen;
		}
		bool isHomotype(const Matrix &n)const; //判断是否同型
		bool isSquare()const {//判断是否是方阵
			return ilen == jlen;
		}
		Matrix transpose();//矩阵转置
		Matrix exp(const int &n); //矩阵的指数运算，前提是n大于0，采用矩阵快速幂，O(log(n))复杂度
		void swapRow(const int &a, const int &b);//交换两行
		void swapCol(const int &a, const int &b);//交换两列
		Matrix getUnit();//获取一个单位矩阵
		Matrix getZero();//获取一个零矩阵

};

void Matrix::set(const int &row, const int &col, const double &key) {
	root[row].data[col] = key;
}
double Matrix::get(const int &row, const int &col)const {
	return root[row].data[col];
}
Matrix Matrix::operator*(const Matrix &n)const {
	if(this->isMultipliable(n)) {
		int row = getRowLen();
		int col = n.getColLen();
		int tk = getColLen();
		double r;
		Matrix t(row, col);
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				r = 0;
				for(int k = 0; k < tk; k++) {
					r += this->get(i, k) * n.get(k, j);
				}
				t.set(i, j, r);
			}
		}
		return t;
	} else {
		Matrix NullMatrix;
		cout<<"无法相乘， 返回空矩阵"<<endl;
		return NullMatrix;
	}
}
Matrix const Matrix::operator+(const Matrix &n)const {
	if(this->isHomotype(n)) {
		int row = this->getRowLen();
		int col = this->getColLen();
		Matrix t(row, col);
		double r;
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				r = this->get(i, j) + n.get(i, j);
				t.set(i, j, r);
			}
		}
		return t;
	} else {
		Matrix NullMatrix;
		cout<<"无法相加，返回空矩阵"<<endl;
		return NullMatrix;
	}
}
ostream &operator<<(ostream &os, const Matrix &n) {
	int row = n.getRowLen();
	int col = n.getColLen();
	int oldp = os.precision(3);
	int oldw = os.width(8);
	os << fixed;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			os << n.get(i, j) << "  ";
		}
		os << endl;
		os.width(8);
	}
	os.precision(oldp);
	os.width(oldw);
	return os;
}
Matrix const Matrix::operator-(const Matrix &n)const {
	if(this->isHomotype(n)) {
		int row = this->getRowLen();
		int col = this->getColLen();
		Matrix t(row, col);
		double r;
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				r = this->get(i, j) - n.get(i, j);
				t.set(i, j, r);
			}
		}
		return t;
	} else {
		Matrix NullMatrix;
		cout<<"无法相减， 返回空矩阵"<<endl;
		return NullMatrix;
	}
}
Matrix::Matrix(const Matrix &n) {
	ilen = n.ilen;
	jlen = n.jlen;
	root = NULL;
	if(ilen != 0 && jlen != 0) {
		root = new Node[ilen];
		for(int i = 0; i < ilen; i++) {
			root[i].data = new double[jlen];
			memcpy(root[i].data, n.root[i].data, jlen * sizeof(double));
		}
	}
}
Matrix Matrix::transpose() {
	int row = getColLen();
	int col = getRowLen();
	Matrix t(row, col);
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			t.set(i, j, get(j, i));
		}
	}
	return t;
}
template<class T>
Matrix::Matrix(const T &a, const int &row, const int &col) {
	ilen = row;
	jlen = col;
	root = NULL;
	if(row != 0 && col != 0) {
		if(ilen != 0 && jlen != 0) {
			root = new Node[ilen];
			for(int i = 0; i < ilen; i++) {
				root[i].data = new double[jlen];
				for(int j = 0; j < jlen; j++) {
					root[i].data[j] = a[i][j];
				}
			}
		}
	}
}
Matrix::~Matrix() {
	if(root) {
		for(int i = 0; i < ilen; i++) {
			delete[] root[i].data;
		}
		delete[] root;
	}
}

Matrix::Matrix(const int &row, const int &col):ilen(row), jlen(col) {
	root = new Node[ilen];
	for(int i = 0; i < ilen; i++) {
		root[i].data = new double[jlen];
	}
}
bool Matrix::isHomotype(const Matrix &n)const {
	int i = n.getRowLen();
	int j = n.getColLen();
	if(i != this->getRowLen())return false;
	else if(j != this->getColLen())return false;
	return true;
}
Matrix & Matrix::operator=(const Matrix &n) {
	if(this == &n)return *this;
	if(root) {
		for(int i = 0; i < ilen; i++) {
			delete[] root[i].data;
		}
		delete[] root;
	}
	ilen = n.getRowLen();
	jlen = n.getColLen();
	if(ilen == 0 || jlen == 0) {
		root = NULL;
	} else {
		root = new Node[ilen];
		for(int i = 0; i < ilen; i++) {
			root[i].data = new double[jlen];
			memcpy(root[i].data, n.root[i].data, jlen * sizeof(double));
		}
	}
	return *this;
}
void Matrix::swapRow(const int &a, const int &b) {
	if(a < 0 || b < 0 || a >= ilen || b >= ilen) {
		cout<<"超出矩阵行数"<<endl;
		return;
	}
	double *t = root[a].data;
	root[a].data = root[b].data;
	root[b].data = t;
}
Matrix Matrix::exp(const int &n) {
	if(!isSquare()) {
		cout << "只有方阵可以指数运算" << endl;
		Matrix NullMatrix;
		return NullMatrix;
	}
	Matrix r = this->getUnit();
	Matrix t = (*this);
	int k = n;
	while(k) {
		if(k & 1) {
			r = r * t;
		}
		k >>= 1;
		t = t * t;
	}
	return t;
}
void Matrix::swapCol(const int &a, const int &b) {
	if(a < 0 || b < 0 || a >= jlen || b >= jlen) {
		cout<<"超出列数"<<endl;
		return;
	}
	for(int i = 0; i < ilen; i++) {
		swap(root[i].data[a], root[i].data[b]);
	}
}
Matrix Matrix::getUnit() {
	if(!isSquare()) {
		cout << "方阵才有单位矩阵" << endl;
		Matrix NullMatrix;
		return  NullMatrix;
	}
	Matrix t(ilen, jlen);
	for(int i = 0; i < ilen; i++) {
		memset(t.root[i].data, 0, jlen * sizeof(double));
		t.root[i].data[i] = 1;
	}
	return t;
}
Matrix & Matrix::operator=(Matrix &&n) {
	if(this == &n)return *this;
	root = n.root;
	n.root = NULL;
	ilen = n.ilen;
	jlen = n.jlen;
	return *this;
}
Matrix Matrix::getZero() {
	Matrix t(ilen, jlen);
	for(int i = 0; i < ilen; i++) {
		memset(t.root[i].data, 0, jlen * sizeof(double));
	}
	return t;
}
Matrix::Matrix(Matrix &&n) {
	*this = std::move(n);
}
const Matrix operator*(const double &t, Matrix n) {
	for(int i = 0; i < n.ilen; i++) {
		for(int j = 0; j < n.jlen; j++) {
			n.root[i].data[j] *= t;
		}
	}
	return n;
}
const Matrix operator*(Matrix n, const double &t) {
	return t * n;
}
int main() {
	double test1[2][3] = {
		3, 5, 8,
		2, 5, 1,
	};
	double test2[3][1] = {
		3,
		4,
		5,
	};
	double test3[2][2] = {
		1, 1,
		1, 0,
	};
	double test4[2][2] = {
		1, 1,
		1, 1,
	};
	Matrix m(test1, 2, 3);
	Matrix t(test2, 3, 1);
	Matrix k(test3, 2, 2);
	Matrix r(test4, 2, 2);
	cout << m << endl;
	cout << m * 5 <<endl;
	m.swapRow(0, 1);
	cout << m << endl;
	m.swapCol(0, 1);
	cout << m << endl;
	cout << m.getZero() << endl;
	cout << k.getUnit() << endl;
	r = k.getUnit();
	for(int i = 1; i < 10; i++) {
		cout<<"i = "<<i<<" 时 "<<endl;
		r = r * k;
		cout<<r<<endl;
	}
}

