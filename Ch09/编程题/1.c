/*1.设计一个函数min(x, y)，返回两个double类型值的较小值。在一个简单
 * 的驱动程序中测试该函数
 */

#include <stdio.h>

double min(double, double);

int main(void)
{
	double x, y;
	printf("Please enter two doubles:\n");
	scanf("%lf %lf", &x, &y);
	printf("the smaller is %.2f.\n", min(x, y));

	return 0;
}

double min(double x, double y)
{
	return (x > y) ? y : x; 
}
