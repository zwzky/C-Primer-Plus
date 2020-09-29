/* 巨人航空公司的机群由 12 个座位的飞机组成。它每天飞行一个航班。
 * 根据下面的要求，编写一个座位预订程序。
 * a.该程序使用一个内含 12 个结构的数组。每个结构中包括：一个成
 * 员表示座位编号、一个成员表示座位是否已被预订、一个成员表示预
 * 订人的名、一个成员表示预订人的姓。
 * 
 * b.该程序显示下面的菜单：
 * To choose a function, enter its letter label:
 * a) Show number of empty seats
 * b) Show list of empty seats
 * c) Show alphabetical list of seats
 * d) Assign a customer to a seat assignment
 * e) Delete a seat assignment
 * f) Quit
 *
 * c.该程序能成功执行上面给出的菜单。选择d)和e)要提示用户进行额外
 * 输入，每个选项都能让用户中止输入。
 *
 * d.执行特定程序后，该程序再次显示菜单，除非用户选择f)。
 */

#include <stdio.h>
#include <string.h>

#define TOTAL_SEAT  12
#define MAX         128

struct seat{
    int seat_num;
    int book;
    char fname[MAX];
    char lname[MAX];
};

void showlist();
char get_choice();
void show_empty_seat(struct seat *airplance);
void list_empty_seat(struct seat *airplance);
void show_alphabetical(struct seat *airplance);
void book_seat(struct seat *airplance);
void delete_seat(struct seat *airplance);
char * s_gets(char * st, int n);

int main(void)
{
    struct seat airplance_seats[TOTAL_SEAT] = {{0, 0, '\0', '\0'}};
    char choice;
    int i;

    for(i = 0; i < TOTAL_SEAT; i++)
    {
        airplance_seats[i].seat_num = i + 1;
        airplance_seats[i].book = 0;
        airplance_seats[i].fname[0] = '\0';
        airplance_seats[i].lname[0] = '\0';
    }

    while (1)
    {
        showlist();
        choice = get_choice();

        if(choice == 'f')
            break;
        switch(choice)
        {
            case 'a':
                show_empty_seat(airplance_seats);
                break;
            case 'b':
                list_empty_seat(airplance_seats);
                break;
            case 'c':
                show_alphabetical(airplance_seats);
                break;
            case 'd':
                book_seat(airplance_seats);
                break;
            case 'e':
                delete_seat(airplance_seats);
                break;
            default:
                break;
        }
    }

    return 0;
}

void showlist()
{
    printf("To choose a function, enter its letter label\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit\n");
}

char get_choice()
{
    char ch;
    ch = getchar();
    while(getchar() != '\n')
        continue;
    return ch;
}


void show_empty_seat(struct seat *airplance)
{
    int num = 0;
    int i;

    for(i = 0; i < TOTAL_SEAT; i++)
    {
        if(airplance[i].book == 0)
            num++;
    }
    printf("There are %d empty seats.\n", num);
}

void list_empty_seat(struct seat *airplance)
{
    int i;
    for(i = 0; i < TOTAL_SEAT; i++)
    {
        if(airplance[i].book == 0)
            printf(" %d", airplance[i].seat_num);
    }
    printf("\n");
}

void show_alphabetical(struct seat *airplance)
{
    int i;
    printf("Show alphabetical\n");
    for(i = 0; i < TOTAL_SEAT; i++)
    {
        if(airplance[i].book == 1)
            printf("%d booked by %s %s.\n", airplance[i].seat_num), airplance[i].fname,
                airplance[i].lname;
    }
}

void book_seat(struct seat *airplance)
{
    int num = 0;
    while(1)
    {
        printf("Enter the seat number you want to book.\n");
        scanf("%d", num);
        while(getchar() != '\n');
        if(airplance[num].book == 1)
            printf("Seat %d is not empty, please enter again.\n", num + 1);
        else
            break;
    }

    printf("Enter the customer first name:");
    s_gets(airplance[num].fname, MAX);
    printf("Enter the customer last name:");
    s_gets(airplance[num].lname, MAX);

    airplance[num].book = 1;
}

void delete_seat(struct seat *airplance)
{
      int num;
      printf("Enter the seat assignment you want to delet:");

      scanf("%d", &num);
      getchar();
      airplance[num].book = 0;
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
