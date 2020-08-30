
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
 
int main(void)
{
    FILE *fp;
    int a, b;
    printf("Input a and b:");
    scanf("%d %d", &a, &b);
    int n[a][b];
    char ch[a][b + 1];
    char s[b + 2];
    int in = 0;
    char l[] = {' ','.','\'','\"','^','*','%','$','@','#'};
    if((fp = fopen("picture", "r")) == NULL)
    {
        fprintf(stderr, "Open %s failed\n", "123.txt");
        exit(EXIT_FAILURE);
    }
    while (fgets(s, 40, fp) && in < a)
    {
        for (int i = 0; i < b; ++i) {
            n[in][i] = s[i] - '0';
        }
        in++;
    }
    for (int j = 0; j < a; ++j) {
        for (int i = 0; i < b; ++i) {
            ch[j][i] = l[n[j][i]];
        }
        ch[j][b] = '\0';
    }
    for (int k = 0; k < a; ++k)
    {
        puts(ch[k]);
    }
    return 0;
}