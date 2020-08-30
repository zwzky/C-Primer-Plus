/*4.使用嵌套循环，按下面的格式打印字母：
  A
  BC
  DEF
  GHIJ
  KLMNO
  PQRSTU
*/

#include <stdio.h>

int main(void)
{
	char start = 'A';
	int i, j;
	for(i = 1; i <= 6; i++)
	{
		for(j = 1; j <= i ; j++,start++)
			printf("%c", start);	
		printf("\n");
	}
	return 0;
}
