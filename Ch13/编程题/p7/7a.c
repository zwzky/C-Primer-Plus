/* 编写一个程序打开两个文件。可以使用命令行参数或者提示用户输入文件名。
 * a. 该程序以这样的顺序打印：打印第1个文件的第1行，打印第2个文件的第1行。以此类推
 * ，打印到行数较多的文件的最后一行。
 * b. 修改该程序，把行号相同的行打印成一行。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    FILE * fp1, * fp2;
    int ch1, ch2;

    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s filename1 filename2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Couldn't open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if((fp2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Couldn't open file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    ch1 = getc(fp1);
    ch2 = getc(fp2);
        
    while(ch1 != EOF || ch2 != EOF)
    {
        while(ch1 != '\n' && ch1 != EOF)
        {
            putchar(ch1);
            ch1 = getc(fp1);
        }
        if(ch1 != EOF)
        {
            putchar('\n');
            ch1 = getc(fp1);
        }
        while(ch2 != '\n' && ch2 != EOF)
        {
            putchar(ch2);
            ch2 = getc(fp2);
        }
        if(ch2 != EOF)
        {
            putchar('\n');
            ch2 = getc(fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}