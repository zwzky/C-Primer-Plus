/*9.编写一个程序，初始化一个double类型的3×5二维数组，使用一个处理
 * 变长数组的函数将其拷贝至另一个二维数组中。还要编写一个以变长数组为
 * 形参的函数以显示两个数组的内容。这两个函数应该能处理任意N×M数组
 * （如果编译器不支持变长数组，就使用传统C函数处理N×5的数组）
 */

#include <stdio.h>

void copy_arr(int, int, double target[*][*], double source[*][*]);
void show_arr(int, int, double arr[*][*]);

int main(void)
{
	double arr[3][5] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0,11.0, 12.0, 13.0, 14.0, 15.0};
	double target[3][5];
	copy_arr(3, 5, target, arr);
	show_arr(3, 5, arr);
	show_arr(3, 5, target);

	return 0;
}

void copy_arr(int m, int n, double target[m][n], double source[m][n])
{
	int i, j;
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			target[i][j] = source[i][j];
}

void show_arr(int m, int n, double arr[m][n])
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j ++)
			printf("%4.1f ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}
