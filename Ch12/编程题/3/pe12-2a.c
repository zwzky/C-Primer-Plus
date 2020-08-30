//pe12-2a.c

#include <stdio.h>
#include "pe12-2a.h"

 void set_mode(int * pt)
{
    
    if(*pt > 1)
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        *pt = 1;
    }
}

void get_info(int n, double * pt1, double * pt2)
{
    if(n == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", pt1);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", pt2);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", pt1);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", pt2);
    }
}

void show_info(int n, double fl1, double fl2)
{
    if(n)
        printf("Fuel constumption is %.1f miles per gallon.\n", fl1 / fl2);
    else
        printf("Fuel constumption is %.1f liters per 100 km.\n", fl2 / fl1 * 100);
}