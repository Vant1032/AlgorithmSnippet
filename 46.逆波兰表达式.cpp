/*
逆波兰表达式
1、将一个中序表达式转化成为逆波兰表达式。
       首先维护的是两个栈，我们这里暂且称为S1和S2，S1中的结果最后存的就是逆波兰表达式，S2中将用于暂时存放运算符并且在最终形成逆波兰表达式的时候，该栈是会清空的。下面我们看看怎样具体的形成逆波兰表达式。
       在此首先定义一下运算符的优先级关系，从小到达排序，相同优先级没有用逗号隔开：（，+-，*\，负号，）。
       从左至右遍历一个给定的中序表达式，也就是我们常规的数学计算的表达式。
（1）如果遇到的是数字，我们直接加入到栈S1中；
（2）如果遇到的是左括号，则直接将该左括号加入到栈S2中；
（3）如果遇到的是右括号，那么将栈S2中的运算符一次出栈加入到栈S1中，直到遇到左括号，但是该左括号出栈S2并不加入到栈S1中；
（4）如果遇到的是运算符，包括单目运算符和双目运算符，我们按照下面的规则进行操作：
          （1）如果此时栈S2为空，则直接将运算符加入到栈S2中；
          （2）如果此时栈S2不为空，当前遍历的运算符的优先级大于栈顶运算符的优先级，那么直接入栈S2；
          （3）如果此时栈S2不为空，当前遍历的运算符的优先级小于等于栈顶运算符的优先级，则将栈顶运算符一直出栈加入到栈S1中，直到栈为空或者遇到一个运算符的优先级小于等于当前遍历的运算符的优先级，此时将该运算符加入到栈S2中；
（5）直到遍历完整个中序表达式之后，栈S2中仍然存在运算符，那么将这些运算符依次出栈加入到栈S1中，直到栈为空。
       按照上面的五条操作反复进行完成，那么栈S1中存放的就是逆波兰表达式。

2、利用逆波兰表达式求值
       利用逆波兰表达式求计算式的值其实很简单，正式因为这一点，所以逆波兰表达式才在编译原理中被用于计算一个表达式的值。
       下面来具体看看如何求一个逆波兰表达式的值：
       我们此时维护一个数据结果栈S3，我们将会看到该栈中最后存放的是最终的表达式的值。我们从左至右的遍历栈S1，然后按照下面的规则进行操作栈S3.
（1）如果遇到的是数字，那么直接将数字压入到S3中；
（2）如果遇到的是单目运算符，那么取S3栈顶的一个元素进行单目运算之后，将结果再次压入到栈S3中；
（3）如果遇到的是双目运算符，那么取S3栈顶的两个元素进行，首先出栈的在左，后出栈的在右进行双目运算符的计算，将结果再次压入到S3中。
       按照上面的三个规则，遍历完整个栈S1，那么最后S3中的值就是逆波兰表达式的值了，所以我们可以看出来使用逆波兰表达式进行求值是很简单的，只有两种操作要么是直接压栈，要么是运算之后将结果压栈。
*/
/*
本程序精度不够，得自己写个大数才能作为计算器
只支持加减乘除括号，暂时不支持负号
*/
#include <vector>
#include <string>
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <sstream>
#include <iomanip>
using namespace std;
/*得保证表达式合法*/

