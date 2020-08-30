/*3.编写一个程序，在遇到 EOF 之前，把输入作为字符流读取。该程序
 * 要报告输入中的大写字母和小写字母的个数。假设大小写字母数值是连续
 * 的。或者使用ctype.h库中合适的分类函数更方便。
 */

#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int ch;
	int upper, lower;
	upper = lower = 0;
	while((ch = getchar()) != EOF){
	//	if(ch >= 'a' && ch <= 'z')
		if(islower(ch))
			lower++;
	//	else if(ch >= 'A' && ch <= 'Z')
		if(isupper(ch))
			upper++;
	}
	printf("\nupper characters are %d, lower characters are %d.\n", upper, lower);

	return 0;
}
