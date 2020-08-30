/*1.修改程序清单10.7的rain.c程序，用指针进行计算（仍然要声明并初始化数组）。*/

#include <stdio.h>

#define MONTHS 12   // 一年的月份数
#define YEARS 5   // 年数

float total_year(const float rain[][MONTHS], int n);
void average_month(const float arr[][MONTHS], int n);

int main(void)
{
	// 用2010～2014年的降水量数据初始化数组
	const float rain[YEARS][MONTHS] =
	{
		{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
	 	{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
	 	{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
	 	{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
	 	{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
	};

	int year, month;
	float subtot, total;
	printf(" YEAR  RAINFALL (inches)\n");

	total = total_year(rain, YEARS);

	printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
	printf("MONTHLY AVERAGES:\n\n");
	printf("  Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
	average_month(rain, YEARS);

	printf("\n");
	
	return 0;
}

float total_year(const float arr[][MONTHS], int n)
{
	int i, j;
	float subtot, total;
	for (i = 0, total = 0; i < n; i++)
	{           // 每一年，各月的降水量总和
		for (j = 0, subtot = 0; j < MONTHS; j++)
	//		subtot += arr[j][j];
			subtot += arr[i][j];
		printf("%5d %15.1f\n", 2010 + i, subtot);
		total += subtot; // 5年的总降水量
	}
	return total;
}

void average_month(const float arr[][MONTHS], int n)
{
	int i, j;
	double subtot;
	for(i = 0; i < MONTHS; i++)
	{
		for(j = 0, subtot = 0; j < n; j++)
			subtot += arr[j][i];
		printf("%5.1f", subtot / YEARS);
	}
}
