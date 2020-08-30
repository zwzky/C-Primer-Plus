/*9.编写一个函数，把字符串中的内容用其反序字符串代替。在一个完整
 * 的程序中测试该函数，使用一个循环给函数提供输入值。
 */

#include <stdio.h>
#include <string.h>

#define SIZE	81

void s(char * st);
char * s_gets(char * st, int n);

int main(void)
{
	char st[SIZE];
	puts("Please input a string:");
	while(s_gets(st, SIZE) && st[0] != '\0')
	{
		s(st);
		puts(st);
		puts("Next, plese input a string:");
	}

	return 0;
}

void s(char * st)
{
	int len = strlen(st);
	int i, temp;

	for(i = 0; i < len / 2; i++)
	{	
		temp = st[i];
		st[i] = st[len - i - 1];
		st[len - i - 1]= temp;
	}
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] = '\0';
		else
			while(getchar() != '\n')
				continue;	
	}
	return ret_val;
}
