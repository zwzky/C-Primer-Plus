/*2.修改并编程练习1的函数，在n个字符后停止，或在读到第1个空白、
 * 制表符或换行符时停止，哪个先遇到哪个停止。不能只使用scanf()
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>	//isspace()
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
	int i, j;
	for(i = 0; i < n; i++)
	{
		if(isspace(*(str + i)))
		{
			for(j = i; j < SIZE; j++)
				*(str + i) = '\0';
			break;
		}
	}
	if(i == n)
		for(; i < SIZE; i++)
			*(str + i) = '\0';
}

