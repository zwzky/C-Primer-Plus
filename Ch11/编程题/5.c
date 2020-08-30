/*5.设计并测试一个函数，搜索第1个函数形参指定的字符串，在其中查
 * 找第2个函数形参指定的字符首次出现的位置。如果成功，该函数返指向该
 * 字符的指针，如果在字符串中未找到指定字符，则返回空指针（该函数的功
 * 能与 strchr()函数相同）。在一个完整的程序中测试该函数，使用一个循环
 * 给函数提供输入值。
 */

#include <stdio.h>
#define SIZE	81

char * findfirst(char * str, char ch);

int main(void)
{
	char input[SIZE];
	char ch;
	char * pt;

	puts("Please input a string:");
	while(gets(input) && input[0] != '\0')
	{
		puts("Please input a character you want to find:");
		ch = getchar();
		while(getchar() != '\n')
			continue;
		pt = findfirst(input, ch);
		if(pt == NULL)
			printf("Can't find %c in sting.\n", ch);
		else
			printf("Find character %c in %p.\n", ch, pt);
		puts("Please enter other string:");
	}

	return 0;
}

char * findfirst(char * str, char ch)
{
	while(*str != '\0')
		if(*str++ == ch)
			return str;
	return NULL;
}
