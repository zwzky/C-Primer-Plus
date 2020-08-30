/*1.编写一个程序，创建一个包含26个元素的数组，并在其中储存26个小
 * 写字母。然后打印数组的所有内容
*/

#include <stdio.h>

int main(void)
{
	char ch[26];
	int i;
	for (i = 0; i < 26; i++){
		ch[i] = 'a' + i;
		printf("%c",ch[i]);
	}	
	printf("\n");
	return 0;
}
