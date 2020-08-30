/*7.编写一个程序，提示用户输入一个double类型的数，并打印该数的立
  方值。自己设计一个函数计算并打印立方值。main()函数要把用户输入的值
  传递给该函数。
*/

#include <stdio.h>
void cubic(double n); 

int main(void)
{
	double num;
	printf("Please enter a double number: ");
	scanf("%lf", &num);
	cubic(num);

	return 0;
}

void cubic(double n)
{
	printf("%.2f\n", n * n * n);
}	
