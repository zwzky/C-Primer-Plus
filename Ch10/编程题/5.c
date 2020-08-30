/*5.编写一个函数，返回储存在double类型数组中最大值和最小值的差
 * 值，并在一个简单的程序中测试该函数。
 */

#include <stdio.h>
#define SIZE	5

double diff_arr(const double *, int);

int main(void)
{
	double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double diff;

	diff = diff_arr(arr, SIZE);
	printf("diff = %.2f\n", diff);

	return 0;
}

double diff_arr(const double *arr, int n)
{
	double max, min;
	max = min = arr[0];
	int i;
	for(i = 1; i < n; i++)
	{
		if(max < arr[i])
			max = arr[i];
		else if(min > arr[i])
			min = arr[i];
	}
	return max - min;
}
