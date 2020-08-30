/*3.编写一个函数，返回储存在int类型数组中的最大值，并在一个简单的
 * 程序中测试该函数。
 */

#include <stdio.h>
#define SIZE	9

int max_arr(const int [], int);

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int max;
	max = max_arr(arr, SIZE);
	printf("%d is the max number in arr.\n", max);

	return 0;
}

int max_arr(const int arr[], int n)
{
	int max = arr[0];
	int i;
	for(i = 1; i < n; i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	return max;
}
