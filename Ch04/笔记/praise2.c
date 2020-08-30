#include <stdio.h>
#include <string.h>
#define PRAISE "What a super marvelous name!"

int main(void)
{
	char name[40];
	
	printf("What's your name?");
	scanf("%s", name);
	printf("Hello, %s\n", name);

	printf("Your name of %zd letters occupies %zd memory.\n", strlen(name), sizeof(name));
	printf("The PRAISE has %zd letters.\n",strlen(PRAISE));
	printf("The PRAISE occupies %zd memory\n", sizeof PRAISE);

	return 0;
}
