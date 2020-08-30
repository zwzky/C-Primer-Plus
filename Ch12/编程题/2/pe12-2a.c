//pe12-2a.c

#include <stdio.h>
#include "pe12-2a.h"

static int mode;
static float distance;
static float fuel;

 void set_mode(int n)
{
    
    if(n > 1)
    {
        if(mode)
            printf("Invalid mode specified. Mode 1(US) used.\n");
        else
            printf("Invalid mode specified. Mdde 0(metric) used.\n"); 
    }
    else
        mode = n;
}

void get_info(void)
{
    if(mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", &fuel);
    }
}

void show_info(void)
{
    if(mode)
        printf("Fuel constumption is %.1f miles per gallon.\n", distance / fuel);
    else
        printf("Fuel constumption is %.1f liters per 100 km.\n", fuel / distance * 100);
}