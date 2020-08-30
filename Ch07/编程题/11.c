/*10.1988年的美国联邦税收计划是近代最简单的税收方案。它分为4个类
 * 别，每个类别有两个等级。
 * 下面是该税收计划的摘要（美元数为应征税的收入）：
 
 *类别			税金
 单身			17850美元按15号计,超出部分按28号计
 户主			23900美元按158计,超出部分按28号计
 已婚,共有		29750美元按158计,超出部分按288计
 已婚,离异		14875美元按158计,超出部分按28号计
 *
 
 * 例如，一位工资为20000美元的单身纳税人，应缴纳税费
 * 0.15×17850+0.28×（20000−17850）美元。编写一个程序，让用户指定缴纳
 * 税金的种类和应纳税收入，然后计算税金。程序应通过循环让用户可以多次
 * 输入。
 */

#include <stdio.h>
#define RATE1		0.15
#define RATE2		0.28
#define SINGEL		17850
#define HOST		23900
#define MARRIED_SHARE	29750
#define MARRIED_DIVORCE	14875
int main(void)
{
	double salary;
	double type_tax;
	double taxes;
	int i;
	while(1){
		printf("Select the type of marriage :\n");
		printf("1) SINGEL	2) HOST		3) MARRIED_SHARE	4) MARRIED_DIVORCE\n");
		while(scanf("%d", &i))
		
		switch (i)
		{
			case 1 : type_tax = SINGEL; break;
			case 2 : type_tax = HOST; break;
			case 3 : type_tax = MARRIED_SHARE; break;
			case 4 : type_tax = MARRIED_DIVORCE; break;
			default : printf("Input error please enter again,\n"); 
		}
		printf("You have selected %d.\n", i);
		printf("Please enter your salary:\n");
		scanf("%lf", &salary);
		if(salary <= type_tax)
			taxes = salary * RATE1;
		else
			taxes = type_tax * RATE1 + (salary - type_tax) * RATE2;
		printf("taxes = %.2f\n", taxes);
	}

	return 0;
}
