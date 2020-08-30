/*4.编写一个程序，在遇到EOF之前，把输入作为字符流读取。该程序要
 * 报告平均每个单词的字母数。不要把空白统计为单词的字母。实际上，标点
 * 符号也不应该统计，但是现在暂时不同考虑这么多（如果你比较在意这点，
 * 考虑使用ctype.h系列中的ispunct()函数）。
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	int count_word = 0;
	int average;
	int count_character = 0;
	int ch;
	bool word_flag = false;
	printf("Please enter the string:\n");
	while((ch = getchar()) != EOF){
		if(!isspace(ch) && !ispunct(ch)){
			count_character++;
			if(!word_flag){
				count_word++;
				word_flag = true;
			}
		}
		if(isspace(ch) || ispunct(ch))
			word_flag = false;		
	}
	printf("the average number of each word is %.1f characters.\n", 1.0 * count_character / count_word);
	return 0;
}
