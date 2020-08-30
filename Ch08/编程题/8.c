/*8.编写一个程序，显示一个提供加法、减法、乘法、除法的菜单。获得
 * 用户选择的选项后，程序提示用户输入两个数字，然后执行用户刚才选择的
 * 操作。该程序只接受菜单提供的选项。程序使用float类型的变量储存用户输
 * 入的数字，如果用户输入失败，则允许再次输入。进行除法运算时，如果用
 * 户输入0作为第2个数（除数），程序应提示用户重新输入一个新值。该程序
 * 的一个运行示例如下：
 * Enter the operation of your choice:
 * a. add        s. subtract
 * m. multiply    d. divide
 * q. quit
 * a
 * Enter first number: 22 .4
 * Enter second number: one
 * one is not an number.
 * Please enter a number, such as 2.5, -1.78E8, or 3: 1
 * 22.4 + 1 = 23.4
 * Enter the operation of your choice:
 * a. add        s. subtract
 * m. multiply    d. divide
 * q. quit
 * d
 * Enter first number: 18.4
 * Enter second number: 0
 * Enter a number other than 0: 0.2
 * 18.4 / 0.2 = 92
 * Enter the operation of your choice:
 * a. add        s. subtract
 * m. multiply    d. divide
 * q. quit
 * q
 * Bye.
 *
 *
 *思路
 *1、打印菜单
 *2、获取用户输入选项，判断是否进入循环
 *3、获取第一个浮点数
 *4、获取第二个浮点数
 *5、当用书输入的为除法选项时，判断第二个浮点数是否为零
 *6、根据用户的输入进行计算并输入
 *7、再次打印菜单
 *8、继续获取用书输入选项，判断是否进入循环
 *9、结束循环，结束
 */

#include <stdio.h>
#include <ctype.h>

void menu(void);	//输出菜单
char get_choice(void);	//获取用户选择
char get_first(void);	//获取用户输入的第一个字符
float get_float(void);	//获取用户输入的浮点数

int main(void)
{
	float num1 = 0;
	float num2 = 0;
	char choice;
	
	menu();

	while((choice = get_choice()) != 'q'){	//循环，当用户输入q时退出
		printf("Enter the first number: ");
		num1 = get_float();		//获取用户输入的第一个浮点数
		printf("Enter the second number: ");
		num2 = get_float();		//获取用户输入的第二个浮点数
		while(num2 == 0 && choice == 'd'){//当用书选择除法时，判断第二个浮点数是否为0
			printf("Enter a number other than 0: ");
			num2 = get_float();
		}
		switch(choice){		//根据用户的输入进行计算并打印
			case 'a': printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2); break;
			case 's': printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2); break;
			case 'm': printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2); break;
			case 'd': printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2); break;
			default:  printf("Quit.\n"); break;
		}
		menu();		//重复打印菜单
	}
	printf("Bye!\n");
	return 0;
}


void menu(void)
{
	printf("Enter the operation fi your choice:\n");
	printf("a. add		s. subtract\n");
	printf("m. multiply	d. divide\n");
	printf("q. quit\n");
}

char get_choice()
{
	char ch;
	ch = get_first();
	while(ch != 'a' && ch != 's' && ch != 'm' && ch !='d' && ch != 'q'){
		printf("Please reponse with a, s, d, m, q\n");
		ch = get_choice();
	}
	return ch;
}

char get_first()
{
	char input;
	while(isspace(input = getchar()));
	while(getchar() != '\n')
		continue;
	return input;

}

float get_float()
{
	float num;
	int ch;
	while(scanf("%f", &num) != 1){
		while((ch = getchar()) != '\n')
			putchar(ch);
		printf("is not float number.\n");
		printf("Please enter a float number as 2.5, 1.78E8, or 3: ");
	}
	return num;
}
