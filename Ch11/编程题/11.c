/*11.编写一个函数，读入10个字符串或者读到EOF时停止。该程序为用
 * 户提供一个有5个选项的菜单：打印源字符串列表、以ASCII中的顺序打印字
 * 符串、按长度递增顺序打印字符串、按字符串中第1个单词的长度打印字符
 * 串、退出。菜单可以循环显示，除非用户选择退出选项。当然，该程序要能
 * 真正完成菜单中各选项的功能
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE	81
#define LIM	10

void show_str(char * st[], int n);
void show_ascii(char * st[], int n);
void show_length(char * st[], int n);
void show_firstwordlen(char * st[], int n);
int first_wordlen(char *st);
char * s_gets(char * st, int n);
char get_choice();
char get_first();

int main(void)
{
	char input[LIM][SIZE];
	int ct;
	char * pt[SIZE];
	char ch;
	while(1)
	{
		puts("Please input no more than 10 string or enter EOF ");
		for(ct = 0; ct < LIM; ct++)
		{
			s_gets(input[ct], SIZE);
			pt[ct] = input[ct];
			if(input[ct][0] == '\0')
				break;
		}
		puts("***************************************");
		puts("a: originally");
		puts("b：order in ASCII");
		puts("c: order in STRING LEN");
		puts("d：order in the first word length");
		puts("q:quit");
		puts("***************************************");
		puts("Please enter your choice:");
	
		ch = get_choice();
		
		switch(ch)
		{
			case 'a': 
				show_str(pt, ct); 
				break;
			case 'b':
				show_ascii(pt, ct); 
				break;
			case 'c': 
				show_length(pt, ct); 
				break;
			case 'd': 
				show_firstwordlen(pt, ct); 
				break;
			default: 
				break;	
		}
	}
	return 0;
}

char get_choice()
{
	char choice;
	choice = get_first();
	while(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'q')
	{
		puts("Please reponse with a, b, c, d, q");
		choice = get_choice();
	}
	return choice;
}

char get_first()
{
	char input;
	while(isspace(input = getchar()));
	while(getchar() != '\n')
		continue;
	return input;
}

void show_str(char * st[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		puts(st[i]);
}

void show_ascii(char * st[], int n)
{
	int i, j;
	char * temp;
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(strcmp(st[i], st[j]) > 0)
			{
				temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
		}
	}
	show_str(st, n);
}

void show_length(char * st[], int n)
{
	int i, j;
	char * temp;
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(strlen(st[i]) > strlen(st[j]))
			{
				temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
		}
	}
	show_str(st, n);
}

void show_firstwordlen(char * st[], int n)
{
	int i, j;
	char * temp;
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(first_wordlen(st[i]) > first_wordlen(st[j]))
			{
				temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
		}
	}
	show_str(st, n);
}

int first_wordlen(char *st)
{
	int n = 0;
	while(*st != '\0')
	{
		if(!isspace(*st++))
			n++;
		else
			break;
	}

	return n;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, SIZE, stdin);
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
