/* 数字图像，尤其是从宇宙飞船发回的数字图像，可能会包含一些失真。
 * 为编程练习12添加消除失真的函数。该函数把每个值与它上下左右相
 * 邻的值作比较，如果该值与其周围相邻的值的差大于1，则用所有相邻
 * 值的平均值（四舍五入为整数）代替该值。注意，与边界上的店相邻的
 * 点少于4个，所以做特殊处理。
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE    40
#define ROWS    20
#define COLS    30

int main(void)
{
    FILE * fp;
    char name[SIZE];
    int arr[ROWS][COLS];
    int i, j;

    puts("Plese input the filename.");
    scanf("%s", name);

    if((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open file %s.\n", name);
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLS; j++)
            fscanf(fp, "%d", &arr[i][j]);

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(i == 0 && j == 0 && abs(arr[i][j]- arr[i+1][j]) > 1 && abs(arr[i][j] - arr[i][j+1]) > 1)
                arr[i][j] = (int)((arr[i+1][j] + arr[i][j+1]) / 2.0 + 0.5);
            else if(i == 0 && j == COLS - 1 && abs(arr[i][j] - arr[i][j-1]) > 1 && abs(arr[i][j] - arr[i+1][j]) > 1)
                arr[i][j] = (int)((arr[i][j-1] + arr[i+1][j]) / 2.0 + 0.5);
            else if(i == ROWS - 1 && j == 0 && abs(arr[i][j] - arr[i-1][j]) > 1 && abs(arr[i][j] - arr[i][j+1]) > 1)
                arr[i][j] = (int)((arr[i-1][j] + arr[i][j+1]) / 2.0 + 0.5);
            else if(i == ROWS - 1 && j ==COLS - 1 && abs(arr[i][j] - arr[i-1][j]) > 1 && abs(arr[i][j] - arr[i][j-1]) > 1)
                arr[i][j] = (int)((arr[i-1][j] + arr[i][j-1]) / 2.0 + 0.5);
            else if(i == 0 && abs(arr[i][j] - arr[i][j-1]) > 1 && abs(arr[i][j] - arr[i][j+1]) > 1 && abs(arr[i][j] - arr[i+1][j]) > 1)
                arr[i][j] = (int)((arr[i][j-1] + arr[i][j+1] + arr[i+1][j])/ 3.0 + 0.5);
            else if(i == ROWS && abs(arr[i][j] - arr[i][j-1]) > 1 && abs(arr[i][j] - arr[i][j+1]) > 1 && abs(arr[i][j] - arr[i-1][j]) > 1)
                arr[i][j] = (int)((arr[i][j-1] + arr[i][j+1] + arr[i-1][j])/ 3.0 + 0.5);
            else if(j == 0 && abs(arr[i][j] - arr[i-1][j]) > 1 && abs(arr[i][j] - arr[i+1][j]) > 1 && abs(arr[i][j] - arr[i][j+1]) > 1)
                arr[i][j] = (int)((arr[i-1][j] + arr[i+1][j] + arr[i][j+1])/ 3.0 + 0.5);
            else if(j == COLS && abs(arr[i][j] - arr[i-1][j]) > 1 && abs(arr[i][j] - arr[i+1][j]) > 1 && abs(arr[i][j] - arr[i][j-1]) > 1)
                arr[i][j] = (int)((arr[i-1][j] + arr[i+1][j] + arr[i][j-1])/ 3.0 + 0.5);
            else if(abs(arr[i][j] - arr[i-1][j]) > 1 && abs(arr[i][j] - arr[i+1][j]) > 1 && abs(arr[i][j] - arr[i][j-1]) > 1 && abs(arr[i][j] - arr[i][j+1]) > 1)
                arr[i][j] = (int)((arr[i-1][j] +arr[i+1][j] + arr[i][j-1] + arr[i][j+1]) / 4.0 + 0/5);
            
            switch(arr[i][j])
            {
                case 0: putchar(' '); break;
                case 1: putchar('.'); break;
                case 2: putchar('\''); break;
                case 3: putchar(':'); break;
                case 4: putchar('~'); break;
                case 5: putchar('*'); break;
                case 6: putchar('='); break;
                case 7: putchar('+'); break;
                case 8: putchar('%'); break;
                case 9: putchar('#'); break;
                default: printf("Error!");
            }
        }
        putchar('\n');
    }
    return 0;
}
