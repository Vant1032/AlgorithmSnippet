/*
牛顿迭代法：
X
1.先猜测一个值 R = X / 2，然后利用公式：R = (R + X / R) / 2;
*/
#include <iostream>
#include <cmath>
using namespace std;
double sqrt1(double x){
  double r = x / 2;
  double err = 1e-15;
  double pre = x;
  while(fabs(pre - r) > err){
    pre = r;
    r = (r + x / r) / 2;
  }
  return r;
}
int main(){
  cout.precision(19);
  cout << sqrt1(2) << endl;
  cout << sqrt(2) << endl;
}

