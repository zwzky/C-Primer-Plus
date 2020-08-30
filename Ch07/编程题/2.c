/*2.编写一个程序读取输入，读到#字符停止。程序要打印每个输入的字
 * 符以及对应的ASCII码（十进制）。一行打印8个字符。建议:使用字符计数
 * 和求模运算符（%）在每8个循环周期时打印一个换行符。
 */

#include <stdio.h>

int main(void)
{	
	char ch;
	int i = 1;
	while ((ch = getchar()) != '#')
	{
		if (i % 9 == 0)
			printf("\n");
		else
			printf("%3c %3d ", ch, ch);
		i++;
	}	
	printf("\n");

	return 0;
}
