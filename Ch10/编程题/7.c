/*7.编写一个程序，初始化一个double类型的二维数组，使用编程练习2中
 * 的一个拷贝函数把该数组中的数据拷贝至另一个二维数组中（因为二维数组
 * 是数组的数组，所以可以使用处理一维数组的拷贝函数来处理数组中的每个
 * 子数组）。
 */

#include <stdio.h>
void copy_arr(double *, double *, int);
void show(double *, int);

int main(void)
{
	double arr[3][3] = {{1.2, 1.2, 3.2}, {1.3, 2.3, 3.3}, {1.4, 2.4, 3.4}};
	double target[3][3];
	show(arr[0], 3 * 3);
	copy_arr(target[0], arr[0], 3 * 3);
	show(target[0], 3 * 3);
	return 0;
}

void copy_arr(double *target, double *source, int n)
{
	int i;
	for(i = 0; i < n; i++)
		*target++ = *source++;
}

void show(double *target, int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		printf("%4.1f ", *target++);
		if((i+1) % 3 == 0)
			printf("\n");
	}
	printf("\n");
}	
