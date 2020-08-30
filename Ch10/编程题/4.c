/*4.编写一个函数，返回储存在double类型数组中最大值的下标，并在一
 * 个简单的程序中测试该函数
 */

#include <stdio.h>

#define SIZE	5

int max_index(const double *, int);

int main(void)
{
	double arr[] = {12.12, 324.21, 3, 34, 3};
	printf("the index of the max number is %d\n", max_index(arr, SIZE));

	return 0;
}

int max_index(const double *arr, int n)
{
	int i, index = 0;
	double max = *arr;
	for(i = 1; i < n; i++)
		if(max < arr[i])
		{
			max = arr[i];
			index = i;
		}

	return index;
}