/*判断表达式是否合法，在调用类前使用*/
bool isValid(char *str) {
  if (str == NULL || str[0] == '\0' || str[0] == '.')return false;
  for (int i = 0; str[i]; i++) {
    /*检查是否有负号*/
    if (str[i] == '-' && (!isdigit(str[i - 1]))) {
      return false;
    }
    /*检查是否有非法符号*/
    if (!(isdigit(str[i]) || str[i] == '(' || str[i] == ')' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '.')) {
      return false;
    }
    /*检查点前是否是数字*/
    if ((str[i] == '.' && i != 0 && !(isdigit(str[i - 1]))))return false;
  }
  return true;
}
class ReversePolandNotation {
private:
  vector<string> init;
  vector<string> op;
  vector<string> result;
  int priorityOfOperator[129];
  long double r;
  void toInversePolandNotation() {
    priorityOfOperator['*'] = priorityOfOperator['/'] = 10;
    priorityOfOperator['+'] = priorityOfOperator['-'] = 9;
    priorityOfOperator['('] = -1e6;//设为极小值，没有比它低的；
    priorityOfOperator[')'] = 1e6;//设为极大值
    priorityOfOperator['#'] = -1e6 - 1;//最小值
    string t;
    t = "#";/*防止栈空*/
    op.push_back(t);
    for (int i = 0; i < init.size(); i++) {
      t = init[i];
      if (isdigit(t[0])) {
        result.push_back(t);
      }
      else if (t[0] == '(') {
        op.push_back(t);
      }
      else if (t[0] == ')') {
        string optmp = op.back();// cout << "#2 op.back = " << op.back() << endl;
        if (op.size() != 1)op.pop_back();
        while (optmp[0] != '(' && op.size() != 1) {
          result.push_back(optmp);
          optmp = op.back(); //cout << "#1 op.back = " << op.back() << endl;
          op.pop_back();
        }
      }
      else {
        //cout << "#3 op.back" << endl;
        string optmp = op.back();
        while (priorityOfOperator[t[0]] <= priorityOfOperator[optmp[0]] && op.size() != 0) {
          result.push_back(optmp);
          op.pop_back();
          optmp = op.back();
        }
        op.push_back(t);
      }
    }
    while (op.size() != 1) {
      result.push_back(op.back());
      op.pop_back();
    }
    calculate();
  }
  void calculate() {
    /*复用已被清空的op，作为运算栈*/
    string t, a, b;
    long double ad, bd, numBuf;
    stringstream ss;
    for (int i = 0; i < result.size(); i++) {
      t = result[i];
      if (isdigit(t[0])) {
        op.push_back(t);
      }
      else {
        b = op.back();
        op.pop_back();
        a = op.back();
        op.pop_back();
        ss << a;
        ss >> ad;
        ss.clear();
        ss << b;
        ss >> bd;
        ss.clear();
        if (t[0] == '+') {
          numBuf = ad + bd;
        }
        else if (t[0] == '-') {
          numBuf = ad - bd;
        }
        else if (t[0] == '*') {
          numBuf = ad * bd;
        }
        else if (t[0] == '/') {
          numBuf = ad / bd;
        }
        ss << numBuf;
        ss >> t;
        ss.clear();
        op.push_back(t);
      }
    }
    ss << op.back();
    ss >> r;
  }
public:
  ReversePolandNotation(char *str) {
    char numBuf[100];
    int len = 0;
    for (int i = 0; str[i]; i++) {
      if (str[i] == ' ')continue;/*去除空格*/
      if (isdigit(str[i]) || str[i] == '.') {
        numBuf[len++] = str[i];
      }
      else {
        string t;
        if (len > 0) {
          numBuf[len] = '\0';
          len = 0;
          t = numBuf;
          init.push_back(t);
        }
        t = str[i];
        init.push_back(t);
      }
    }
    if (len > 0) {
      numBuf[len] = 0;
      string tt(numBuf);
      init.push_back(tt);
    }
    toInversePolandNotation();
  }
  double getResult() {
    return r;
  }
  const string getNotation()const {
    string t;
    int len = result.size();
    for (int i = 0; i < len; i++) {
      t.append(result[i]);
      t.append(" ");
    }
    return t;
  }
};
int main() {
  char d[1000];
  cout << "     1.请输入数学表达式，本计算器能够计算出表达式的值" << endl;
  cout << "     2.支持+-*/以及括号" << endl;
  cout << "     3.不支持负号，输入负号结果未知" << endl;
  cout << "     4.采用逆波兰表达式算法处理表达式，程序同时输出逆波兰表达式" << endl;
  cout << "     5.请使用英文字符输入" << endl;
  cout << setprecision(7);
  while (gets(d)) {
    if (isValid(d)) {
      ReversePolandNotation r(d);
      cout << "结果: " << r.getResult() << endl;
      cout << "逆波兰表达式: " << r.getNotation() << endl;
    }
    else {
      cout << "表达式不合法" << endl;
    }
  }
}

