/* 5. 编写一个程序满足下面的要求
 *   a. 外部定义一个有两个成员的结构模name；一个字符串存名，一个字符串存姓。
 *   b. 外部定义一个有3个成员的结构模板student：一个name类型的结构，一个grade
 *      数组存储3个浮点型分数，一个变量存储3个分数的平均数。
 *   c. 在main()函数中声明一个内含CSIZE(CSIZE = 4)个student类型结构的数组，
 *      并初始化这些结构的名字部分。用函数执行g、e、f和g中描述的任务。
 *   d. 以交互的方式获每个学生的成绩，提示用户输入学生的姓名和分数。把分数储存到
 *      grade数组相应的结构中。可以在main()函数或者其他函数中用循环来完成。
 *   e. 计算每个结构的平均数，并把计算后的结果赋值给合适的成员。
 *   f. 打印每个结构的信息。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CSIZE 4
#define LEN   12

struct name {
    char fname[LEN];
    char lname[LEN];
};

struct student {
    struct name student_name;
    double grade[3];
    double average;
};

char * s_gets(char * st, int n);

int main(void)
{
    struct student students[CSIZE];
    int i, j;
    double total_grade, total_grades;

    for(i = 0; i < CSIZE; i++)
    {
        printf("Enter the student's first name:");
        s_gets(students[i].student_name.fname, LEN);

        printf("Enter the student's last name:");
        s_gets(students[i].student_name.lname, LEN);

        printf("Enter three gradess of this student:");
        for(j = 0; j < 3; j++)
            scanf("%lf", &students[i].grade[j]);
        getchar();
    }

    for(i = 0; i < CSIZE; i++)
    {
        for(j = 0; j < 3; i++)
            total_grade += students[i].grade[j];
        students[i].average = total_grade / 3;
    }

    for(i = 0; i < CSIZE; i++)
    {
        printf("Student: %s %s. grade: %,2.lf %.2lf, %.2lf, average: %.2lf", 
            students[i].student_name.fname, students[i].student_name.lname, students[i].grade[0], 
            students[i].grade[1], students[i].grade[2], students[i].average);
    }

    for(i = 0; i < CSIZE; i++)
        total_grades =+ students[i].average;
    printf("All students' average grade is %.2lf\n", total_grades / CSIZE);

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
