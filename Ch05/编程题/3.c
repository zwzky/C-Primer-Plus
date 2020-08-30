/*3.编写一个程序，提示用户输入天数，然后将其转换成周数和天数。例
  如，用户输入18，则转换成2周4天。以下面的格式显示结果：
*/

#include <stdio.h>

int main(void)
{
	int day;
	int week,w_day;
	printf("Please enter the days:");
	scanf("%d", &day);
	while(day > 0){
		week = day / 7;
		w_day = day % 7;
		printf("%d days are %d weeks, %d days\n", day, week, w_day);
		printf("Please enter the days:");
		scanf("%d", &day);
	}
	printf("Done!\n");
	return 0;
}
