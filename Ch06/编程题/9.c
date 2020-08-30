/*9.修改练习8，使用一个函数返回计算的结果。*/

#include <stdio.h>
double f(double a, double b);

int main(void)
{
	double a, b;
	printf("Enter two double number: ");
	while(scanf("%lf %lf", &a ,&b) == 2){
		printf("%f", f(a, b));
	}



	return 0;
}

double f(double a, double b){
	double n;
	n = (a - b)/(a * b);
	return n;
}
