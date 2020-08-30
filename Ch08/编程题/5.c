/*5.修改程序清单8.4的猜数字程序，使用更智能的猜测策略。例如，程序
 * 最初猜50，询问用户是猜大了、猜小了还是猜对了。如果猜小了，那么下一
 * 次猜测的值应是50和100中值，也就是75。如果这次猜大了，那么下一次猜
 * 测的值应是50和75的中值，等等。使用二分查找（binary search）策略，如
 * 果用户没有欺骗程序，那么程序很快就会猜到正确的答案。
 */

#include <stdio.h>

 int main(void)
{
	int guess = 50;
	int high = 100;
	int low = 1;
	char response;

	printf("Pick an integer from 1 to 100. I will try to guess it.\n");
	printf("Respond with a 'y' if my guess is right,or a 'h' if it is high, or a 'l' if is low.\n");
	printf("The number is %d?\n", guess);
	while ((response = getchar()) != 'y'){
		if(response == 'h')
			high = guess - 1;
		else if(response == 'l')
			low = guess + 1;
		else
			printf("Sorry, I understand only 'y', 'h' or 'l'.\n");
		guess = (high + low) / 2;
		printf("Is it %d.\n", guess);
		while (getchar() != '\n')
			continue;
	}
	printf("I knew I could do it!\n");
	return 0;
}
