/*7.strncpy(s1, s2, n)函数把s2中的n个字符拷贝至s1中，截断s2，或者有必
 * 要的话在末尾添加空字符。如果s2的长度是n或多于n，目标字符串不能以空
 * 字符结尾。该函数返回s1。自己编写一个这样的函数，名为mystrncpy()。在
 * 一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */

#include <stdio.h>
#include <string.h>
#define SIZE	81

char * mystrncpy(char * st1, char * st2, int n);
char * s_gets(char *ch, int n);

int main(void)
{
	char st1[SIZE], st2[SIZE];
	int n;
	puts("Please input a string:");
	while(s_gets(st2, SIZE) && st2[0] != '\0')
	{
		puts("Please input a number:");
		scanf("%d", &n);
		getchar();
		mystrncpy(st1, st2, n);
		puts(st1);
		puts("Next, please input a string:");
	}
	puts("Done!");
	return 0;
}

char * mystrncpy(char * st1, char * st2, int n)
{
	int i;
	for(i = 0; i < n; i++)
		*(st1 + i) = *(st2 +i);
	if(strlen(st2) > n)
		*(st1 + i) = '\0';
	return st1;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val =fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] = '\0';
		else
			while(st[i] != '\n')
				continue;
	}
	return ret_val;
}
