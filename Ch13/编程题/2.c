/* 编写一个文件拷贝程序，该程序通过命令行获取原始文件名和拷贝文件名，
 * 尽量使用标准I/O和二进制模式。
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int ch;
    FILE * fp1, * fp2;
    if(argc != 3)
    {
        printf("Usage: %s filename1 filename2", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp1 = fopen(argv[1], "rb")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if((fp2 = fopen(argv[2], "wb")) == NULL)
    {
        printf("Can't create copy file\n");
        exit(3);
    }

    while((ch = getc(fp1)) != EOF)
    {
        putc(ch, fp2);
    }
    if(fclose(fp1) != 0 || fclose(fp2) != 0)
        printf("Error in closing files\n");
    
    return 0;
}