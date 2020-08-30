/* 编写一个程序，接受两个命令行参数。第1个参数是一个字符串，第2个参数
 * 是一个文件名。然后该程序查找该文件，打印文件中包含该字符串所在的行。
 * 因为该任务是面向行而不是面向字符的，所以要使用fgets()而不是getc()。
 * 使用标准C库函数strstr()在每一行中查找指定字符串。假设文件中的所有行
 * 都不超过255个字符。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(int argc, char * argv[])
{
    FILE * fp;
    char st[MAX];
    
    if(argc != 3)
    {
        printf("Usage: %s string filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("Can't open file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while(fgets(st, MAX, fp))
    {
        if(strstr(st, argv[1]))
            fputs(st, stdout);
    }
    fclose(fp);
    return 0;
}