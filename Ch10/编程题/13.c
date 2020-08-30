/*13.编写一个程序，提示用户输入3组数，每组数包含5个double类型的数
 * （假设用户都正确地响应，不会输入非数值数据）。该程序应完成下列任务。
 * a.把用户输入的数据储存在3×5的数组中
 * b.计算每组（5个）数据的平均值
 * c.计算所有数据的平均值
 * d.找出这15个数据中的最大值
 * e.打印结果
 * 每个任务都要用单独的函数来完成（使用传统C处理数组的方式）。完
 * 成任务b，要编写一个计算并返回一维数组平均值的函数，利用循环调用该
 * 函数3次。对于处理其他任务的函数，应该把整个数组作为参数，完成任务c
 * 和d的函数应把结果返回主调函数。
 */

#include <stdio.h>

void get_arr(double (*arr)[5], int n);
double average_c(double *arr, int n);
double average_arr(double (*arr)[5], int n);
double max_arr(double (*arr)[5], int n);

int main(void)
{
	double arr[3][5];
	get_arr(arr, 3);
	int i;
	for(i = 0; i < 3; i++)
		printf("the average of %d colum is %4.1f\n", i + 1, average_c(arr[i], 5));
	printf("the average of arr is %.1f\n", average_arr(arr, 3));
	printf("the max number of arr is %.1f\n", max_arr(arr, 3));

	return 0;
}

void get_arr(double (*arr)[5], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < 5; j++)
			scanf("%lf", &arr[i][j]);
}

double average_c(double *arr, int n)
{
	int i;
	double subtot = 0;
	for(i = 0; i < n; i++)
		subtot += arr[i];
	return subtot / n;
}

double average_arr(double (*arr)[5], int n)
{
	int i, j;
	double total = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < 5; j++)
			total += arr[i][j];
	return total / (n * 5);
}

double max_arr(double (*arr)[5], int n)
{
	double max = arr[0][0];
	int i ,j;
	for(i = 0; i < n; i++)
		for(j = 1; j < 5; j++)
			if(max < arr[i][j])
				max = arr[i][j];
	return max;
}
