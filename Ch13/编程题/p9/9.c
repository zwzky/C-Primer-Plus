/* 修改程序清单13.3中的程序，从1开始，根据加入列表的顺序为每一个单词
 * 编号。/当程序下次运行时，确保新的单词编号接着上次的编号开始。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];
    int count = 0;
    char ch;

    if((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add tp the file; press the # key at the");
    puts("beginning of a line to terminate.");

    while((ch = getc(fp)) != EOF)
    {
        if(ch == '\n')
            count++;
    }

    while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%d:%s\n", ++count, words);
    puts("File contents:");
    rewind(fp);
    while(fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Done!");
    if(fclose(fp) != 0)
        fprintf(stderr, "Error closing file.\n");

    return 0;
}