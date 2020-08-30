/*13.编写一个程序，创建一个包含8个元素的int类型数组，分别把数组元
 素设置为2的前8次幂。使用for循环设置数组元素的值，使用do while循环显
 示数组元素的值。
*/
#include <stdio.h>
#define SIZE 8

int main(void)
{
	int arr[SIZE];
	int i;
	int value = 1;
	for(i = 0; i < SIZE; i++){
		arr[i] = value;
		value *= 2;	
	}
	i = 0;
	do{
		printf("%d ", arr[i]);
		i++;
	}while(i < SIZE);
	printf("\n");
	return 0;
}
