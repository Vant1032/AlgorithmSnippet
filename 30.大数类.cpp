/*

*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream> 
using namespace std;
class BigNumber{
  private:
    int *root;
    int size;
    int len;
    bool isPositive; 
    void adjustSize(const BigNumber &n);//调整BigNumber的size的长度 
  public:
    BigNumber(const int &size_ = 5000){
      root = new int[size_];
      size = size_;
    }
    BigNumber(char *p, const int &size_ = 5000){//size为大数运算时的最大长度 
      root = new int[size_];
      size = size_;
      if(p[0] == '-')isPositive = false, p++;
      else isPositive = true;
      for(len = 0; p[len]; len++){
        root[len] = p[len] - '0';
      }
    }
    ~BigNumber(){
      delete [] root;
    }
    BigNumber operator+(const BigNumber &n);//得保证n为正整数 
    BigNumber & operator=(const BigNumber &n);
};
void BigNumber::adjustSize(BigNumber &n){
  if(size > n.size){
    int *tmp = new int[size];
    memcpy(tmp, n.root, n.size * sizeof(int));
    delete [] n.root;
    n.root = tmp;
    n.size = size;
  }else if(size < n.size){
    int *tmp = new int[n.size];
    memcpy(tmp, root, size * sizeof(int));
    delete [] root;
    root = tmp;
    size = n.size;
  }
}
BigNumber & BigNumber::operator=(const BigNumber &n){
  
}
BigNumber BigNumber::operator+(const BigNumber &n){
  adjust(n);
  BigNumber tmp();
  
}
int main(){
	
}

