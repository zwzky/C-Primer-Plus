/*3.编写一个函数，接受3个参数：一个字符和两个整数。字符参数是待
 * 打印的字符，第1个整数指定一行中打印字符的次数，第2个整数指定打印指
 * 定字符的行数。编写一个调用该函数的程序。
 */

#include <stdio.h>

void print(char, int, int);

int main(void)
{
	print('a', 2, 4);
	return 0;
}

void print(char ch, int a, int b)
{
	int i, j;
	for(i = 1; i <= b; i++){
		for(j = 1; j <= a; j++)
			printf("%c", ch);
		printf("\n");
	}


}
