/*15.使用字符分类函数实现atoi()函数。如果输入的字符串不是纯数字，该函数返回0 */

#include <stdio.h>
#include <ctype.h>
#define SIZE	81

int myatoi(char *st);
char * s_gets(char * st, int n);

int main(void)
{
	char st[SIZE];
	while(s_gets(st, SIZE) && st[0] != '\0')
	{
		printf("%d\n", myatoi(st));
		puts("Next again");
	}
	return 0;
}

int myatoi(char *st)
{
	int n = 0;
	int sign = 1;
	while(isspace(*st))
		st++;
	if(*st == '-')
	{
		sign = -1;
		st++;
	}
	if(*st == '+')
	{
		sign = 1;
		st++;
	}
	else
	{
		while(*st)
		{
			if(!isdigit(*st))
				return 0;
			n =10 * n + (*st - '0');
			st++;
		}
	}
	n *= sign;

	return n;
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
