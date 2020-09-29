/* 2.编写一个程序，通过命令行参数读出连个二进制字符串，对这两个二进制数使用
 * ~运算符、&运算符、|运算符和……运算符，并以二级制字符串形式打印结果（如果
 * 无法使用命令行环境，可以通过交互让程序读取字符串）。
 */

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//二进制转化为整数
int convert(char * st, int n);
//整数转化为二进制字符串
char * itobs(int n, char * ps, int m);

int main(int argc, char * argv[])
{
    char ch[CHAR_BIT * sizeof(int) + 1];
    int a, b;
    int i, j;

    if(argc != 3)
    {
        fprintf(stderr, "用法：%s 二进制字符串 二进制字符串\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for(i = 0; argv[1][i] != '\0'; i++)
    {
        if(argv[1][i] != '0' && argv[1][i] != '1')
        {
            fputs("错误，二进制只能为0或1，请重新输入\n", stderr);
            exit(EXIT_FAILURE);
        }
    }
    for(j = 0; argv[2][j] != '\0'; i++)
    {
        if(argv[2][j] != '0' && argv[2][j] != '1')
        {
            fputs("错误，二进制只能为0或1，请重新输入\n", stderr);
            exit(EXIT_FAILURE);
        }
    }

    a = convert(argv[1], i - 1);
    b = convert(argv[2], j - 1);
    printf()
    int num1, num2;
    num1 = btois(argv[1]);
    num2 = btois(argv[2]);

    printf("~%s == %s",argv[1], itobs(~num1, str));
    /* print_bstr(~num1);
    printf('\n');

    printf("~%s == ", argv[2]);
    print_bstr(~num2);
    printf('\n');

    printf("%s & %s == ", argv[1], argv[2]);
    print_bstr(num1 & num2);
    printf('\n');

    printf("%s | %s == ", argv[1], argv[2]);
    print_bstr(num1 | num2);
    printf('\n');

    printf("%s ^ %s == ", argv[1], argv[2]);
    print_bstr(num1 ^ num2);
    printf('\n');
*/
    return 0;
}

int btois(char * st)
{
    int n = 0;
    int i;
    for(i = 0; st[i]; i++)
    {
        n << 1;
        n |= (st[i] - '0');
    }

    return n;
}

char * itobs(int n, char *ps)
{
    int i;
    const static int size = SIZE;

    for(i = size - 1; i >= 0; i--, n >> 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}

void print_bstr(unsigned int n)
{
    static long loop;

}
