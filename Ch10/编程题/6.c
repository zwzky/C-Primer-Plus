/*6.编写一个函数，把double类型数组中的数据倒序排列，并在一个简单
 * 的程序中测试该函数。
 */

#include <stdio.h>
#define SIZE	5

void re_order(double *, int);
void show(const double *, int);

int main(void)
{
	double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	re_order(arr, SIZE);
	show(arr, SIZE);

	return 0;
}

void re_order(double *arr, int n)
{
	int i;
	double temp;
	for(i = 0; i < n / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}
}

void show(const double *arr, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%4.1f", arr[i]);
	printf("\n");
}
