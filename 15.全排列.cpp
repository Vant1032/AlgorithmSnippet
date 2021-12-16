/*

回溯法加分治法 

*/ 

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
    //从当前序列中选择一个出来，对剩下的做全排列 ，直到最后还剩一个元素 
    //可以选取某一个值(包括begin自己)与begin的位置交换，然后对剩下的字符全排列
    //所以对于每一个位置要么选择先交换，然后递归，要么选择不交换（即交换两次）
    for(i=begin;i<length;i++)
    {
        temp=str[begin];//交换位置 
        str[begin]=str[i];
        str[i]=temp;

        bianli(str,begin+1,length);

        temp=str[begin];
        str[begin]=str[i];
        str[i]=temp;//恢复原样 
    }
}

int main()
{
    char str[4]="123";
    bianli(str,0,3);
    return 0;
}
