/*4.使用if else语句编写一个程序读取输入，读到#停止。用感叹号替换句
 * 号，用两个感叹号替换原来的感叹号，最后报告进行了多少次替换。
 */

#include <stdio.h>

int main(void)
{
	char ch;
	int n = 0;
	printf("Please enter the string:\n");
	while ((ch = getchar()) != '#'){
		if(ch == '.')
		{	putchar('!');
			n++;
		}
		else if(ch == '!')
		{
			putchar('i');		
			putchar('!');
			n++;
		}
		else
			putchar(ch);
	}
	printf("the number of replace are %d\n", n);

	return 0;
}
