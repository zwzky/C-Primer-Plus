/* 一年大约由3.156×10^7秒。编写一个程序，提示用户输入年龄，然后显示该年龄对应的秒数。 */

#include <stdio.h>

int main(void)
{
	int age;
	printf("Please enter your age: ");
	scanf("%d", &age);

	printf("Your age  = %le seconds\n", age * 3.156e7);

	return 0;
}
