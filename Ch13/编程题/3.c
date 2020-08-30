/* 编写一个文件拷贝程序，提示用户输入文本文件名，并以该文件名作为原始文件名
 * 和输出文件名。该程序要使用ctype.h中的tupper()函数，在写入到输出文件时，
 * 把所有文本转换成大写。使用标准I/O和文本模式。
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SLEN    81

int main(void)
{
    char ch;
    FILE *fp;
    char file[SLEN];

    printf("Please enter the naem of file to open\n");
    scanf("%s", file);

    if((fp = fopen(file, "r+")) == NULL)
    {
        printf("recerse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }
    while((ch = getc(fp)) != EOF)
    {
        if(islower(ch))
        {
            fseek(fp, -1, SEEK_CUR);
            putc(toupper(ch), fp);
            fseek(fp, 0, SEEK_CUR);
        }
    }
    if(fclose(fp) != 0)
        printf("Rrror in closing file.\n");
    
    return 0;
}