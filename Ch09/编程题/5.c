/*5.编写并测试一个函数larger_of()，该函数把两个double类型变量的值替换为较
 * 大的值。例如， larger_of(x, y)会把x和y中较大的值重新赋给两个变量
 */

#include <stdio.h>

void larger_of(double * x, double * y);

int main(void)
{
	double x, y;
	printf("Please enter two doubles:\n");
	scanf("%lf %lf", &x, &y);
	larger_of(&x, &y);
	printf("x = %.2f, y = %.2f\n", x, y);
	return 0;
}

void larger_of(double * x, double * y)
{
	*x = *y= (*x > *y) ? *x : *y;



}
