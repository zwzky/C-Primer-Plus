/*9.第6章的程序清单6.20中，power()函数返回一个double类型数的正整数
 * 次幂。改进该函数，使其能正确计算负幂。另外，函数要处理0的任何次幂
 * 都为0，任何数的0次幂都为1（函数应报告0的0次幂未定义，因此把该值处
 * 理为1）。要使用一个循环，并在程序中测试该函数。
 */

#include <stdio.h>

double power(double n, int p); // ANSI函数原型
int main(void)

{
	double x, xpow;
	int exp;
	printf("Enter a number and the positive integer power");
	printf(" to which\nthe number will be raised. Enter q");
	printf(" to quit.\n");
	while (scanf("%lf%d", &x, &exp) == 2)
	{
		xpow = power(x, exp); // 函数调用
		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoyed this power trip -- bye!\n");
	return 0;
}

double power(double x, int y)
{
	double pow = 1;
	int i;
	if(y == 0){
		if(x == 0)
			printf("The 0 of power 0 is not defined.\n");
		pow = 1.0;
	}
	else if(x == 0)
		pow =0.0;
	else if(y > 0){
		pow = x * power(x, y -1);
//		for(i = 1; i <= -y; i++)
//			pow *= 1 / x;
	}
	else{
		pow = 1 / power(x, -y);
//		for(i = 1; i <= y; i++)
			pow *= x;
	}
	return pow;
}
