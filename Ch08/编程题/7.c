/*7.修改第7章的编程练习8，用字符代替数字标记菜单的选项。用q代替5
* 作为结束输入的标记
*/

#include <stdio.h>
#include <ctype.h>
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
	printf("a) $8.75/hr		b) $9.33/hr\n");
	printf("c) $10.00/hr		d) $11.20/hr\n");
	printf("q) quit\n");
	printf("***********************************************************************\n");
	switch(get_choice())
	{
		case 'a': basepay =  8.75; break;
		case 'b': basepay =  9.33; break;
		case 'c': basepay = 10.00; break;
		case 'd': basepay = 11.20; break;
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
	int ch;
	while(isspace(ch = getchar()));
	while((ch < 'a' || ch > 'd') && ch != 'q')
	{
		printf("Please enter the right choice.(ex:a~d, or q)\n");
		printf("***********************************************************************\n");
		printf("Enter the number corresponding to the desired pay rate or action:\n");
		printf("a) $8.75/hr		b) $9.33/hr\n");
		printf("c) $10.00/hr		d) $11.20/hr\n");
		printf("q) quit\n");
		printf("***********************************************************************\n");
		while(isspace(ch = getchar()));
	}
	return ch;
}
