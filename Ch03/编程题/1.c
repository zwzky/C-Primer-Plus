//通过实验（即编写带有此类问题的程序）观察系统如何处理整数x上溢、d浮点数上溢和d下溢的情况

#include <stdio.h>

int main(void)
{
	int i = 214783647;
	unsigned int j = 4294967295;
	printf("%d %d %d\n", i, i+1, i+2);
	printf("%d %d %d\n", j, j+1, j+2);
	return 0;
}
