/*6.编写一个程序打印一个表格，每一行打印一个整数、该数的平方、该
  数的立方。要求用户输入表格的上下限。使用一个for循环。
*/

#include <stdio.h>

int main(void)
{
	int a, b, t;
	printf("Please enter a min number and a max number: ");
	scanf("%d %d", &a,  &b);
	if(a > b){
		t = a; a = b; b = t;
		
	}
	for(; a <= b; a++){
		printf("%5d %5d %5d\n", a, a * a , a * a * a);

	}
	return 0;
}
