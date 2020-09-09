/* 2. 编写一个函数，提示用户输入日、月和年。月份可以是月份号、月份名
 * 或者月份名缩写。然后该程序应返回一年中到用户指定日子（包括这一天）
 * 的总天数。
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct month {
    char monthname[10];
    char abbrev[4];
    int days;
    int num_month;
};

int days(int year, int month, int day);
int leapyear(int year);
char * s_gets(char * st, int n);

struct month months[12] = {
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
    int daystotal;
    int i;
    int year, month, day;
    char mname[10];

    puts("Please input the year:");
    while (scanf("%d", &year) == 1)
    {
        puts("Please input the month:");
        if(scanf("%d", &month) == 1)
            printf("\n");
        else
        {
            s_gets(mname, 10);
            for(i = 0; i < 12; i++)
                if(strcmp(mname, months[i].monthname) == 0)
                {
                    month =months[i].num_month;
                    break;
                }
        }
        puts("Please input the date:");
        if(scanf("%d", &day) != 1)
            exit(1);
        printf("%d days have passed.\n", days(year, month, day));
        while(getchar() != '\n')
            continue;
        puts("Please input the next date. Press q to quit.");
    }
    puts("Bye!");

    return 0;
}

int days(int year, int month, int day)
{
    int total = 0;
    int i;
    leapyear(year) ? (months[1].days = 29) : (months[1].days = 28);

    for(i = 0; i < month - 1; i++)
        total += months[i].days;
        
    return total + day;
}

int  leapyear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\0');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
