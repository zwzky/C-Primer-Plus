/*16.Daphne以10%的单利息投资了100美元（也就是说，每年投资获利相
 * 当于原始投资的10%）。Deirdre以 5%的复合利息投资了 100 美元（也就是
 * 说，利息是当前余额的 5%，包含之前的利息）。编写一个程序，计算需要
 * 多少年Deirdre的投资额才会超过Daphne，并显示那时两人的投资额
 */

#include <stdio.h>

int main(void)
{
	double  money1 = 100, money2 = 100;
	int i = 0;
	while(money2 <= money1){
		money1 += 100 * 0.1;
	       	money2 *= 1.05;
		i++;
	}
	printf("%f %f %d\n", money1, money2, i);
	return 0;
}
