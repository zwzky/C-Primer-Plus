/*5.使用switch重写练习4。 */

#include <stdio.h>

int main(void)
{
	char ch;
	int n = 0;
	printf("Please enter the string:\n");
	while ((ch = getchar()) != '#'){
		switch(ch)
		{
			case '.': putchar('!'); n++; break;
			case '!': putchar('!'); putchar('!'); n++; break;
			default : putchar(ch);
		}
	}
	printf("the number of replace are %d\n", n);

	return 0;
}
