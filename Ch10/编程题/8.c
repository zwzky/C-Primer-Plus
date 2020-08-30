/*8.使用编程练习2中的拷贝函数，把一个内含7个元素的数组中第3～第5
 * 个元素拷贝至内含3个元素的数组中。该函数本身不需要修改，只需要选择
 * 合适的实际参数（实际参数不需要是数组名和数组大小，只需要是数组元素
 * 的地址和待处理元素的个数）。
 */

#include <stdio.h>

void show_arr(int * target, int n);
void copy_ptrs(int * target, int * source, int n);

int main(void)
{
	int arr[7] ={1, 2, 3, 4, 5, 6, 7};
	int target[3];
	copy_ptrs(target, arr+2, 3);
	show_arr(target, 3);

	return 0;
}

void copy_ptrs(int * target, int * source, int n)
{
	for(int i = 0; i < n; i++)
		*target++ = *source++;
}

void show_arr(int * target, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", *target++);
	printf("\n");
}
