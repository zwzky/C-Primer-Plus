/* 1.编写一个函数，把二进制字符串转化为一个数值。例如，有下面的语句：
 * char * pbin = "01001001";
 * 那么把pbin作为参数传递给该函数，它应该返回一个int类型的值25。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#define SIZE  33

int get_bstr(char * st, int n);
char * del_space(char * st);
int bit_to_int(char * );

int main(void)
{
    char binstr[SIZE];
    int num;

    printf("请输入二进制数（输入空行退出）\n");
    while(get_bstr(binstr, SIZE) && binstr[0])
    {
        num = bit_to_int(del_space(binstr));
        printf("%s is %d\n", binstr, num);
        printf("q请输入下一个二进制数（输入空行退出）\n");
    }

    return 0;
}
/* 从标准输入里读取二进制字符串,给出字符串数组地址,和读取长度,读取n-1个二进制字符.自动添加'\0'
返回成功读取的字符个数,读取失败返回0,遇到不是二进制字符,或者达到指定个数,都将停止读取  */
int get_bstr(char * st, int n)
{
    char ch;
    int i;

    for(i = 0; i < n - 1 && (ch = getchar()) != '\n' && (isdigit(ch) || isspace(ch)); i++)
        st[i] = ch;
    st[i] = '\0';

    if(ch != '\n')
        while(getchar() != '\n')
            continue;

    return i;
}

/* 删除字符串中的空格 */
char * del_space(char * st)
{
      int i;
      char * find = NULL;

      while(find = strchr(st, ' '))   //strchr(const char * s, int c)，如果s字符串包含c字符，该函数返回指向s字符串首次出现c字符的指针
      {
          for(i = 0; find[i]; i++)
              find[i] = find[i + 1];
      }

      return st;
}

/* 将二进制字符串转换为十进制 */
int bit_to_int(char * pbin)
{
    int n = 0;
    int i;
    for(i = 0; pbin[i]; i++)
    {
        n <<= 1;
        n |= (pbin[i] - '0');
    }

    return n;
}
