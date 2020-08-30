/*11.编写一个程序，在数组中读入8个整数，然后按倒序打印这8个整数。*/

#include <stdio.h>

int main(void)
{
	int arr[8];
	int i;
	for(i = 0; i < 8; i++){
		scanf("%d", &arr[i]);
	}
	for(i = 0; i < 8; i++){
		printf("%d ", arr[7 - i]);
	}

	return 0;
}
