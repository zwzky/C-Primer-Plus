/*7.编写一个程序，提示用户输入一周工作的小时数，然后打印工资总
 * 额、税金和净收入。做如下假设：
 * a.基本工资 = 1000美元/小时
 * b.加班（超过40小时） = 1.5倍的时间
 * c.税率： 前300美元为15%
 * 续150美元为20%
 * 余下的为25%
 * 用#define定义符号常量。不用在意是否符合当前的税法。
 */

#include <stdio.h>
#define	BASEPAY		10.00
#define BASEHOURS	40
#define OVERTIME	1.5
#define AMT1		300
#define AMT2		150
#define RATE1		0.15
#define RATE2		0.2
#define RATE3		0.25

int main(void)
{	
	double hours;
	double gross;
	double taxes;
	double net;
	printf("Please enter your work hours:\n");
	scanf("%lf", &hours);
	if(hours <= BASEHOURS)
		gross = BASEPAY * hours;
	else
		gross = BASEPAY * BASEHOURS + BASEPAY * OVERTIME * (hours - BASEHOURS);
	if(gross < AMT1)
		taxes = gross * RATE1;
	else if(gross <= AMT1 + AMT2)
		taxes = AMT1 * RATE1 + (gross - AMT1) * RATE2;
	else
		taxes = AMT1 * RATE1 + AMT2 * RATE2 + (gross - AMT1 - AMT2) * RATE3;
	net = gross - taxes;
	printf("gross = $%.2f, taxes = $%.2f, net = $%.2f", gross, taxes, net);
	
	return 0;
	
}
