/*12.编写一个程序，读取输入，直至读到 EOF，报告读入的单词数、大
 * 写字母数、小写字母数、标点符号数和数字字符数。使用ctype.h头文件中的
 * 函数。
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE	81

char * s_gets(char * st, int n);

int main(void)
{
	char str[SIZE];
	char * pt;
	
	pt = str;

	int low_cnt = 0;
	int up_cnt = 0;
	int dig_cnt = 0;
	int punc_cnt = 0;
	int word_cnt = 0;
	bool inword = false;

	puts("Enter a string:");
	s_gets(str, SIZE);
	
	while(*pt)
	{
		if(islower(*pt))
			low_cnt++;
		else if(isupper(*pt))
			up_cnt++;
		else if(isdigit(*pt))
			dig_cnt++;
		else if(ispunct(*pt))
			punc_cnt++;
		if(!isspace(*pt) && !inword)
		{
			word_cnt++;
			inword = true;
		}
		if(isspace(*pt) && inword)
			inword = false;
		pt++;
	}
	printf("low_cnt = %d, up_cnt = %d, dig_cnt = %d, punc_cnt = %d, word_cnt = %d\n",
			low_cnt, up_cnt, dig_cnt, punc_cnt, word_cnt);
	return 0;
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
