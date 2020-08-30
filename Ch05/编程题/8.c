/*8.编写一个程序，显示求模运算的结果。把用户输入的第1个整数作为
  求模运算符的第2个运算对象，该数在运算过程中保持不变。用户后面输入
  的数是第1个运算对象。当用户输入一个非正值时，程序结束。其输出示例
  如下：
  This program computes moduli.
  Enter an integer to serve as the second operand: 256
  Now enter the first operand: 438
  438 % 256 is 182
  Enter next number for first operand (<= 0 to quit): 1234567
  1234567 % 256 is 135
  Enter next number for first operand (<= 0 to quit): 0
  Done
*/

#include <stdio.h>
int main(void)
{
	int i, num;
	printf("This program computer moduli.\n");
	printf("Enter a integer to serve as the second operand: ");
	scanf("%d", &i);
	printf("Now enter the first operand: ");
	scanf("%d", &num);
	while(num > 0){
		printf("%d %% %d is %d\n", num, i, num % i);
		printf("Enter next number for first operand (<=0 to quit): ");
		scanf("%d", &num);
	}
	printf("Done!\n");
	return 0;
}
