/* 6、1个水分子的质量约为3.0×10^-23克，1夸脱水大约为950克，编写一个程序，提示用户输入水的夸脱数，并显示水分子的质量 */

#include <stdio.h>

int main(void)
{
	float mass_moll = 3.0e-23;
	float mass_qt = 950;
	float quarts;
	float molecules;
	
	printf("Enter the number of quarts of water:  ");
	scanf("%f", &quarts);
	molecules = quarts * mass_qt / mass_moll;
	printf("%f quarts of water contain %e molecules.\n", quarts, molecules);
	
	return 0;
}
