/*15.编写一个程序，读取一行输入，然后把输入的内容倒序打印出来。
 * 可以把输入储存在char类型的数组中，假设每行字符不超过255。回忆一
 * 下，根据%c转换说明，scanf()函数一次只能从输入中读取一个字符，而且
 * 在用户按下Enter键时scanf()函数会生成一个换行字符（\n)
 */

#include <stdio.h>

int main(void)
{	
	char ch[255];
	int i;
	scanf("%c", &ch[0]);
	for(i = 0; ch[i] != '\n'; ){
		scanf("%c", &ch[i++]);
	}
	for(i--; i >= 0; i-- ){
		printf("%c", ch[i]);
	}
	printf("\n");
	return 0;
}
