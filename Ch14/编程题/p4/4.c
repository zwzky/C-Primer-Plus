/* 4. 编写一个程序，创建一个有两个成员的结构模板：
 * a. 第1个成员是社会保险号，第2个成员是一个有3个成员结构的结构，第1个
 *    成员代表名，第2个成员代表中间名，第三个成员代表姓。创建并初始化一
 *    个内含5个该类型结构的数组。该程序以下面的格式打印数据：
 *    Dribble. Flossie M. -- 30209823
 *    如果有中间名，只打印它的第一个字母，然后家一个点（.）;如果没有中间
 *    名，则不用打印点。编写一个程序进行打印，把结构数组传递给这个函数。
 * b. 修改a部分，传递结构的值而不是结构的地址。
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define LEN   15

struct name_info {
    char fname[LEN];
    char mname[LEN];
    char lname[LEN];
};

struct info {
    char ssn[10];
    struct name_info name;
};

void show1(struct info *);
void show2(struct info information[5]);

int main(void)
{
    struct info *pt;

    struct info information[5] = {
        {"30209823", {"Dribble", "Mas", "Flossie"}},
        {"23101322", {"Mas", "SKLA", "Sdfjkas"}},
        {"12330432", {"Ssadf", "Eerw", "Ewefsd"}},
        {"32490123", {"Fsx", "Afsa", "Asdfw"}},
        {"23490112", {"Ssaf", "KDasjl", "LJIDAO"}},
    };

    pt = information;

    show1(information);
    printf("***********************\n");
    puts("The other method :\n");
    show2(information);

    return 0;
}

void show1(struct info * pt)
{
    int i;
    for(i = 0; i < 5; i++)
    {
      if(pt->name.mname[0] == '\0')
          printf("%s, %s -- %s\n", pt->name.fname, pt->name.lname, pt->ssn);
      else
          printf("%s, %s %c. -- %s\n", pt->name.fname, pt->name.lname, pt->name.mname[0], pt->ssn);
      pt++;
    }
}

void show2(struct info information[5])
{
    int i;
    for(i = 0; i < 5; i++)
    {
        if(information[i].name.mname[0] == '\0')
            printf("%s, %s --%s\n", information[i].name.fname, information[i].name.lname, information[i].ssn);
        else
            printf("%s, %s  %c--%s\n", information[i].name.fname, information[i].name.lname, information[i].name.mname[0], information[i].ssn);


    }

}
