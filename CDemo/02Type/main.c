#include <stdio.h>

//void foo(int *a,int len)    void foo(int a[10]) 效果相同
void foo(int a[10]) //a是一个指针
{
	 for(int i = 0; i < 10; i++)
    {
        printf("指针数据 *(a+%d) 的值为 %d\n", i, *(a+i));
    }
}

//定义结构体
struct student
{
    char *name;
    int age;
    char *num;
};

union utest
{
   char *name;
   int age;
};

enum etest
{
    TEST1,
    TEST2
};

int main(int argc, char const *argv[])
{
   
    /**
     * 基本类型
     */

    //整型
    int a = 0;
    short b = 0;
    long c = 0;

    //浮点型
    float f = 3.14f;
    double d = 3.14;

    //字符型  转义字符 编码
    char z = 'a';
    

    /**
     *  构造类型
     */ 

    //数组定义与初始化
    int t[10] = { 1,2,3 }; //其他数据为0
    printf("t[5] = %d\n", t[5]); //数据访问
    t[4] = 2;      //写数据

    for(int i = 0; i < 10; i++)
    {
        printf("数组元素 t[%d] 的值为 %d\n", i, t[i]);
    }
    
    int temp = *(t+4);   //t是一个指针
    printf("temp = %d\n", temp);

    foo(t);  //t是一个指针

    //结构体
    struct student stu;
    
    stu.name = "jack";
    stu.age = 18;
    stu.num = "1234567";

    union utest u;
    
    //同一时间只能有一个值
    u.age = 12;
    u.name = "hello";
    
    enum etest hello =  TEST1;
    
    return 0;
}



