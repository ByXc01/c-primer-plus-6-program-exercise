// File: pe12-2a.c

#include <stdio.h>
#define METRIC 100

static int i_save_mode;                 // 自動初始化為 0
static double db_fuel, db_distance; 

void set_mode(int i_mode)
{
    if (i_mode == 0 || i_mode == 1)
        i_save_mode = i_mode;
    else if (i_save_mode == 0)
        printf("Invalid mode specified. Mode %d(metric) used.\n", i_save_mode);
    else
        printf("Invalid mode specified. mode %d(Us) used.\n", i_save_mode);
}

void get_info(void)
{
    if (i_save_mode == 0 || i_save_mode == 1)
    {
        if (i_save_mode == 0)
        {
            puts("Enter distance traveled in kilometers: ");
            scanf("%lf", &db_distance);
            puts("Enter fuel consumed in liters: ");
            scanf("%lf", &db_fuel);
        }
        else 
        {
            puts("Enter distance traveled in miles: ");
            scanf("%lf", &db_distance);
            puts("Enter fuel consumed in gallons: ");
            scanf("%lf", &db_fuel);
        }
    }
}

void show_info(void)
{
    double db_fuel_consumption;
    if (i_save_mode == 0)
    {
        db_fuel_consumption = db_fuel * METRIC / db_distance;
        printf("Fuel consumption is %3.2f liters per %d km.\n", db_fuel_consumption, METRIC);
    }    
    else
    {
        db_fuel_consumption = db_distance / db_fuel;
        printf("Fuel consumption is %3.1f miles per gallon. \n", db_fuel_consumption);
    }
}
