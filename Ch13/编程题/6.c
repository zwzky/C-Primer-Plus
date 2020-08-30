/* 使用命令行参数的程序依赖于用户的内存如何正确地使用它们。重写程序清单
 * 13.2中的程序，不使用命令行参数，而是提示用户输入所需信息
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE    81

int main(void)
{
    FILE * in, * out;
    int ch;
    char file1[SIZE];
    char file2[SIZE];
    int count = 0;

    printf("Please enter file name to reduced.\n");
    scanf("%s", file1);
    
    if((in = fopen(file1, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", file1);
        exit(EXIT_FAILURE);
    }

    printf("Please enter file2 name.\n");
    scanf("%s", file2);
    
    if((out = fopen(file2, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    while((ch = getc(in)) != EOF)
        if(count++ % 3 == 0)
            putc(ch, out);
    if(fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}