/* 编写一个程序打开一个文本文件，通过交互方式获取文件名。通过一个循环
 * ，提示用户输入一个文件位置。然后该程序打印从该位置开始到下一个换行
 * 符之前的内容。用户输入复数或非数值字符可以结束循环。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 81

int main(void)
{
    FILE * fp;
    char filename[MAX];
    char ch;
    long num, count;

    printf("Please input a file name.\n");
    scanf("%s", filename);
    if((fp = fopen(filename, "r")) == NULL)
    {
        printf("Can't open the file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    num = ftell(fp);

    printf("Please input a location.\n");
    while((scanf("%ld", &count)) == 1 && count > 0)
    {
        if(count < num)
        {
            fseek(fp, count, SEEK_SET);
            while((ch = getc(fp)) != '\n' && ch != EOF)
                putchar(ch);
            putchar('\n');
        }
        else
            printf("Out of range.\n");
        printf("Input again.\n");
    }

    return 0;
}