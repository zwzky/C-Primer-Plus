/*9.编写一个程序，只接受正整数输入，然后显示所有小于或等于该数的素数。*/
#include <stdio.h>
int isprime(int n);
int main(void)
{
	int num;
	int i;
	printf("Please enter a number:\n");
	scanf("%d", &num);
	for(i = 2; i <= num; i++)
		if(isprime(i))
			printf("%d\t", i);
	return 0;
}

int isprime(int n)
{
	int i;
	for(i = 2; i < n; i++)
		if(n % i == 0)
			return 0;	
	return 1;
}
