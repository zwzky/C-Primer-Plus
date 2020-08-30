/*10.编写一个程序，要求用户输入一个上限整数和一个下限整数，计算
   从上限到下限范围内所有整数的平方和，并显示计算结果。然后程序继续提
   示用户输入上限和下限整数，并显示结果，直到用户输入的上限整数小于下
   限整数为止。程序的运行示例如下：
   Enter　lower　and　upper　integer　limits:　5　9
   The　sums　of　the　squares　from　25　to　81　is　255
   Enter　next　set　of　limits:　3　25
   The　sums　of　the　squares　from　9　to　625　is　5520
   Enter　next　set　of　limits:　5　5
   Done
*/

#include <stdio.h>

int main(void)
{
	long int a, b, sum;
	printf("Enter lower and upper integer limits: ");
	scanf("%ld %ld", &a, &b);
	while(a < b){
		sum = 0;
		for(int i = 0; a + i <= b; i++){
			sum += (a + i) * (a + i);
		}
		printf("The sums of the squares for %ld to %ld is %ld\n",
			a*a, b*b, sum);
		printf("Enter next set of limits: ");
		scanf("%ld %ld", &a, &b);
	}
	printf("Done\n");
	return 0;
}
