/* 编写一个程序，要求提示输入一个ASCII码值（如：66），然后打印输入的字符。 */
#include <stdio.h>

int main(void)
{
	int i;
	printf("请输入一个ASCII值：");
	scanf("%d", &i);
	printf("%c\n", i);

	return 0;
}
