/*6.编写并测试一个函数，该函数以3个double变量的地址作为参数，把最
 * 小值放入第1个函数，中间值放入第2个变量，最大值放入第3个变量。
 */

#include <stdio.h>

void asd(double *, double *, double *);

int main(void)
{

	double x, y, z;
	
	printf("Please enter shree doubles:\n");
	scanf("%lf %lf %lf", &x, &y, &z);
	asd(&x, &y, &z);
	printf("x = %.2f, y = %.2f, z = %.2f.\n", x, y, z);
	return 0;
}
void asd(double * x, double * y, double * z)
{
	double temp;
	if(*y < *x){
		temp = *x;
		*x = *y;
		*y = temp;
	}
	if(*z < *x)
	{
		temp = *x;
		*x = *z;
		*z = temp;
	}
	if(*z < *y)
	{
		temp = *y;
		*y = *z;
		*z = temp;
	}
}
