/*16.编写一个程序读取输入，直至读到文件结尾，然后把字符串打印出
 * 来。该程序识别和实现下面的命令行参数：
 * -p　　　　按原样打印
 * -u　　　　把输入全部转换成大写
 * -l　　　　把输入全部转换成小写
 *  如果没有命令行参数，则让程序像是使用了-p参数那样运行。
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE	81

void ToUpper(char * st);
void ToLower(char * st);
char * s_gets(char * st, int n);

int main(int argc, char * argv[])
{
	char st[SIZE];
	s_gets(st, SIZE);
	if(argc < 2)
	{
		printf("%s\n", st);
		return 0;
	}
	if(argc > 3)
	{
		puts("too more argument");
		return 0;
	}
	if(strcmp(argv[1], "-p") != 0 && strcmp(argv[1], "-u") != 0 && strcmp(argv[1], "-l") != 0)
	{
		puts("Plsase input -p -u -l.");
		return 0;
	}
	if(strcmp(argv[1], "-p") == 0)
		printf("%s\n", st);
	else if(strcmp(argv[1], "-u") == 0)
	{
		ToUpper(st);
		printf("%s\n", st);
	}
	else if(strcmp(argv[1], "-l") == 0)
	{
		ToLower(st);
		printf("%s\n", st);
	}
	return 0;
}

void ToUpper(char * st)
{
	while(*st)
	{
		*st = toupper(*st);
		st++;
	}
}

void ToLower(char * st)
{
	while(*st)
	{
		*st = tolower(*st);
		st++;
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
