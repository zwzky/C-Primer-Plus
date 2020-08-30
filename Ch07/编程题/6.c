/*6.编写程序读取输入，读到#停止，报告ei出现的次数。注意
 * 该程序要记录前一个字符和当前字符。用“Receive your eieio award”这
 * 样的输入来测试。
 */

#include <stdio.h>

int main(void)
{
	char ch, a = ' ';
	int n = 0;
	while((ch = getchar()) != '#')
	{
		if (ch == 'i' && a == 'e')
			n++;
		a = ch;
	}
	printf("%d\n", n);
	return 0;
}
