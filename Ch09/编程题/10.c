/*10.为了让程序清单9.8中的to_binary()函数更通用，编写一个to_base_n()
 * 函数接受两个在2～10范围内的参数，然后以第2个参数中指定的进制打印第
 * 1个参数的数值。例如，to_base_n(129， 8)显示的结果为201，也就是129的
 * 八进制数。在一个完整的程序中测试该函数。
 */

#include <stdio.h>

void to_base_n(unsigned long int, unsigned int);

int main(void)
{
	unsigned long int number;
	unsigned int n;
	printf("Enter two integers (q to quit):\n");
	while ((scanf("%lu%u", &number, &n)) == 2)
	{
		printf("Binary equivalent: ");
		to_base_n(number, n);
		putchar('\n');
		printf("Enter two integers (q to quit):\n");
	}
	printf("Done.\n");
	return 0;
}
void to_base_n(unsigned long  int sum, unsigned int n) /* 递归函数 */
{
	int r;

	r = sum % n;
	if (sum >= n)
		to_base_n(sum / n, n);

	putchar('0'+ r);
	return;
}
