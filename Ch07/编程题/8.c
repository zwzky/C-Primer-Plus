/*8.修改练习7的假设a，让程序可以给出一个供选择的工资等级菜单。使
 * 用switch完成工资等级选择。运行程序后，显示的菜单应该类似这样：
 * *****************************************************************
 * Enter the number corresponding to the desired pay rate or action:
 * 1) $8.75/hr　　　　　　　　　　　　　2) $9.33/hr
 * 3) $10.00/hr　　　　　　　　　　　　　4) $11.20/hr
 * 5) quit
 * *****************************************************************
 * 如果选择 1～4 其中的一个数字，程序应该询问用户工作的小时数。程
 * 序要通过循环运行，除非用户输入 5。如果输入 1～5 以外的数字，程序应
 * 提醒用户输入正确的选项，然后再重复显示菜单提示用户输入。使用#define
 * 创建符号常量表示各工资等级和税率。
 */

#include <stdio.h>
#define BASEHOURS	40
#define OVERTIME	1.5
#define AMT1		300
#define AMT2		150
#define RATE1		0.15
#define RATE2		0.2
#define RATE3		0.25

int get_choice(void);

int main(void)
{
	double basepay;
	double hours;
	double gross;
	double taxes;
	double net;
	printf("***********************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) $8.75/hr		2) $9.33/hr\n");
	printf("3) $8.75/hr		4) $9.33/hr\n");
	printf("5) quit\n");
	printf("***********************************************************************\n");
	switch(get_choice())
	{
		case 1:	basepay =  8.75; break;
		case 2:	basepay =  9.33; break;
		case 3: basepay = 10.00; break;
		case 4: basepay = 11.20; break;
		defalut: printf("quit\n"); return 0;
	
	}
	printf("You have selseted %.2lf\n", basepay);
	printf("Please enter your work hours:\n");
	scanf("%lf", &hours);
	if(hours <= BASEHOURS)
		gross = basepay * hours;
	else
		gross = basepay * BASEHOURS + basepay * OVERTIME * (hours - BASEHOURS);
	if(gross < AMT1)
		taxes = gross * RATE1;
	else if(gross <= AMT1 + AMT2)
		taxes = AMT1 * RATE1 + (gross - AMT1) * RATE2;
	else
		taxes = AMT1 * RATE1 + AMT2 * RATE2 + (gross - AMT1 - AMT2) * RATE3;
	net = gross - taxes;
	printf("gross = $%.2f, taxes = $%.2f, net = $%.2f\n", gross, taxes, net);
	
	return 0;
}

int get_choice(void)
{
	int n;
	scanf("%d", &n);
	while(n < 1 || n > 5)
	{
		printf("Please enter the right choice:\n");
		printf("***********************************************************************\n");
		printf("Enter the number corresponding to the desired pay rate or action:\n");
		printf("1) $8.75/hr		2) $9.33/hr\n");
		printf("3) $8.75/hr		4) $9.33/hr\n");
		printf("5) quit\n");
		printf("***********************************************************************\n");
		scanf("%d", &n);
	}
	return n;
}
