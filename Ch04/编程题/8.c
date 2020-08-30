/*编写一个程序，提示用户输入旅行的里程和消耗的汽油量。然后计算
  并显示消耗每加仑汽油行驶的英里数，显示小数点后面一位数字。接下来，
  使用1加仑大约3.785升，1英里大约为1.609千米，把单位是英里/加仑的值转
  换为升/100公里（欧洲通用的燃料消耗表示法），并显示结果，显示小数点
  后面 1 位数字。注意，美国采用的方案测量消耗单位燃料的行程（值越大越
  好），而欧洲则采用单位距离消耗的燃料测量方案（值越低越好）。使用
  #define 创建符号常量或使用 const 限定符创建变量来表示两个转换系数。
*/

#include <stdio.h>
#define G_L 3.785
#define M_K 1.609

int main(void)
{
	float miles, gallons;

	printf("Please enter run miles:\n");
	scanf("%f", &miles);
	printf("Please enter use gallons:\n");
	scanf("%f", &gallons);
	
	printf("Run %.1f miles per gallon\n", miles / gallons);

	printf("Run 100km use %.1f liter.\n", (gallons * G_L) / (miles * M_K) * 100);

	return 0;
}
