/* 2.编写一个程序，提示用户输入名和姓，并执行一下操作：
 * a.打印名和姓，包括双引号；
 * b.在宽度为20的字段右端打印名和姓，包括双引号；
 * c.在宽度为20的字段左端打印名和姓，包括双引号；
 * d.在比姓名宽度宽3的字段中打印名和姓
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char name[40];

	printf("Please enter your name:\n");
	scanf("%s", name);

	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("%*s\n", (int)strlen(name)+3, name);
	return 0;
}
