/*编写一个程序，先提示用户输入名，然后提示用户输入姓。在一行打
  印用户输入的名和姓，下一行分别打印名和姓的字母数。字母数要与相应名
  和姓的结尾对齐，如下所示：
  Melissa Honeybee
  7　　　　8
  接下来，再打印相同的信息，但是字母个数与相应名和姓的开头对齐，
  如下所示：
  Melissa Honeybee
  7　　　8
*/

#include <stdio.h>
#include <string.h>
int main(void)
{
	char fname[40];
	char lname[40];

	printf("Please ernter your first name:\n");
	scanf("%s", fname);
	printf("Please ernter your last name:\n");
	scanf("%s", lname);

	printf("%s %s\n", lname, fname);
	printf("%7ld %8ld\n", strlen(lname), strlen(fname));
	printf("%s %s\n", lname, fname);
	printf("%-7ld %-8ld\n", strlen(lname), strlen(fname));

	return 0;
}
