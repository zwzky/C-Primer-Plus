/*4.两数的调和平均数这样计算：先得到两数的倒数，然后计算两个倒数
 * 的平均值，最后取计算结果的倒数。编写一个函数，接受两个double类型的
 * 参数，返回这两个参数的调和平均数。
 */

#include <stdio.h>

double  ad(double, double);

int main(void)
{
	printf("%.2f and %.2f is %.2f\n", 1.34, 323.3, ad(1.34, 342));
	
	return 0;
}

double ad(double x, double y)
{
	return 2 / (1/x + 1/y);
}
