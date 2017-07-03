/* File: fe12-2a.c */

#include <stdio.h>
#include "pe12-2a.h"

#define METRIC 100

void set_mode(int i_mode, int i_save_mode)
{
    if (i_mode == 0 || i_mode == 1)
        i_save_mode = i_mode;
    else if (i_save_mode == 0)
        printf("Invalid mode specified. Mode %d(metric) used.\n", i_save_mode);
    else
        printf("Invalid mode specified. Mode %d(Us) used.\n", i_save_mode);
    get_info(i_save_mode);
}

void get_info(int i_save_mode)
{
    double db_fuel, db_distance;

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
    show_info(db_fuel, db_distance, i_save_mode);
}

void show_info(double db_fuel, double db_distance, int i_save_mode)
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
