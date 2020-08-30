/*14.编写一个通过命令行运行的程序计算幂。第1个命令行参数是double
 * 类型的数，作为幂的底数，第2个参数是整数，作为幂的指数。
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	double a, result = 1;
	int b;
	if(argc != 3)
		printf("Usage: %s number exponent\n", argv[0]);
	else
	{
		a = atof(argv[1]);
		b = atoi(argv[2]);
		int i;
		for(i = 0; i < b; i++)
			result *= a;
		printf("the %.2lf power of %d is %.2lf.\n", a, b, result);
	}
	
	return 0;
}
