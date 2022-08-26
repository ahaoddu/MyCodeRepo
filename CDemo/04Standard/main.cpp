#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void createFile(char *path); 

int main(int argc, char const *argv[])
{

    //memset
    char *buf = (char *)malloc(10);
    memset(buf, 0 ,10);

    //memcpy,避免拷贝的内存没有重叠部分
    memcpy(buf, "Hello", 6);

    //memmove,可以处理两段内存有重叠的情况
    char buf2[20] = "Hello,World\n";
    memmove(buf2+1, buf2, 13);
    printf("%s", buf2);

    createFile("Hello.txt");

    //errno perror strerror
    FILE *file2 = fopen("abcde", "r");
    if (file2 == NULL)
    {
        //打印错误原因
        //方式一
        // perror("Open file abcde");
        //方式二
        EOF
        fprintf(stderr, "%s, line %d: %s\n", __FILE__, __LINE__, strerror(errno));
        exit(1);
    }
    
    return 0;
}

//标准库没有提供直接创建文件的函数
void createFile(char *path) 
{
    FILE *file;
    //只读方式打开文件，要求文件必须存在
    file = fopen(path, "r");

    if (file == NULL)
    {
        //只写的方式打开，文件不存在，创建文件，文件存在，文件长度截断为0
        file = fopen(path, "w");
    }

    if (file != NULL)
    {
        fclose(file);
    }
}




