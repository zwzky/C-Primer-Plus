/*9. 编写一个符合以下描述的函数。首先，询问用户需要输入多少个单词。然后，接收用户输入的单词
 * 并显示出来，使用malloc()并回答第一个问题（即要输入多少个单词），创建一个动态数组，该数
 * 组内含相应的指向char的指针（注意，由于数组的每个元素都是指向char的指针，所以用于malloc()
 * 返回值的指针应该是一个指向指针的指针，且它所指向的指针指向char）。在读取字符串时，该程序
 * 应该把单词读入一个临时的char数组，使用malloc()分配足够的空存储间来存储单词，并把地址存入
 * 该指针数组（该数组中每个元素都是指向char的指针）。然后，从临时数组中把单词拷贝到动态分配
 * 的存储空间中。因此，有一个字符指针数组，每个指针都指向一个对象，该对象的大小正好能够容纳
 * 被存储的特定单词。下面是该程序的一个运行示例：
 * How many words do you wish to enter? 5
 * Enter 5 words now:
 * I enjoyed doing this exercise
 * Here are your words:
 * I
 * enjoyed
 * doing
 * this
 * exercise
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char ** pt;
    char * word;
    char tmp_arr_ch[100];
    int count;

    printf("How many words do you wish to enter? ");
    scanf("%d", &count);
    pt = (char **)malloc(count *  sizeof(char *));

    printf("Enter %d words now:\n", count);
    for(int i = 0; i < count; i++)
    {
        scanf("%s", tmp_arr_ch);
        word = (char *)malloc((strlen(tmp_arr_ch) + 1) * sizeof (char));
        strcpy(word, tmp_arr_ch);
        pt[i] = word;
    }

    puts("Here are you words:");
    for(int i = 0; i < count; i++)
    {
        puts(pt[i]);
        free(pt[i]);
    }
    free(pt);

    return 0;
}
