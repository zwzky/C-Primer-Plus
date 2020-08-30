// 4.在一个循环中编写并测试一个函数，该函数返回它被调用的次数。

#include <stdio.h>

int call_time(void);

int main(void)
{
    int count;
    int num;
    printf("Please enter the times you want to run:\n");
    while(scanf("%d", &num) == 1 && num > 0)
    {
        while(num--)
            count = call_time();
        printf("funtion call_time run %d times.\n", count);
        printf("Please enter the times you want to run:\n");
    }

    return 0;
}    

int call_time(void)
{
    static int count;
    return ++count;
}