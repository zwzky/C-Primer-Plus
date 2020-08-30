/*1.编写一个程序读取输入，读到#字符停止，然后报告读取的空格数、
 * 换行符数和所有其他字符的数量。
 */

#include <stdio.h>

int main(void)
{
	char ch;
	int a, b, c;
	a = b = c = 0;
	while((ch = getchar()) != '#')
	{
		switch(ch)
		{
			case ' ' : a++; break;
			case '\n': b++; break;
			default  : c++;
		}
	}
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	return 0;
}
