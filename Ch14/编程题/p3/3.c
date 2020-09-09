/* 3.修改程序清单14.2中的图书目录程序，使其按照输入图书的顺序输出图书的信息
 * 。然后按照标题字母的顺序输出图书的信息。最后，按照价格的升序输出图书的信息
 */

#include <stdio.h>
#include <string.h>

char * s_gets(char * st, int n);

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index, k;
    char * temporary;
    float temp;

    printf("Please enter the book title.\n");
    printf("Press [Enter] at the start of a line to stop.\n");
    while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL); //把输入的字符串变量赋给author
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while(getchar() != '\n')
            continue;
        if(count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if(count > 0)
    {
        printf("按照输入图书的顺序输出图书的信息：\n");
        printf("Here is the list of your books sorted by input order:\n");
        for(index = 0; index < count; index++)
            printf("%s by %s: %.2f\n", library[index].title, library[index].author, library[index].value);
        printf("按照标题字母的声明输出图书的信息：\n");
        printf("Here is the list of your books in alphabetical order:\n");
        for(index = 0; index < count; index++)
        {
            for(k = index + 1; k < count; k++)
            {
                if(strcmp(library[index].title, library[k].title)> 0)
                {
                    temporary = library[index].title;
                    library.[index].title = library[k].title;
                    library[k].title = temporary;
                }
            }
        }
        for(index = 0; index < count; index++)
            printf("%s by %s: %.2f\n", library[index].title, library[index].author, library[index].value);
        printf("Here ios the list of you books by price:\n");
        for(index = 0; index < count; index++)
        {
            for(k = index + 1; k < count; k++)
            {
                if(library[index].price > library[k].price)
                {
                      temp = library[index].price;
                      library[index].price = library[k].price;
                      library[k].price = temp;
                }
            }
        }
        for(index = 0; index < count; index++)
            printf("%s by %s: %.2f\n", library[index].title, library[index].author, library[index].value);
    }
    else
        printf("No books? Too bad.\n");
        
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
