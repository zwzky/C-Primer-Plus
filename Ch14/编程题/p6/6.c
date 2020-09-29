/* 6.一个文本文件中保存着一个垒球队的信息。每一行都是这样的排列：
 * 4 Jessie Joybat 5 2 1 1
 * 第1项是球员号，为方便起见，其范围是0~18。第2项是球员的名。第
 * 3项是球员的姓。名和姓都是一个单词。第四项是官方统计的球员上场
 * 次数。接着3项分别是击中数、走垒数和打点（RBI）。问价可能包含
 * 多场比赛的数据，所以同一个球员可能存在多行数据，而且每一个球员
 * 的多行数据之间可能有其他球员的数据。编写一个程序。把数据存储到
 * 一个结构数组中。该结构中的成员要分别表示球员的名、姓、上场次数、
 * 击中数、走垒数、打点和安达率（稍后计算）。可以使用球员号作为数
 * 组的索引。该程序要读到文件结尾，并统计每位球员的各项累计总和。
 * 世界棒球统计与之相关。例如，一次走垒和触垒中的失误不计入上场次
 * 数，但是可能产生一个RBI。但是该程序要做的是像下面描述的一样读取
 * 和 * 处理数据文件，不会关心数据的实际含义。
 * 要实现这些功能，最简单的方法是把结构的内容都初始化为零，把文件
 * 中的数据读入临时变量中，然后将其加入相应的结构中。程序读完文件
 * 后，应计算每位球员的安打率，并把计算结果储存到结构的相应成员中。
 * 计算安打率是用球员的累计击中数除以上场累计次数。这是一个浮点数
 * 计算。最后，程序结合整个球队的统计数据，一行显示一位球员的累计数据。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN   20
#define MAX   128

struct softball_player {
    char fname[LEN];    //名
    char lname[LEN];    //姓
    int play_games;     //上场次数
    int hit_times;      //击中数
    int run_bar_times;  //走垒数
    int bri;            //打点
    double hit_rate;    //安打率
};

char * s_gets(char * st, int n);

int main(void)
{
    struct softball_player players[19] = {{'\0', '\0', 0, 0, 0, 0, 0.0} };  //创建一个结构数组变量并初始化为0
    FILE *fp;  //创建一个文件变量指针
    char file_name[MAX];  //创建一个字符串数组用于存储文件名
    struct softball_player player;  //创建一个临时结构变量用于存储文件中每一行的数据
    int player_num;  //球员号
    int i;
    
    //获取文件名，如果打开文件失败，则退出
    puts("Please enter the file name:");
    s_gets(file_name, MAX);

    if((fp = fopen(file_name, "r")) == NULL)
    {
        fputs("Can't open file", stderr);
        exit(EXIT_FAILURE);
    }

    //将文件数据通过一个结构变量存入到结构变量数组中
    while(feof(fp) == 0)  //feof()：当上一次输入调用检测文件结尾时，返回一个非零值，否则返回0
    {
        fscanf(fp, "%d %s %s %d %d %d %d", &player_num, player.fname, player.lname,
            &player.play_games, &player.hit_times, &player.run_bar_times, &player.bri);
        if(players[player_num].fname[0] == '\0')  //判断球员名是否为空，为空就表示第一行数据开始记录
            players[player_num] = player;
        else  //球员号相同的各项数据进行累加
        {
            players[player_num].play_games += player.play_games;
            players[player_num].hit_times += player.hit_times;
            players[player_num].run_bar_times += player.run_bar_times;
            players[player_num].bri += player.bri;
        }
    }
    
  // 计算每个球员的hit_rate
  for(i = 0; i < 19; i++)
  {
      if(players[i].fname[0] != '\0')
          players[i].hit_rate = (double)players[i].hit_times / players[i].play_games;
  }
  
  //输出每一个球员的数据
  for(i = 0; i < 19; i++)
  {
      if(players[i].fname[0] == '\0')
          continue;
      else
          printf("Player: %s %s, play games: %d, hit times: %d, run bar times: %d, hit_rate: %.2lf\n",
              players[i].fname, players[i].lname, players[i].play_games, players[i].hit_times,
              players[i].run_bar_times, players[i].hit_rate);
  }

  return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
