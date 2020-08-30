/* 编写一个程序，以一个字符和任意文件名作为命令行参数。如果字符后面没有
 * 参数，该程序读取标准输入；否则，程序依次打开每个文件并报告文件中该字
 * 符出现的次数。文件名和字符本身也要一同报告出来。程序应包含错误检查，
 * 以确定参数数量是否正确和是否能打开文件。如果无法打开文件，程序应报告
 * 该问题，然后处理下一个文件。
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE    81

int main(int argc, char * argv[])
{
    FILE *fp;
    int i;
    int count = 0;
    char file[SIZE];
    char ch;
    
    if(argc < 2)
    {
        printf("Usage: %s character filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(argc == 2)
    {
        printf("please enter the name of files.\n");
        while(scanf("%s", file) == 1 && file[0] !='\0')
        {
            if((fp = fopen(file, "r")) == NULL)
            {
                printf("Could not open file %s.\n", file);
                continue;
            }
            while((ch = getc(fp)) != EOF)
            {
                if(ch == argv[1][0])
                    count++;
            }
            if(fclose(fp) != 0)
            {
                printf("Error in closing file.\n");
                exit(EXIT_FAILURE);
            }
            printf("%c in file %s appence %d.\n", argv[1][0], file, count);
        }
    }
    else
    {
        for(i = 2; i < argc; i++)
        {
            if((fp = fopen(argv[i], "r")) == NULL)
            {
                printf("Could not open file");
                exit(EXIT_FAILURE);
            }
            while((ch = getc(fp)) != EOF)
                if(ch == argv[1][0])
                    count++;
            if(fclose(fp) != 0)
            {
                printf("Error in closing file.\n");
                exit(EXIT_FAILURE);
            }
            printf("%c in file %s appence %d.\n", argv[1][0], argv[i], count);
            
        }
    }
    return 0;
}