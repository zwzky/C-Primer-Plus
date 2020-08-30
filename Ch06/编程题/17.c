/*17.Chuckie Lucky赢得了100万美元（税后），他把奖金存入年利率8%的
 * 账户。在每年的最后一天， Chuckie取出10万美元。编写一个程序，计算多
 * 少年后Chuckie会取完账户的钱？
 */

#include <stdio.h>

int main(void)
{
	double money = 1000000;
	int i = 0;
	while( money > 0){
		money *= 1.08;
		money -= 100000;
		i++;
	}
	printf("%d\n", i);
	return 0;
}
