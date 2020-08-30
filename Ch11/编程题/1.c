/*1.设计并测试一个函数，从输入中获取下n个字符（包括空白、制表
 * 符、换行符），把结果储存在一个数组里，它的地址被传递作为一个参数。
 */

#include <stdio.h>
#include <string.h>
#define SIZE	81

void getnword(char * str, int n);

int main(void)
{
	char input[SIZE];
	int n;

	puts("Please input a number you want to read:");
	scanf("%d", &n);
	getchar();
	puts("Please input a string:");
	gets(input);
	getnword(input, n);
	puts(input);

	return 0;
}

void getnword(char * str, int n)
{
	int i;
	for(; n < SIZE; n++)
	{
		*(str + n) = '\0';
	}
}

