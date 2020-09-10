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
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN   20
#define MAX   128

struct softball_player {
    char fname[LEN];
    char lname[LEN];
    int play_games;
    int hit_times;
    int run_bar_times;
    int bri;
    double hit_rate;
};

char * s_gets(char * st, int n);

int main(void)
{
    struct softball_player players[18] = {{'\0', '\0', 0, 0, 0, 0, 0.0} };
    FILE *fp;
    char file_name[MAX];
    struct softball_player player;
    int player_num;
    int i;

    puts("Please enter the file name:");
    s_gets(file_name, MAX);


    if((fp = fopen(file_name, "r")) == NULL)
    {
        fputs("Can't open file", stderr);
        exit(EXIT_FAILURE);
    }
    while(feof(fp) == 0)
    {
        fscanf(fp, "%d %s %s %d %d %d %d", &player_num, player.fname, player.lname,
            &player.play_games, &player.hit_times, &player.run_bar_times, &player.bri);
        if(players[player_num].fname[0] =='\0')
            players[player_num] = player;
        else
        {
            players[player_num].play_games += player.play_games;
            players[player_num].hit_times += player.hit_times;
            players[player_num].run_bar_times += player.run_bar_times;
            players[player_num].bri += player.bri;
        }
        for(i = 0; i < 19; i++)
        {
            if(players[i].fname[0] != '\0')
                players[i].hit_rate = (double)players[i].hit_times / players[i].play_games;
                printf("Player: %s %s, play games: %d, hit times: %d, run bar times: %d, hit_rate: %.2lf\n",
                    players[i].fname, players[i].lname, players[i].play_games, players[i].hit_times,
                    players[i].run_bar_times, players[i].hit_rate);
        }
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
        find = strchr(st, '\0');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
