/* 1.重现编写复习题5，用月份名的拼写代替月份号（别忘了使用strcmp()）。在一个
 * 简单的程序中测试该函数。
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int days(char * pt);
char * s_gets(char * st, int n);

struct month {
    char monthname[10];
    char abbrev[4];
    int days;
    int num_month;
};

const struct month months[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"Septemper", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

int main(void)
{
    char input[20];
    int totaldays;
    
    puts("Enter the name of the month:");
    while(s_gets(input, 20) != NULL && input[0] != '\0')
    {
        totaldays = days(input);
        if(totaldays > 0)
            printf("There are %d days througt %s.\n", totaldays, input);
        else
            printf("%s is not valid input.\n", input);
        printf("Next month (empty line to quit)\n");
    }
    puts("Bye!");

    return 0;
}

int days(char * pt)
{
    int total = 0;
    int i;
    int mon_num = 0;
  
    pt[0] = toupper(pt[0]);
    for(i = 1; pt[i] != '\0'; i++)
        pt[i] = tolower(pt[i]);
    for(i = 0; i < 12; i++)
        if(strcmp(pt, months[i].monthname) == 0)
        {
            mon_num = months[i].num_month;
            break;
        }
    if (mon_num == 0)
        total = -1;
    else
        for(i = 0; i < mon_num; i++)
            total += months[i].days;
    
    return total;
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
