/*4.编写一个程序，提示用户输入一个身高（单位：厘米），并分别以厘
   米和英寸为单位显示该值，允许有小数部分。程序应该能让用户重复输入身
   高，直到用户输入一个非正值。其输出示例如下：
   Enter　a　height　in　centimeters:　182
   182.0　cm　=　5　feet,　11.7　inches
   Enter　a　height　in　centimeters　(<=0　to　quit):　168.7
   168.0　cm　=　5　feet,　6.4　inches
   Enter　a　height　in　centimeters　(<=0　to　quit):　0
   bye
*/

#include <stdio.h>
#define CM_INCHE 2.54
int main(void)
{
	float height; 
	int feet;
	float inche;
	printf("Enter a height in centimeters: ");
	scanf("%f", &height);
	while(height > 0){
		feet = height / CM_INCHE / 12;
		inche = height / CM_INCHE - feet * 12;
		printf("%.1f cm = %d feet, %.1f inches\n", height, feet, inche);
   		printf("Enter　a　height　in　centimeters　(<=0　to　quit):");
		scanf("%f", &height);	
	}
	printf("bye\n");

	return 0;
}
