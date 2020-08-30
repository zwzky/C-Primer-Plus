/*编写一个程序，将一个double类型的变量设置为1.0/3.0，一个float类
  型的变量设置为1.0/3.0。分别显示两次计算的结果各3次：一次显示小数点
  后面6位数字；一次显示小数点后面12位数字；一次显示小数点后面16位数
  字。程序中要包含float.h头文件，并显示FLT_DIG和DBL_DIG的值。1.0/3.0
  的值与这些值一致吗?
*/

#include <stdio.h>
#include <float.h>

int main(void)
{
	float num1;
	double num2;

	num1 = 1.0/ 3.0;
	num2 = 1.0/ 3.0;

	printf("%.6f %.12f %.16f\n", num1, num1, num1);
	printf("%.6f %.12f %.16f\n", num2, num2, num2);
	printf("%d %d\n", FLT_DIG, DBL_DIG);

	return 0;
}
