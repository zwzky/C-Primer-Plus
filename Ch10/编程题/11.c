/*11.编写一个程序，声明一个int类型的3×5二维数组，并用合适的值初始
 * 化它。该程序打印数组中的值，然后各值翻倍（即是原值的2倍），并显示
 * 出各元素的新值。编写一个函数显示数组的内容，再编写一个函数把各元素
 * 的值翻倍。这两个函数都以函数名和行数作为参数。
 */

#include <stdio.h>

void show(int (*pt)[5], int n);
void arr_add(int arr[][5], int n);

int main(void)
{
	int arr[3][5]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	printf("arr now is:\n");
	show(arr, 3);
	arr_add(arr, 3);
	printf("arr now is:\n");
	show(arr, 3);

	return 0;
}

void show(int (*pt)[5], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 5; j++)
			printf("%4d", pt[i][j]);
		printf("\n");
	}
}

void arr_add(int arr[][5], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < 5; j++)
			arr[i][j] *= 2;
}
