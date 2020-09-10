/* invert4.c -- 使用位操作显示二进制 */

#include <stdio.h>
#include <limits.h>     //提供CHAR_BIT的定义，CHAT_BIT表示每字节的位数
#define BITS  4

char * itobs(int, char *);
void show_bstr(const char *);
int invert_end(int num, int bits);

int main(void)
{
    int num;
    char bin_str[CHAR_BIT * sizeof(int) + 1];

    puts("Please enter integets and see them in binary.");
    puts("Non-numeric input terminates program.");
    while(scanf("%d", &num) == 1)
    {
        itobs(num, bin_str);
        printf("%d is\n", num);
        show_bstr(bin_str);
        putchar('\n');
        num = invert_end(num, BITS);
        printf("Inverting the last %d bits gives\n", BITS);
        show_bstr(itobs(num, bin_str));
        putchar('\n');
    }
    puts("Bye!");

    return 0;
}


char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for(i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}

void show_bstr(const char * str)
{
    int i = 0;
    while(str[i])
    {
        putchar(str[i]);
        if(++i % 4 == 0 && str[i])
            putchar(' ');
    }
}

int invert_end(int num, int bits)
{
    int mask = 0;
    int bitval = 1;
    
    while(bits-- > 0)
    {
        mask |= bitval;
        bitval <<= 1;
    }

    return num ^ mask;
}
