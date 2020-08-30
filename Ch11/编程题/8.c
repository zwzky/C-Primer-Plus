/*8.编写一个名为string_in()的函数，接受两个指向字符串的指针作为参
 * 数。如果第2个字符串中包含第1个字符串，该函数将返回第1个字符串开始
 * 的地址。例如，string_in("hats", "at")将返回hats中a的地址。否则，该函数返
 * 回空指针。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */

#include <stdio.h>
#include <string.h>
#define SIZE	81

char * string_in(const char * st1, const char * st2);
char * s_gets(char *st, int n);

int main(void)
{
	char st1[SIZE], st2[SIZE];
	char * pt;

	puts("Please enter the 1st string:");
	while(s_gets(st1, SIZE) && st1[0] != '\0')
	{
		puts("Please enter the 2nd string:");
		while(s_gets(st2, SIZE) == NULL || st2[0] == '\0');
		pt = string_in(st1, st2);
		if(pt == NULL)
			printf("the st2 is not in the st1.\n");
		else
			printf("the st2 is in the st1.\n");
		puts("Next, please enter the 1st string:");
	}

	return 0;
}

char* string_in(const char * st1, const char * st2)
{
	int len1 = strlen(st1);
	int len2 = strlen(st2);
	int try_num = len1 - len2 + 1;
	int status;
	
	while((status = strncmp(st1, st2, len2)) && try_num--)
		st1++;
	if(status)
		return NULL;
	else
		return (char *)st1;
}

char * s_gets(char *st, int n)
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
