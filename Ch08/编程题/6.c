/*6.修改程序清单8.8中的get_first()函数，让该函数返回读取的第1个非空
 * 白字符，并在一个简单的程序中测试
 */

#include <stdio.h>
#include <ctype.h>

int get_first(void);

int main(void)
{
	putchar(get_first());
	printf("\n");
	return 0;
}

int get_first(void)
{
	int ch;
	while(isspace(ch = getchar()));
	return ch;
}
