/* 编写一个程序，按顺序在屏幕上显示命令行中列出的所有文件。使用argc控制循环。
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int i;
    FILE * fp;
    int ch;

    if(argc < 2)
    {
        printf("Error: No file.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < argc; i++)
    {
        fp = fopen(argv[i], "r");
        printf("File %d %s contents:\n", argc, argv[i]);
        puts("***************************************");
        while((ch = getc(fp)) != EOF)
            putc(ch, stdout);
        puts("***************************************");
        fclose(fp);
    }
    return 0;
}