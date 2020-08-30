/*修改程序addemup.c（程序清单5.13），你可以认为addemup.c是计算20
  天里赚多少钱的程序（假设第1天赚$1、第2天赚$2、第3天赚$3，以此类
  推）。修改程序，使其可以与用户交互，根据用户输入的数进行计算（即，
  用读入的一个变量来代替20）。
*/

#include <stdio.h>

int main(void)
{	
	int day, i, money;
	i = 1;
	money = 0;
	printf("Please enter days: ");
	scanf("%d", &day);
	while(i <= day){
		money += i++;
	}
	printf("In %d days, you make %d money.\n", day, money);

	return 0;
}
