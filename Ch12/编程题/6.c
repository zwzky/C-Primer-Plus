/* 编写一个程序，生成1000个1~10范围内的随机数。不同保存或打印这些数字，
 * 仅打印每个数出现的次数。用10个不同的种子运行，生成的数字出现的次数是
 * 否相同？可以用本章自定义的函数或者ANSI C的rand()和srand()函数，它们
 * 的格式相同。这是一个测试特定随机数生成器随机性的方法。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE    10
#define MAX     1000

int main(void)
{
    int arr[MAX];
    int count[SIZE][SIZE] = {0};
    int i, j, k, side;
    side = 1;

    for(i = 0; i < SIZE; i++)
    {
        srand(side++);

        for(j = 0; j < MAX; j++)
        {
            arr[j] = rand() % 10 + 1;
            for(k = 0; k < SIZE; k++)
            {
                if(arr[j] == k + 1)
                {
                    count[i][k] = count[i][k] + 1;
                    break;
                }
            }
        }
    }
    for(i = 0; i < SIZE; i++)
        printf("%4d", i + 1);
    printf("\n");
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
            printf("%4d", count[i][j]);
        printf("\n");
    }
    printf("\n");
}