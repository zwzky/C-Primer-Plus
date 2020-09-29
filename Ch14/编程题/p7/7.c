/* 修改程序清单 14.14，从文件中读取每条记录并显示出来，允许用户删
 * 除记录或修改记录的内容。如果删除记录，把空出来的空间留给下一个
 * 要读入的记录。要修改现有的文件内容，必须用"r+b"模式，而不是"a+b"
 * 模式。而且，必须更加注意定位文件指针，防止新加入的记录覆盖现有记录。
 * 最简单的方法是改动储存在内存中的所有数据，然后再把最后的信息写入文件。
 * 跟踪的一个方法是在book结构中添加一个成员表示是否该项被删除。
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10

char * s_gets(char * st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    int delete;
};

int main(void)
{
    struct book library[MAXBKS] = {{'\0', '\0', 0, 0.0}};
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof(struct book);

    if((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Cant't open book.dat.", stderr);
        exit(EXIT_FAILURE);
    }

    rewind(pbooks);
    while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if(count == 0)
            puts("Current contents of book.dat");
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if(count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Please add new book titles");
    puts("Press [enter] at the start of a line to stop.\n");
    while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the author");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value");
        scanf("%f", &library[count++].value);
        while(getchar() != '\n')
            continue;
        if(count < MAXBKS)
            puts("Enter the next title");
    }

    if(count > 0)
    {
        puts("Here is the list of your books:");
        for(index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
            fwrite(&library[filecount], size, count - filecount, pbooks);
        }
    }
    else
        puts("No books? Too bad!\n");

    while(1)
    {
        int item;
        char ch;
        printf("Which book do you want to delete or modify(-1 to exit)?\n");
        scanf("%d", item);
        while(getchar() != '\n')
            continue;
        if(item == -1)
            break;
        printf("[D]elete of [Modify]?\n");
        scanf("%c", ch);
        if(ch == 'D')
            library[item - 1].delete = 1;
        else
        {
            printf("Please enter the book title.\n");
            s_gets(library[item - 1].title, MAXTITL);
            printf("Now enter the authour.\n");
            s_gets(library[item - 1].author, MAXAUTL);
            printf("%f", &library[item - 1].value);
            scanf("%f", &library[count++].value);
            while(getchar() != '\n')
                continue;
        }
    }
    // 关闭文件后，以"w"只读打开文件清空文件，然后写入delete不等于1的书籍信息
    fclose(pbooks);
    if((pbooks = fopen("book.dat", "w")) == NULL)
    {
        printf("Can't open book.dat file.\n");
        exit(EXIT_FAILURE);
    }
    for(index = 0; index < count; index++)
    {
        if(library[index].delete != 1)
            fwrite(&library[index], size, 1, pbooks);
    }
    puts("Done.\n");
    return 0;
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
