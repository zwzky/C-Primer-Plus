/*4.设计并测试一个函数，它类似编程练习3的描述，只不过它接受第2个
 * 参数指明可读取的最大字符数。
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define  SIZE	81

void isword(char * st, int n);

int main(void)
{
	char input[SIZE];
	int n;
	puts("Please input a number:");
	scanf("%d", &n);
	getchar();
	puts("Please input a string:");
	gets(input);
	isword(input, n);
	puts(input);

	return 0;
}

void isword(char * st, int n)
{
	int i = 0;
	char * ptr = st;
	while(isspace(*ptr))
		*ptr++ = '\0';
	while(!isspace(*ptr) && i < n)
	{
		st[i] = *ptr++;
		i++;
	}
	st[ptr - st] = '\0';
}
