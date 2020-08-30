/*3.使用嵌套循环，按下面的格式打印字母：
  F
  FE
  FED
  FEDC
  FEDCB
  FEDCBA
  注意：如果你的系统不使用ASCII或其他以数字顺序编码的代码，可以
  把字符数组初始化为字母表中的字母：
  char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  然后用数组下标选择单独的字母，例如lets[0]是‘A’，等等.
*/

#include <stdio.h>

int main(void)
{
	char let = 'F';
	char start;
	char end;
	for(end = let; end > 'A'; end--){
		for(start = let; start >= end ; start--){
			printf("%c", start);	
		}
		printf("\n");
	}
	return 0;
}
