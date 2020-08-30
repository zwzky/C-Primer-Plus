/*2.设计一个函数chline(ch, i, j)，打印指定的字符j行i列。在一个简单的驱
 * 动程序中测试该函数。
 */

#include <stdio.h>

void chline(char, int, int);

int main(void)
{
	chline('*', 2, 5);
	return 0;
}

void chline(char ch, int i, int j)
{
	int k = 0;
	while(k++ < i)
		printf(" ");
	while(i++ < j)
		printf("%c", ch);
	printf("\n");
}
