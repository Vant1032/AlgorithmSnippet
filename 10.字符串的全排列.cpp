#include<iostream>
using namespace std;

void print(char *str)
{
    char *p=str;
    while(*p)
    {
        cout<<*p<<' ';
        p++;
    }
}
void bianli(char *str,int begin,int length)
{
    char temp;
    int i;
    if(begin==length-1)
    {
        print(str);
        cout<<endl;
        return ;
    }
    //可以选取某一个值(包括begin自己)与begin的位置交换，然后对剩下的字符全排列
    //所以对于每一个位置要么选择先交换，然后递归，要么选择不交换（即交换两次）
    for(i=begin;i<length;i++)
    {
        swap(str[begin], str[i]);
        
        bianli(str,begin+1,length);
        
        swap(str[begin], str[i]);//还原成上个状态 
    }
}

int main()
{
    char str[9]="1234";
    bianli(str,0,4);
    return 0;
}
