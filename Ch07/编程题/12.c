/*ABC 邮购杂货店出售的洋蓟售价为 2.05 美元/磅，甜菜售价为 1.15
 * 美元/磅，胡萝卜售价为 1.09美元/磅。在添加运费之前，100美元的订单有
 * 5%的打折优惠。少于或等于5磅的订单收取6.5美元的运费和包装费，5磅～
 * 20磅的订单收取14美元的运费和包装费，超过20磅的订单在14美元的基础上
 * 每续重1磅增加0.5美元。编写一个程序，在循环中用switch语句实现用户输
 * 入不同的字母时有不同的响应，即输入a的响应是让用户输入洋蓟的磅数，b
 * 是甜菜的磅数，c是胡萝卜的磅数，q 是退出订购。程序要记录累计的重
 * 量。即，如果用户输入 4 磅的甜菜，然后输入 5磅的甜菜，程序应报告9磅
 * 的甜菜。然后，该程序要计算货物总价、折扣（如果有的话）、运费和包装
 * 费。随后，程序应显示所有的购买信息：物品售价、订购的重量（单位：
 * 磅）、订购的蔬菜费用、订单的总费用、折扣（如果有的话）、运费和包装
 * 费，以及所有的费用总额.
 */

#include <stdio.h>
#define A_PRICE		2.05
#define B_PRICE		1.15
#define C_PRICE		1.09
#define DISCOUNT_LIMIT	100
#define DISCOUNT_RATE	0.05
#define FREIGHT_LIMIT1	5
#define FREIGHT_FEE1	6.4
#define FREIGHT_LIMIT2	20
#define FREIGHT_FEE2	14
#define FREIGHT_RATE	0.5

int main(void)
{	
	char ch;
	double a, b, c;
	double sum, discount, freight;
	discount = 0;
	printf("Please select your vegetables:\n");
	printf("a) artichoke: $2.05/p	b) beet: $1.15/p	c) carrot: $1.09/p	q)quit\n");
	while((ch = getchar()) != 'q'){
		switch(ch){
			case 'a': 
				printf("Please enter the pounds of artichoke you want buy.\n");
				scanf("%lf", &a);
				printf("Please select your vegetables:\n");
				printf("a) artichoke: $2.05/p	b) beet: $1.15/p	c) carrot: $1.09/p	q)quit\n");
				continue;
			case 'b':
				printf("Please enter the pounds of beet you want buy.\n");
				scanf("%lf", &b);
				printf("Please select your vegetables:\n");
				printf("a) artichoke: $2.05/p	b) beet: $1.15/p	c) carrot: $1.09/p	q)quit\n");
				continue;
			case 'c':
				printf("Please enter the pound of carrot you want buy.\n");
				scanf("%lf", &c);
				printf("Please select your vegetables:\n");
				printf("a) artichoke: $2.05/p	b) beet: $1.15/p	c) carrot: $1.09/p	q)quit\n");
				continue;
			default:
				break;
		}
	}
	printf("%10s%10s%10s%10s\n", " ", "artichoke", "beet", "carrot");
	printf("%10s%10.2lf%10.2lf%10.2lf\n", "price", A_PRICE, B_PRICE, C_PRICE);
	printf("%10s%10.2lf%10.2lf%10.2lf\n", "pound", a, b, c);
	printf("%10s%10.2lf%10.2lf%10.2lf\n", "chrage", a * A_PRICE, b * B_PRICE, c * C_PRICE);

	sum = a * A_PRICE + b * B_PRICE + c * C_PRICE;

	if(sum > DISCOUNT_LIMIT)
		discount = sum * DISCOUNT_RATE;
	printf("Discount is %.2lf.\n", discount);

	if(a + b + c < FREIGHT_LIMIT1)
		freight = FREIGHT_FEE1;
	else if(a + b + c < FREIGHT_LIMIT2)
		freight = FREIGHT_FEE2;
	else 
		freight = FREIGHT_FEE2 + (a + b + c - FREIGHT_LIMIT2) * FREIGHT_RATE;
	printf("Freight is %.2lf\n", freight);
	
	sum = sum - discount + freight;
	printf("sum is %.2lf\n", sum);

	return 0;
}
