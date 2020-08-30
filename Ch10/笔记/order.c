#include <stdio.h>

int date[] = {100, 200};
int moredate[] = {300, 300};
int main(void)
{
	int *p1, *p2, *p3;

	p1 = p2 = date;
	p3 = moredate;
	printf("  *p1 = %d,    *p2 = %d,     *p3 = %d\n", *p1, *p2, *p3);
	printf("*p1++ = %d , *++p2 = %d, (*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
	printf("  *p1 = %d,    *p2 = %d,     *p3 = %d\n", *p1, *p2, *p3);

	return 0;
}
