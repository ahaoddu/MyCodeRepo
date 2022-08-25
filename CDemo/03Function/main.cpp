#include <stdio.h>

//自定义函数
void newline() 
{
    printf("\n");
} 

//形参 实参
void print_time(int hour, int minute) 
{
    printf("%d %d \n", hour, minute);
}

//传值 传引用
void foo(int x) {
    x = 10;
}

//引用是 c++ 特性
void foo2(int& x) {
    x = 20;
}

//递归


//全局变量
int variable_g = 123;

int main(int argc, char const *argv[])
{

    //局部变量
    int variable_s = 123;    
    //调用自定义函数
    newline();

    int t = 1;
    
    foo(t);
    printf("t = %d \n", t);
    foo2(t);
    printf("t = %d \n", t);

    return 0;
}



