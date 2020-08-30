/*11.编写并测试Fibonacci()函数，该函数用循环代替递归计算斐波那契数。*/

#include <stdio.h>

unsigned long Fibonacci(unsigned);

int main(void)
{
	unsigned n, i;
	printf("Please enter an integer.\n");
	while((scanf("%u", &n)) ==1){
		for(i = 1; i <= n; i++){
			printf("%lu ", Fibonacci(i));
			if((i % 10) == 0)
				printf("\n");
		}
		printf("\nPlease enter an integer.\n");
	}
	printf("\n");
	return 0;
}

unsigned long Fibonacci(unsigned n)
{
	unsigned long num, temp1 ,temp2;
	int i;
	num = temp1 = temp2 = 1;
	if(n > 2){
		for(i = 1; i <= n - 2; i++){
			num = temp1 + temp2;
			temp1 = temp2;
			temp2 = num;
		}
	}
	return num;
}
