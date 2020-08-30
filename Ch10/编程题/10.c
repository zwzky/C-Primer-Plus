/*10.编写一个函数，把两个数组中相对应的元素相加，然后把结果储存
 * 到第 3 个数组中。也就是说，如果数组1中包含的值是2、4、5、8，数组2中
 * 包含的值是1、0、4、6，那么该函数把3、4、9、14赋给第3个数组。函数接
 * 受3个数组名和一个数组大小。在一个简单的程序中测试该函数。
 */

#include <stdio.h>

void sum_arr(int a[], int b[], int c[], int n);
void show(int arr[], int n);

int main(void)
{
	int a[] = {2, 4, 5, 8};
	int b[] = {1, 0, 4, 6};
	int c[4];
	sum_arr(a, b, c, 4);
	show(a, 4);
	show(b, 4);
	show(c, 4);

	return 0;
}

void sum_arr(int a[], int b[], int c[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		c[i] = a[i] + b[i];
}

void show(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%4d ", arr[i]);
	printf("\n");

}
