//.编写一个程序，提示用户输入名和姓，然后以“名,姓”的格式打印出来。

#include <stdio.h>

int main(void)
{
	char first_name[40], last_name[40];

	printf("Please enter your first name:\n");
	scanf("%s", first_name);
	printf("Please enter your last name:\n");
	scanf("%s", last_name);

	printf("%s.%s\n", last_name, first_name);

	return 0;
}
