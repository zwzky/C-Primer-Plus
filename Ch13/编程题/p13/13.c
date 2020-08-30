/*13.用变长数组（VLA）代替标准数组，完成编程练习12 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE    40

int main(void)
{
    FILE * fp;
    char name[SIZE];
    int rows, cols;
    int i = 0, j = 0;
    char l[] = {' ', ',', '\'', '\"', '^', '*', '%', '$', '@', '#'};

    printf("Please input rows and cols.\n");
    scanf("%d %d", &rows, &cols);

    int arr[rows][cols];
    char ch[rows][cols + 1];

    puts("Plese input the filename.");
    scanf("%s", name);

    if((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open file %s.\n", name);
        exit(EXIT_FAILURE);
    }
    while((fscanf(fp, "%d", &arr[i][j])) == 1 && i < rows)
    {
        j++;
        if(j < cols)
            continue;
        else
        {
            j = 0;
            i++;
        }
    }
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            ch[i][j] = l[arr[i][j]];
        ch[i][cols] = '\0'; 
    }
    for(i = 0; i < rows; i++)
        puts(ch[i]);

    return 0;
}
