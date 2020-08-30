#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
#define SLEN    81

void append(FILE * source, FILE * dest);
char * s_gets(char * st, int n);

int main(void)
{
    FILE *fa, *fs;   //  fa 指向目标文件，fs 指向源文件
    int files = 0;   //  附加文件的数目
    char file_app[SLEN]; //  目标文件名
    char file_src[SLEN]; //  源文件名
    char ch;

    puts("Enter name of destination file:");
    s_gets(file_app, SLEN); //  获取目标文件名
    if((fa = fopen(file_app, "a+")) == NULL)    //  判断是否成功打开目标文件
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) //  判断是否成功分配4096字节的缓冲区
    {
        fprintf(stderr,"Can't create output buffer\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter name of first source file (empty line to quit");
    while(s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        if(strcmp(file_app, file_src) == 0) //  判断目标文件名是否和源文件名一样
            fputs("Can't append file to itself\n", stderr);
        else if((fs = fopen(file_src, "r")) == NULL)    //  判断是否成功打开源文件
            fprintf(stderr, "Can't open %s\n", file_src);
        else
        {
            if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);    //  判断是否成功创建缓冲区
                continue;
            }
            append(fs, fa); //  将源文件 fs 的内容附加到目标文件fa
            if(ferror(fs) != 0) //  
                fprintf(stderr, "Error in reading file %s\n", file_src);
            if(ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s\n", file_app);
            fclose(fs); //  关闭源文件
            files++;    //  转到下一个文件
            printf("File %s appended.\n",file_src);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa); //  回到目标文件开始处
    printf("%s contents\n", file_app);
    while((ch = getc(fa)) != EOF)
        putchar(ch);
    putchar('\n');
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append(FILE * source, FILE * dest)
{
    size_t bytes;
    static char temp[BUFSIZE];

    while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
    {
        fwrite(temp, sizeof(char), bytes, dest);
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
