/*3.编写一个程序，读取整数直到用户输入 0。输入结束后，程序应报告
 * 用户输入的偶数（不包括 0）个数、这些偶数的平均值、输入的奇数个数及
 * 其奇数的平均值
 */
#include <stdio.h>
int main(void)
{	
	int is_even, is_odd;
	int num, total_even, total_odd;
	is_even = is_odd = total_even = total_odd = 0;
	while(scanf("%d", &num) == 1){
		if(num == 0)
			break;
		if(num % 2){
			is_odd++;
			total_odd += num;
		}
		else{
			is_even++;
			total_even += num;
		}

	}
	printf("%d %.1f %d %.1f\n", is_even, 1.0 * total_even / is_even,
		is_odd, 1.0 * total_odd / is_odd);	

	return 0;
}
