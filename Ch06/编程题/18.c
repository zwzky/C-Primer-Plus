/*18.Rabnud博士加入了一个社交圈。起初他有5个朋友。他注意到他的朋
 * 友数量以下面的方式增长。第1周少了1个朋友，剩下的朋友数量翻倍；第2
 * 周少了2个朋友，剩下的朋友数量翻倍。一般而言，第N周少了N个朋友，剩
 * 下的朋友数量翻倍。编写一个程序，计算并显示Rabnud博士每周的朋友数
 * 量。该程序一直运行，直到超过邓巴数（Dunbar’s number）。邓巴数是粗略
 * 估算一个人在社交圈中有稳定关系的成员的最大值，该值大约是150
 */

#include <stdio.h>
#define DN 150

int main(void)
{
	int i = 5;
	int week;
	for(week = 1; i < 150; week++){
		i = 2 * (i - week);
		printf("%d %d\n", week ,i);
	
	}
	return 0;
}
