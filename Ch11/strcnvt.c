#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIM 30

char * s_gets(char * st, int n);

int main(void)
{
	char number[30];
	char *end;
	long value;

	puts("Enter a number (empty line to quit):");
	while(s_gets(number, LIM) != NULL && number[0] != '\0')
	{
		value = strtol(number, &end, 10);
		printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n",
				value, end, *end);
		value = strtol(number, &end, 16);
		printf("base 16 input, base 10 output: %ld, stopped at %s (%d)\n",
				value, end, *end);
		puts("Nest number");
	}
	
	puts("Bye");

	return 0;
}

char * s_gets(char *st, int n)
{
	char * re_val;
	int i = 0;

	re_val = fgets(st, n, stdin);
	if(re_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return re_val;
}
