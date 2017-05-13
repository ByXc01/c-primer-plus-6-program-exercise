/* File: harmonic_mean.c
 * Author: ByXc
 * About: harmonic_mean
 * Version: 1.0
 * Compilation: gcc 5.3.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

double average_number(double, double);
int main(void)
{
    printf("%f \n", average_number(2, 5));

    return 0;
}

double average_number(double db_value, double db_number)
{
    return 2 / ( 1 / db_value + 1 / db_number);         //項的個數處以（各項數的數倒數之和） 
}

