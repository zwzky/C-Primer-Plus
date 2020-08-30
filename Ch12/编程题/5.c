/* 编写一个程序，生成100个1~10范围内的随机数，并以降序排列（可以
 * 把第11章的排序方法稍微改动，便可用于整数排列，这里仅对整数排列）
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int arr[100];
    int i;

    srand((unsigned int) time(0));

    for(i = 0; i < 100; i++)
    {
        arr[i] = rand() % 10 + 1;
        printf("%3d", arr[i]);
        if((i+1) % 10 == 0)
            printf("\n");
    }
    printf("\n");

    for(i = 0; i < 99; i++)
    {
        int j, temp;
        for(j = i + 1; j < 100; j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        printf("%3d", arr[i]);
        if((i+1) % 10  == 0)
            printf("\n");
    }
    printf("%3d\n", arr[99]);
    return 0;
}