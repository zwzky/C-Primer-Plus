/* 1英寸相当于2.54厘米。编写一个程序，提示用户输入身高（/英寸），然后以厘米为单位显示身高 */

#include <stdio.h>

int main(void)
{
	float height;
	printf("Enter your height: ");
	scanf("%f", &height);
	
	height = height * 2.54;
	printf("your height is %.2f\n", height);

	return 0;
}
