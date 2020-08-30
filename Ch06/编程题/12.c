/*12.考虑下面两个无限序列：
  1.0　+　1.0/2.0　+　1.0/3.0　+　1.0/4.0　+　...
  1.0　-　1.0/2.0　+　1.0/3.0　-　1.0/4.0　+　...
  编写一个程序计算这两个无限序列的总和，直到到达某次数。提示：奇
  数个-1 相乘得-1，偶数个-1相乘得1。让用户交互地输入指定的次数，当用
  户输入0或负值时结束输入。查看运行100项、1000项、10000项后的总和，
  是否发现每个序列都收敛于某值？
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	double sum1, sum2;
	int i, item;
	printf("Enter the number of item: ");
	scanf("%d", &item);
	while(item > 0){
		sum1 = sum2 = 0;
		for(i = 1; i <= item; i++){
			sum1 += 1.0 / i;
			sum2 += 1.0 / i * pow(-1, i+1);
		}
		printf("sum1 = %10f, sum2 = %10f\n", sum1, sum2);
		scanf("%d", &item);
	}
	return 0;
}
