/*3.设计并测试一个函数，从一行输入中把一个单词读入一个数组中，并
 * 丢弃输入行中的其余字符。该函数应该跳过第1个非空白字符前面的所有空
 * 白。将一个单词定义为没有空白、制表符或换行符的字符序列
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define  SIZE	81

void isword(char * st);

int main(void)
{
	char input[SIZE];
	puts("Please inoput a string:");
	gets(input);
	isword(input);
	puts(input);

	return 0;
}

void isword(char * st)
{
	int i = 0;
	char * ptr = st;
	while(isspace(*ptr))
		*ptr++ = '\0';
	while(!isspace(*ptr))
	{
		st[i] = *ptr++;
		i++;
	}
	st[ptr - st] = '\0';
}
