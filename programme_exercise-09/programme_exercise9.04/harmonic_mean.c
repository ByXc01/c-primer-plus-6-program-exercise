/* File: harmonic_mean.c
 * Author: ByXc
 * About: harmonic mean
 * Version: 1.0
 * Compiler: gcc 5.1.0 for MinGw
 * Date: 20170513
 * Github: ByXc01
 * Blog: http://ByXc01.github.io
 */

#include <stdio.h>

double average_number(double, double);
int main(void)
{
    printf("%f \n", average_number(5.0, 6.0));			   	  // 簡單的測試

    return 0;
}

double average_number(double db_value, double db_number)
{
    return 1.0 / ((1.0 / db_value + 1.0 / db_number) / 2);    //（各項數的數倒數之和）除以項的個數，然後再倒數
}

