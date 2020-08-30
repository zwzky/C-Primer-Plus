/*1.编写一个程序，把用分钟表示的时间转换成用小时和分钟表示的时
  间。使用#define或const创建一个表示60的符号常量或const变量。通过while
  循环让用户重复输入值，直到用户输入小于或等于0的值才停止循环。
*/

#include <stdio.h>
const int M_PER_H = 60;

int main(void)
{	
	int time;
	int min, hour;
	printf("Please enter minutes:");
	scanf("%d", &time);
	while(time > 0){
		hour = time / M_PER_H;
		min = time % M_PER_H;
		printf("%d minutes is %d hours %d minutes.\n", time, hour, min);
		printf("Please enter minutes:");
		scanf("%d", &time);	
	}
	printf("Done!\n");
	return 0;
}
