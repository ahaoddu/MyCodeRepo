#include <iostream>

//函数指针
void say_hello(const char *str) {
    printf("Hello %s\n", str);
}

void say_hello2(void *str) {
    printf("Hello %s\n", (const char *) str);
}

void count_numbers(void *num) {
    for (int i = 1; i <= (int) num; i++) {
        printf("%d ", i);
    }
    putchar('\n');
}

//函数回调
typedef void (*callback_t)(void *);

void repeat_three_times(callback_t f, void *para) {
    f(para);
    f(para);
    f(para);
}

//二级指针做传出参数
static const char *msg[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

void get_a_day(const char **pp) {
    static int i = 234234;
    //対一级指针分配堆内存
    *pp = msg[i%7];
    i++;
}

//通过二级指针分配内存
typedef struct {
    int number;
    char *msg;
} unit_t;

void alloc_unit(unit_t **pp)
{
    unit_t *p  = (unit_t *)malloc(sizeof (unit_t));
    if (p == nullptr) {
        printf("out if memeory \n");
    }
    p->number = 3;
    //不能直接赋值， “HelloWorld” 保存在栈内存中
    p->msg = (char *)malloc(20);
    strcpy(p->msg, "HelloWorld");
    *pp = p;
}

void free_unit(unit_t *p) {
    free(p->msg);
    free(p);
}

//指针做返回值
char *get_a_day(int idx) {
    static char buf[20];
    strcpy(buf, msg[idx]);
    return buf;
}

int main() {
    void (*f)(const char *) = say_hello;
    f("World");

    repeat_three_times(count_numbers, (void *) 4);
    repeat_three_times(say_hello2, (void *) "say Hello");

    const char *firstday = NULL;
    const char *seconday = NULL;
    get_a_day(&firstday);
    printf("firstday is %s \n", firstday);
    get_a_day(&seconday);
    printf("seconday is %s \n", seconday);

    unit_t *p = nullptr;
    alloc_unit(&p);
    free_unit(p);

    get_a_day(1);
    return 0;
}
