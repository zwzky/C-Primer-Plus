// funds1.c --传递一个结构

#include <stdio.h>
#define FUNDLEN 50

struct funds{
    char    bank[FUNDLEN];
    double  bankfund;
    char    save[FUNDLEN];
    double  savefund;
};

double sum(struct funds moolanh);

int main(void)
{
    struct funds stan = {
        "Gralic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
    printf("Stan has total of $%.2f.\n", sum(stan));

    return 0;
}

double sum(struct funds moolanh)
{
    return (moolanh.bankfund + moolanh.savefund);
}