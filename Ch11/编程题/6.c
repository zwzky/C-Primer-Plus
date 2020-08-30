/*6.编写一个名为is_within()的函数，接受一个字符和一个指向字符串的
 * 指针作为两个函数形参。如果指定字符在字符串中，该函数返回一个非零值
 * （即为真）。否则，返回0（即为假）。在一个完整的程序中测试该函数，
 * 使用一个循环给函数提供输入值。
 */


#include <stdio.h>
#define SIZE	81

int is_within(char * str, char ch);

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
		if(is_within(input, ch))
			printf("Find character %c in %s.\n", ch, input);
		else
			printf("Can't find character %c in %s.\n", ch, input);
		puts("Please enter other string:");
	}

	return 0;
}

int is_within(char * str, char ch)
{
	while(*str != '\0')
		if(*str++ == ch)
			return 1;
	return 0;
}
