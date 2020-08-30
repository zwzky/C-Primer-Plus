/*7.编写一个函数，从标准输入中读取字符，直到遇到文件结尾。程序要
 * 报告每个字符是否是字母。如果是，还要报告该字母在字母表中的数值位
 * 置。例如，c和C在字母表中的位置都是3。合并一个函数，以一个字符作为
 * 参数，如果该字符是一个字母则返回一个数值位置，否则返回-1。
 */

#include <stdio.h>
#include <ctype.h>

int fun(char);

int main(void)
{	
	int ch, a;
	while((ch = getchar()) != EOF){
		if(ch == '\n')
			continue;
		a = fun(ch);
		if(a == -1)
			printf("The character you input is not an alpha.\n");
		else
			printf("%c is number %d\n", ch, a);
		while((ch = getchar()) != '\n')
			continue;
	}
	printf("Bye!\n");

	return 0;
}

int fun(char ch)
{
	int n;
	if(isalpha(ch)){
		ch = toupper(ch);
		return ch - 64;
	}
	else
		return -1;
}
