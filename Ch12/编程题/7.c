/* 与 diceroll.c 一起编译 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    int dice, sides;
    int i, j, sum;
    int sets;

    srand((unsigned int) time(0));
    printf("Enter the number of sets; enter q to stop : ");
    while(scanf("%d", &sets) == 1 && sets > 0)
    {
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides, &dice);
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for(i = 0; i < sets; i++)
        {
            for(j = 0, sum = 0; j < dice; j++)
                sum +=(rand() % sides + 1);
            printf("%3d ", sum);
            if(i % 5 == 4)
                printf("\n");
        }
        printf("\n");
        printf("How many sets? Enter q to stop: ");
        scanf("%d", &sets);
    }
    
    return 0;
}