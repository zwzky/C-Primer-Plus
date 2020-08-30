/* 4、编写一个程序，读取一个浮点数，先打印成小数点形式，在打印成指数形式。然后，如果系统支持，d再打印p记数法（即16进制记数法）。按以下格式输出：
 
   Enter a floating-point value: 64.25
   fixed-point notation: 64.250000
   exponential nontation: 6.425e+01
   p nontation: 0x1.01p+6 */

#include <stdio.h>

int main(void)
{
	float fl;
	printf("Enter a floating-point value:");
	scanf("%f", &fl);
	printf("fixed-point nontation: %f\n", fl);
	printf("exponential nontation: %e\n", fl);
	printf("p nontation: %p\n", fl);

	return 0;
}
